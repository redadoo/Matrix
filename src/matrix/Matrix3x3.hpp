#pragma once

#include "Matrix.hpp"
#include <array>
#include <cstddef>

namespace Maft
{
	template<typename T>
	struct Matrix<3, 3, T>
	{
		std::array<T, 9> data;
		
		// Constructors
		
		Matrix() = default;
		MAFT_CONSTEXPR Matrix(const T& x);
		MAFT_CONSTEXPR Matrix(const Matrix& other);
		MAFT_CONSTEXPR Matrix(T m00, T m10, T m20, T m01, T m11, T m21, T m02, T m12, T m22);
		
		// assignment operators (Matrix-Matrix)

		MAFT_CONSTEXPR Matrix<3, 3, T>& operator=(const Matrix<3, 3, T>& other);
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator+=(const Matrix<3, 3, T>& other);
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator-=(const Matrix<3, 3, T>& other);
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator*=(const Matrix<3, 3, T>& other);
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator/=(const Matrix<3, 3, T>& other);

		// assignment operators (Matrix-Scalar)

		template<typename U>
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<3, 3, T>& operator/=(U s);
		
		//  increment / decrement

		Matrix<3, 3, T>& operator++();
		Matrix<3, 3, T>& operator--();
		Matrix<3, 3, T> operator++(int);
		Matrix<3, 3, T> operator--(int);

		//  element access

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator()(std::size_t col, std::size_t row);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t col, std::size_t row) const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](std::size_t index);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](std::size_t index) const;

		//  matrix Operations
		MAFT_FORCE_INLINE MAFT_CONSTEXPR int rank() const;

		MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> inverse() const;

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_row(int first_row_index, int second_row_index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_column(int first_column_index, int second_column_index);

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix<3, 3, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix<3, 3, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix<3, 3, T>& other);
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> multiply_vector(const Vector<3, T>& v);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> multiply_matrix(const Matrix<3, 3, T>& other) const;
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T determinant() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T trace() const;

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> row_echelon_no_div() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> row_echelon() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> transpose() const;

		// static utility functions

		MAFT_CONSTEXPR static Matrix<3,3,T> Identity();
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<3, 3, T> Lerp(const Matrix& a, const Matrix& b, float t);

		// // friend
		friend std::ostream& operator<< <>(std::ostream& os, const Matrix& m);
	};

	//  unary operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& other);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& other);

	// binary operators

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator+(T scalar, const Matrix<3, 3, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator+(const Matrix<3, 3, T>& m1, const Matrix<3, 3, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator-(T scalar, const Matrix<3, 3, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator-(const Matrix<3, 3, T>& m1, const Matrix<3, 3, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator*(const Matrix<3, 3, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator*(T scalar, const Matrix<3, 3, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator*(const Matrix<3, 3, T>& m1, const Matrix<3, 3, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator/(const Matrix<3, 3, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator/(T scalar, const Matrix<3, 3, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<3, 3, T> operator/(const Matrix<3, 3, T>& m1, const Matrix<3, 3, T>& m2);

	// comparison operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator==(const Matrix<3, 3, T>& m1, const Matrix<3, 3, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator!=(const Matrix<3, 3, T>& m1, const Matrix<3, 3, T>& m2);
}

#include "Matrix3x3.inl"
