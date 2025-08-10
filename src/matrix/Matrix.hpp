// #pragma once

// #include <cassert>
// #include <iomanip>

// template<std::size_t R, std::size_t C, typename T>
// struct mat
// {
// 	std::array<T, R * C> data{};

// 	mat(const mat& other) = default;
// 	mat() = default;

// 	T& operator()(std::size_t row, std::size_t col)
// 	{
// 		assert(row < R && col < C);
// 		return data[row * C + col];
// 	}

// 	const T& operator()(std::size_t row, std::size_t col) const
// 	{
// 		assert(row < R && col < C);
// 		return data[row * C + col];
// 	}

// 	mat& operator=(const mat& other)
// 	{
// 		if (this != &other)
// 			data = other.data;
// 		return *this;
// 	}

// 	bool operator==(const mat& other) const
// 	{
// 		return data == other.data;
// 	}

// 	void Add(const mat& other)
// 	{
// 		for (std::size_t i = 0; i < data.size(); ++i)
// 			data[i] += other.data[i];
// 	}

// 	void Scale(const mat& other)
// 	{
// 		for (std::size_t i = 0; i < data.size(); ++i)
// 			data[i] *= other.data[i];
// 	}

// 	void Scale(const T& scalar)
// 	{
// 		for (size_t i = 0; i < data.size(); i++)
// 			this->data[i] *= scalar;
// 	}

// 	void Subtract(const mat& other) {
// 		for (size_t i = 0; i < data.size(); i++)
// 			this->data[i] -= other.data[i]; 
// 	}

// 	template <size_t C, typename T>
// 	vec<T,C> multiply_vec(const &vec<T,C>) const
// 	{
// 		vec<R, T> result{};
// 		return result;
// 	}
	
// 	friend std::ostream& operator<<(std::ostream& os, const mat& m)
// 	{
// 		constexpr int width = 2; 
// 		os << "\n";
// 		for (std::size_t i = 0; i < R; ++i)
// 		{
// 			for (std::size_t j = 0; j < C; ++j)
// 				os << std::setw(width) << m(i, j) << " ";
// 			os << "\n";
// 		}
// 		return os;
// 	}
// };