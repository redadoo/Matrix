#pragma once

#include "setup.hpp"
#include <cstddef>
#include <array>
#include <iostream>
#include <vector>

namespace Maft
{
	template<std::size_t C, typename T>
	struct Vector;

	template<std::size_t C, typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<C, T>& v);

	template<std::size_t C, typename T>
	struct Vector
	{
		std::array<T, C> data{};
		
		Vector() = default;
		Vector(const Vector& other) = default;

		//overload
		MAFT_FORCE_INLINE MAFT_CONSTEXPR T& operator[](std::size_t i);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& operator[](std::size_t i) const;
		MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector& operator=(const Vector& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR bool operator==(const Vector& other) const;

		//operation
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Add(const Vector& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Subtract(const Vector& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const Vector& other);
		MAFT_FORCE_INLINE MAFT_CONSTEXPR void Scale(const T& scalar);

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float Dot(const Vector& other) const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm_1() const;
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float norm_inf() const;

		// static functions

		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<C, T> Lerp(const Vector<C, T>& a, const Vector<C, T>& b, float t);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<C, T> LinearCombination(const std::vector< Vector<C,T> >& vectors, const Vector<C,T>& scalar);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static Vector<C, T> cross_product(const Vector<C, T>& a, const Vector<C, T>& b); 
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float magnitude(Vector<C, float> vector);
		MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR static float angle_cos(const Vector<C, T>& a, const Vector<C, T>& b);

		friend std::ostream& operator<< <>(std::ostream& os, const Vector<C, T>& v);
	};
}

#include "Vector.inl"
