#pragma once

// TODO: Research SIMD optimization and implement it
namespace Maft
{
	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2, T>::Matrix()
	{
		this->data[0] = 0;
		this->data[1] = 0;
		this->data[2] = 0;
		this->data[3] = 0;
	}

	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2, T>::Matrix(T a11, T a12, T a21, T a22)
	{
		this->data[0] = a11;
		this->data[1] = a12;
		this->data[2] = a21;
		this->data[3] = a22;
	}
	
	template<typename T>
	MAFT_CONSTEXPR Matrix<2, 2, T>::Matrix(const Matrix<2, 2, T>& other)
	{
		this->data = other.data;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR T& Matrix<2, 2, T>::operator()(std::size_t row, std::size_t col)
	{
		return this->data[col * 2 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR const T& Matrix<2, 2, T>::operator()(std::size_t row, std::size_t col) const
	{
		return this->data[col * 2 + row];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR  Matrix<2, 2, T>& Matrix<2, 2, T>::operator=(const Matrix2x2<T>& other)
	{
		this->data = other.data;
		return *this;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR bool Matrix<2, 2, T>::operator==(const Matrix2x2<T>& other) const
	{
		return this->data == other.data;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Add(const Matrix2x2<T>& other)
	{
		this->data[0] += other.data[0];
		this->data[1] += other.data[1];
		this->data[2] += other.data[2];
		this->data[3] += other.data[3];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Scale(const Matrix2x2<T>& other)
	{
		this->data[0] *= other.data[0];
		this->data[1] *= other.data[1];
		this->data[2] *= other.data[2];
		this->data[3] *= other.data[3];
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Scale(const T& scalar)
	{
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;
		this->data[3] *= scalar;
	}

	template<typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR void Matrix<2, 2, T>::Subtract(const Matrix2x2<T>& other)
	{
		this->data[0] -= other.data[0];
		this->data[1] -= other.data[1];
		this->data[2] -= other.data[2];
		this->data[3] -= other.data[3];
	}

	template <typename T>
	MAFT_FORCE_INLINE MAFT_CONSTEXPR Matrix<2, 2, T> Matrix<2, 2, T>::Lerp(const Matrix<2, 2, T> &a, const Matrix<2, 2, T> &b, float t)
	{
		t = clamp01(t);
		Matrix<2, 2, T> result;

		result.data[0] = static_cast<T>(a.data[0] + (b.data[0] - a.data[0]) * t);
		result.data[1] = static_cast<T>(a.data[1] + (b.data[1] - a.data[1]) * t);
		result.data[2] = static_cast<T>(a.data[2] + (b.data[2] - a.data[2]) * t);
		result.data[3] = static_cast<T>(a.data[3] + (b.data[3] - a.data[3]) * t);

		return result;
	}
}
