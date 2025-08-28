#pragma once

#include "Matrix.hpp"

// TODO: Research SIMD optimization and implement it
namespace Maft
{
	// constructors

	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2, T>::Matrix(const T& x)
	{
		data[0] = x;
		data[1] = x;
		data[2] = x;
		data[3] = x;
	}

	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2, T>::Matrix(T m00, T m10, T m01, T m11)
	{
		data[0] = m00;
		data[1] = m10;
		data[2] = m01;
		data[3] = m11;
	}
	
	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2, T>::Matrix(const Matrix<2, 2, T>& other)
	{
		this->data[0] = other.data[0];
		this->data[1] = other.data[1];
		this->data[2] = other.data[2];
		this->data[3] = other.data[3];
	}

	// assignment operators (matrix matrix)

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator=(const Matrix<2, 2, T> &other)
	{
		this->data[0] = other.data[0];
		this->data[1] = other.data[1];
		this->data[2] = other.data[2];
		this->data[3] = other.data[3];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator+=(const Matrix<2, 2, T> &other)
	{
		this->data[0] += other.data[0];
		this->data[1] += other.data[1];
		this->data[2] += other.data[2];
		this->data[3] += other.data[3];
		return *this;
	}

    template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator-=(const Matrix<2, 2, T> &other)
	{
		this->data[0] -= other.data[0];
		this->data[1] -= other.data[1];
		this->data[2] -= other.data[2];
		this->data[3] -= other.data[3];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator*=(const Matrix<2, 2, T> &other)
	{
		this->data[0] *= other.data[0];
		this->data[1] *= other.data[1];
		this->data[2] *= other.data[2];
		this->data[3] *= other.data[3];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator/=(const Matrix<2, 2, T> &other)
	{
		this->data[0] /= other.data[0];
		this->data[1] /= other.data[1];
		this->data[2] /= other.data[2];
		this->data[3] /= other.data[3];
		return *this;
	}

	// assignment operators (matrix scalar)

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator+=(U s)
    {
		this->data[0] += s;
		this->data[1] += s;
		this->data[2] += s;
		this->data[3] += s;
		return *this;
	}

    template <typename T>
    template <typename U>
    MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator-=(U s)
    {
		this->data[0] -= s;
		this->data[1] -= s;
		this->data[2] -= s;
		this->data[3] -= s;;
		return *this;
	}

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator*=(U s)
    {
		this->data[0] *= s;
		this->data[1] *= s;
		this->data[2] *= s;
		this->data[3] *= s;
		return *this;
	}

	template <typename T>
    template <typename U>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> &Matrix<2, 2, T>::operator/=(U s)
    {
		this->data[0] /= s;
		this->data[1] /= s;
		this->data[2] /= s;
		this->data[3] /= s;
		return *this;
	}
	
	//  increment / decrement
	
	template <typename T>
	Matrix<2, 2, T>& Matrix<2, 2, T>::operator++()
	{
		this->data[0]++;
		this->data[1]++;
		this->data[2]++;
		this->data[3]++;
		return *this;
	}

	template <typename T>
	Matrix<2, 2, T>& Matrix<2, 2, T>::operator--()
	{
		this->data[0]--;
		this->data[1]--;
		this->data[2]--;
		this->data[3]--;
		return *this;
	}
	
	template <typename T>
	Matrix<2, 2, T> Matrix<2, 2, T>::operator++(int)
	{
		Matrix<2, 2, T> res(*this);
		++*this;
		return res;
	}

	template <typename T>
	Matrix<2, 2, T> Matrix<2, 2, T>::operator--(int)
	{
		Matrix<2, 2, T> res(*this);
		--*this;
		return res;
	}

	//  element access
	
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<2, 2, T>::operator()(std::size_t col, std::size_t row)
	{
		assert(row < 2 && col < 2);
		return data[col * 2 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<2, 2, T>::operator()(std::size_t col, std::size_t row) const
	{
		assert(row < 2 && col < 2);
		return data[col * 2 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<2, 2, T>::operator[](std::size_t index)
	{
		assert(index < 2);
		return data[index];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<2, 2, T>::operator[](std::size_t index) const
	{
		assert(index < 2);
		return data[index];
	}

	//  matrix Operations

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::inverse()
	{
		if (determinant() == 0)
			return;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Add(const Matrix& other)
	{
		(*this) += other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Scale(const Matrix& other)
	{
		(*this) *= other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Scale(const T& scalar)
	{
		(*this) *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Subtract(const Matrix& other) 
	{
		(*this) -= other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::swap_row()
	{
		std::swap((*this)(0, 0), (*this)(1, 0));
		std::swap((*this)(0, 1), (*this)(1, 1));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::swap_column()
	{
		std::swap((*this)(0, 0), (*this)(0, 1));
		std::swap((*this)(1, 0), (*this)(1, 1));
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> Matrix<2, 2, T>::transpose() const
	{
		return Matrix<2, 2, T>({
			{ (*this)(0,0), (*this)(1,0) },
			{ (*this)(0,1), (*this)(1,1) }
		});
	}

	template<typename T>
	MAFT_CONSTEXPR T Matrix<2, 2, T>::trace() const
	{
    	return (*this)(0,0) + (*this)(1,1);
	}
    
	template <typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Matrix<2, 2, T>::determinant() const
    {
		return (*this)(0,0) * (*this)(1,1) - (*this)(0,1) * (*this)(1,0);  
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> Matrix<2, 2, T>::row_echelon() const
	{
		Matrix<2, 2, T> res(*this);

		if (res(0,0) == T(0) && res(1,0) != T(0)) 
		{
			std::swap(res(0,0), res(1,0));
			std::swap(res(0,1), res(1,1));
		}

		if (res(0,0) != T(0)) 
		{
			T factor = res(1,0) / res(0,0);
			res(1,0) -= factor * res(0,0);
			res(1,1) -= factor * res(0,1);
		}

		return res;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<2, T> Matrix<2, 2, T>::multiply_vector(const Vector<2, T>& v)
	{
		Vector<2, T> result;
		result.x = (*this)(0, 0) * v.x + (*this)(0, 1) * v.y;
		result.y = (*this)(1, 0) * v.x + (*this)(1, 1) * v.y;
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> Matrix<2, 2, T>::multiply_matrix(const Matrix<2, 2, T>& m) const
	{
		Matrix<2, 2, T> result;

		result(0,0) = (*this)(0,0) * m(0,0) + (*this)(1,0) * m(0,1);
		result(1,0) = (*this)(0,1) * m(0,0) + (*this)(1,1) * m(0,1);
		result(0,1) = (*this)(0,0) * m(1,0) + (*this)(1,0) * m(1,1);
		result(1,1) = (*this)(0,1) * m(1,0) + (*this)(1,1) * m(1,1);

		return result;
	}

	// static utility functions

	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2,T> Matrix<2, 2, T>::Identity()
	{
		Matrix<2, 2,T> I{};
		for(int i=0;i<2;++i)
			I(i,i) = T(1);
		return I;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> Matrix<2, 2, T>::Lerp(const Matrix<2, 2, T> &a, const Matrix<2, 2, T> &b, float t)
	{
		t = clamp01(t);
		Matrix<2, 2, T> result;

		result.data[0] = (a.data[0] + (b.data[0] - a.data[0]) * t);
		result.data[1] = (a.data[1] + (b.data[1] - a.data[1]) * t);
		result.data[2] = (a.data[2] + (b.data[2] - a.data[2]) * t);
		result.data[3] = (a.data[3] + (b.data[3] - a.data[3]) * t);

		return result;
	}
	
	//  unary operators
	
    template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> operator+(const Matrix<2, 2, T> &m)
    {
		return m;
	}

    template<typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> operator-(const Matrix<2, 2, T> &m)
    {
		m[0] = -m[0]; 
		m[1] = -m[1]; 
		m[2] = -m[2]; 
		m[3] = -m[3]; 
		return m;
	}

	// binary operators 

	template<typename T>
    Matrix<2, 2, T> operator+(const Matrix<2, 2, T> &m, T scalar)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] + scalar;
		res[1] = m[1] + scalar;
		res[2] = m[2] + scalar;
		res[3] = m[3] + scalar;
		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator+(T scalar, const Matrix<2, 2, T> &m)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] + scalar;
		res[1] = m[1] + scalar;
		res[2] = m[2] + scalar;
		res[3] = m[3] + scalar;
		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator+(const Matrix<2, 2, T> &m1, const Matrix<2, 2, T> &m2)
    {
		Matrix<2, 2, T> res;
		res[0] = m1[0] + m2[0];
		res[1] = m1[1] + m2[1];
		res[2] = m1[2] + m2[2];
		res[3] = m1[3] + m2[3];
		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator-(const Matrix<2, 2, T> &m, T scalar)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] - scalar;
		res[1] = m[1] - scalar;
		res[2] = m[2] - scalar;
		res[3] = m[3] - scalar;

		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator-(T scalar, const Matrix<2, 2, T> &m)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] - scalar;
		res[1] = m[1] - scalar;
		res[2] = m[2] - scalar;
		res[3] = m[3] - scalar;

		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator-(const Matrix<2, 2, T> &m1, const Matrix<2, 2, T> &m2)
    {
		Matrix<2, 2, T> res;
		res[0] = m1[0] - m2[0];
		res[1] = m1[1] - m2[1];
		res[2] = m1[2] - m2[2];
		res[3] = m1[3] - m2[3];

		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator*(const Matrix<2, 2, T> &m, T scalar)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] * scalar;
		res[1] = m[1] * scalar;
		res[2] = m[2] * scalar;
		res[3] = m[3] * scalar;
		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator*(T scalar, const Matrix<2, 2, T> &m)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] * scalar;
		res[1] = m[1] * scalar;
		res[2] = m[2] * scalar;
		res[3] = m[3] * scalar;
		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator*(const Matrix<2, 2, T> &m1, const Matrix<2, 2, T> &m2)
    {
		Matrix<2, 2, T> res;
		res[0] = m1[0] * m2[0];
		res[1] = m1[1] * m2[1];
		res[2] = m1[2] * m2[2];
		res[3] = m1[3] * m2[3];

		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator/(const Matrix<2, 2, T> &m, T scalar)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] / scalar;
		res[1] = m[1] / scalar;
		res[2] = m[2] / scalar;
		res[3] = m[3] / scalar;

		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator/(T scalar, const Matrix<2, 2, T> &m)
    {
		Matrix<2, 2, T> res;
		res[0] = m[0] / scalar;
		res[1] = m[1] / scalar;
		res[2] = m[2] / scalar;
		res[3] = m[3] / scalar;

		return res;
	}

    template<typename T>
    Matrix<2, 2, T> operator/(const Matrix<2, 2, T> &m1, const Matrix<2, 2, T> &m2)
    {
		Matrix<2, 2, T> res;
	
		res[0] = m1[0] / m2[0];
		res[1] = m1[1] / m2[1];
		res[2] = m1[2] / m2[2];
		res[3] = m1[3] / m2[3];

		return res;
	}

	// comparison operators

    template<typename T>
	MAFT_CONSTEXPR bool Maft::operator==(const Matrix<2, 2, T> &m1, const Matrix<2, 2, T> &m2)
	{
		return	m1[0] == m2[0] &&
				m1[1] == m2[1] &&
				m1[2] == m2[2] &&
				m1[3] == m2[3];
	}

	template<typename T>
	MAFT_CONSTEXPR bool Maft::operator!=(const Matrix<2, 2, T> &m1, const Matrix<2, 2, T> &m2)
	{
		return	m1[0] != m2[0] &&
				m1[1] != m2[1] &&
				m1[2] != m2[2] &&
				m1[3] != m2[3];
	}

	// print

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<2, 2, T>& m)
	{
		os  << "[" << m(0, 0) << ", " << m(0, 1) << "]\n"
			<< "[" << m(1, 0) << ", " << m(1, 1) << "]";
		return os;
	}
}
