#ifndef FIELDS_FACTORY_H
#define FIELDS_FACTORY_H

#include <field_types.hpp>

template <class TDerived>
class TFieldFactoryAbs
{
public:
    /// @brief Abs C'tor
    TFieldFactoryAbs()
    {}

    /// @brief Abs D'tor
    ~TFieldFactoryAbs()
    {}

    /// @brief Call the Child process Implementation
    template <class TMessageField>
    bool process(TMessageField f1)
    {
        static_cast<TDerived*>(this)->processImpl(f1);
        return true;
    }
};

/// Field Implementation
class Field1 : public TFieldFactoryAbs<Field1>
{
public:
    /// @brief Default C'tor
    Field1()
    {

    }

    /// @brief Process field
    void processImpl(sField1_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field2 : public TFieldFactoryAbs<Field2>
{
public:
    /// @brief Default C'tor
    Field2()
    {
    }

    /// @brief Default D'tor
    ~Field2()
    {
    }


    /// @brief Process field
    void processImpl(sField2_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field3 : public TFieldFactoryAbs<Field3>
{
public:
    /// @brief Default C'tor
    Field3()
    {
    }

    /// @brief Default D'tor
    ~Field3()
    {
    }

    /// @brief Process field
    void processImpl(sField3_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field4 : public TFieldFactoryAbs<Field4>
{
public:
    /// @brief Default C'tor
    Field4()
    {
    }

    /// @brief Default D'tor
    ~Field4()
    {
    }

    /// @brief Process field
    void processImpl(sField4_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field5 : public TFieldFactoryAbs<Field5>
{
public:
    /// @brief Default C'tor
    Field5()
    {
    }

    /// @brief Default D'tor
    ~Field5()
    {
    }

    /// @brief Process field
    void processImpl(sField5_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

#endif // FIELDS_FACTORY_H
