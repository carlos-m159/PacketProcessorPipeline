#ifndef MESSAGE_TEMPLATE_H
#define MESSAGE_TEMPLATE_H

#include <template_factories.h>
#include <fields_factory.h>
#include <atomic>

/// Here define the Factories:
using LaserScanFactoryType = TPacketFactory<Field1, Field2, Field3>;
using CalibrationFactoryType = TPacketFactory<Field4,Field5>;


/// Message Definition
template <typename TDerived, typename TMessageType, typename TFactory>
class TMessage
{
public:
    /// @brief Default C'tor
    TMessage(TMessageType* ptr, TFactory factory)
        :
          m_msg_ptr(ptr),
          m_factory(factory)
    {
        getCounter()++;
    }

    /// @brief Default D'tor
    ~TMessage(void)
    {
        getCounter()--;
    }

    /// @brief Process method, this is mandatory to be defined in the message side
    void process(void)
    {
        static_cast<TDerived*>(this)->processImpl();
    }

protected:
    /// @brief Process All fields within the factory
    template <class TField>
    void processField(TField* pointer)
    {
        m_factory.processField(pointer);
    }

    /// @brief Member holding pointer to the message location
    TMessageType* m_msg_ptr;

    /// @brief Factory member to construct fields
    TFactory m_factory;

    /// @brief Get Counter
    const std::atomic_int32_t readCounter()
    {
        return getCounter();
    }

private:

    std::atomic_uint32_t&  getCounter()
    {
        static std::atomic_uint32_t m_counter = {0};
        return m_counter;
    }
};

class LaserScanMessage : public TMessage<LaserScanMessage, sMessageLaserScan, LaserScanFactoryType>
{
public:
    /// @brief Default C'tor
    LaserScanMessage(sMessageLaserScan* ptr, LaserScanFactoryType factory)
        :
          TMessage<LaserScanMessage, sMessageLaserScan, LaserScanFactoryType> (ptr, factory)
    {}

    /// @brief Default D'tor
    ~LaserScanMessage(void)
    {}

    /// @brief Specify which message fields to process
    void processImpl()
    {
        // TODO: Should this also be implemented as a n input function
        processField(&this->m_msg_ptr->body1);
        processField(&this->m_msg_ptr->body2);
    }

    void specificMessageRoutine()
    {
        // Specific routine
        std::cout << "This is a specific Message Routine" << std::endl;
        processField(&this->m_msg_ptr->header);
    }
};

class CalibrationMessage : public TMessage<CalibrationMessage, sMessageCalibration, CalibrationFactoryType>
{
public:
    /// @brief Default C'tor
    CalibrationMessage(sMessageCalibration* ptr, CalibrationFactoryType factory)
        :
          TMessage<CalibrationMessage, sMessageCalibration, CalibrationFactoryType> (ptr, factory)
    {}

    /// @brief Default D'tor
    ~CalibrationMessage(void)
    {}

    /// @brief Specify which message fields to process
    void processImpl()
    {
        // TODO: Should this also be implemented as a n input function
        processField(&this->m_msg_ptr->header);
        processField(&this->m_msg_ptr->body1);
    }

    void specificMessageRoutine()
    {
        // Specific routine
        std::cout << "This is a specific Message Routine" << std::endl;
    }
};



#endif // MESSAGE_TEMPLATE_H
