#ifndef FIELDS_FACTORY_H
#define FIELDS_FACTORY_H

#include <iostream>

template <class DERIVED>
class TFieldFactoryAbs
{
public:
    /// @brief Abs C'tor
    TFieldFactoryAbs()
    {
    }

    /// @brief Abs D'tor
    ~TFieldFactoryAbs()
    {
    }

    /// @brief Call the Child process Implementation
    bool process()
    {
        static_cast<DERIVED*>(this)->processImpl();
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
    void processImpl()
    {
        std::cout << "Processing Field1!" << std::endl;
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
    void processImpl()
    {
        std::cout << "Process Field2!" << std::endl;
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
    void processImpl()
    {
        std::cout << "Process Field3!" << std::endl;
    }
};

#endif // FIELDS_FACTORY_H
