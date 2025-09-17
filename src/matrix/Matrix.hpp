#pragma once

#include "../vectors/Vector.hpp"

namespace Maft
{
	template<std::size_t C, std::size_t R, typename T>
	struct Matrix;

	template<std::size_t C, std::size_t R, typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<C, R, T>& m);

	template<std::size_t C, std::size_t R, typename T>
	struct Matrix
	{
		std::array<T, C * R> data{};

		//  constructors

		Matrix() = default;
	 	MAFT_CONSTEXPR Matrix(const T& x);
	 	MAFT_CONSTEXPR Matrix(std::initializer_list<T> values);
		MAFT_CONSTEXPR Matrix(const Matrix<C, R, T>& other);

		// assignment operators (matrix matrix)

		MAFT_CONSTEXPR Matrix<C, R, T>& operator=(const Matrix<C, R, T>& other);
		MAFT_CONSTEXPR Matrix<C, R, T>& operator+=(const Matrix<C, R, T>& other);
		MAFT_CONSTEXPR Matrix<C, R, T>& operator-=(const Matrix<C, R, T>& other);
		MAFT_CONSTEXPR Matrix<C, R, T>& operator*=(const Matrix<C, R, T>& other);
		MAFT_CONSTEXPR Matrix<C, R, T>& operator/=(const Matrix<C, R, T>& other);

		// assignment operators (matrix scalar)

		template<typename U>
		MAFT_CONSTEXPR Matrix<C, R, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Matrix<C, R, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<C, R, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Matrix<C, R, T>& operator/=(U s);
		
		//  increment / decrement

		Matrix<C, R, T>& operator++();
		Matrix<C, R, T>& operator--();
		Matrix<C, R, T> operator++(int);
		Matrix<C, R, T> operator--(int);

		//  element access

		MAFT_NODISCARD MAFT_FORCE_INLINE T& operator()(std::size_t col, std::size_t row);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator()(std::size_t col, std::size_t row) const;
		
		// matrix Operations

		MAFT_FORCE_INLINE MAFT_CONSTEXPR int rank() const;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix inverse() const;


		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Matrix& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Matrix& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Matrix& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_row(std::size_t r1, std::size_t r2);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void swap_column(std::size_t c1, std::size_t c2);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T> multiply_vector(const Vector<C, T>& v);
		
		template <std::size_t P>
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, P, T> multiply_matrix(const Matrix<C, P, T>& other) const;
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T trace() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool is_square () const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T determinant() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> transpose() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> row_echelon() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> row_echelon_no_div() const;

		// static utility functions

		MAFT_CONSTEXPR static Matrix<C,R,T> Identity();
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Matrix<C, R, T> Lerp(const Matrix& a, const Matrix& b, float t);

		// // friend
		friend std::ostream& operator<< <>(std::ostream& os, const Matrix& m);
	};

	//  unary operators

	template<std::size_t C, std::size_t R, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> operator+(const Matrix<C, R, T>& other);

	template<std::size_t C, std::size_t R, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> operator-(const Matrix<C, R, T>& other);

	// binary operators

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator+(const Matrix<C, R, T>& m, T scalar);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator+(T scalar, const Matrix<C, R, T>& m);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator+(const Matrix<C, R, T>& m1, const Matrix<C, R, T>& m2);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator-(const Matrix<C, R, T>& m, T scalar);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator-(T scalar, const Matrix<C, R, T>& m);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator-(const Matrix<C, R, T>& m1, const Matrix<C, R, T>& m2);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator*(const Matrix<C, R, T>& m, T scalar);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator*(T scalar, const Matrix<C, R, T>& m);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator*(const Matrix<C, R, T>& m1, const Matrix<C, R, T>& m2);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator/(const Matrix<C, R, T>& m, T scalar);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator/(T scalar, const Matrix<C, R, T>& m);

	template<std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> operator/(const Matrix<C, R, T>& m1, const Matrix<C, R, T>& m2);

	// comparison operators

	template<std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR bool operator==(const Matrix<C, R, T>& m1, const Matrix<C, R, T>& m2);

	template<std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR bool operator!=(const Matrix<C, R, T>& m1, const Matrix<C, R, T>& m2);
}

#include "Matrix.inl"
