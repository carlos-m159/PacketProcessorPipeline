#include <iostream>
#include <array>
using namespace std;

/// Field Factory
///
template <class Derived>
class SimpleFieldFactory
{
public:
    SimpleFieldFactory()
    {}

    void processSingleField()
    {
        static_cast<Derived*>(this)->processImpl();
    }
};

class SpecificField : public SimpleFieldFactory<SpecificField>
{
public:
    SpecificField(){}


    void processImpl()
    {
        std::cout << "This is Specifc Field Method" << std::endl;
    }
};

class SpecificCalibrationField : public SimpleFieldFactory<SpecificCalibrationField>
{
public:
    SpecificCalibrationField(){}

    void processImpl()
    {
        std::cout << "This is Specific Calibration Field" << std::endl;
    }
};


class SpecificTOFField : public SimpleFieldFactory<SpecificTOFField>
{
public:
    SpecificTOFField(){}

    void processImpl()
    {
        std::cout << "This is Specific TOF Field" << std::endl;
    }
};

class CPacket
{
public:
    CPacket()
    {
        // Increase instance counter
        getCounter()++;
    }
    ~CPacket()
    {
        // Decrease instance counter
        getCounter()--;
    }

    template <class ...T>
    void process(T ... args)
    {
        bool d [] = {doSomethingDummy(args)...};
    }

    template <class T>
    bool doSomethingDummy(T args)
      {
          //
          args.processSingleField();
          return false;
      }

private:
    /// @brief Factory Field

    static uint32_t & getCounter()
    {
        static uint32_t m_counter = 0;
        return m_counter;
    }

    /// @brief Ptr to the data
    /// dataPacketptr ptr;
};

int main()
{
    cout << "Processing Calibration message" << endl;

    SpecificField time_stamp;
    SpecificCalibrationField specific_calibration;
    CPacket calibration_packet;
    calibration_packet.process(time_stamp, specific_calibration);

    cout << "Processing Laser Scan step message" << endl;

    // Factory
    SpecificField time_stamp2;
    SpecificTOFField specific_tof;
    CPacket LaserScanPacket;
    LaserScanPacket.process(time_stamp2, specific_tof);


    return 0;
}
