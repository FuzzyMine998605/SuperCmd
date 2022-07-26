#pragma once
#include <string>
// https://blog.csdn.net/yozidream/article/details/22789147

typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_(char const *str)
{
    hash_t ret{basis};

    while (*str)
    {
        ret ^= *str;
        ret *= prime;
        str++;
    }

    return ret;
}

constexpr hash_t _hash(char const *str, hash_t last_value = basis)
{
    return *str ? _hash(str + 1, (*str ^ last_value) * prime) : last_value;
}