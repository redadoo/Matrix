#pragma once

#include "Matrix.hpp"
#include <array>
#include <cstddef>

namespace Maft
{
    template<typename T>
    struct Matrix<2, 2, T>
    {
        std::array<T, 4> data;

        // Constructors
        MAFT_CONSTEXPR Matrix();
        MAFT_CONSTEXPR Matrix(T a11, T a12, T a21, T a22);
    	MAFT_CONSTEXPR Matrix(const Matrix& other);
        
		// Element access
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator()(std::size_t row, std::size_t col);
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t row, std::size_t col) const;

        // Assignment
        MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T>& operator=(const Matrix<2, 2, T>& other);

        // Comparison
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Matrix<2, 2, T>& other) const;

        // Operations
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix<2, 2, T>& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix<2, 2, T>& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix<2, 2, T>& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);

		// static
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<2, 2, T> Lerp(const Matrix<2, 2, T>& a, const Matrix<2, 2, T>& b, float t);
    };

    template<typename T>
    using Matrix2x2 = Matrix<2, 2, T>;
}

#include "Matrix2x2.inl"
