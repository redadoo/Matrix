#pragma once

#include "../vectors/Vector.hpp"

namespace Maft
{
	template<typename T>
    struct Vector<3, T>
    {
        T x, y, z;

		// Constructors

		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector() = default;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T n);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T x, T y, T z);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(const Vector<3, T>& other);

		// assignment operators (vector-vector)

		MAFT_CONSTEXPR Vector<3, T>& operator=(const Vector<3, T>& other);
		MAFT_CONSTEXPR Vector<3, T>& operator+=(const Vector<3, T>& other);
		MAFT_CONSTEXPR Vector<3, T>& operator-=(const Vector<3, T>& other);
		MAFT_CONSTEXPR Vector<3, T>& operator*=(const Vector<3, T>& other);
		MAFT_CONSTEXPR Vector<3, T>& operator/=(const Vector<3, T>& other);

		// assignment operators (vector-Scalar)

		template<typename U>
		MAFT_CONSTEXPR Vector<3, T>& operator+=(U s);
		
		template<typename U>
		MAFT_CONSTEXPR Vector<3, T>& operator-=(U s);

		template<typename U>
		MAFT_CONSTEXPR Vector<3, T>& operator*=(U s);

		template<typename U>
		MAFT_CONSTEXPR Vector<3, T>& operator/=(U s);

		//  increment / decrement

		Vector<3, T> & operator++();
		Vector<3, T> & operator--();
		Vector<3, T> operator++(int);
		Vector<3, T> operator--(int);

		//  element access

		MAFT_FORCE_INLINE T& operator[](int index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](int index) const;

		//  vector Operations

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR std::size_t length() { return 3; }

		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Vector<3, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Vector<3, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Vector<3, T>& other);
		
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm_1() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm_inf() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Dot(const Vector<3, T>& other) const;


		// static utility functions

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static T magnitude(const Vector<3, T>& vector);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static T angle_cos(const Vector<3, T>& a, const Vector<3, T>& b);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<3, T> cross_product(const Vector<3, T>& a, const Vector<3, T>& b); 
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<3, T> Lerp(const Vector<3, T>& a, const Vector<3, T>& b, float t);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<3, T> LinearCombination(const std::vector< Vector<3, T> >& vectors, const std::vector<T>& scalars);
    };

		
    //  unary operators

	template<std::size_t R, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> operator+(const Vector<3, T>& other);

	template<std::size_t R, typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> operator-(const Vector<3, T>& other);

	// binary operators

	template<std::size_t R, typename T>
	Vector<3, T> operator+(const Vector<3, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<3, T> operator+(T scalar, const Vector<3, T>& m);

	template<std::size_t R, typename T>
	Vector<3, T> operator+(const Vector<3, T>& m1, const Vector<3, T>& m2);

	template<std::size_t R, typename T>
	Vector<3, T> operator-(const Vector<3, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<3, T> operator-(T scalar, const Vector<3, T>& m);

	template<std::size_t R, typename T>
	Vector<3, T> operator-(const Vector<3, T>& m1, const Vector<3, T>& m2);

	template<std::size_t R, typename T>
	Vector<3, T> operator*(const Vector<3, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<3, T> operator*(T scalar, const Vector<3, T>& m);

	template<std::size_t R, typename T>
	Vector<3, T> operator*(const Vector<3, T>& m1, const Vector<3, T>& m2);

	template<std::size_t R, typename T>
	Vector<3, T> operator/(const Vector<3, T>& m, T scalar);

	template<std::size_t R, typename T>
	Vector<3, T> operator/(T scalar, const Vector<3, T>& m);

	template<std::size_t R, typename T>
	Vector<3, T> operator/(const Vector<3, T>& m1, const Vector<3, T>& m2);

	// comparison operators

	template<std::size_t R, typename T>
	MAFT_CONSTEXPR bool operator==(const Vector<3, T>& m1, const Vector<3, T>& m2);

	template<std::size_t R, typename T>
	MAFT_CONSTEXPR bool operator!=(const Vector<3, T>& m1, const Vector<3, T>& m2);
}

#include "Vector3.inl"
