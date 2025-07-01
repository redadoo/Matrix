#pragma once

#include <cstddef>
#include <ostream>
#include <array>
#include <cassert>
#include <iomanip>

template<std::size_t R, std::size_t C, typename T>
struct mat
{
    std::array<T, R * C> data{};

    T& operator()(std::size_t row, std::size_t col)
    {
        assert(row < R && col < C);
        return data[row * C + col];
    }

    const T& operator()(std::size_t row, std::size_t col) const
    {
        assert(row < R && col < C);
        return data[row * C + col];
    }

    void Add(const mat& other)
    {
        for (std::size_t i = 0; i < data.size(); ++i)
            data[i] += other.data[i];
    }

    friend std::ostream& operator<<(std::ostream& os, const mat& m)
    {
        constexpr int width = 3;
        os << "[";
        for (std::size_t i = 0; i < R; ++i)
        {
            if (i > 0)
                os << "\n          ";
            for (std::size_t j = 0; j < C; ++j)
            {
                os << std::setw(width) << m(i, j);
                if (j + 1 < C)
                    os << ",";
            }
        }
        os << "]";
        return os;
    }
};
