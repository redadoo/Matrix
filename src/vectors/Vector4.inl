#pragma once

#include "utils.hpp"

#include <iostream>
#include <cassert>
#include "Vector2.hpp"
#include "Vector3.hpp"

namespace Maft
{
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>::Vector(const Vector<4, T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->w = other.w;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>::Vector(T x, T y, T z, T w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>::Vector(T n)
	{
		this->x = n;
		this->y = n;
		this->z = n;
		this->w = n;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator=(const Vector<4, T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->w = other.w;
		return *this;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Vector<4, T>::operator==(const Vector<4, T> &other) const
	{
		return  this->x == other.x && 
				this->y == other.y && 
				this->z == other.z && 
				this->w == other.w;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Vector<4, T>::operator[](int index)
	{
		switch (index)
		{
			case 0: return this->x;
			case 1: return this->y;
			case 2: return this->z;
			case 3: return this->w;
			default:
				throw std::out_of_range("Invalid Vector4 index");

		}
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Vector<4, T>::operator[](int index) const
	{
		switch (index)
		{
			case 0: return this->x;
			case 1: return this->y;
			case 2: return this->z;
			case 3: return this->w;
			default:
				throw std::out_of_range("Invalid Vector4 index");
		}
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Add(const Vector<4, T> &other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Subtract(const Vector<4, T>& other) 
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Scale(const Vector<4, T>& other) 
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Scale(const T& scalar) 
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::Dot(const Vector<4, T>& other) const 
	{
		return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::norm() const 
	{
		return sqrt(x * x + y * y + z * z + w * w);
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::norm_1() const 
	{
		return (std::abs(x) + std::abs(y) + std::abs(z) + std::abs(w));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::norm_inf() const 
	{
		T ax = std::abs(x);
		T ay = std::abs(y);
		T az = std::abs(z);
		T aw = std::abs(w);

		T maxVal = ax;
		if (ay > maxVal) maxVal = ay;
		if (az > maxVal) maxVal = az;
		if (aw > maxVal) maxVal = aw;

		return maxVal;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> Vector<4, T>::Lerp(const Vector<4, T>& a, const Vector<4, T>& b, float t)
	{
		t = clamp01(t);
		
		Vector<4, T> res;
		res.x = a.x + (b.x - a.x) * t;
		res.y = a.y + (b.y - a.y) * t;
		res.z = a.z + (b.z - a.z) * t;
		res.w = a.w + (b.w - a.w) * t;
		return res;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> Vector<4, T>::LinearCombination(const std::vector< Vector<4, T> >& vectors, const std::vector<T>& scalars)
	{
		Vector<4, T> result{};

		for (size_t i = 0; i < vectors.size(); i++)
		{
			Vector<4, T> tmp = vectors[i];
			tmp.Scale(scalars[i]);
			result.Add(tmp);
		}
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<4, T>::magnitude(const Vector<4, T>& vector) 
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<4, T>::angle_cos(const Vector<4, T>& a, const Vector<4, T>& b) 
	{
		float dot = a.Dot(b);
		float mag1 = a.norm();
		float mag2 = b.norm();

		if (mag1 == 0.0f || mag2 == 0.0f)
			return 0.0f;

		return dot / (mag1 * mag2);
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<4, T>& v)
	{
		os << '{'
		<< v.x 
		<< ", " 
		<< v.y 
		<< ", " 
		<< v.z 
		<< ", " 
		<< v.w 
		<< '}';
		return os;
	}
}
