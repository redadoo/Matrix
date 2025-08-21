#pragma once

#include "../utils/utils.hpp"

#include <iostream>
#include <cassert>
#include "Vector2.hpp"
#include "Vector3.hpp"

namespace Maft
{
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T>::Vector(const Vector<3, T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T>::Vector(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T>::Vector(T n)
	{
		this->x = n;
		this->y = n;
		this->z = n;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T>& Vector<3, T>::operator=(const Vector<3, T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return *this;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Vector<3, T>::operator==(const Vector<3, T> &other) const
	{
		return  this->x == other.x && 
				this->y == other.y && 
				this->z == other.z;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Vector<3, T>::operator[](int index)
	{
		switch (index)
		{
			case 0: return this->x;
			case 1: return this->y;
			case 2: return this->z;
			default:
				throw std::out_of_range("Invalid Vector3 index");
		}
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Vector<3, T>::operator[](int index) const
	{
		switch (index)
		{
			case 0: return this->x;
			case 1: return this->y;
			case 2: return this->z;
			default:
				throw std::out_of_range("Invalid Vector3 index");
		}
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<3, T>::Add(const Vector<3, T> &other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<3, T>::Subtract(const Vector<3, T>& other) 
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<3, T>::Scale(const Vector<3, T>& other) 
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<3, T>::Scale(const T& scalar) 
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<3, T>::Dot(const Vector<3, T>& other) const 
	{
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<3, T>::norm() const 
	{
		return sqrt(x * x + y * y + z * z);
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<3, T>::norm_1() const 
	{
		return (std::abs(x) + std::abs(y) + std::abs(z));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<3, T>::norm_inf() const 
	{
		T ax = std::abs(x);
		T ay = std::abs(y);
		T az = std::abs(z);

		T maxVal = ax;
		if (ay > maxVal) maxVal = ay;
		if (az > maxVal) maxVal = az;

		return maxVal;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> Vector<3, T>::Lerp(const Vector<3, T>& a, const Vector<3, T>& b, float t)
	{
		t = clamp01(t);
		
		Vector<3, T> res;
		res.x = a.x + (b.x - a.x) * t;
		res.y = a.y + (b.y - a.y) * t;
		res.z = a.z + (b.z - a.z) * t;
		return res;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> Vector<3, T>::cross_product(const Vector<3, T>& a, const Vector<3, T>& b) 
	{
		Vector<3, T> result;
		result[0] = a[1] * b[2] - a[2] * b[1];
		result[1] = a[2] * b[0] - a[0] * b[2];
		result[2] = a[0] * b[1] - a[1] * b[0];
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> Vector<3, T>::LinearCombination(const std::vector< Vector<3, T> >& vectors, const Vector<3, T>& scalar)
	{
		Vector<3,T> result{};

		for (size_t i = 0; i < vectors.size(); i++)
		{
			Vector<3,T> tmp = vectors[i];
			tmp.Scale(scalar[i]);
			result.Add(tmp);
		}
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<3, T>::magnitude(const Vector<3, T>& vector) 
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y); 
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<3, T>::angle_cos(const Vector<3, T>& a, const Vector<3, T>& b) 
	{
		float dot = a.Dot(b);
		float mag1 = a.norm();
		float mag2 = b.norm();

		if (mag1 == 0.0f || mag2 == 0.0f)
			return 0.0f;

		return dot / (mag1 * mag2);
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<3, T>& v)
	{
		os << '{';
		os << v.x;
		os << ", ";
		os << v.y;
		os << ", ";
		os << v.z;
		os << '}';
		return os;
	}
}
