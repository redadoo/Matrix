#pragma once

#include <cstddef>
#include <ostream>
#include <array>
#include <vector>

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