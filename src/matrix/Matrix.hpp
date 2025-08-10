#pragma once

#include "Vector.hpp"

namespace Maft
{
    template<std::size_t R, std::size_t C, typename T>
    struct Matrix;

    template<std::size_t R, std::size_t C, typename T>
    std::ostream& operator<<(std::ostream& os, const Matrix<R, C, T>& m);

    template<std::size_t R, std::size_t C, typename T>
    struct Matrix
    {
        std::array<T, R * C> data{};

        Matrix() = default;
        Matrix(const Matrix& other) = default;

        //overload
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator()(std::size_t row, std::size_t col);
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t row, std::size_t col) const;
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix& operator=(const Matrix& other);
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Matrix& other) const;

        //operation
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix& other);
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T> multiply_vector(const Vector<C, T>& v) const;

        // static
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<R, C, T> Lerp(const Matrix<R, C, T>& a, const Matrix<R, C, T>& b, float t);

        // friend
        friend std::ostream& operator<< <R, C, T>(std::ostream& os, const Matrix<R, C, T>& m);
    };
} 

#include "Matrix.inl"
