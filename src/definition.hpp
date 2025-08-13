#pragma once

namespace Maft
{
    using f32 = float;
    using f64 = double;

    using Vector1f = Vector<1, f32>;
    using Vector2f = Vector<2, f32>;
    using Vector3f = Vector<3, f32>;
    using Vector4f = Vector<4, f32>;

    using Vector1i = Vector<1, int>;
    using Vector2i = Vector<2, int>;
    using Vector3i = Vector<3, int>;
    using Vector4i = Vector<4, int>;

    using Vector1d = Vector<1, f64>;
    using Vector2d = Vector<2, f64>;
    using Vector3d = Vector<3, f64>;
    using Vector4d = Vector<4, f64>;

    using Matrix2x2f = Matrix<2, 2, f32>;
    using Matrix3x3f = Matrix<3, 3, f32>;
    using Matrix4x4f = Matrix<4, 4, f32>;

    using Matrix2x2d = Matrix<2, 2, f64>;
    using Matrix3x3d = Matrix<3, 3, f64>;
    using Matrix4x4d = Matrix<4, 4, f64>;

    using Matrix2x2i = Matrix<2, 2, int>;
    using Matrix3x3i = Matrix<3, 3, int>;
    using Matrix4x4i = Matrix<4, 4, int>;
}
