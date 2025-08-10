#pragma once

namespace Maft
{
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float absf(const float x)
	{
		return x < 0.0f ? -x : x;
	}

	//TODO :rewrite
	MAFT_NODISCARD MAFT_FORCE_INLINE MAFT_CONSTEXPR float sqrt(const float n)
	{
		if (n <= 0.0f)
			return 0.0f;

		float x = n;
		float prev = 0.0f;

		for (int i = 0; i < 20; ++i)
		{
			prev = x;
			x = 0.5f * (x + n / x);
			if (absf(x - prev) < 1e-6f)
				break;
		}

		return x;
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
} 
