#pragma once

#include "utils.hpp"
#include <cassert>
#include <iomanip>
#include "Matrix.hpp"

namespace Maft
{
	template <std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T>::Matrix(T const& x)
	{
		for(std::size_t i = 0; i < R * C; i++)
			this->data[i] = x;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<R, C, T>::operator()(std::size_t row, std::size_t col)
	{
		assert(row < R && col < C);
		return data[col * R + row];
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<R, C, T>::operator()(std::size_t row, std::size_t col) const
	{
		assert(row < R && col < C);
		return data[col * R + row];
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T>& Matrix<R, C, T>::operator=(const Matrix<R, C, T>& other)
	{
		if (this != &other)
			data = other.data;
		return *this;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Matrix<R, C, T>::operator==(const Matrix& other) const
	{
		return data == other.data;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Add(const Matrix& other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			data[i] += other.data[i];
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Scale(const Matrix& other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			data[i] *= other.data[i];
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Scale(const T& scalar)
	{
		for (size_t i = 0; i < data.size(); i++)
			this->data[i] *= scalar;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Subtract(const Matrix& other) 
	{
		for (size_t i = 0; i < data.size(); i++)
			this->data[i] -= other.data[i]; 
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> Matrix<R, C, T>::Lerp(const Matrix<R, C, T> &a, const Matrix<R, C, T> &b, float t)
	{
		t = clamp01(t);
		Matrix<R, C, T> result;

		for (size_t r = 0; r < R; ++r)
		{
			for (size_t c = 0; c < C; ++c)
			{
				result(r,c) = static_cast<T>(
					a(r,c) + (b(r,c) - a(r,c)) * t
				);
			}
		}
		return result;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T> Matrix<R, C, T>::multiply_vector(const Vector<C, T>& v)
	{
		Vector<R, T> result;
		for (std::size_t r = 0; r < R; ++r)
		{
			T sum = T{};
			for (std::size_t c = 0; c < C; ++c)
				sum += (*this)(r, c) * v[c];
			result[r] = sum;
		}
		return result;
	}

	template <std::size_t R, std::size_t C, typename T>
	template <std::size_t P>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, P, T> Matrix<R, C, T>::multiply_matrix(const Matrix<C, P, T>& m) const
	{
		Matrix<R, P, T> result{};
		for (std::size_t i = 0; i < R; ++i) 
		{
			for (std::size_t j = 0; j < P; ++j) 
			{
				T sum = T{};

				for (std::size_t k = 0; k < C; ++k) 
					sum += (*this)(i, k) * m(k, j);
				result(i, j) = sum;
			}
		}
		return result;
	}

    template<std::size_t R, std::size_t C, typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<R, C, T>& m)
	{
		constexpr int width = 2; 
		os << "\n";
		for (std::size_t i = 0; i < R; ++i)
		{
			for (std::size_t j = 0; j < C; ++j)
				os << std::setw(width) << m(i, j) << " ";
			os << "\n";
		}
		return os;
	}
} // namespace Maft