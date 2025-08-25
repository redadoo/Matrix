#pragma once

#include "../utils/utils.hpp"

#include <iostream>
#include <cassert>
#include "Vector2.hpp"
#include "Vector3.hpp"

namespace Maft
{
	// constructors

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

	// assignment operators (vector vector)

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator=(const Vector<4, T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		this->w = other.w;
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator+=(const Vector<4, T>&other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		this->w += other.w;
		return *this;
	}

    template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator-=(const Vector<4, T>&other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		this->w -= other.w;
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator*=(const Vector<4, T>&other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		this->w *= other.w;
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator/=(const Vector<4, T>&other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		this->w /= other.w;
		return *this;
	}

	// assignment operators (vector scalar)

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator+=(U s)
    {
		this->x += s;
		this->y += s;
		this->z += s;
		this->w += s;
		return *this;
	}

    template <typename T>
    template <typename U>
    MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator-=(U s)
    {
		this->x -= s;
		this->y -= s;
		this->z -= s;
		this->w -= s;
		return *this;
	}

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> &Vector<4, T>::operator*=(U s)
    {
		this->x *= s;
		this->y *= s;
		this->z *= s;
		this->W *= s;
		return *this;
	}

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T>& Vector<4, T>::operator/=(U s)
    {
		this->x /= s;
		this->y /= s;
		this->z /= s;
		this->W /= s;
		return *this;
	}

	// increment / decrement

	template <typename T>
	Vector<4, T>& Vector<4, T>::operator++()
	{
		this->x++;
		this->y++;
		this->z++;
		this->W++;
		return *this;
	}

	template <typename T>
	Vector<4, T>& Vector<4, T>::operator--()
	{
		this->x--;
		this->y--;
		this->z--;
		this->W++;
		return *this;
	}
	
	template <typename T>
	Vector<4, T> Vector<4, T>::operator++(int)
	{
		Vector<4, T> res(*this);
		++*this;
		return res;
	}

	template <typename T>
	Vector<4, T> Vector<4, T>::operator--(int)
	{
		Vector<4, T> res(*this);
		--*this;
		return res;
	}

	// element access

	template <typename T>
	MAFT_FORCE_INLINE T& Vector<4, T>::operator[](int index)
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

	// vector Operations

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Add(const Vector<4, T>& other) 
	{
		(*this) += other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Scale(const Vector<4, T>& other) 
	{
		(*this) *= other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Scale(const T& scalar) 
	{
		(*this) *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<4, T>::Subtract(const Vector<4, T>& other) 
	{
		(*this) -= other;
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
		return (abs(x) + abs(y) + abs(z) + abs(w));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::norm_inf() const 
	{
		T ax = abs(x);
		T ay = abs(y);
		T az = abs(z);
		T aw = abs(w);

		T maxVal = ax;
		if (ay > maxVal) maxVal = ay;
		if (az > maxVal) maxVal = az;
		if (aw > maxVal) maxVal = aw;

		return maxVal;
	}

	// static utility functions

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
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> Vector<4, T>::LinearCombination(const std::vector< Vector<4, T> >& vectors, const Vector<4, T>& scalar)
	{
		Vector<4, T> result{};

		for (size_t i = 0; i < vectors.size(); i++)
		{
			Vector<4, T> tmp = vectors[i];
			tmp.Scale(scalar[i]);
			result.Add(tmp);
		}
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::magnitude(const Vector<4, T>& vector) 
	{
		return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T Vector<4, T>::angle_cos(const Vector<4, T>& a, const Vector<4, T>& b) 
	{
		float dot = a.Dot(b);
		float mag1 = a.norm();
		float mag2 = b.norm();

		if (mag1 == 0.0f || mag2 == 0.0f)
			return 0.0f;

		return dot / (mag1 * mag2);
	}
	
	// unary operators

	template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> operator+(const Vector<4, T> &m)
    {
		return m;
	}

    template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> operator-(const Vector<4, T> &m)
    {
		m.x = -m.x;
		m.y = -m.y;
		m.z = -m.z;
		m.w = -m.w;
		return m;
	}

	// binary operators

	template<typename T>
	Vector<4, T> operator+(const Vector<4, T> &m, T scalar)
	{
		Vector<4, T> res;
		res.x = m.x + scalar;
		res.y = m.y + scalar;
		res.z = m.z + scalar;
		res.w = m.w + scalar;
		return res;
	}

	template<typename T>
	Vector<4, T> operator+(T scalar, const Vector<4, T> &m)
	{
		Vector<4, T> res;
		res.x = m.x + scalar;
		res.y = m.y + scalar;
		res.z = m.z + scalar;
		res.w = m.w + scalar;
		return res;
	}

	template<typename T>
	Vector<4, T> operator+(const Vector<4, T> &m1, const Vector<4, T> &m2)
	{
		Vector<4, T> res;
		res.x = m1.x + m2.x;
		res.y = m1.y + m2.y;
		res.z = m1.z + m2.z;
		res.w = m1.w + m2.w;
		return res;
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T> &m, T scalar)
	{
		Vector<4, T> res;
		res.x = m.x - scalar;
		res.y = m.y - scalar;
		res.z = m.z - scalar;
		res.w = m.w - scalar;
		return res;
	}

	template<typename T>
	Vector<4, T> operator-(T scalar, const Vector<4, T> &m)
	{
		Vector<4, T> res;
		res.x = scalar - m.x;
		res.y = scalar - m.y;
		res.z = scalar - m.z;
		res.w = scalar - m.w;
		return res;
	}

	template<typename T>
	Vector<4, T> operator-(const Vector<4, T> &m1, const Vector<4, T> &m2)
	{
		Vector<4, T> res;
		res.x = m1.x - m2.x;
		res.y = m1.y - m2.y;
		res.z = m1.z - m2.z;
		res.w = m1.w - m2.w;
		return res;
	}

	template<typename T>
	Vector<4, T> operator*(const Vector<4, T> &m, T scalar)
	{
		Vector<4, T> res;
		res.x = m.x * scalar;
		res.y = m.y * scalar;
		res.z = m.z * scalar;
		res.w = m.w * scalar;
		return res;
	}

	template<typename T>
	Vector<4, T> operator*(T scalar, const Vector<4, T> &m)
	{
		Vector<4, T> res;
		res.x = m.x * scalar;
		res.y = m.y * scalar;
		res.z = m.z * scalar;
		res.w = m.w * scalar;
		return res;
	}

	template<typename T>
	Vector<4, T> operator*(const Vector<4, T> &m1, const Vector<4, T> &m2)
	{
		Vector<4, T> res;
		res.x = m1.x * m2.x;
		res.y = m1.y * m2.y;
		res.z = m1.z * m2.z;
		res.w = m1.w * m2.w;
		return res;
	}

	template<typename T>
	Vector<4, T> operator/(const Vector<4, T> &m, T scalar)
	{
		Vector<4, T> res;
		res.x = m.x / scalar;
		res.y = m.y / scalar;
		res.z = m.z / scalar;
		res.w = m.w / scalar;
		return res;
	}

	template<typename T>
	Vector<4, T> operator/(T scalar, const Vector<4, T> &m)
	{
		Vector<4, T> res;
		res.x = scalar / m.x;
		res.y = scalar / m.y;
		res.z = scalar / m.z;
		res.w = scalar / m.w;
		return res;
	}

	template<typename T>
	Vector<4, T> operator/(const Vector<4, T> &m1, const Vector<4, T> &m2)
	{
		Vector<4, T> res;
		res.x = m1.x / m2.x;
		res.y = m1.y / m2.y;
		res.z = m1.z / m2.z;
		res.w = m1.w / m2.w;
		return res;
	}

	// comparison operators

	template<typename T>
    MAFT_CONSTEXPR bool Maft::operator==(const Vector<4, T>& m1, const Vector<4, T>& m2)
	{
		return m1.x == m2.x && m1.y == m2.y && m1.z == m2.z && m1.w == m2.w;
	}

	template<typename T>
	MAFT_CONSTEXPR bool Maft::operator!=(const Vector<4, T> &m1, const Vector<4, T> &m2)
	{
		return m1.x != m2.x && m1.y != m2.y && m1.z != m2.z && m1.w != m2.w;
	}

	//print

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<4, T>& v)
	{
		auto fmt = [](T x) { return (abs(x) < 1e-6f) ? T(0) : x; };

		os << '{'
		<< fmt(v.x) << ", "
		<< fmt(v.y) << ", "
		<< fmt(v.z) << ", "
		<< fmt(v.w)
		<< '}';
		return os;
	}
}
