#pragma once

#include <limits>

namespace Maft
{
	template<typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T abs(T x)
	{
		MAFT_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "For abs, only floating-point input is accepted");
		return x < 0.0f ? -x : x;
	}

	template<typename T>
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR T sqrt(T n)
	{
		if (n <= T(0))
			return T(0);

		T x = n;
		T prev = 0;

		for (int i = 0; i < 20; ++i)
		{
			prev = x;
			x = T(0.5) * (x + n / x);
			if (abs(x - prev) < T(1e-12))
				break;
		}

		return x;
	}

	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float clamp(float t, float min, float max)
	{
		if (t < min) return min;
		if (t > max) return max;
		return t;
	}

	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float clamp01(const float t)
	{
		if (t < 0.0f) return 0.0f;
		if (t > 1.0f) return 1.0f;
		return t;
	}

	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float lerpFloat(const float a, const float b, float t)
	{
		t = clamp01(t);
		return a + (b - a) * t;
	}

	template<typename T>
	MAFT_CONSTEXPR T radians(T degrees)
	{
		MAFT_STATIC_ASSERT(std::numeric_limits<T>::is_iec559, "For radians, only floating-point input is accepted");

		return degrees * static_cast<T>(0.01745329251994329576923690768489);
	}
} 
