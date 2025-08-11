#pragma once

// TODO: Research SIMD optimization and implement it
namespace Maft
{
	template<typename T>
	MAFT_CONSTEXPR Matrix<3, 3, T>::Matrix()
	{
		this->data[0] = 0;
		this->data[1] = 0;
		this->data[2] = 0;
		this->data[3] = 0;
		this->data[4] = 0;
		this->data[5] = 0;
		this->data[6] = 0;
		this->data[7] = 0;
		this->data[8] = 0;
	}

	template<typename T>
	MAFT_CONSTEXPR Matrix<3, 3, T>::Matrix(T a11, T a12, T a13, T a21, T a22, T a23, T a31, T a32, T a33)
	{
		this->data[0] = a11;
		this->data[1] = a12;
		this->data[2] = a13;
		this->data[3] = a21;
		this->data[4] = a22;
		this->data[5] = a23;
		this->data[6] = a31;
		this->data[7] = a32;
		this->data[8] = a33;
	}
	
	template<typename T>
	MAFT_CONSTEXPR Matrix<3, 3, T>::Matrix(const Matrix<3, 3, T>& other)
	{
		this->data = other.data;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<3, 3, T>::operator()(std::size_t row, std::size_t col)
	{
		assert(row < 3 && col < 3);
		return this->data[col * 3 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<3, 3, T>::operator()(std::size_t row, std::size_t col) const
	{
		return this->data[col * 3 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<3, 3, T>& Matrix<3, 3, T>::operator=(const Matrix<3, 3, T>& other)
	{
		this->data = other.data;
		return *this;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Matrix<3, 3, T>::operator==(const Matrix<3, 3, T>& other) const
	{
		return this->data == other.data;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Add(const Matrix<3, 3, T>& other)
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
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Scale(const Matrix<3, 3, T>& other)
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
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Scale(const T& scalar)
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
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<3, 3, T>::Subtract(const Matrix<3, 3, T>& other)
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
	}

	template <typename T>
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
}
