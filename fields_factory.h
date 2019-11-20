#ifndef FIELDS_FACTORY_H
#define FIELDS_FACTORY_H

#include <iostream>

struct sField1_type
{
    uint32_t field;
    std::string identifier = "Field 1";
};

struct sField2_type
{
    uint32_t field;
    std::string identifier = "Field 2";
};
struct sField3_type
{
    uint32_t field;
    std::string identifier = "Field 3";
};

typedef struct sMessage
{
    sField1_type header;
    sField2_type body1;
    sField3_type body2;

} sMessage_tst;

template <class TFactory>
class cMessage
{
public:
    cMessage (sMessage* ptr, TFactory* fac)
        :
          ptr(ptr),
          factory(fac)
    {

    }

    template <class TField>
    void processField(TField* pointer)
    {
        factory->processField(pointer);
    }

    template <class TField>
    void processFieldWithIndex(TField* pointer)
    {
        factory->processFieldWithIndx(pointer);
    }

    sMessage* ptr;

    TFactory* factory;

};

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
    template <class TMessageField>
    bool process(TMessageField f1)
    {
        static_cast<DERIVED*>(this)->processImpl(f1);
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

#endif // FIELDS_FACTORY_H
