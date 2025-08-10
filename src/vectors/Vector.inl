#pragma once

#include "Vector.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

namespace Maft
{
	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Vector<C, T>::operator[](std::size_t i) 
	{
		assert(i < this->data.size());
		return data[i]; 
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Vector<C, T>::operator[](std::size_t i) const 
	{
		assert(i < this->data.size());
		return data[i]; 
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T>& Vector<C, T>::operator=(const Vector& other) 
	{
		if (this != &other)
			data = other.data;
		return *this;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Vector<C, T>::operator==(const Vector& other) const 
	{
		return data == other.data;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Add(const Vector& other) 
	{
		for (size_t i = 0; i < C; i++)
			data[i] += other.data[i];
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Subtract(const Vector& other) 
	{
		for (size_t i = 0; i < C; i++)
			data[i] -= other.data[i];
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Scale(const Vector& other) 
	{
		for (size_t i = 0; i < C; i++)
			data[i] *= other.data[i];
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Scale(const T& scalar) 
	{
		for (size_t i = 0; i < C; i++)
			data[i] *= scalar;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::Dot(const Vector& other) const 
	{
		float final_value = 0; 
		for (size_t i = 0; i < C; i++)
			final_value += data[i] * other.data[i];
		return final_value;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::norm() const 
	{
		float res = 0;
		for (size_t i = 0; i < C; i++)
			res += data[i] * data[i];
		return std::sqrt(res);
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::norm_1() const 
	{
		float res = 0;
		for (size_t i = 0; i < C; i++)
			res += std::abs(data[i]);
		return res;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::norm_inf() const 
	{
		float max_val = std::abs(data[0]);
		for (size_t i = 1; i < C; i++)
			max_val = std::max(max_val, std::abs(data[i]));
		return max_val;
	}

	template<std::size_t C, typename T>
	std::ostream& operator<<(std::ostream& os, const Vector<C, T>& v)
	{
		os << '{';
		for (std::size_t i = 0; i < C; ++i)
		{
			os << v.data[i];
			if (i + 1 < C) os << ", ";
		}
		os << '}';
		return os;
	}
}
