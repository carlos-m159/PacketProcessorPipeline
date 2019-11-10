#include <iostream>
#include <atomic>
#include <thread>
#include <utility>

#include "fields_factory.h"
#include "template_factories.h"

class CPacket
{
public:
    CPacket()
    {
        // Increase instance counter
        operationCounter()++;
    }
    ~CPacket()
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
    std::atomic_uint32_t&  operationCounter()
    {
        static std::atomic_uint32_t m_counter = {0};
        return m_counter;
    }
};


// Specify packet factory fields
using packet1_factory_type = TPacketFactory<Field1, Field2, Field3>;

int main()
{
    // Packet
    CPacket pkt;

    // Factory
    packet1_factory_type factory_1;

    // Process Packet
    factory_1.processPacket(&pkt);

    return 0;
}
