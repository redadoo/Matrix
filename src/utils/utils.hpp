// #pragma once

// #include "Matrix.hpp"
// #include "Vector.hpp"

// #include <cmath>

// static float Clamp01(float t)
// {
//     if (t < 0.0f) return 0.0f;
//     if (t > 1.0f) return 1.0f;
//     return t;
// }

// static float Lerp(const float a, const float b, float t)
// {
//     t = Clamp01(t);
//     return a + (b - a) * t;
// }

// template<std::size_t R, std::size_t C, typename T>
// static mat<R,C, T> Lerp(const mat<R,C, T>& a, const mat<R,C, T>& b, float t)
// {
//     t = Clamp01(t);
//     mat<R, C, T> result;

//     for (size_t r = 0; r < R; ++r)
//     {
//         for (size_t c = 0; c < C; ++c)
//         {
//             result(r,c) = static_cast<T>(
//                 a(r,c) + (b(r,c) - a(r,c)) * t
//             );
//         }
//     }
//     return result;
// }

// template <size_t C, typename T>
// static vec<C, T> Lerp(const vec<C, T>& a, const vec<C, T>& b, float t)
// {
//     t = Clamp01(t);
//     vec<C, T> result;
//     for (size_t i = 0; i < C; ++i)
//         result[i] = static_cast<T>(a[i] + (b[i] - a[i]) * t);
//     return result;
// }

// template <size_t C, typename T>
// vec<C,T> LinearCombination(const std::vector< vec<C,T> >& vectors, const vec<C,T>& scalar)
// {
//     vec<C,T> result{};

//     for (size_t i = 0; i < vectors.size(); i++)
//     {
//         vec<C,T> tmp = vectors[i];
//         tmp.Scale(scalar[i]);
//         result.Add(tmp);
//     }

//     return result;
// }

// template <size_t C, typename T>
// float Magnitude(vec<C,T> vector) 
// {
//     float res = 0.0f;
//     for (size_t i = 0; i < vector.size(); i++)
//         res = vector[i] * vector[i];
//     return std::sqrt(res); 
// }

// template <size_t C, typename T>
// float angle_cos(const vec<C, T>& a, const vec<C, T>& b) 
// {
//     float dot = a.Dot(b);
//     float mag1 = a.norm();
//     float mag2 = b.norm();

//     if (mag1 == 0.0f || mag2 == 0.0f)
//         return 0.0f;

//     return dot / (mag1 * mag2);
// }

// template <size_t C, typename T>
// float determinant(const vec<C, T>& a, const vec<C, T>& b) 
// {
//     static_assert(C == 2);
//     return a[0] * b[1] - a[1] * b[0];
// }

// template <size_t C, typename T>
// vec<C, T> cross_product(const vec<C, T>& a, const vec<C, T>& b) 
// {
//     static_assert(C == 3);

//     vec<3, T> result;
//     result[0] = a[1] * b[2] - a[2] * b[1];
//     result[1] = a[2] * b[0] - a[0] * b[2];
//     result[2] = a[0] * b[1] - a[1] * b[0];
//     return result;
// }