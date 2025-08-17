#pragma once

#include "Vector.hpp"

namespace Maft
{
	template<typename T>
    struct Vector<2, T>
    {
        T x, y;

		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector() = default;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T n);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T x, T y);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(const Vector<2, T>& other);

		//overload
		MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](int index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](int index) const;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector& operator=(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Vector<2, T>& other) const;

		//operation
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Vector<2, T>& other);

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm_1() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm_inf() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float Dot(const Vector<2, T>& other) const;

		// static functions
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static int length() { return 2; }
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float magnitude(Vector<2, T> vector);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float angle_cos(const Vector<2, T>& a, const Vector<2, T>& b);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> cross_product(const Vector<2, T>& a, const Vector<2, T>& b); 
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> Lerp(const Vector<2, T>& a, const Vector<2, T>& b, float t);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> LinearCombination(const std::vector< Vector<2, T> >& vectors, const Vector<2, T>& scalar);
    };
}

#include "Vector2.inl"
