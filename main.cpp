#include <iostream>
#include <atomic>
#include <thread>
#include <utility>

#include "fields_factory.h"
#include "template_factories.h"


class CMessage
{
public:
    CMessage(sMessage_tst* ptr)
        :
          ptr(ptr)
    {
        // Increase instance counter
        operationCounter()++;
    }
    ~CMessage()
    {
        // Decrease instance counter
        operationCounter()--;
    }

    template <class T>
    void createMessage(T& args)
    {
        // Here We can send the pointer to the memory
        args.processFields();
    }

    uint32_t getCounter()
    {
        return operationCounter().load();
    }

private:

    sMessage_tst* ptr;
    std::atomic_uint32_t&  operationCounter()
    {
        static std::atomic_uint32_t m_counter = {0};
        return m_counter;
    }
};


// Specify packet factory fields

using t1  = std::tuple<sField1_type, Field1>;
using t2  = std::tuple<sField2_type, Field2>;
using t3  = std::tuple<sField3_type, Field3>;


//using packet1_factory_type = TPacketFactory<t1,t2,t3>;
using packet1_factory_type = TPacketFactory<Field1, Field2, Field3>;

int main()
{
    // Memory Pool
    sMessage pkt;

    // Factory
    packet1_factory_type factory_1;

    // Message containing the ptr to factory
    cMessage<packet1_factory_type> laserScanMessage(&pkt, factory_1);

    // Process Packet
    // Cons: Having a friend method to allow the template specialization
    laserScanMessage.processField(&pkt.body1);
    laserScanMessage.processField(&pkt.header);
    laserScanMessage.processField(&pkt.body2);

    // Process with indx
    // Cons: Keeping track of the index
    laserScanMessage.processFieldWithIndex<1>(&pkt.body1);
    laserScanMessage.processFieldWithIndex<0>(&pkt.header);
    laserScanMessage.processFieldWithIndex<2>(&pkt.body2);


    return 0;
}
