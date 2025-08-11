#pragma once

#include "Matrix.hpp"

namespace Maft
{
	template<typename T>
    struct Matrix<4, 4, T>
    {
        std::array<T, 16> data;

        MAFT_CONSTEXPR Matrix() = default;
        MAFT_CONSTEXPR Matrix(
			T a11, T a12, T a13, T a14, 
			T a21, T a22, T a23, T a24, 
			T a31, T a32, T a33, T a34, 
			T a41, T a42, T a43, T a44
		);
    	MAFT_CONSTEXPR Matrix(const Matrix& other);
        
        // overload
        MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T>& operator=(const Matrix<4, 4, T>& other);
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator()(std::size_t row, std::size_t col);
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Matrix<4, 4, T>& other) const;
        MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t row, std::size_t col) const;

        // Operations
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix<4, 4, T>& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix<4, 4, T>& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix<4, 4, T>& other);
        MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);

		// static
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<4, 4, T> Lerp(const Matrix<4, 4, T>& a, const Matrix<4, 4, T>& b, float t);
    };
}

#include "Matrix4x4.inl"
