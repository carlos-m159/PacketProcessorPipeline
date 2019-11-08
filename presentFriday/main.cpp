#include "factory_definition.h"

using namespace std;
class CPacket
{
public:
    CPacket(PacketFieldFactory* fc)
        :
          m_fc(fc)
    {
        m_fc->createPacket();
    }


private:
   // ptr to the mem where the packet will be located))
    PacketFieldFactory* m_fc;

};

class CPipeline
{
public:
    void run()
    {
        // Stream Event (Get Time stamp costumer 1)
        PacketTimeCostumer1 fc;
        CPacket tmpPck(&fc);
    }
};

int main()
{
    CPipeline pipeline;
    pipeline.run();
    return 0;
}
