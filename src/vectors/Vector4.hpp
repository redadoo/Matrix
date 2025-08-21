#pragma once

#include "../vectors/Vector.hpp"

namespace Maft
{
	template<typename T>
    struct Vector<4, T>
    {
        T x, y, z, w;

		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector() = default;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T n);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(T x, T y, T z, T w);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector(const Vector<4, T>& other);

		//overload
		MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](int index);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](int index) const;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector& operator=(const Vector<4, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Vector<4, T>& other) const;

		//operation
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Vector<4, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Vector<4, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Vector<4, T>& other);

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm_1() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T norm_inf() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Dot(const Vector<4, T>& other) const;

		// static functions
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static std::size_t length() { return 4; }
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float magnitude(const Vector<4, T>& vector);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float angle_cos(const Vector<4, T>& a, const Vector<4, T>& b);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<4, T> Lerp(const Vector<4, T>& a, const Vector<4, T>& b, float t);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<4, T> cross_product(const Vector<4, T>& a, const Vector<4, T>& b); 
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<4, T> LinearCombination(const std::vector< Vector<4, T> >& vectors, const std::vector<T>& scalars);
    };
}

#include "Vector4.inl"
