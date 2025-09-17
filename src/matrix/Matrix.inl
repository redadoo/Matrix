#pragma once

#include "../utils/utils.hpp"
#include <cassert>
#include <iomanip>
#include "Matrix.hpp"

namespace Maft
{
	//  constructors

	template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR Matrix<C, R, T>::Matrix(T const& x)
	{
		for(std::size_t i = 0; i < R * C; i++)
			this->data[i] = x;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR Matrix<C, R, T>::Matrix(std::initializer_list<T> values)
	{
		assert(values.size() == R * C && "Initializer list must match matrix size");

		auto it = values.begin();
		for (std::size_t r = 0; r < R; ++r)
		{
			for (std::size_t c = 0; c < C; ++c)
			{
				(*this)(c, r) = *it++;
			}
		}
	}


    template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR Matrix<C, R, T>::Matrix(const Matrix<C, R, T> &other)
	{
		for(std::size_t i = 0; i < R * C; i++)
			this->data[i] = other.data[i];
	}

	// assignment operators (matrix matrix)

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator=(const Matrix<C, R, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] = other.data[i];
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator+=(const Matrix<C, R, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] += other.data[i];
		return *this;
	}

    template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator-=(const Matrix<C, R, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] -= other.data[i];
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator*=(const Matrix<C, R, T> &other)
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] *= other.data[i];
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator/=(const Matrix<C, R, T> &other)
	{
		return *this *= inverse(other);
	}

	// assignment operators (matrix scalar)

	template <std::size_t C, std::size_t R, typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator+=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] += s;
		return *this;
	}

    template <std::size_t C, std::size_t R, typename T>
    template <typename U>
    MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator-=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] -= s;
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator*=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] *= s;
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> &Matrix<C, R, T>::operator/=(U s)
    {
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i] /= s;
		return *this;
	}

	//  increment / decrement

	template <std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T>& Matrix<C, R, T>::operator++()
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i]++;
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T>& Matrix<C, R, T>::operator--()
	{
		for (std::size_t i = 0; i < data.size(); ++i)
			this->data[i]--;
		return *this;
	}

	template <std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> Matrix<C, R, T>::operator++(int)
	{
		Matrix<C, R, T> res(*this);
		++*this;
		return res;
	}

	template <std::size_t C, std::size_t R, typename T>
	Matrix<C, R, T> Matrix<C, R, T>::operator--(int)
	{
		Matrix<C, R, T> res(*this);
		--*this;
		return res;
	}

	//  element access

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE T& Matrix<C, R, T>::operator()(std::size_t col, std::size_t row)
	{
		assert(row < R && col < C);
		return data[col * R + row];
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<C, R, T>::operator()(std::size_t col, std::size_t row) const
	{
		assert(row < R && col < C);
		return data[col * R + row];
	}

	//  matrix operations
	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR int Matrix<C, R, T>::rank() const
	{
		Matrix<C, R, T> ref = this->row_echelon_no_div();
		constexpr T eps = std::is_floating_point<T>::value ? T(1e-7) : T(0);

		int rank = 0;
		for (std::size_t r = 0; r < R; ++r)
		{
			bool nonZero = false;
			for (std::size_t c = 0; c < C; ++c)
			{
				if (std::is_floating_point<T>::value
						? std::abs(ref(c, r)) > eps
						: ref(c, r) != T(0))
				{
					nonZero = true;
					break;
				}
			}
			if (nonZero) ++rank;
		}
		return rank;
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> Matrix<C, R, T>::inverse() const
	{
		Matrix<C, R, T> A(*this);
		Matrix<C, R, T> inv = Identity();
		constexpr T EPS = T(1e-7);

		for (std::size_t col = 0; col < R; ++col)
		{
			std::size_t pivot_row = col;
			for (std::size_t row = col; row < R; ++row)
				if (abs(A(col, row)) > abs(A(col, pivot_row)))
					pivot_row = row;

			if (abs(A(col, pivot_row)) < EPS)
				throw std::runtime_error("Matrix is singular, cannot invert");

			if (pivot_row != col)
			{
				A.swap_row(col, pivot_row);
				inv.swap_row(col, pivot_row);
			}

			T pivot = A(col, col);
			for (std::size_t c = 0; c < R; ++c)
			{
				A(c, col) /= pivot;
				inv(c, col) /= pivot;
			}

			for (std::size_t row = 0; row < R; ++row)
			{
				if (row == col) continue;
				T factor = A(col, row);
				for (std::size_t c = 0; c < R; ++c)
				{
					A(c, row) -= factor * A(c, col);
					inv(c, row) -= factor * inv(c, col);
				}
			}
		}

		for (std::size_t row = 0; row < R; ++row)
			for (std::size_t col = 0; col < R; ++col)
				if (abs(inv(col, row)) < EPS)
					inv(col, row) = T(0);

		return inv;
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<C, R, T>::Add(const Matrix& other)
	{
		(*this) += other;
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<C, R, T>::Scale(const Matrix& other)
	{
		(*this) *= other;
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<C, R, T>::Scale(const T& scalar)
	{
		(*this) *= scalar;
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<C, R, T>::Subtract(const Matrix& other)
	{
		(*this) -= other;
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<C, R, T>::swap_row(std::size_t r1, std::size_t r2)
	{
		assert(r1 < R && r2 < R);
		if (r1 == r2) return;

		for (std::size_t col = 0; col < C; ++col)
			std::swap((*this)(col, r1), (*this)(col, r2));
	}

	template<std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<C, R, T>::swap_column(std::size_t c1, std::size_t c2)
	{
		assert(c1 < C && c2 < C);
		if (c1 == c2) return;

		for (std::size_t row = 0; row < R; ++row)
			std::swap((*this)(c1, row), (*this)(c2, row));
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, C, T> Matrix<C, R, T>::transpose() const
	{
		Matrix<R, C, T> result{};
		for (std::size_t r = 0; r < R; ++r)
		{
			for (std::size_t c = 0; c < C; ++c)
			{
				result(r, c) = (*this)(c, r);
			}
		}
		return result;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR T Matrix<C, R, T>::trace() const
	{
		assert(R == C);
		T sum {};

		for (size_t i = 0; i < C; i++)
			sum += (*this)(i,i);

		return sum;
	}

    template <std::size_t C, std::size_t R, typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Matrix<C, R, T>::is_square() const
    {
		return R == C;
	}

    template <std::size_t C, std::size_t R, typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Matrix<C, R, T>::determinant() const
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

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> Matrix<C, R, T>::row_echelon() const
	{
		Matrix<C, R, T> m(*this);

		constexpr bool isFloat = std::is_floating_point<T>::value;
		constexpr T eps = isFloat ? T(1e-7) : T(0);

		std::size_t lead = 0;
		for (std::size_t r = 0; r < R; ++r)
		{
			if (lead >= C) break;

			std::size_t i = r;
			while (i < R && (isFloat ? std::abs(m(lead, i)) < eps : m(lead, i) == T(0)))
				++i;

			if (i == R) 
			{ 
				++lead; 
				--r; 
				continue; 
			}

			if (i != r) 
				m.swap_row(r, i);

			T pivot = m(lead, r);

			if constexpr (std::is_floating_point<T>::value)
			{
				if (std::abs(pivot) > eps)
					for (std::size_t c = 0; c < C; ++c)
						m(c, r) /= pivot;
			}

			for (std::size_t rb = r + 1; rb < R; ++rb)
			{
				T factor = m(lead, rb);

				if constexpr (std::is_floating_point<T>::value)
				{
					if (std::abs(factor) > eps)
						for (std::size_t c = 0; c < C; ++c)
							m(c, rb) -= factor * m(c, r);
				}
				else
				{
					if (factor != T(0))
						for (std::size_t c = 0; c < C; ++c)
							m(c, rb) = m(c, rb) * pivot - m(c, r) * factor;
				}
			}

			++lead;
		}

		if constexpr (std::is_floating_point<T>::value)
		{
			for (std::size_t c = 0; c < C; ++c)
				for (std::size_t r = 0; r < R; ++r)
					if (std::abs(m(c, r)) < eps) m(c, r) = T(0);
		}

		return m;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR Matrix<C, R, T> Matrix<C, R, T>::row_echelon_no_div() const
	{
		Matrix<C,R,T> m(*this);
		constexpr T eps = std::is_floating_point<T>::value ? T(1e-7) : T(0);

		std::size_t lead = 0;

		for (std::size_t r = 0; r < R && lead < C; ++r)
		{
			std::size_t pivotRow = r;
			T maxVal = std::abs(m(lead, r));
			for (std::size_t i = r + 1; i < R; ++i)
			{
				if (std::abs(m(lead, i)) > maxVal)
				{
					pivotRow = i;
					maxVal = std::abs(m(lead, i));
				}
			}

			if (maxVal < eps) 
			{ 
				++lead; --r; 
				continue; 
			}

			if (pivotRow != r) 
				m.swap_row(r, pivotRow);

			for (std::size_t rb = r + 1; rb < R; ++rb)
			{
				T factor = m(lead, rb) / m(lead, r);
				for (std::size_t c = 0; c < C; ++c)
					m(c, rb) -= factor * m(c, r);
			}

			++lead;
		}

		if constexpr (std::is_floating_point<T>::value)
			for (std::size_t r = 0; r < R; ++r)
				for (std::size_t c = 0; c < C; ++c)
					if (std::abs(m(c,r)) < eps) m(c,r) = 0;

		return m;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<C, T> Matrix<C, R, T>::multiply_vector(const Vector<C, T>& v)
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

	template <std::size_t C, std::size_t R, typename T>
	template <std::size_t P>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<R, P, T> Matrix<C, R, T>::multiply_matrix(const Matrix<C, P, T>& m) const
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

	template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR Matrix<C, R, T> Matrix<C, R, T>::Identity()
	{
		Matrix<C,R,T> I{0};
		for(int i=0;i<C;++i)
			I(i,i) = T(1);
		return I;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> Matrix<C, R, T>::Lerp(const Matrix<C, R, T> &a, const Matrix<C, R, T> &b, float t)
	{
		t = clamp01(t);
		Matrix<C, R, T> result;

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

    template <std::size_t C, std::size_t R, typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> operator+(const Matrix<C, R, T> &m)
    {
		return m;
	}

    template <std::size_t C, std::size_t R, typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<C, R, T> operator-(const Matrix<C, R, T> &m)
    {
		for (size_t i = 0; i < R * C; i++)
			m[i] = -m[i];

		return m;
	}

	// binary operators

	template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator+(const Matrix<C, R, T> &m, T scalar)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] + scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator+(T scalar, const Matrix<C, R, T> &m)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] + scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator+(const Matrix<C, R, T> &m1, const Matrix<C, R, T> &m2)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] + m2[i];

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator-(const Matrix<C, R, T> &m, T scalar)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] - scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator-(T scalar, const Matrix<C, R, T> &m)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] - scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator-(const Matrix<C, R, T> &m1, const Matrix<C, R, T> &m2)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] - m2[i];

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator*(const Matrix<C, R, T> &m, T scalar)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] * scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator*(T scalar, const Matrix<C, R, T> &m)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] * scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator*(const Matrix<C, R, T> &m1, const Matrix<C, R, T> &m2)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] * m2[i];

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator/(const Matrix<C, R, T> &m, T scalar)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] / scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator/(T scalar, const Matrix<C, R, T> &m)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m[i] / scalar;

		return res;
	}

    template <std::size_t C, std::size_t R, typename T>
    Matrix<C, R, T> operator/(const Matrix<C, R, T> &m1, const Matrix<C, R, T> &m2)
    {
		Matrix<C, R, T> res;
		for (size_t i = 0; i < R * C; i++)
			res[i] = m1[i] / m2[i];

		return res;
	}

	// comparison operators

    template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR bool Maft::operator==(const Matrix<C, R, T> &m1, const Matrix<C, R, T> &m2)
	{
		for (size_t i = 0; i < R * C; i++)
		{
			if (m1.data[i] != m2.data[i]) return false;
		}
		return true;
	}

	template <std::size_t C, std::size_t R, typename T>
	MAFT_CONSTEXPR bool Maft::operator!=(const Matrix<C, R, T> &m1, const Matrix<C, R, T> &m2)
	{
		for (size_t i = 0; i < R * C; i++)
		{
			if (m1.data[i] == m2.data[i]) return false;
		}
		return true;
	}

	// print

	template<std::size_t C, std::size_t R, typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<C, R, T>& m)
	{
		constexpr int width = 1;
		os << "\n";
		for (std::size_t i = 0; i < R; ++i)
		{
			os << "[";
			for (std::size_t j = 0; j < C; ++j)
			{
				os << std::setw(width) << m(j, i);
				
				if (j != C - 1) 
					os << ", ";
			}
			os << "]\n";
		}
		return os;
	}
}