#include "../utils/vector_utils.hpp"
#include <math.h>
#include "Maft.hpp"

namespace Maft
{
	template<typename T>
	Matrix<4, 4, T> rotate(Matrix<4, 4, T> const& m, T angle, Vector<3, T> const& v)
	{
		const T a = angle;
		const T c = cos(a);
		const T s = sin(a);

		Vector<3, T> axis(normalize(v));
		Vector<3, T> temp((T(1) - c) * axis);

		Matrix<4, 4, T> Rotate;

		Rotate(0,0) = c + temp[0] * axis[0];
		Rotate(0,1) = temp[0] * axis[1] + s * axis[2];
		Rotate(0,2) = temp[0] * axis[2] - s * axis[1];

		Rotate(1,0) = temp[1] * axis[0] - s * axis[2];
		Rotate(1,1) = c + temp[1] * axis[1];
		Rotate(1,2) = temp[1] * axis[2] + s * axis[0];

		Rotate(2,0) = temp[2] * axis[0] + s * axis[1];
		Rotate(2,1) = temp[2] * axis[1] - s * axis[0];
		Rotate(2,2) = c + temp[2] * axis[2];

		Matrix<4, 4, T> Result(m);

		// Result[0] = m[0] * Rotate(0, 0) + m[1] * Rotate(0,1) + m[2] * Rotate(0,2);
		// Result[1] = m[0] * Rotate(1, 0) + m[1] * Rotate(1,1) + m[2] * Rotate(1,2);
		// Result[2] = m[0] * Rotate(2,0) + m[1] * Rotate(2,1) + m[2] * Rotate(2,2);
		// Result[3] = m[3];

		return Result;
	}
} // namespace Maft
