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
class Field1Worker : public TFieldFactoryAbs<Field1Worker>
{
public:
    /// @brief Default C'tor
    Field1Worker()
    {

    }

    ~Field1Worker()
    {

    }

    /// @brief Process field
    void processImpl(sField1_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field2Worker : public TFieldFactoryAbs<Field2Worker>
{
public:
    /// @brief Default C'tor
    Field2Worker()
    {
    }

    /// @brief Default D'tor
    ~Field2Worker()
    {
    }


    /// @brief Process field
    void processImpl(sField2_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field3Worker : public TFieldFactoryAbs<Field3Worker>
{
public:
    /// @brief Default C'tor
    Field3Worker()
    {
    }

    /// @brief Default D'tor
    ~Field3Worker()
    {
    }

    /// @brief Process field
    void processImpl(sField3_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field4Worker : public TFieldFactoryAbs<Field4Worker>
{
public:
    /// @brief Default C'tor
    Field4Worker()
    {
    }

    /// @brief Default D'tor
    ~Field4Worker()
    {
    }

    /// @brief Process field
    void processImpl(sField4_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field5Worker : public TFieldFactoryAbs<Field5Worker>
{
public:
    /// @brief Default C'tor
    Field5Worker()
    {
    }

    /// @brief Default D'tor
    ~Field5Worker()
    {
    }

    /// @brief Process field
    void processImpl(sField5_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

#endif // FIELDS_FACTORY_H
