#ifndef TEMPLATE_FACTORIES_H
#define TEMPLATE_FACTORIES_H

#include <iostream>
#include <utility>
#include <array>
#include <fields_factory.h>


template <typename ...TField>
class TPacketFactory
{
private:
    /// @brief ...
    template<bool Cond, typename T>
    using accept_if = typename std::conditional<Cond,T,void>::type;

    /// @brief Dummy structure to filter types
    template < typename TPtr, typename TTuple, typename validity> struct sFilter
    {
        sFilter(TPtr* ptr, TTuple thistuple)
        {
            std::get<1>(thistuple).process(ptr);
        }
    };

    /// @brief Specialization of the dummy structure
    template<typename TPtr, typename TTuple> struct sFilter<TPtr,TTuple,void>
    {
        sFilter(TPtr* ptr, TTuple thistuple)
        {
            // Do Nothing
        }
    };

    /// @brief Create compile time sequence
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

    /// @brief Get multiple tuple elements to process fields
    template<size_t ... INDICES, class TIndividual>
    void tuple_call_(sequence<INDICES...>, TTypeListElement& tupple, TIndividual* ptr)
    {
        processFields(ptr,std::get<INDICES>(tupple)...);
    }

public:

    /// @brief Default C'tor
    TPacketFactory()
    {
    }

    /// @brief Process Packet
    template <class TIndividual>
    void processField(TIndividual* ptr)
    {
        // Field
        TTypeListElement field_tupple;

        // Get the element from the pair
        tuple_call_(sequence_t<sizeof...(TField)>{},field_tupple, ptr);
    }

    /// @brief For each interface, call the process if available
    template<class TIndividual, class T>
    bool callIndividual(TIndividual* ptr, T field)
    {
        // TODO: Explore the possibility of using a recursive template function to check the Idx of the correct field.
        sFilter<TIndividual, T, accept_if<std::is_same<typeof  (std::get<0>(field)),typeof (*ptr)>::value, bool>>(ptr, field);
    }

    /// @brief Processing single fields, unpack different tupple elements
    template<class TIndividual, class ...T>
    void processFields( TIndividual* ptr,T... field)
    {       
        // Call the function for each index
        bool dummy [] = {callIndividual(ptr, field)...};
    }
};



#endif // TEMPLATE_FACTORIES_H
