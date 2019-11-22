#ifndef FIELDS_FACTORY_H
#define FIELDS_FACTORY_H

#include <field_types.hpp>

template <class TDerived>
class TFieldAbs
{
public:
    /// @brief Abs C'tor
    TFieldAbs(void){}

    /// @brief Abs D'tor
    ~TFieldAbs(void){}

    /// @brief Call the Child process Implementation
    template <class TMessageField>
    bool process(TMessageField f1)
    {
        static_cast<TDerived*>(this)->processImpl(f1);
        return true;
    }
};


#endif // FIELDS_FACTORY_H
