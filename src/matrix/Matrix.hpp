#pragma once

#include "../vectors/Vector.hpp"

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

		//  constructors

		Matrix() = default;
	 	MAFT_CONSTEXPR Matrix(const T& x);
		MAFT_CONSTEXPR Matrix(const Matrix<R, C, T>& other);

		// assignment operators (matrix matrix)

		MAFT_CONSTEXPR Matrix<R, C, T>& operator=(const Matrix<R, C, T>& other);
		MAFT_CONSTEXPR Matrix<R, C, T>& operator+=(const Matrix<R, C, T>& other);
		MAFT_CONSTEXPR Matrix<R, C, T>& operator-=(const Matrix<R, C, T>& other);
		MAFT_CONSTEXPR Matrix<R, C, T>& operator*=(const Matrix<R, C, T>& other);
		MAFT_CONSTEXPR Matrix<R, C, T>& operator/=(const Matrix<R, C, T>& other);

		// assignment operators (matrix scalar)

		template<typename U>
		MAFT_CONSTEXPR Matrix<R, C, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Matrix<R, C, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<R, C, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<R, C, T>& operator/=(U s);
		
		//  increment / decrement

		Matrix<R, C, T>& operator++();
		Matrix<R, C, T>& operator--();
		Matrix<R, C, T> operator++(int);
		Matrix<R, C, T> operator--(int);

		//  element access

		MAFT_NODISCARD MAFT_FORCE_INLINE T& operator()(std::size_t row, std::size_t col);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t row, std::size_t col) const;
		
		// matrix Operations

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_row(int first_row_index, int second_row_index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_column(int first_column_index, int second_column_index);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T> multiply_vector(const Vector<C, T>& v);
		
		template <std::size_t P>
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, P, T> multiply_matrix(const Matrix<C, P, T>& other) const;
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T trace() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool is_square () const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T determinant() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> transpose() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> row_echelon() const;

		// static utility functions

		MAFT_CONSTEXPR static Matrix<R,C,T> Identity();
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<R, C, T> Lerp(const Matrix& a, const Matrix& b, float t);

		// // friend
		friend std::ostream& operator<< <>(std::ostream& os, const Matrix& m);
	};

	//  unary operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> operator+(const Matrix<R, C, T>& other);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> operator-(const Matrix<R, C, T>& other);

	// binary operators

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator+(const Matrix<R, C, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator+(T scalar, const Matrix<R, C, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator+(const Matrix<R, C, T>& m1, const Matrix<R, C, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator-(const Matrix<R, C, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator-(T scalar, const Matrix<R, C, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator-(const Matrix<R, C, T>& m1, const Matrix<R, C, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator*(const Matrix<R, C, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator*(T scalar, const Matrix<R, C, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator*(const Matrix<R, C, T>& m1, const Matrix<R, C, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator/(const Matrix<R, C, T>& m, T scalar);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator/(T scalar, const Matrix<R, C, T>& m);

	template<std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> operator/(const Matrix<R, C, T>& m1, const Matrix<R, C, T>& m2);

	// comparison operators

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator==(const Matrix<R, C, T>& m1, const Matrix<R, C, T>& m2);

	template<std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool operator!=(const Matrix<R, C, T>& m1, const Matrix<R, C, T>& m2);
}

#include "Matrix.inl"
