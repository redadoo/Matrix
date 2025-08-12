#pragma once

#include "utils.hpp"

#include <iostream>
#include <cassert>

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
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T>& Vector<C, T>::operator=(const Vector<C, T>& other) 
	{
		if (this != &other)
			data = other.data;
		return *this;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Vector<C, T>::operator==(const Vector<C, T>& other) const 
	{
		return data == other.data;
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Add(const Vector<C, T>& other) 
	{
		for (size_t i = 0; i < C; i++)
			data[i] += other.data[i];
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Subtract(const Vector<C, T>& other) 
	{
		for (size_t i = 0; i < C; i++)
			data[i] -= other.data[i];
	}

	template<std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Vector<C, T>::Scale(const Vector<C, T>& other) 
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
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::Dot(const Vector<C, T>& other) const 
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
		// TODO: remove replace std::sqrt
		return sqrt(res);
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

	template <size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T> Vector<C, T>::Lerp(const Vector<C, T>& a, const Vector<C, T>& b, float t)
	{
		t = clamp01(t);
		Vector<C, T> result;
		for (size_t i = 0; i < C; ++i)
			result[i] = static_cast<T>(a[i] + (b[i] - a[i]) * t);
		return result;
	}

	template <size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C,T> Vector<C, T>::LinearCombination(const std::vector< Vector<C,T> >& vectors, const Vector<C,T>& scalar)
	{
		Vector<C,T> result{};

		for (size_t i = 0; i < vectors.size(); i++)
		{
			Vector<C,T> tmp = vectors[i];
			tmp.Scale(scalar[i]);
			result.Add(tmp);
		}
		return result;
	}

	template <size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::magnitude(Vector<C, float> vector) 
	{
		float res = 0.0f;
		for (size_t i = 0; i < vector.size(); i++)
			res = vector[i] * vector[i];
		return sqrt(res); 
	}

	template <size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR float Vector<C, T>::angle_cos(const Vector<C, T>& a, const Vector<C, T>& b) 
	{
		float dot = a.Dot(b);
		float mag1 = a.norm();
		float mag2 = b.norm();

		if (mag1 == 0.0f || mag2 == 0.0f)
			return 0.0f;

		return dot / (mag1 * mag2);
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
