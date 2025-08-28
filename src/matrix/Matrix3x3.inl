#pragma once

#include "Matrix.hpp"

namespace Maft
{
	// constructors

	template<typename T>
	MAFT_CONSTEXPR Matrix<3, 3, T>::Matrix(const T& x)
	{
		this->data[0] = x;
		this->data[1] = x;
		this->data[2] = x;
		this->data[3] = x;
		this->data[4] = x;
		this->data[5] = x;
		this->data[6] = x;
		this->data[7] = x;
		this->data[8] = x;
	}

	template<typename T>
	MAFT_CONSTEXPR Matrix<3, 3, T>::Matrix( T m00, T m10, T m20, T m01, T m11, T m21, T m02, T m12, T m22)
	{
		this->data[0] = m00;
		this->data[1] = m10;
		this->data[2] = m20;
		this->data[3] = m01;
		this->data[4] = m11;
		this->data[5] = m21;
		this->data[6] = m02;
		this->data[7] = m12;
		this->data[8] = m22;
	}
	
	template<typename T>
	MAFT_CONSTEXPR Matrix<3, 3, T>::Matrix(const Matrix<3, 3, T>& other)
	{
		this->data[0] = other.data[0];
		this->data[1] = other.data[1];
		this->data[2] = other.data[2];
		this->data[3] = other.data[3];
		this->data[4] = other.data[4];
		this->data[5] = other.data[5];
		this->data[6] = other.data[6];
		this->data[7] = other.data[7];
		this->data[8] = other.data[8];
	}

	// assignment operators (matrix matrix)

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator=(const Matrix<3, 3, T> &other)
	{
		this->data[0] = other.data[0];
		this->data[1] = other.data[1];
		this->data[2] = other.data[2];
		this->data[3] = other.data[3];
		this->data[4] = other.data[4];
		this->data[5] = other.data[5];
		this->data[6] = other.data[6];
		this->data[7] = other.data[7];
		this->data[8] = other.data[8];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator+=(const Matrix<3, 3, T> &other)
	{
		this->data[0] += other.data[0];
		this->data[1] += other.data[1];
		this->data[2] += other.data[2];
		this->data[3] += other.data[3];
		this->data[4] += other.data[4];
		this->data[5] += other.data[5];
		this->data[6] += other.data[6];
		this->data[7] += other.data[7];
		this->data[8] += other.data[8];
		return *this;
	}

    template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator-=(const Matrix<3, 3, T> &other)
	{
		this->data[0] -= other.data[0];
		this->data[1] -= other.data[1];
		this->data[2] -= other.data[2];
		this->data[3] -= other.data[3];
		this->data[4] -= other.data[4];
		this->data[5] -= other.data[5];
		this->data[6] -= other.data[6];
		this->data[7] -= other.data[7];
		this->data[8] -= other.data[8];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator*=(const Matrix<3, 3, T> &other)
	{
		this->data[0] *= other.data[0];
		this->data[1] *= other.data[1];
		this->data[2] *= other.data[2];
		this->data[3] *= other.data[3];
		this->data[4] *= other.data[4];
		this->data[5] *= other.data[5];
		this->data[6] *= other.data[6];
		this->data[7] *= other.data[7];
		this->data[8] *= other.data[8];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator/=(const Matrix<3, 3, T> &other)
	{
		this->data[0] /= other.data[0];
		this->data[1] /= other.data[1];
		this->data[2] /= other.data[2];
		this->data[3] /= other.data[3];
		this->data[4] /= other.data[4];
		this->data[5] /= other.data[5];
		this->data[6] /= other.data[6];
		this->data[7] /= other.data[7];
		this->data[8] /= other.data[8];
		return *this;
	}

	// assignment operators (matrix scalar)

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator+=(U s)
    {
		this->data[0] += s;
		this->data[1] += s;
		this->data[2] += s;
		this->data[3] += s;
		this->data[4] += s;
		this->data[5] += s;
		this->data[6] += s;
		this->data[7] += s;
		this->data[8] += s;
		return *this;
	}

    template <typename T>
    template <typename U>
    MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator-=(U s)
    {
		this->data[0] -= s;
		this->data[1] -= s;
		this->data[2] -= s;
		this->data[3] -= s;
		this->data[4] -= s;
		this->data[5] -= s;
		this->data[6] -= s;
		this->data[7] -= s;
		this->data[8] -= s;
		return *this;
	}

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator*=(U s)
    {
		this->data[0] *= s;
		this->data[1] *= s;
		this->data[2] *= s;
		this->data[3] *= s;
		this->data[4] *= s;
		this->data[5] *= s;
		this->data[6] *= s;
		this->data[7] *= s;
		this->data[8] *= s;
		return *this;
	}

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> &Matrix<3, 3, T>::operator/=(U s)
    {
		this->data[0] /= s;
		this->data[1] /= s;
		this->data[2] /= s;
		this->data[3] /= s;
		this->data[4] /= s;
		this->data[5] /= s;
		this->data[6] /= s;
		this->data[7] /= s;
		this->data[8] /= s;
		return *this;
	}
	
	//  increment / decrement
	
	template <typename T>
	Matrix<3, 3, T>& Matrix<3, 3, T>::operator++()
	{
		this->data[0]++;
		this->data[1]++;
		this->data[2]++;
		this->data[3]++;
		this->data[4]++;
		this->data[5]++;
		this->data[6]++;
		this->data[7]++;
		this->data[8]++;
		return *this;
	}

	template <typename T>
	Matrix<3, 3, T>& Matrix<3, 3, T>::operator--()
	{
		this->data[0]--;
		this->data[1]--;
		this->data[2]--;
		this->data[3]--;
		this->data[4]--;
		this->data[5]--;
		this->data[6]--;
		this->data[7]--;
		this->data[8]--;
		return *this;
	}
	
	template <typename T>
	Matrix<3, 3, T> Matrix<3, 3, T>::operator++(int)
	{
		Matrix<3, 3, T> res(*this);
		++*this;
		return res;
	}

	template <typename T>
	Matrix<3, 3, T> Matrix<3, 3, T>::operator--(int)
	{
		Matrix<3, 3, T> res(*this);
		--*this;
		return res;
	}

	//  element access
	
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<3, 3, T>::operator()(std::size_t col, std::size_t row)
	{
		assert(row < 3 && col < 3);
		return data[col * 3 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<3, 3, T>::operator()(std::size_t col, std::size_t row) const
	{
		assert(row < 3 && col < 3);
		return data[col * 3 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<3, 3, T>::operator[](std::size_t index)
	{
		assert(index < 3);
		return data[index];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<3, 3, T>::operator[](std::size_t index) const
	{
		assert(index < 3);
		return data[index];
	}

	//  natrix Operations

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Add(const Matrix<3, 3, T>& other)
	{
		(*this) += other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Scale(const Matrix<3, 3, T>& other)
	{
		(*this) *= other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Scale(const T& scalar)
	{
		(*this) *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Subtract(const Matrix<3, 3, T>& other) 
	{
		(*this) -= other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::swap_column(int first_column_index, int second_column_index)
	{
		std::swap((*this)(0, first_column_index), (*this)(0, second_column_index));
		std::swap((*this)(1, first_column_index), (*this)(1, second_column_index));
		std::swap((*this)(2, first_column_index), (*this)(2, second_column_index));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::swap_row(int first_row_index, int second_row_index)
	{
		std::swap((*this)(first_row_index, 0), (*this)(second_row_index, 0));
		std::swap((*this)(first_row_index, 1), (*this)(second_row_index, 1));
		std::swap((*this)(first_row_index, 2), (*this)(second_row_index, 2));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> Matrix<3, 3, T>::transpose() const
	{
		return Matrix<3, 3, T>(
			(*this)(0,0), (*this)(1,0), (*this)(2,0),
			(*this)(0,1), (*this)(1,1), (*this)(2,1),
			(*this)(0,2), (*this)(1,2), (*this)(2,2)
		);
	}

	template<typename T>
	MAFT_CONSTEXPR T Matrix<3, 3, T>::trace() const
	{
    	return (*this)(0,0) + (*this)(1,1) + (*this)(2,2);
	}

	template <typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Matrix<3, 3, T>::determinant() const
    {
		 
		return (*this)(0,0) * ((*this)(1,1) * (*this)(2,2) - (*this)(1,2) * (*this)(2,1))
			 - (*this)(0,1) * ((*this)(1,0) * (*this)(2,2) - (*this)(1,2) * (*this)(2,0))
			 + (*this)(0,2) * ((*this)(1,0) * (*this)(2,1) - (*this)(1,1) * (*this)(2,0));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> Matrix<3, 3, T>::row_echelon() const
	{
		Matrix<3, 3, T> res(*this);

		if (res(0,0) == T(0)) 
		{
			if (res(1,0) != T(0)) 
				res.swap_row(0, 1);
			else if (res(2,0) != T(0)) 
				res.swap_row(0, 2);
		}

		if (res(0,0) != T(0)) 
		{
			T pivot = res(0,0);
			for (int j = 0; j < 3; ++j)
				res(0,j) /= pivot;
		}

		for (int i = 1; i < 3; ++i) 
		{
			if (res(i,0) != T(0)) 
			{
				T factor = res(i,0);
				for (int j = 0; j < 3; ++j)
					res(i,j) -= factor * res(0,j);
			}
		}

		if (res(1,1) == T(0) && res(2,1) != T(0))
			res.swap_row(1, 2);

		if (res(1,1) != T(0)) {
			T pivot = res(1,1);
			for (int j = 1; j < 3; ++j) 
				res(1,j) /= pivot;
		}

		if (res(2,1) != T(0)) 
		{
			T factor = res(2,1);
			for (int j = 1; j < 3; ++j)
				res(2,j) -= factor * res(1,j);
			res(2,1) = 0;
		}

		if (res(2,2) != T(0)) 
		{
			T pivot = res(2,2);
			res(2,2) /= pivot;
		}

		return res;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<3, T> Matrix<3, 3, T>::multiply_vector(const Vector<3, T>& v)
	{
		Vector<3, T> result;
		result.x = (*this)(0, 0) * v.x + (*this)(0, 1) * v.y + (*this)(0, 2) * v.z;
		result.y = (*this)(1, 0) * v.x + (*this)(1, 1) * v.y + (*this)(1, 2) * v.z;
		result.z = (*this)(2, 0) * v.x + (*this)(2, 1) * v.y + (*this)(2, 2) * v.z;
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> Matrix<3, 3, T>::multiply_matrix(const Matrix<3, 3, T>& m) const
	{
		Matrix<3, 3, T> result;

		result(0,0) = (*this)(0,0) * m(0,0) + (*this)(1,0) * m(0,1) + (*this)(2,0) * m(0,2);
		result(1,0) = (*this)(0,1) * m(0,0) + (*this)(1,1) * m(0,1) + (*this)(2,1) * m(0,2);
		result(2,0) = (*this)(0,2) * m(0,0) + (*this)(1,2) * m(0,1) + (*this)(2,2) * m(0,2);
		result(0,1) = (*this)(0,0) * m(1,0) + (*this)(1,0) * m(1,1) + (*this)(2,0) * m(1,2);
		result(1,1) = (*this)(0,1) * m(1,0) + (*this)(1,1) * m(1,1) + (*this)(2,1) * m(1,2);
		result(2,1) = (*this)(0,2) * m(1,0) + (*this)(1,2) * m(1,1) + (*this)(2,2) * m(1,2);
		result(0,2) = (*this)(0,0) * m(2,0) + (*this)(1,0) * m(2,1) + (*this)(2,0) * m(2,2);
		result(1,2) = (*this)(0,1) * m(2,0) + (*this)(1,1) * m(2,1) + (*this)(2,1) * m(2,2);
		result(2,2) = (*this)(0,2) * m(2,0) + (*this)(1,2) * m(2,1) + (*this)(2,2) * m(2,2);
		return result;
	}

	// static utility functions

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> Matrix<3, 3, T>::Lerp(const Matrix<3, 3, T> &a, const Matrix<3, 3, T> &b, float t)
	{
		t = clamp01(t);
		Matrix<3, 3, T> result;

		result.data[0] = static_cast<T>(a.data[0] + (b.data[0] - a.data[0]) * t);
		result.data[1] = static_cast<T>(a.data[1] + (b.data[1] - a.data[1]) * t);
		result.data[2] = static_cast<T>(a.data[2] + (b.data[2] - a.data[2]) * t);
		result.data[3] = static_cast<T>(a.data[3] + (b.data[3] - a.data[3]) * t);
		result.data[4] = static_cast<T>(a.data[4] + (b.data[4] - a.data[4]) * t);
		result.data[5] = static_cast<T>(a.data[5] + (b.data[5] - a.data[5]) * t);
		result.data[6] = static_cast<T>(a.data[6] + (b.data[6] - a.data[6]) * t);
		result.data[7] = static_cast<T>(a.data[7] + (b.data[7] - a.data[7]) * t);
		result.data[8] = static_cast<T>(a.data[8] + (b.data[8] - a.data[8]) * t);

		return result;
	}
	
	//  unary operators
	
    template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> operator+(const Matrix<3, 3, T> &m)
    {
		return m;
	}

    template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T> operator-(const Matrix<3, 3, T> &m)
    {
		m[0] = -m[0]; 
		m[1] = -m[1]; 
		m[2] = -m[2]; 
		m[3] = -m[3];
		m[4] = -m[5]; 
		m[5] = -m[6]; 
		m[6] = -m[7]; 
		m[7] = -m[8]; 
		m[8] = -m[9]; 
		return m;
	}

	// binary operators 

	template<typename T>
    Matrix<3, 3, T> operator+(const Matrix<3, 3, T> &m, T scalar)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] + scalar;
		res[1] = m[1] + scalar;
		res[2] = m[2] + scalar;
		res[3] = m[3] + scalar;
		res[4] = m[4] + scalar;
		res[5] = m[5] + scalar;
		res[6] = m[6] + scalar;
		res[7] = m[7] + scalar;
		res[8] = m[8] + scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator+(T scalar, const Matrix<3, 3, T> &m)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] + scalar;
		res[1] = m[1] + scalar;
		res[2] = m[2] + scalar;
		res[3] = m[3] + scalar;
		res[4] = m[4] + scalar;
		res[5] = m[5] + scalar;
		res[6] = m[6] + scalar;
		res[7] = m[7] + scalar;
		res[8] = m[8] + scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator+(const Matrix<3, 3, T> &m1, const Matrix<3, 3, T> &m2)
    {
		Matrix<3, 3, T> res;
		res[0] = m1[0] + m2[0];
		res[1] = m1[1] + m2[1];
		res[2] = m1[2] + m2[2];
		res[3] = m1[3] + m2[3];
		res[4] = m1[4] + m2[4];
		res[5] = m1[5] + m2[5];
		res[6] = m1[6] + m2[6];
		res[7] = m1[7] + m2[7];
		res[8] = m1[8] + m2[8];
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator-(const Matrix<3, 3, T> &m, T scalar)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] - scalar;
		res[1] = m[1] - scalar;
		res[2] = m[2] - scalar;
		res[3] = m[3] - scalar;
		res[4] = m[4] - scalar;
		res[5] = m[5] - scalar;
		res[6] = m[6] - scalar;
		res[7] = m[7] - scalar;
		res[8] = m[8] - scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator-(T scalar, const Matrix<3, 3, T> &m)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] - scalar;
		res[1] = m[1] - scalar;
		res[2] = m[2] - scalar;
		res[3] = m[3] - scalar;
		res[4] = m[4] - scalar;
		res[5] = m[5] - scalar;
		res[6] = m[6] - scalar;
		res[7] = m[7] - scalar;
		res[8] = m[8] - scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator-(const Matrix<3, 3, T> &m1, const Matrix<3, 3, T> &m2)
    {
		Matrix<3, 3, T> res;
		res[0] = m1[0] - m2[0];
		res[1] = m1[1] - m2[1];
		res[2] = m1[2] - m2[2];
		res[3] = m1[3] - m2[3];
		res[4] = m1[4] - m2[4];
		res[5] = m1[5] - m2[5];
		res[6] = m1[6] - m2[6];
		res[7] = m1[7] - m2[7];
		res[8] = m1[8] - m2[8];
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator*(const Matrix<3, 3, T> &m, T scalar)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] * scalar;
		res[1] = m[1] * scalar;
		res[2] = m[2] * scalar;
		res[3] = m[3] * scalar;
		res[4] = m[4] * scalar;
		res[5] = m[5] * scalar;
		res[6] = m[6] * scalar;
		res[7] = m[7] * scalar;
		res[8] = m[8] * scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator*(T scalar, const Matrix<3, 3, T> &m)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] * scalar;
		res[1] = m[1] * scalar;
		res[2] = m[2] * scalar;
		res[3] = m[3] * scalar;
		res[4] = m[4] * scalar;
		res[5] = m[5] * scalar;
		res[6] = m[6] * scalar;
		res[7] = m[7] * scalar;
		res[8] = m[8] * scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator*(const Matrix<3, 3, T> &m1, const Matrix<3, 3, T> &m2)
    {
		Matrix<3, 3, T> res;
		res[0] = m1[0] * m2[0];
		res[1] = m1[1] * m2[1];
		res[2] = m1[2] * m2[2];
		res[3] = m1[3] * m2[3];
		res[4] = m1[4] * m2[4];
		res[5] = m1[5] * m2[5];
		res[6] = m1[6] * m2[6];
		res[7] = m1[7] * m2[7];
		res[8] = m1[8] * m2[8];
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator/(const Matrix<3, 3, T> &m, T scalar)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] / scalar;
		res[1] = m[1] / scalar;
		res[2] = m[2] / scalar;
		res[3] = m[3] / scalar;
		res[4] = m[4] / scalar;
		res[5] = m[5] / scalar;
		res[6] = m[6] / scalar;
		res[7] = m[7] / scalar;
		res[8] = m[8] / scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator/(T scalar, const Matrix<3, 3, T> &m)
    {
		Matrix<3, 3, T> res;
		res[0] = m[0] / scalar;
		res[1] = m[1] / scalar;
		res[2] = m[2] / scalar;
		res[3] = m[3] / scalar;
		res[4] = m[4] / scalar;
		res[5] = m[5] / scalar;
		res[6] = m[6] / scalar;
		res[7] = m[7] / scalar;
		res[8] = m[8] / scalar;
		return res;
	}

    template<typename T>
    Matrix<3, 3, T> operator/(const Matrix<3, 3, T> &m1, const Matrix<3, 3, T> &m2)
    {
		Matrix<3, 3, T> res;
	
		res[0] = m1[0] / m2[0];
		res[1] = m1[1] / m2[1];
		res[2] = m1[2] / m2[2];
		res[3] = m1[3] / m2[3];
		res[4] = m1[4] / m2[4];
		res[5] = m1[5] / m2[5];
		res[6] = m1[6] / m2[6];
		res[7] = m1[7] / m2[7];
		res[8] = m1[8] / m2[8];
		return res;
	}

	// comparison operators

    template<typename T>
	MAFT_CONSTEXPR bool Maft::operator==(const Matrix<3, 3, T> &m1, const Matrix<3, 3, T> &m2)
	{
		return	m1[0] == m2[0] &&
				m1[1] == m2[1] &&
				m1[2] == m2[2] &&
				m1[3] == m2[3] &&
				m1[4] == m2[4] &&
				m1[5] == m2[5] &&
				m1[6] == m2[6] &&
				m1[7] == m2[7] &&
				m1[8] == m2[8];
	}

	template<typename T>
	MAFT_CONSTEXPR bool Maft::operator!=(const Matrix<3, 3, T> &m1, const Matrix<3, 3, T> &m2)
	{
		return	m1[0] != m2[0] &&
				m1[1] != m2[1] &&
				m1[2] != m2[2] &&
				m1[3] != m2[3] &&
				m1[4] != m2[4] &&
				m1[5] != m2[5] &&
				m1[6] != m2[6] &&
				m1[7] != m2[7] &&
				m1[8] != m2[8];
	}

	// print

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<3, 3, T>& m)
	{
		os  << "[" << m(0, 0) << ", " << m(0, 1) << ", " << m(0, 2) << "]\n"
			<< "[" << m(1, 0) << ", " << m(1, 1) << ", " << m(1, 2) << "]\n"
			<< "[" << m(2, 0) << ", " << m(2, 1) << ", " << m(2, 2) << "]";
		return os;
	}
}
