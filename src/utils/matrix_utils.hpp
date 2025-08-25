#include "../utils/vector_utils.hpp"
#include <math.h>
#include "Maft.hpp"

namespace Maft
{
	template<typename T>
	Matrix<4, 4, T> rotate(const Matrix<4,4,T>& m, T angle, const Vector<3,T>& v)
	{
		const T c = std::cos(angle);
		const T s = std::sin(angle);

		Vector<3,T> axis = normalize(v);
		Vector<3,T> temp = (T(1) - c) * axis;

		Matrix<4,4,T> Rotate = Matrix<4,4,T>::Identity();

		Rotate(0,0) = c + temp[0] * axis[0];
		Rotate(0,1) = temp[0] * axis[1] - s * axis[2];   
		Rotate(0,2) = temp[0] * axis[2] + s * axis[1];

		Rotate(1,0) = temp[1] * axis[0] + s * axis[2];
		Rotate(1,1) = c + temp[1] * axis[1];
		Rotate(1,2) = temp[1] * axis[2] - s * axis[0];

		Rotate(2,0) = temp[2] * axis[0] - s * axis[1];
		Rotate(2,1) = temp[2] * axis[1] + s * axis[0];
		Rotate(2,2) = c + temp[2] * axis[2];

		return m * Rotate;
	}

	template<typename T>
	Matrix<4, 4, T> lookAtRH(const Vector<3, T>& eye, const Vector<3, T>& center, const Vector<3, T>& up)
	{
		Vector<3, T> f = normalize(center - eye);
		Vector<3, T> s = normalize(Vector3f::cross_product(f, up));
		Vector<3, T> u = Vector3f::cross_product(s, f);

		Matrix<4, 4, T> result = Matrix<4,4,T>::Identity();

		result(0,0) = s.x;
		result(1,0) = s.y;
		result(2,0) = s.z;

		result(0,1) = u.x;
		result(1,1) = u.y;
		result(2,1) = u.z;

		result(0,2) = -f.x;
		result(1,2) = -f.y;
		result(2,2) = -f.z;

		result(3,0) = -s.Dot(eye);
		result(3,1) = -u.Dot(eye);
		result(3,2) =  f.Dot(eye);

		return result;
	}

	template<typename T>
	Matrix<4, 4, T> lookAtLH(const Vector<3, T>& eye, const Vector<3, T>& center, const Vector<3, T>& up)
	{
		Vector<3, T> f = normalize(center - eye);
		Vector<3, T> s = normalize(cross(up, f));
		Vector<3, T> u = cross(f, s);

		Matrix<4, 4, T> result = Matrix<4,4,T>::Identity();

		// Column 0
		result(0,0) = s.x;
		result(1,0) = s.y;
		result(2,0) = s.z;

		// Column 1
		result(0,1) = u.x;
		result(1,1) = u.y;
		result(2,1) = u.z;

		// Column 2
		result(0,2) = f.x;
		result(1,2) = f.y;
		result(2,2) = f.z;

		// Translation (column 3)
		result(3,0) = -dot(s, eye);
		result(3,1) = -dot(u, eye);
		result(3,2) = -dot(f, eye);

		return result;
	}

	template<typename T>
	Matrix<4, 4, T> lookAt(const Vector<3, T>& eye, const Vector<3, T>& center, const Vector<3, T>& up, bool leftHanded=false)
	{
		return leftHanded ? lookAtLH(eye, center, up) : lookAtRH(eye, center, up);
	}

	template<typename T>
	Matrix<4, 4, T> perspectiveRH_ZO(T fovy, T aspect, T zNear, T zFar)
	{
		assert(aspect != static_cast<T>(0));
		assert(zNear != zFar);

		T const tanHalfFovy = std::tan(fovy / static_cast<T>(2));

		Matrix<4, 4, T> Result(static_cast<T>(0));
		Result(0,0) = static_cast<T>(1) / (aspect * tanHalfFovy);
		Result(1,1) = static_cast<T>(1) / tanHalfFovy;
		Result(2,2) = zFar / (zNear - zFar);
		Result(2,3) = -static_cast<T>(1);
		Result(3,2) = -(zFar * zNear) / (zFar - zNear);
		Result(3,3) = 0;

		return Result;
	}

	template<typename T>
	Matrix<4, 4, T> perspective(T fovy, T aspect, T zNear, T zFar)
	{
		return perspectiveRH_ZO(fovy, aspect, zNear, zFar);
	}
} // namespace Maft
