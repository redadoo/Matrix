#pragma once

namespace Maft
{
	// constructors

	template<typename T>
	MAFT_CONSTEXPR Matrix<4, 4, T>::Matrix(const T& x)
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
		this->data[9] = x;
		this->data[10] = x;
		this->data[11] = x;
		this->data[12] = x;
		this->data[13] = x;
		this->data[14] = x;
		this->data[15] = x;
	}

	template<typename T>
	MAFT_CONSTEXPR Matrix<4, 4, T>::Matrix(    
		T m00, T m10, T m20, T m30,
		T m01, T m11, T m21, T m31,
		T m02, T m12, T m22, T m32,
		T m03, T m13, T m23, T m33)
	{
		this->data[0]  = m00; 
		this->data[1]  = m10; 
		this->data[2]  = m20; 
		this->data[3]  = m30;
		this->data[4]  = m01;
		this->data[5]  = m11; 
		this->data[6]  = m21;
		this->data[7]  = m31;
		this->data[8]  = m02; 
		this->data[9]  = m12;
		this->data[10] = m22;
		this->data[11] = m32;
		this->data[12] = m03;
		this->data[13] = m13;
		this->data[14] = m23;
		this->data[15] = m33;
	}
	
	template<typename T>
	MAFT_CONSTEXPR Matrix<4, 4, T>::Matrix(const Matrix<4, 4, T>& other)
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
		this->data[9] = other.data[9];
		this->data[10] = other.data[10];
		this->data[11] = other.data[11];
		this->data[12] = other.data[12];
		this->data[13] = other.data[13];
		this->data[14] = other.data[14];
		this->data[15] = other.data[15];
	}

	// assignment operators (matrix matrix)

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator=(const Matrix<4, 4, T> &other)
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
		this->data[9] = other.data[9];
		this->data[10] = other.data[10];
		this->data[11] = other.data[11];
		this->data[12] = other.data[12];
		this->data[13] = other.data[13];
		this->data[14] = other.data[14];
		this->data[15] = other.data[15];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator+=(const Matrix<4, 4, T> &other)
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
		this->data[9] += other.data[9];
		this->data[10] += other.data[10];
		this->data[11] += other.data[11];
		this->data[12] += other.data[12];
		this->data[13] += other.data[13];
		this->data[14] += other.data[14];
		this->data[15] += other.data[15];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator-=(const Matrix<4, 4, T> &other)
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
		this->data[9] -= other.data[9];
		this->data[10] -= other.data[10];
		this->data[11] -= other.data[11];
		this->data[12] -= other.data[12];
		this->data[13] -= other.data[13];
		this->data[14] -= other.data[14];
		this->data[15] -= other.data[15];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator*=(const Matrix<4, 4, T> &other)
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
		this->data[9] *= other.data[9];
		this->data[10] *= other.data[10];
		this->data[11] *= other.data[11];
		this->data[12] *= other.data[12];
		this->data[13] *= other.data[13];
		this->data[14] *= other.data[14];
		this->data[15] *= other.data[15];
		return *this;
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator/=(const Matrix<4, 4, T> &other)
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
		this->data[9] /= other.data[9];
		this->data[10] /= other.data[10];
		this->data[11] /= other.data[11];
		this->data[12] /= other.data[12];
		this->data[13] /= other.data[13];
		this->data[14] /= other.data[14];
		this->data[15] /= other.data[15];
		return *this;
	}

	// assignment operators (matrix scalar)

	template <typename T>
	template <typename U>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator+=(U s)
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
		this->data[9] += s;
		this->data[10] += s;
		this->data[11] += s;
		this->data[12] += s;
		this->data[13] += s;
		this->data[14] += s;
		this->data[15] += s;
		return *this;
	}

	template <typename T>
	template <typename U>
	MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator-=(U s)
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
		this->data[9] -= s;
		this->data[10] -= s;
		this->data[11] -= s;
		this->data[12] -= s;
		this->data[13] -= s;
		this->data[14] -= s;
		this->data[15] -= s;
		return *this;
	}

	template <typename T>
	template <typename U>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator*=(U s)
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
		this->data[9] *= s;
		this->data[10] *= s;
		this->data[11] *= s;
		this->data[12] *= s;
		this->data[13] *= s;
		this->data[14] *= s;
		this->data[15] *= s;
		return *this;
	}

	template <typename T>
	template <typename U>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> &Matrix<4, 4, T>::operator/=(U s)
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
		this->data[9] /= s;
		this->data[10] /= s;
		this->data[11] /= s;
		this->data[12] /= s;
		this->data[13] /= s;
		this->data[14] /= s;
		this->data[15] /= s;
		return *this;
	}
	
	//  increment / decrement
	
	template <typename T>
	Matrix<4, 4, T>& Matrix<4, 4, T>::operator++()
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
		this->data[9]++;
		this->data[10]++;
		this->data[11]++;
		this->data[12]++;
		this->data[13]++;
		this->data[14]++;
		this->data[15]++;
		return *this;
	}

	template <typename T>
	Matrix<4, 4, T>& Matrix<4, 4, T>::operator--()
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
		this->data[9]--;
		this->data[10]--;
		this->data[11]--;
		this->data[12]--;
		this->data[13]--;
		this->data[14]--;
		this->data[15]--;
		return *this;
	}
	
	template <typename T>
	Matrix<4, 4, T> Matrix<4, 4, T>::operator++(int)
	{
		Matrix<4, 4, T> res(*this);
		++*this;
		return res;
	}

	template <typename T>
	Matrix<4, 4, T> Matrix<4, 4, T>::operator--(int)
	{
		Matrix<4, 4, T> res(*this);
		--*this;
		return res;
	}

	//  element access
	
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<4, 4, T>::operator()(std::size_t col, std::size_t row)
	{
		assert(row < 4 && col < 4);
		return data[col * 4 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<4, 4, T>::operator()(std::size_t col, std::size_t row) const
	{
		assert(row < 4 && col < 4);
		return data[col * 4 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<4, 4, T>::operator[](std::size_t index)
	{
		assert(index < 16);
		return data[index];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<4, 4, T>::operator[](std::size_t index) const
	{
		assert(index < 16);
		return data[index];
	}

	//  matrix Operations

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::inverse()
	{
		
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Add(const Matrix<4, 4, T>& other)
	{
		(*this) += other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Scale(const Matrix<4, 4, T>& other)
	{
		(*this) *= other;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Scale(const T& scalar)
	{
		(*this) *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Subtract(const Matrix<4, 4, T>& other) 
	{
		(*this) -= other;
	}


	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> Matrix<4, 4, T>::get_column(std::size_t index) const
    {
		assert(index < 4);
		Vector<4, T> column;
		column[0] = this->data[index * 4 + 0];
		column[1] = this->data[index * 4 + 1];
		column[2] = this->data[index * 4 + 2];
		column[3] = this->data[index * 4 + 3];
		return column;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::set_column(std::size_t index, Vector<4, T> v)
    {
		assert(index < 4);
		this->data[index * 4 + 0] = v[0];
		this->data[index * 4 + 1] = v[1];
		this->data[index * 4 + 2] = v[2];
		this->data[index * 4 + 3] = v[3];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::swap_column(int first_column_index, int second_column_index)
	{
		std::swap((*this)(0, first_column_index), (*this)(0, second_column_index));
		std::swap((*this)(1, first_column_index), (*this)(1, second_column_index));
		std::swap((*this)(2, first_column_index), (*this)(2, second_column_index));
		std::swap((*this)(3, first_column_index), (*this)(3, second_column_index));
	}

    template <typename T>
    MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::swap_row(int first_row_index, int second_row_index)
	{
		std::swap((*this)(first_row_index, 0), (*this)(second_row_index, 0));
		std::swap((*this)(first_row_index, 1), (*this)(second_row_index, 1));
		std::swap((*this)(first_row_index, 2), (*this)(second_row_index, 2));
		std::swap((*this)(first_row_index, 3), (*this)(second_row_index, 3));
	}


	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> Matrix<4, 4, T>::transpose() const
	{
		return Matrix<4, 4, T>(
			(*this)(0,0), (*this)(1,0), (*this)(2,0), (*this)(3,0),
			(*this)(0,1), (*this)(1,1), (*this)(2,1), (*this)(3,1),
			(*this)(0,2), (*this)(1,2), (*this)(2,2), (*this)(3,2),
			(*this)(0,3), (*this)(1,3), (*this)(2,3), (*this)(3,3)
		);
	}

	template<typename T>
	MAFT_CONSTEXPR T Matrix<4, 4, T>::trace() const
	{
		return (*this)(0,0) + (*this)(1,1) + (*this)(2,2) + (*this)(3,3);
	}

	template <typename T>
    MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T Matrix<4, 4, T>::determinant() const
    {
		return
			(*this)(0,0) * (
				(*this)(1,1) * ((*this)(2,2)*(*this)(3,3) - (*this)(2,3)*(*this)(3,2))
			- (*this)(1,2) * ((*this)(2,1)*(*this)(3,3) - (*this)(2,3)*(*this)(3,1))
			+ (*this)(1,3) * ((*this)(2,1)*(*this)(3,2) - (*this)(2,2)*(*this)(3,1))
			)
		- (*this)(0,1) * (
				(*this)(1,0) * ((*this)(2,2)*(*this)(3,3) - (*this)(2,3)*(*this)(3,2))
			- (*this)(1,2) * ((*this)(2,0)*(*this)(3,3) - (*this)(2,3)*(*this)(3,0))
			+ (*this)(1,3) * ((*this)(2,0)*(*this)(3,2) - (*this)(2,2)*(*this)(3,0))
			)
		+ (*this)(0,2) * (
				(*this)(1,0) * ((*this)(2,1)*(*this)(3,3) - (*this)(2,3)*(*this)(3,1))
			- (*this)(1,1) * ((*this)(2,0)*(*this)(3,3) - (*this)(2,3)*(*this)(3,0))
			+ (*this)(1,3) * ((*this)(2,0)*(*this)(3,1) - (*this)(2,1)*(*this)(3,0))
			)
		- (*this)(0,3) * (
				(*this)(1,0) * ((*this)(2,1)*(*this)(3,2) - (*this)(2,2)*(*this)(3,1))
			- (*this)(1,1) * ((*this)(2,0)*(*this)(3,2) - (*this)(2,2)*(*this)(3,0))
			+ (*this)(1,2) * ((*this)(2,0)*(*this)(3,1) - (*this)(2,1)*(*this)(3,0))
			);
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> Matrix<4, 4, T>::row_echelon() const
	{
		Matrix<4, 4, T> res(*this);

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
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Vector<4, T> Matrix<4, 4, T>::multiply_vector(const Vector<4, T>& v)
	{
		Vector<4, T> result;
		result.x = (*this)(0,0) * v.x + (*this)(0,1) * v.y + (*this)(0,2) * v.z + (*this)(0,3) * v.w;
		result.y = (*this)(1,0) * v.x + (*this)(1,1) * v.y + (*this)(1,2) * v.z + (*this)(1,3) * v.w;
		result.z = (*this)(2,0) * v.x + (*this)(2,1) * v.y + (*this)(2,2) * v.z + (*this)(2,3) * v.w;
		result.w = (*this)(3,0) * v.x + (*this)(3,1) * v.y + (*this)(3,2) * v.z + (*this)(3,3) * v.w;
		return result;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> Matrix<4, 4, T>::multiply_matrix(const Matrix<4, 4, T>& m) const
	{
		Matrix<4, 4, T> result;

		result(0,0) = (*this)(0,0)*m(0,0) + (*this)(1,0)*m(0,1) + (*this)(2,0)*m(0,2) + (*this)(3,0)*m(0,3);
		result(0,1) = (*this)(0,0)*m(1,0) + (*this)(1,0)*m(1,1) + (*this)(2,0)*m(1,2) + (*this)(3,0)*m(1,3);
		result(0,2) = (*this)(0,0)*m(2,0) + (*this)(1,0)*m(2,1) + (*this)(2,0)*m(2,2) + (*this)(3,0)*m(2,3);
		result(0,3) = (*this)(0,0)*m(3,0) + (*this)(1,0)*m(3,1) + (*this)(2,0)*m(3,2) + (*this)(3,0)*m(3,3);
		result(1,0) = (*this)(0,1)*m(0,0) + (*this)(1,1)*m(0,1) + (*this)(2,1)*m(0,2) + (*this)(3,1)*m(0,3);
		result(1,1) = (*this)(0,1)*m(1,0) + (*this)(1,1)*m(1,1) + (*this)(2,1)*m(1,2) + (*this)(3,1)*m(1,3);
		result(1,2) = (*this)(0,1)*m(2,0) + (*this)(1,1)*m(2,1) + (*this)(2,1)*m(2,2) + (*this)(3,1)*m(2,3);
		result(1,3) = (*this)(0,1)*m(3,0) + (*this)(1,1)*m(3,1) + (*this)(2,1)*m(3,2) + (*this)(3,1)*m(3,3);
		result(2,0) = (*this)(0,2)*m(0,0) + (*this)(1,2)*m(0,1) + (*this)(2,2)*m(0,2) + (*this)(3,2)*m(0,3);
		result(2,1) = (*this)(0,2)*m(1,0) + (*this)(1,2)*m(1,1) + (*this)(2,2)*m(1,2) + (*this)(3,2)*m(1,3);
		result(2,2) = (*this)(0,2)*m(2,0) + (*this)(1,2)*m(2,1) + (*this)(2,2)*m(2,2) + (*this)(3,2)*m(2,3);
		result(2,3) = (*this)(0,2)*m(3,0) + (*this)(1,2)*m(3,1) + (*this)(2,2)*m(3,2) + (*this)(3,2)*m(3,3);
		result(3,0) = (*this)(0,3)*m(0,0) + (*this)(1,3)*m(0,1) + (*this)(2,3)*m(0,2) + (*this)(3,3)*m(0,3);
		result(3,1) = (*this)(0,3)*m(1,0) + (*this)(1,3)*m(1,1) + (*this)(2,3)*m(1,2) + (*this)(3,3)*m(1,3);
		result(3,2) = (*this)(0,3)*m(2,0) + (*this)(1,3)*m(2,1) + (*this)(2,3)*m(2,2) + (*this)(3,3)*m(2,3);
		result(3,3) = (*this)(0,3)*m(3,0) + (*this)(1,3)*m(3,1) + (*this)(2,3)*m(3,2) + (*this)(3,3)*m(3,3);

		return result;
	}

	// static utility functions

	template<typename T>
	MAFT_CONSTEXPR Matrix<4,4,T> Matrix<4, 4, T>::Identity()
	{
		Matrix<4,4,T> I{};
		for(int i=0;i<4;++i)
			I(i,i) = T(1);
		return I;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> Matrix<4, 4, T>::Lerp(const Matrix<4, 4, T> &a, const Matrix<4, 4, T> &b, float t)
	{
		t = clamp01(t);
		Matrix<4, 4, T> result;

		result.data[0] = static_cast<T>(a.data[0] + (b.data[0] - a.data[0]) * t);
		result.data[1] = static_cast<T>(a.data[1] + (b.data[1] - a.data[1]) * t);
		result.data[2] = static_cast<T>(a.data[2] + (b.data[2] - a.data[2]) * t);
		result.data[3] = static_cast<T>(a.data[3] + (b.data[3] - a.data[3]) * t);
		result.data[4] = static_cast<T>(a.data[4] + (b.data[4] - a.data[4]) * t);
		result.data[5] = static_cast<T>(a.data[5] + (b.data[5] - a.data[5]) * t);
		result.data[6] = static_cast<T>(a.data[6] + (b.data[6] - a.data[6]) * t);
		result.data[7] = static_cast<T>(a.data[7] + (b.data[7] - a.data[7]) * t);
		result.data[8] = static_cast<T>(a.data[8] + (b.data[8] - a.data[8]) * t);
		result.data[9] = static_cast<T>(a.data[9] + (b.data[9] - a.data[9]) * t);
		result.data[10] = static_cast<T>(a.data[10] + (b.data[10] - a.data[10]) * t);
		result.data[11] = static_cast<T>(a.data[11] + (b.data[11] - a.data[11]) * t);
		result.data[12] = static_cast<T>(a.data[12] + (b.data[12] - a.data[12]) * t);
		result.data[13] = static_cast<T>(a.data[13] + (b.data[13] - a.data[13]) * t);
		result.data[14] = static_cast<T>(a.data[14] + (b.data[14] - a.data[14]) * t);
		result.data[15] = static_cast<T>(a.data[15] + (b.data[15] - a.data[15]) * t);
		return result;
	}
	
	//  unary operators
	
	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> operator+(const Matrix<4, 4, T> &m)
	{
		return m;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T> operator-(const Matrix<4, 4, T> &m)
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
		m[9] = -m[3];
		m[10] = -m[10]; 
		m[11] = -m[11]; 
		m[12] = -m[12]; 
		m[13] = -m[13]; 
		m[14] = -m[14]; 
		m[15] = -m[15]; 
		return m;
	}

	// binary operators 

	template<typename T>
	Matrix<4, 4, T> operator+(const Matrix<4, 4, T> &m, T scalar)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] + scalar;
		res[1] = m[1] + scalar;
		res[2] = m[2] + scalar;
		res[3] = m[3] + scalar;
		res[4] = m[4] + scalar;
		res[5] = m[5] + scalar;
		res[6] = m[6] + scalar;
		res[7] = m[7] + scalar;
		res[8] = m[8] + scalar;
		res[9] = m[9] + scalar;
		res[10] = m[10] + scalar;
		res[11] = m[11] + scalar;
		res[12] = m[12] + scalar;
		res[13] = m[13] + scalar;
		res[14] = m[14] + scalar;
		res[15] = m[15] + scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator+(T scalar, const Matrix<4, 4, T> &m)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] + scalar;
		res[1] = m[1] + scalar;
		res[2] = m[2] + scalar;
		res[3] = m[3] + scalar;
		res[4] = m[4] + scalar;
		res[5] = m[5] + scalar;
		res[6] = m[6] + scalar;
		res[7] = m[7] + scalar;
		res[8] = m[8] + scalar;
		res[9] = m[9] + scalar;
		res[10] = m[10] + scalar;
		res[11] = m[11] + scalar;
		res[12] = m[12] + scalar;
		res[13] = m[13] + scalar;
		res[14] = m[14] + scalar;
		res[15] = m[15] + scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator+(const Matrix<4, 4, T> &m1, const Matrix<4, 4, T> &m2)
	{
		Matrix<4, 4, T> res;
		res[0] = m1[0] + m2[0];
		res[1] = m1[1] + m2[1];
		res[2] = m1[2] + m2[2];
		res[3] = m1[3] + m2[3];
		res[4] = m1[4] + m2[4];
		res[5] = m1[5] + m2[5];
		res[6] = m1[6] + m2[6];
		res[7] = m1[7] + m2[7];
		res[8] = m1[8] + m2[8];
		res[9] = m1[9] + m2[9];
		res[10] = m1[10] + m2[10];
		res[11] = m1[11] + m2[11];
		res[12] = m1[12] + m2[12];
		res[13] = m1[13] + m2[13];
		res[14] = m1[14] + m2[14];
		res[15] = m1[15] + m2[15];
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator-(const Matrix<4, 4, T> &m, T scalar)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] - scalar;
		res[1] = m[1] - scalar;
		res[2] = m[2] - scalar;
		res[3] = m[3] - scalar;
		res[4] = m[4] - scalar;
		res[5] = m[5] - scalar;
		res[6] = m[6] - scalar;
		res[7] = m[7] - scalar;
		res[8] = m[8] - scalar;
		res[9] = m[9] - scalar;
		res[10] = m[10] - scalar;
		res[11] = m[11] - scalar;
		res[12] = m[12] - scalar;
		res[13] = m[13] - scalar;
		res[14] = m[14] - scalar;
		res[15] = m[15] - scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator-(T scalar, const Matrix<4, 4, T> &m)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] - scalar;
		res[1] = m[1] - scalar;
		res[2] = m[2] - scalar;
		res[3] = m[3] - scalar;
		res[4] = m[4] - scalar;
		res[5] = m[5] - scalar;
		res[6] = m[6] - scalar;
		res[7] = m[7] - scalar;
		res[8] = m[8] - scalar;
		res[9] = m[9] - scalar;
		res[10] = m[10] - scalar;
		res[11] = m[11] - scalar;
		res[12] = m[12] - scalar;
		res[13] = m[13] - scalar;
		res[14] = m[14] - scalar;
		res[15] = m[15] - scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator-(const Matrix<4, 4, T> &m1, const Matrix<4, 4, T> &m2)
	{
		Matrix<4, 4, T> res;
		res[0] = m1[0] - m2[0];
		res[1] = m1[1] - m2[1];
		res[2] = m1[2] - m2[2];
		res[3] = m1[3] - m2[3];
		res[4] = m1[4] - m2[4];
		res[5] = m1[5] - m2[5];
		res[6] = m1[6] - m2[6];
		res[7] = m1[7] - m2[7];
		res[8] = m1[8] - m2[8];
		res[9] = m1[9] - m2[9];
		res[10] = m1[10] - m2[10];
		res[11] = m1[11] - m2[11];
		res[12] = m1[12] - m2[12];
		res[13] = m1[13] - m2[13];
		res[14] = m1[14] - m2[14];
		res[15] = m1[15] - m2[15];
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator*(const Matrix<4, 4, T> &m, T scalar)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] * scalar;
		res[1] = m[1] * scalar;
		res[2] = m[2] * scalar;
		res[3] = m[3] * scalar;
		res[4] = m[4] * scalar;
		res[5] = m[5] * scalar;
		res[6] = m[6] * scalar;
		res[7] = m[7] * scalar;
		res[8] = m[8] * scalar;
		res[9] = m[9] * scalar;
		res[10] = m[10] * scalar;
		res[11] = m[11] * scalar;
		res[12] = m[12] * scalar;
		res[13] = m[13] * scalar;
		res[14] = m[14] * scalar;
		res[15] = m[15] * scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator*(T scalar, const Matrix<4, 4, T> &m)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] * scalar;
		res[1] = m[1] * scalar;
		res[2] = m[2] * scalar;
		res[3] = m[3] * scalar;
		res[4] = m[4] * scalar;
		res[5] = m[5] * scalar;
		res[6] = m[6] * scalar;
		res[7] = m[7] * scalar;
		res[8] = m[8] * scalar;
		res[9] = m[9] * scalar;
		res[10] = m[10] * scalar;
		res[11] = m[11] * scalar;
		res[12] = m[12] * scalar;
		res[13] = m[13] * scalar;
		res[14] = m[14] * scalar;
		res[15] = m[15] * scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator*(const Matrix<4, 4, T> &a, const Matrix<4, 4, T> &b)
	{
		Matrix<4,4,T> r;

		for(int row=0; row<4; ++row)
			for(int col=0; col<4; ++col)
			{
				r(row,col) = 0;
				for(int k=0; k<4; ++k)
					r(row,col) += a(row,k) * b(k,col);
			}
		return r;
	}

	template<typename T>
	Matrix<4, 4, T> operator/(const Matrix<4, 4, T> &m, T scalar)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] / scalar;
		res[1] = m[1] / scalar;
		res[2] = m[2] / scalar;
		res[3] = m[3] / scalar;
		res[4] = m[4] / scalar;
		res[5] = m[5] / scalar;
		res[6] = m[6] / scalar;
		res[7] = m[7] / scalar;
		res[8] = m[8] / scalar;
		res[9] = m[9] / scalar;
		res[10] = m[10] / scalar;
		res[11] = m[11] / scalar;
		res[12] = m[12] / scalar;
		res[13] = m[13] / scalar;
		res[14] = m[14] / scalar;
		res[15] = m[15] / scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator/(T scalar, const Matrix<4, 4, T> &m)
	{
		Matrix<4, 4, T> res;
		res[0] = m[0] / scalar;
		res[1] = m[1] / scalar;
		res[2] = m[2] / scalar;
		res[3] = m[3] / scalar;
		res[4] = m[4] / scalar;
		res[5] = m[5] / scalar;
		res[6] = m[6] / scalar;
		res[7] = m[7] / scalar;
		res[8] = m[8] / scalar;
		res[9] = m[9] / scalar;
		res[10] = m[10] / scalar;
		res[11] = m[11] / scalar;
		res[12] = m[12] / scalar;
		res[13] = m[13] / scalar;
		res[14] = m[14] / scalar;
		res[15] = m[15] / scalar;
		return res;
	}

	template<typename T>
	Matrix<4, 4, T> operator/(const Matrix<4, 4, T> &m1, const Matrix<4, 4, T> &m2)
	{
		Matrix<4, 4, T> res;
	
		res[0] = m1[0] / m2[0];
		res[1] = m1[1] / m2[1];
		res[2] = m1[2] / m2[2];
		res[3] = m1[3] / m2[3];
		res[4] = m1[4] / m2[4];
		res[5] = m1[5] / m2[5];
		res[6] = m1[6] / m2[6];
		res[7] = m1[7] / m2[7];
		res[8] = m1[8] / m2[8];
		res[9] = m1[9] / m2[9];
		res[10] = m1[10] / m2[10];
		res[11] = m1[11] / m2[11];
		res[12] = m1[12] / m2[12];
		res[13] = m1[13] / m2[13];
		res[14] = m1[14] / m2[14];
		res[15] = m1[15] / m2[15];
		return res;
	}

	// comparison operators

	template<typename T>
	MAFT_CONSTEXPR bool Maft::operator==(const Matrix<4, 4, T> &m1, const Matrix<4, 4, T> &m2)
	{
		return	m1[0] == m2[0] &&
				m1[1] == m2[1] &&
				m1[2] == m2[2] &&
				m1[3] == m2[3] &&
				m1[4] == m2[4] &&
				m1[5] == m2[5] &&
				m1[6] == m2[6] &&
				m1[7] == m2[7] &&
				m1[8] == m2[8] &&
				m1[9] == m2[9] &&
				m1[10] == m2[10] &&
				m1[11] == m2[11] &&
				m1[12] == m2[12] &&
				m1[13] == m2[13] &&
				m1[14] == m2[14] &&
				m1[15] == m2[15];
	}

	template<typename T>
	MAFT_CONSTEXPR bool Maft::operator!=(const Matrix<4, 4, T> &m1, const Matrix<4, 4, T> &m2)
	{
		return	m1[0] != m2[0] &&
				m1[1] != m2[1] &&
				m1[2] != m2[2] &&
				m1[3] != m2[3] &&
				m1[4] != m2[4] &&
				m1[5] != m2[5] &&
				m1[6] != m2[6] &&
				m1[7] != m2[7] &&
				m1[8] != m2[8] &&
				m1[9] != m2[9] &&
				m1[10] != m2[10] &&
				m1[11] != m2[11] &&
				m1[12] != m2[12] &&
				m1[13] != m2[13] &&
				m1[14] != m2[14] &&
				m1[15] != m2[15];
	}

	// print
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<4, 4, T>& m)
	{
		os << "[" << (m(0,0)) << ", " << (m(1,0)) << ", " << (m(2,0)) << ", " << (m(3,0)) << "]\n"
		   << "[" << (m(0,1)) << ", " << (m(1,1)) << ", " << (m(2,1)) << ", " << (m(3,1)) << "]\n"
		   << "[" << (m(0,2)) << ", " << (m(1,2)) << ", " << (m(2,2)) << ", " << (m(3,2)) << "]\n"
		   << "[" << (m(0,3)) << ", " << (m(1,3)) << ", " << (m(2,3)) << ", " << (m(3,3)) << "]";
		
		return os;
	}
}
