#pragma once

#include "Vector.hpp"

namespace Maft
{
	template<typename T>
    struct Vector<2, T>
    {
        T x, y;

		Vector() = default;
		Vector(const Vector& other) = default;

		//overload
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector& operator=(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Vector<2, T>& other) const;

		//operation
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Vector<2, T>& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float Dot(const Vector<2, T>& other) const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm_1() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm_inf() const;

		// static functions
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> Lerp(const Vector<2, T>& a, const Vector<2, T>& b, float t);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> LinearCombination(const std::vector< Vector<2, T> >& vectors, const Vector<2, T>& scalar);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<2, T> cross_product(const Vector<2, T>& a, const Vector<2, T>& b); 
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float magnitude(Vector<2, float> vector);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float angle_cos(const Vector<2, T>& a, const Vector<2, T>& b);
    };

    template<typename T>
    using Vector2 = Vector<2, T>;
}

#include "Vector2.inl"
