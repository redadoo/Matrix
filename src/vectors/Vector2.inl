#pragma once

#include "utils.hpp"

#include <iostream>
#include <cassert>
#include "Vector2.hpp"

namespace Maft
{
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T>::Vector(const Vector<2, T>& other)
    {
		this->x = other.x;
		this->y = other.y;
    }

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T>::Vector(T x, T y)
    {
		this->x = x;
		this->y = y;
    }

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T>::Vector(T n)
    {
		this->x = n;
		this->y = n;
    }

		template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Vector<2, T>::operator[](int index)
	{
		switch (index)
		{
			case 0: return this->x;
			case 1: return this->y;
			default:
				throw std::out_of_range("Invalid Vector2 index");
		}
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Vector<2, T>::operator[](int index) const
	{
		switch (index)
		{
			case 0: return this->x;
			case 1: return this->y;
			default:
				throw std::out_of_range("Invalid Vector2 index");
		}
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T>& Vector<2, T>::operator=(const Vector<2, T>& other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Vector<2, T>::operator==(const Vector<2, T> &other) const
	{
		return x == other.x && y == other.y;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<2, T>::Add(const Vector<2, T>& other) 
	{
		x += other.x;
		y += other.y;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<2, T>::Subtract(const Vector<2, T>& other) 
	{
		x -= other.x;
		y -= other.y;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<2, T>::Scale(const Vector<2, T>& other) 
	{
		x *= other.x;
		y *= other.y;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<2, T>::Scale(const T& scalar) 
	{
		x *= scalar;
		y *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<2, T>::Dot(const Vector<2, T>& other) const 
	{
		return x * other.x + y * other.y;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<2, T>::norm() const 
	{
		return sqrt(x * x + y * y);
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<2, T>::norm_1() const 
	{
		return (std::abs(x) + std::abs(y));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<2, T>::norm_inf() const 
	{
		return std::max(std::abs(x), std::abs(y));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T> Vector<2, T>::Lerp(const Vector<2, T>& a, const Vector<2, T>& b, float t)
	{
		t = clamp01(t);
		
		Vector<2, T> res;
		res.x = a.x + (b.x - a.x) * t;
		res.y = a.y + (b.y - a.y) * t;

		return res;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T> Vector<2, T>::LinearCombination(const std::vector< Vector<2, T> >& vectors, const Vector<2, T>& scalar)
	{
		Vector<2, T> result{};

		for (size_t i = 0; i < vectors.size(); i++)
		{
			Vector<2, T> tmp = vectors[i];
			tmp.Scale(scalar[i]);
			result.Add(tmp);
		}

		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<2, T>::magnitude(Vector<2, T> vector) 
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y); 
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<2, T>::angle_cos(const Vector<2, T>& a, const Vector<2, T>& b) 
	{
		float dot = a.Dot(b);
		float mag1 = a.norm();
		float mag2 = b.norm();

		if (mag1 == 0.0f || mag2 == 0.0f)
			return 0.0f;

		return dot / (mag1 * mag2);
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<2, T>& v)
	{
		os << '{';
		os << v.x;
		os << ", ";
		os << v.y;
		os << '}';
		return os;
	}
}
