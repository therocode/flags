#pragma once

namespace flg
{
template <typename numeric_type, typename tag>
struct flag
{

struct type
{
    using value_type = numeric_type;

    explicit operator value_type() const { return value; }
    operator bool() const { return value; }

    type operator~() const
    {
        return type{~value};
    }
    type operator&(type other) const
    {
        return type{value & other.value};
    }
    type operator|(type other) const
    {
        return type{value | other.value};
    }
    type operator^(type other) const
    {
        return type{value ^ other.value};
    }
    type& operator&=(type other)
    {
        value &= other.value;
        return *this;
    }
    type& operator|=(type other)
    {
        value |= other.value;
        return *this;
    }
    type& operator^=(type other)
    {
        value ^= other.value;
        return *this;
    }
    bool operator==(type other) const
    {
        return value == other.value;
    }
    bool operator!=(type other) const
    {
        return value != other.value;
    }

    value_type value;

    constexpr static type none_flag()
    {
       return  {0};
    }
    
    constexpr static type from_index(value_type v)
    {
        return {1 << v};
    }
};
};
}
