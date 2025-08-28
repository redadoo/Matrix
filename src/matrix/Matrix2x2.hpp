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
        
        Matrix() = default;
        MAFT_CONSTEXPR Matrix(const T& x);
    	MAFT_CONSTEXPR Matrix(const Matrix& other);
        MAFT_CONSTEXPR Matrix(T m00, T m10, T m01, T m11);
        
        // assignment operators (Matrix-Matrix)

		MAFT_CONSTEXPR Matrix<2, 2, T>& operator=(const Matrix<2, 2, T>& other);
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator+=(const Matrix<2, 2, T>& other);
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator-=(const Matrix<2, 2, T>& other);
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator*=(const Matrix<2, 2, T>& other);
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator/=(const Matrix<2, 2, T>& other);

		// assignment operators (Matrix-Scalar)

		template<typename U>
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<2, 2, T>& operator/=(U s);
		
		//  increment / decrement

		Matrix<2, 2, T>& operator++();
		Matrix<2, 2, T>& operator--();
		Matrix<2, 2, T> operator++(int);
		Matrix<2, 2, T> operator--(int);

		//  element access

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator()(std::size_t col, std::size_t row);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t col, std::size_t row) const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](std::size_t index);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](std::size_t index) const;

		//  matrix Operations

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void inverse();

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_row();
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_column();

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix<2, 2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix<2, 2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix<2, 2, T>& other);
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T> multiply_vector(const Vector<2, T>& v);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> multiply_matrix(const Matrix<2, 2, T>& other) const;
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T trace() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T determinant() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> transpose() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> row_echelon() const;

		// static utility functions

		MAFT_CONSTEXPR static Matrix<2,2,T> Identity();
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<2, 2, T> Lerp(const Matrix& a, const Matrix& b, float t);

		// // friend
		friend std::ostream& operator<< <>(std::ostream& os, const Matrix& m);
    };

    //  unary operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> operator+(const Matrix<2, 2, T>& other);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> operator-(const Matrix<2, 2, T>& other);

	// binary operators

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator+(const Matrix<2, 2, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator+(T scalar, const Matrix<2, 2, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator+(const Matrix<2, 2, T>& m1, const Matrix<2, 2, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator-(const Matrix<2, 2, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator-(T scalar, const Matrix<2, 2, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator-(const Matrix<2, 2, T>& m1, const Matrix<2, 2, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator*(const Matrix<2, 2, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator*(T scalar, const Matrix<2, 2, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator*(const Matrix<2, 2, T>& m1, const Matrix<2, 2, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator/(const Matrix<2, 2, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator/(T scalar, const Matrix<2, 2, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<2, 2, T> operator/(const Matrix<2, 2, T>& m1, const Matrix<2, 2, T>& m2);

	// comparison operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator==(const Matrix<2, 2, T>& m1, const Matrix<2, 2, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator!=(const Matrix<2, 2, T>& m1, const Matrix<2, 2, T>& m2);
}

#include "Matrix2x2.inl"
