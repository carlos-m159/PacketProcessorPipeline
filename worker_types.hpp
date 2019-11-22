#ifndef WORKER_TYPES_HPP
#define WORKER_TYPES_HPP

#include "field_template.hpp"

class Field1Worker : public TFieldAbs<Field1Worker>
{
public:
    /// @brief Default C'tor
    Field1Worker(void){}

    /// @brief Default D'tor
    ~Field1Worker(void){}

    /// @brief Process field
    void processImpl(sField1_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field2Worker : public TFieldAbs<Field2Worker>
{
public:
    /// @brief Default C'tor
    Field2Worker(void){}

    /// @brief Default D'tor
    ~Field2Worker(void){}

    /// @brief Process field
    void processImpl(sField2_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field3Worker : public TFieldAbs<Field3Worker>
{
public:
    /// @brief Default C'tor
    Field3Worker(void){}

    /// @brief Default D'tor
    ~Field3Worker(void){}

    /// @brief Process field
    void processImpl(sField3_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field4Worker : public TFieldAbs<Field4Worker>
{
public:
    /// @brief Default C'tor
    Field4Worker(void){}

    /// @brief Default D'tor
    ~Field4Worker(void){}

    /// @brief Process field
    void processImpl(sField4_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

class Field5Worker : public TFieldAbs<Field5Worker>
{
public:
    /// @brief Default C'tor
    Field5Worker(void){}

    /// @brief Default D'tor
    ~Field5Worker(void){}

    /// @brief Process field
    void processImpl(sField5_type* ptr)
    {
        std::cout << "Processing " << ptr->identifier << std::endl;
    }
};

#endif // WORKER_TYPES_HPP
