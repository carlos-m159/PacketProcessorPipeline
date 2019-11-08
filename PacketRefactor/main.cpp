#include <iostream>

using namespace std;

/// Field Factory
///
template <class Derived>
class SimpleFieldFactory
{
public:
    SimpleFieldFactory()
    {}

    bool processSingleField()
    {
        static_cast<Derived*>(this)->processImpl();
    }
};


class SpecificFieldFactory : public SimpleFieldFactory<SpecificFieldFactory>
{
public:
    SpecificFieldFactory(){}


    void processImpl()
    {
        std::cout << "This is Specifc Field Method" << std::endl;
    }
};


class SpecificCalibrationFieldFactory : public SimpleFieldFactory<SpecificCalibrationFieldFactory>
{
public:
    SpecificCalibrationFieldFactory(){}

    void processImpl()
    {
        std::cout << "This is Specific Calibration Field" << std::endl;
    }
};


//----------------------------------------------------------------------------
/// Packet "Factory"
template <class DERIVED>
class CPacketRecipes
{
public:
    CPacketRecipes(){}

    void processFields()
    {
        static_cast<DERIVED*>(this)->processFieldsImpl();
    }
};


class CLaserScanStepRecipe : public CPacketRecipes <CLaserScanStepRecipe>
{
public:

    void processFieldsImpl()
    {
        std::cout << "Preparing Laser Scan Packet" << std::endl;

        //
        SpecificFieldFactory time_stamp;
        SpecificCalibrationFieldFactory specific_calibration;

        this->processFactoryField(time_stamp, specific_calibration);
    }

    template<class ...T>
    void processFactoryField(T... args)
    {
        // Dummy call
        bool d[] = {args.processSingleField()...};
    }

private:
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

    template <class T>
    void createMessage(T& args)
    {
        // Here We can send the pointer to the memory
        args.processFields();
    }

private:
    /// @brief Factory Field

    static uint32_t & getCounter()
    {
        static uint32_t m_counter = 0;
        return m_counter;
    }

    /// @brief Ptr to the data (Data Type union)
    /// dataPacketptr ptr;
};

int main()
{
    // Create packet
    CPacket packet;

    // Packet factory -> "Abstract Class" is CPacketRecipes
    CLaserScanStepRecipe cod_factory;
    packet.createMessage(cod_factory);

    return 0;
}
