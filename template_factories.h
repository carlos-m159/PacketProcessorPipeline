#ifndef TEMPLATE_FACTORIES_H
#define TEMPLATE_FACTORIES_H

#include <iostream>
#include <utility>

class CPacket;

template <class ...TField>
class TPacketFactory
{
    /// @brief ...
    using TTypeListElement = typename std::tuple<TField...>;

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

    /// @brief Process Packet
    void processPacket(CPacket* ptr)
    {
        TTypeListElement field_tupple;

        tuple_call_(sequence_t<sizeof...(TField)>{},field_tupple);
    }

    /// @brief Get multiple tuple elements to process fields
    template<size_t ... INDICES>
    void tuple_call_(sequence<INDICES...>, TTypeListElement& tupple)
    {
        processFields(std::get<INDICES>(tupple)...);
    }

    /// @brief Processing single fields, unpack different tupple elements
    template<class ...T>
    void processFields(T... field)
    {
        bool test[] = {field.process()...};
    }

};


#endif // TEMPLATE_FACTORIES_H
