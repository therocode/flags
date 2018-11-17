#pragma once

namespace flg
{
template <typename numeric_type, typename user_type>
struct flags
{
    using value_type = numeric_type;

    explicit constexpr operator value_type() const { return value; }
    constexpr operator bool() const { return value; }

    constexpr flags operator~() const
    {
        return flags{~value};
    }
    constexpr flags operator&(flags other) const
    {
        return flags{value & other.value};
    }
    constexpr flags operator|(flags other) const
    {
        return flags{value | other.value};
    }
    constexpr flags operator^(flags other) const
    {
        return flags{value ^ other.value};
    }
    constexpr flags& operator&=(flags other)
    {
        value &= other.value;
        return *this;
    }
    constexpr flags& operator|=(flags other)
    {
        value |= other.value;
        return *this;
    }
    constexpr flags& operator^=(flags other)
    {
        value ^= other.value;
        return *this;
    }
    constexpr bool operator==(flags other) const
    {
        return value == other.value;
    }
    constexpr bool operator!=(flags other) const
    {
        return value != other.value;
    }

    value_type value;

    struct flag
    {
        value_type value;

        constexpr operator user_type() const
        {
            return user_type{value};
        }
        constexpr user_type operator~() const
        {
            return user_type{~value};
        }
        constexpr user_type operator&(flag other) const
        {
            return user_type{value & other.value};
        }
        constexpr user_type operator|(flag other) const
        {
            return user_type{value | other.value};
        }
        constexpr user_type operator^(flag other) const
        {
            return user_type{value ^ other.value};
        }
        constexpr bool operator==(flag other) const
        {
            return value == other.value;
        }
        constexpr bool operator!=(flag other) const
        {
            return value != other.value;
        }
    };

    constexpr static flag none_flag()
    {
       return  {0};
    }

    constexpr static flag from_index(value_type v)
    {
        return {1 << v};
    }
};
}
