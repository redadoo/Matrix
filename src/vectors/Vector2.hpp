#pragma once

#include "../vectors/Vector.hpp"

namespace Maft
{
	template<typename T>
    struct Vector<2, T>
    {
        T x, y;

        // Constructors

		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector() = default;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T n);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T x, T y);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(const Vector<2, T>& other);

		// assignment operators (vector-vector)

		MAFT_CONSTEXPR Vector<2, T>& operator=(const Vector<2, T>& other);
		MAFT_CONSTEXPR Vector<2, T>& operator+=(const Vector<2, T>& other);
		MAFT_CONSTEXPR Vector<2, T>& operator-=(const Vector<2, T>& other);
		MAFT_CONSTEXPR Vector<2, T>& operator*=(const Vector<2, T>& other);
		MAFT_CONSTEXPR Vector<2, T>& operator/=(const Vector<2, T>& other);

		// assignment operators (vector-Scalar)

		template<typename U>
		MAFT_CONSTEXPR Vector<2, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Vector<2, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Vector<2, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Vector<2, T>& operator/=(U s);

		//  increment / decrement

		Vector<2, T> & operator++();
		Vector<2, T> & operator--();
		Vector<2, T> operator++(int);
		Vector<2, T> operator--(int);

		//  element access

		MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](int index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](int index) const;

		//  vector Operations

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR std::size_t length() { return 2; }

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Vector<2, T>& other);
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm_1() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm_inf() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Dot(const Vector<2, T>& other) const;


		// static utility functions

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static T magnitude(Vector<2, T> vector);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static T angle_cos(const Vector<2, T>& a, const Vector<2, T>& b);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> cross_product(const Vector<2, T>& a, const Vector<2, T>& b); 
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> Lerp(const Vector<2, T>& a, const Vector<2, T>& b, float t);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> LinearCombination(const std::vector< Vector<2, T> >& vectors, const std::vector<T>& scalars);

    };
	
    //  unary operators

	template<std::size_t R, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T> operator+(const Vector<2, T>& other);

	template<std::size_t R, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T> operator-(const Vector<2, T>& other);

	// binary operators

	template<std::size_t R, typename T>
	Vector<2, T> operator+(const Vector<2, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<2, T> operator+(T scalar, const Vector<2, T>& m);

	template<std::size_t R, typename T>
	Vector<2, T> operator+(const Vector<2, T>& m1, const Vector<2, T>& m2);

	template<std::size_t R, typename T>
	Vector<2, T> operator-(const Vector<2, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<2, T> operator-(T scalar, const Vector<2, T>& m);

	template<std::size_t R, typename T>
	Vector<2, T> operator-(const Vector<2, T>& m1, const Vector<2, T>& m2);

	template<std::size_t R, typename T>
	Vector<2, T> operator*(const Vector<2, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<2, T> operator*(T scalar, const Vector<2, T>& m);

	template<std::size_t R, typename T>
	Vector<2, T> operator*(const Vector<2, T>& m1, const Vector<2, T>& m2);

	template<std::size_t R, typename T>
	Vector<2, T> operator/(const Vector<2, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<2, T> operator/(T scalar, const Vector<2, T>& m);

	template<std::size_t R, typename T>
	Vector<2, T> operator/(const Vector<2, T>& m1, const Vector<2, T>& m2);

	// comparison operators

	template<std::size_t R, typename T>
	MAFT_CONSTEXPR bool operator==(const Vector<2, T>& m1, const Vector<2, T>& m2);

	template<std::size_t R, typename T>
	MAFT_CONSTEXPR bool operator!=(const Vector<2, T>& m1, const Vector<2, T>& m2);
}

#include "Vector2.inl"
