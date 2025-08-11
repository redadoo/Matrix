#pragma once

// TODO: Research SIMD optimization and implement it
namespace Maft
{
	template<typename T>
	MAFT_CONSTEXPR Matrix<4, 4, T>::Matrix(
		T a11, T a12, T a13, T a14, 
		T a21, T a22, T a23, T a24, 
		T a31, T a32, T a33, T a34, 
		T a41, T a42, T a43, T a44)
	{
		this->data[0] = a11;
		this->data[1] = a12;
		this->data[2] = a13;
		this->data[3] = a14;
		this->data[4] = a21;
		this->data[5] = a22;
		this->data[6] = a23;
		this->data[7] = a24;
		this->data[8] = a31;
		this->data[9] = a32;
		this->data[10] = a33;
		this->data[11] = a34;
		this->data[12] = a41;
		this->data[13] = a42;
		this->data[14] = a43;
		this->data[15] = a44;
	}
	
	template<typename T>
	MAFT_CONSTEXPR Matrix<4, 4, T>::Matrix(const Matrix<4, 4, T>& other)
	{
		this->data = other.data;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<4, 4, T>::operator()(std::size_t row, std::size_t col)
	{
		assert(row < 4 && col < 4);
		return this->data[col * 4 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<4, 4, T>::operator()(std::size_t row, std::size_t col) const
	{
		return this->data[col * 4 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<4, 4, T>& Matrix<4, 4, T>::operator=(const Matrix<4, 4, T>& other)
	{
		this->data = other.data;
		return *this;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Matrix<4, 4, T>::operator==(const Matrix<4, 4, T>& other) const
	{
		return this->data == other.data;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Add(const Matrix<4, 4, T>& other)
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
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Scale(const Matrix<4, 4, T>& other)
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
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Scale(const T& scalar)
	{
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;
		this->data[3] *= scalar;
		this->data[4] *= scalar;
		this->data[5] *= scalar;
		this->data[6] *= scalar;
		this->data[7] *= scalar;
		this->data[8] *= scalar;
		this->data[9] *= scalar;
		this->data[10] *= scalar;
		this->data[11] *= scalar;
		this->data[12] *= scalar;
		this->data[13] *= scalar;
		this->data[14] *= scalar;
		this->data[15] *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<4, 4, T>::Subtract(const Matrix<4, 4, T>& other)
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
	}

	template <typename T>
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
}
