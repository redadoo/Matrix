#pragma once

#include <cstddef>
#include <ostream>
#include <array>
#include <vector>
#include <cmath>

template<std::size_t C, typename T>
struct vec
{
	std::array<T,C> data{};

	vec() = default;
	vec(const vec& other) = default;
	 
	T& operator[](std::size_t i) { return data[i]; }
	const T& operator[](std::size_t i) const { return data[i]; }
	
	vec& operator=(const vec& other)
	{
		if (this != &other)
			data = other.data;
		return *this;
	}

	bool operator==(const vec& other) const
	{
		return data == other.data;
	}
	
	void Add(const vec& other) 
	{
		for (size_t i = 0; i < C; i++)
			this->data[i] += other.data[i]; 
	}

	void Subtract(const vec& other) 
	{
		for (size_t i = 0; i < C; i++)
			this->data[i] -= other.data[i]; 
	}

	void Scale(const vec& other)
	{
		for (size_t i = 0; i < C; i++)
			this->data[i] *= other.data[i]; 
	}

	void Scale(const T& scalar)
	{
		for (size_t i = 0; i < C; i++)
			this->data[i] *= scalar;
	}

	float Dot(const vec& other) const
	{
		float final_value = 0; 
		for (size_t i = 0; i < C; i++)
		{
			float value = this->data[i] * other.data[i];
			final_value += value;
		}
		return final_value;
	}

	float norm() const
	{
		float res = 0;
		for (size_t i = 0; i < C; i++)
			res += this->data[i] * this->data[i]; 
		return std::sqrt(res);
	}

	float norm_1() const
	{
		float res = 0;
		for (size_t i = 0; i < C; i++)
			res += std::abs(this->data[i]);
		return res;
	}

	float norm_inf() const
	{
		float max = std::abs(this->data[0]);
		for (size_t i = 1; i < C; i++)
		{
			float tmp = std::abs(this->data[i]);
			if (tmp > max)
				max = tmp;
		}
		return max;
	}


	friend std::ostream& operator<<(std::ostream& os, const vec<C, T>& v)
	{
		os << "[";
		for (std::size_t i = 0; i < C; ++i) 
		{
			os << v[i];
			if (i != C - 1) os << ", ";
		}
		os << "]";
		return os;
	}
};