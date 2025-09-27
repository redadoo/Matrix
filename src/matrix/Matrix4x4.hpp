#pragma once

#include "Matrix.hpp"
#include <immintrin.h>

namespace Maft
{
	template<typename T>
    struct Matrix<4, 4, T>
    {
        std::array<T, 16> data;

		// Constructors
		
		Matrix() : data{} {}
		MAFT_CONSTEXPR Matrix(const T& x);
		MAFT_CONSTEXPR Matrix(const Matrix& other);
		MAFT_CONSTEXPR Matrix(
			T m00, T m10, T m20, T m30,
			T m01, T m11, T m21, T m31,
			T m02, T m12, T m22, T m32,
			T m03, T m13, T m23, T m33);
		
		// assignment operators (Matrix-Matrix)

		MAFT_CONSTEXPR Matrix<4, 4, T>& operator=(const Matrix<4, 4, T>& other);
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator+=(const Matrix<4, 4, T>& other);
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator-=(const Matrix<4, 4, T>& other);
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator*=(const Matrix<4, 4, T>& other);
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator/=(const Matrix<4, 4, T>& other);

		// assignment operators (Matrix-Scalar)

		template<typename U>
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<4, 4, T>& operator/=(U s);
		
		//  increment / decrement

		Matrix<4, 4, T>& operator++();
		Matrix<4, 4, T>& operator--();
		Matrix<4, 4, T> operator++(int);
		Matrix<4, 4, T> operator--(int);

		//  element access

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator()(std::size_t col, std::size_t row);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t col, std::size_t row) const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](std::size_t index);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](std::size_t index) const;

		//  matrix Operations
		MAFT_FORCE_INLINE MAFT_CONSTEXPR int rank() const;

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void inverse();

		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> get_column(std::size_t index) const;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> get_row(std::size_t index) const;

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void set_column(std::size_t index, Vector<4, T> v);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void set_row(std::size_t index, Vector<4, T> v);

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_row(int first_row_index, int second_row_index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_column(int first_column_index, int second_column_index);

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix<4, 4, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix<4, 4, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix<4, 4, T>& other);
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> multiply_vector(const Vector<4, T>& v);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> multiply_matrix(const Matrix<4, 4, T>& other) const;
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T trace() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T determinant() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> row_echelon() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> transpose() const;

		// static utility functions

		MAFT_CONSTEXPR static Matrix<4,4,T> Identity();
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<4, 4, T> Lerp(const Matrix& a, const Matrix& b, float t);

		// // friend
		friend std::ostream& operator<< <>(std::ostream& os, const Matrix& m);
	};

	//  unary operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& other);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& other);

	// binary operators

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator+(T scalar, const Matrix<4, 4, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator+(const Matrix<4, 4, T>& m1, const Matrix<4, 4, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator-(T scalar, const Matrix<4, 4, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator-(const Matrix<4, 4, T>& m1, const Matrix<4, 4, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator*(const Matrix<4, 4, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator*(T scalar, const Matrix<4, 4, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator*(const Matrix<4, 4, T>& m1, const Matrix<4, 4, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator/(const Matrix<4, 4, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator/(T scalar, const Matrix<4, 4, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<4, 4, T> operator/(const Matrix<4, 4, T>& m1, const Matrix<4, 4, T>& m2);

	// comparison operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator==(const Matrix<4, 4, T>& m1, const Matrix<4, 4, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator!=(const Matrix<4, 4, T>& m1, const Matrix<4, 4, T>& m2);
}

#include "Matrix4x4.inl"
