#pragma once

#include "../utils/utils.hpp"
#include <cassert>
#include <iomanip>
#include "Matrix.hpp"

namespace Maft
{
	//  constructors
	
	template <std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR Matrix<R, C, T>::Matrix(T const& x)
	{
		for(std::size_t i = 0; i < R * C; i++)
			this->data[i] = x;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR Matrix<R, C, T>::Matrix(const Matrix<R, C, T> &other)
	{
		for(std::size_t i = 0; i < R * C; i++)
			this->data[i] = other.data[i];
	}

	// assignment operators (matrix matrix)

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator=(const Matrix<R, C, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] = other.data[i];
		return *this;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator+=(const Matrix<R, C, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] += other.data[i];
		return *this;
	}

    template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator-=(const Matrix<R, C, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] -= other.data[i];
		return *this;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator*=(const Matrix<R, C, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] *= other.data[i];
		return *this;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator/=(const Matrix<R, C, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] /= other.data[i];
		return *this;
	}

	// assignment operators (matrix scalar)

	template <std::size_t R, std::size_t C, typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator+=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] += s;
		return *this;
	}

    template <std::size_t R, std::size_t C, typename T>
    template <typename U>
    MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator-=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] -= s;
		return *this;
	}

	template <std::size_t R, std::size_t C, typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator*=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] *= s;
		return *this;
	}

	template <std::size_t R, std::size_t C, typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> &Matrix<R, C, T>::operator/=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] /= s;
		return *this;
	}

	//  increment / decrement
	
	template <std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T>& Matrix<R, C, T>::operator++()
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i]++;
		return *this;
	}

	template <std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T>& Matrix<R, C, T>::operator--()
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i]--;
		return *this;
	}
	
	template <std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> Matrix<R, C, T>::operator++(int)
	{
		Matrix<R, C, T> res(*this);
		++*this;
		return res;
	}

	template <std::size_t R, std::size_t C, typename T>
	Matrix<R, C, T> Matrix<R, C, T>::operator--(int)
	{
		Matrix<R, C, T> res(*this);
		--*this;
		return res;
	}

	//  element access
	
	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE T& Matrix<R, C, T>::operator()(std::size_t row, std::size_t col)
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

	//  matrix operations

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Add(const Matrix& other)
	{
		(*this) += other;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Scale(const Matrix& other)
	{
		(*this) *= other;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Scale(const T& scalar)
	{
		(*this) *= scalar;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::Subtract(const Matrix& other) 
	{
		(*this) -= other;
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::swap_row(int first_row_index, int second_row_index)
	{
		assert(first_row_index >= 0 && first_row_index < static_cast<int>(R));
    	assert(second_row_index >= 0 && second_row_index < static_cast<int>(R));
		if (first_row_index == second_row_index) return;

		for (std::size_t col = 0; col < C; ++col)
			std::swap((*this)(first_row_index, col), (*this)(second_row_index, col));
	}

	template<std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<R, C, T>::swap_column(int first_column_index, int second_column_index)
	{
		assert(first_column_index >= 0 && first_column_index < static_cast<int>(R));
    	assert(second_column_index >= 0 && second_column_index < static_cast<int>(R));
		if (first_column_index == second_column_index) return;

		for (std::size_t row = 0; row < R; ++row)
			std::swap((*this)(row, first_column_index), (*this)(row, second_column_index));
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> Matrix<R, C, T>::transpose() const
	{
		Matrix<C, R, T> result{};
		for (std::size_t r = 0; r < R; ++r) 
		{
			for (std::size_t c = 0; c < C; ++c) 
				result(c, r) = (*this)(r, c);
		}
		return result;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR T Matrix<R, C, T>::trace() const
	{
		assert(R == C);
		T sum {};

		for (size_t i = 0; i < C; i++)
			sum += (*this)(i,i);

		return sum;
	}

    template <std::size_t R, std::size_t C, typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Matrix<R, C, T>::is_square() const
    {
		return R == C;
	}

    template <std::size_t R, std::size_t C, typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Matrix<R, C, T>::determinant() const
    {
    	static_assert(R == C);
		
        T det = T(0);
        for (size_t col = 0; col < R; ++col)
        {
            Matrix<R-1, C-1, T> minor;
            for (size_t i = 1; i < R; ++i)
            {
                size_t minor_col = 0;
                for (size_t j = 0; j < C; ++j)
                {
                    if (j == col) continue;
                    minor(i-1, minor_col) = (*this)(i,j);
                    ++minor_col;
                }
            }

            T cofactor = ((col % 2 == 0) ? 1 : -1) * (*this)(0,col);
            det += cofactor * minor.determinant();
        }
        return det;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> Matrix<R, C, T>::row_echelon() const
	{
		Matrix<R, C, T> m(*this);
		std::size_t lead = 0;
		constexpr T epsilon = T(1e-7);

		for (std::size_t r = 0; r < R; ++r)
		{
			if (lead >= C)
				break;

			std::size_t i = r;
			while (i < R && abs(m(i, lead)) < epsilon)
				++i;

			if (i == R)
			{
				++lead;
				--r; 
				continue;
			}

			if (i != r)
				m.swap_row(i, r);

			T pivot = m(r, lead);
			if (abs(pivot) >= epsilon)
			{
				for (std::size_t col = 0; col < C; ++col)
					m(r, col) /= pivot;
			}

			for (std::size_t row_below = r + 1; row_below < R; ++row_below)
			{
				T factor = m(row_below, lead);
				if (abs(factor) >= epsilon)
				{
					for (std::size_t col = 0; col < C; ++col)
						m(row_below, col) -= factor * m(r, col);
				}
			}

			++lead;
		}

		for (std::size_t row = 0; row < R; ++row)
			for (std::size_t col = 0; col < C; ++col)
				if (abs(m(row, col)) < epsilon)
					m(row, col) = T(0);

		return m;
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

	// static utility functions

	template <std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR Matrix<R, C, T> Matrix<R, C, T>::Identity()
	{
		Matrix<R,C,T> I{};
		for(int i=0;i<C;++i)
			I(i,i) = T(1);
		return I;
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
	
	//  unary operators
	
    template <std::size_t R, std::size_t C, typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> operator+(const Matrix<R, C, T> &m)
    {
		return m;
	}

    template <std::size_t R, std::size_t C, typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> operator-(const Matrix<R, C, T> &m)
    {
		for (size_t i = 0; i < R * C; i++)
			m[i] = -m[i]; 
		
		return m;
	}

	// binary operators 

	template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator+(const Matrix<R, C, T> &m, T scalar)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] + scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator+(T scalar, const Matrix<R, C, T> &m)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] + scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator+(const Matrix<R, C, T> &m1, const Matrix<R, C, T> &m2)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] + m2[i];

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator-(const Matrix<R, C, T> &m, T scalar)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] - scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator-(T scalar, const Matrix<R, C, T> &m)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] - scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator-(const Matrix<R, C, T> &m1, const Matrix<R, C, T> &m2)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] - m2[i];

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator*(const Matrix<R, C, T> &m, T scalar)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] * scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator*(T scalar, const Matrix<R, C, T> &m)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] * scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator*(const Matrix<R, C, T> &m1, const Matrix<R, C, T> &m2)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] * m2[i];

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator/(const Matrix<R, C, T> &m, T scalar)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] / scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator/(T scalar, const Matrix<R, C, T> &m)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] / scalar;

		return res;
	}

    template <std::size_t R, std::size_t C, typename T>
    Matrix<R, C, T> operator/(const Matrix<R, C, T> &m1, const Matrix<R, C, T> &m2)
    {
		Matrix<R, C, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] / m2[i];

		return res;
	}

	// comparison operators

    template <std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool Maft::operator==(const Matrix<R, C, T> &m1, const Matrix<R, C, T> &m2)
	{
		for (size_t i = 0; i < R * C; i++)
		{
			if (m1[i] != m2[i]) return false;
		}
		return true;
	}

	template <std::size_t R, std::size_t C, typename T>
	MAFT_CONSTEXPR bool Maft::operator!=(const Matrix<R, C, T> &m1, const Matrix<R, C, T> &m2)
	{
		for (size_t i = 0; i < R * C; i++)
		{
			if (m1[i] == m2[i]) return false;
		}
		return true;
	}

	// print

	template<std::size_t R, std::size_t C, typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<R, C, T>& m)
	{
		constexpr int width = 3; 
		os << "\n";
		for (std::size_t i = 0; i < R; ++i)
		{
			os << "[";
			for (std::size_t j = 0; j < C; ++j)
				os << std::setw(width) << m(i, j) << ", ";
			os << "]\n";
		}
		return os;
	}
} 