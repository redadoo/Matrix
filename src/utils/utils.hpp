#pragma once

float Clamp01(float t)
{
    if (t < 0.0f) return 0.0f;
    if (t > 1.0f) return 1.0f;
    return t;
}

float LerpFloat(const float a, const float b, float t)
{
    t = Clamp01(t);
    return a + (b - a) * t;
}
