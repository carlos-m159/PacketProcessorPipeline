#ifndef TEMPLATE_FACTORIES_H
#define TEMPLATE_FACTORIES_H

#include <iostream>
#include <utility>
#include <array>
#include <fields_factory.h>
class CPacket;


template <typename ...TField>
class TPacketFactory
{
    /// @brief ...
    using TTypeListElement = typename std::tuple<TField...>;
    //using container = std::array<TField...,sizeof... (TField)>;
    //using TTypeListElement = TField;

    // C++11 Work around
    // C++14 we can use make index
    // This is the type which holds sequences
    template <size_t ... Ns> struct sequence {};

    // First define the template signature
    template <size_t ... Ns> struct seq_gen;

    // Recursion case
    template <size_t I, size_t ... Ns>
    struct seq_gen<I, Ns...>
    {
        // Take front most number of sequence,
        // decrement it, and prepend it twice.
        // First I - 1 goes into the counter,
        // Second I - 1 goes into the sequence.
        using type = typename seq_gen<
            I - 1, I - 1, Ns...>::type;
    };

    // Recursion abort
    template <size_t ... Ns>
    struct seq_gen<0, Ns...>
    {
        using type = sequence<Ns...>;
    };

    template <size_t N>
    using sequence_t = typename seq_gen<N>::type;

public:
    /// @brief Default C'tor
    TPacketFactory()
    {
    }

    /// @brief Process Field saying the index of the field to process
    template <size_t idx,class TIndividual>
    void processFieldWithIndx(TIndividual* ptr)
    {
        TTypeListElement field_tupple;
        std::get<idx>(field_tupple).process(ptr);
    }

    /// @brief Process Packet
    template <class TIndividual>
    void processField(TIndividual* ptr)
    {
        TTypeListElement field_tupple;

        // Not very beautifull solution, but works
        //std::get<idx>(field_tupple).process(ptr);

        // Lets see who can work over this data
        tuple_call_(sequence_t<sizeof...(TField)>{},field_tupple, ptr);
    }

    /// @brief Get multiple tuple elements to process fields
    template<size_t ... INDICES, class TIndividual>
    void tuple_call_(sequence<INDICES...>, TTypeListElement& tupple, TIndividual* ptr)
    {
        processFields(ptr,std::get<INDICES>(tupple)...);
    }

    /// @brief Worker to call individual process based on the input
    template<class TIndividual, class T>
    friend bool callIndividual(TIndividual* ptr, T field);

    /// @brief Processing single fields, unpack different tupple elements
    template<class TIndividual, class ...T>
    void processFields( TIndividual* ptr,T... field)
    {
        bool dummy [] = {callIndividual(ptr, field)...};
    }

};


template<class TIndividual, class T>
bool callIndividual(TIndividual* ptr, T field)
{
    // DO nothing
}

template<>
bool callIndividual(sField1_type* ptr, Field1 field)
{
    // DO nothing
    field.process(ptr);
    return true;
}


template<>
bool callIndividual(sField2_type* ptr, Field2 field)
{
    // DO nothing
    field.process(ptr);
    return true;
}


template<>
bool callIndividual(sField3_type* ptr, Field3 field)
{
    // DO nothing
    field.process(ptr);
    return true;
}





#endif // TEMPLATE_FACTORIES_H
