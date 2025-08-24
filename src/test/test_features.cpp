#include "Maft.hpp"
#include "../utils/hash.hpp"
#include "../utils/matrix_utils.hpp"

#include <unordered_map>
#include <math.h>

using namespace Maft;

void test_hash()
{
    std::unordered_map<Vector2i, std::string> map2;
    map2[{1, 2}] = "hello";
    map2[{3, 4}] = "world";

    for (auto &kv : map2) {
        std::cout << "vec2(" << kv.first.x << "," << kv.first.y
                  << ") -> " << kv.second << "\n";
    }

    std::unordered_map<Vector3i, int> map3;
    map3[{1,2,3}] = 42;
    map3[{4,5,6}] = 99;

    std::cout << "vec3(1,2,3) = " << map3[{1,2,3}] << "\n";
    std::cout << "vec3(4,5,6) = " << map3[{4,5,6}] << "\n";
}

void test_radiant()
{
    {
        float deg = 180.0f;
        float rad = radians(deg);
        std::cout << deg << " degrees = " << rad << " radians\n";
        if (abs(rad - 3.14159265f) < 1e-6f)
            std::cout << "OK\n";
        else
            std::cout << "FAIL\n";
    }

    {
        double deg = 90.0;
        double rad = radians(deg);
        std::cout << deg << " degrees = " << rad << " radians\n";
        if (abs(rad - (M_PI / 2.0)) < 1e-12)
            std::cout << " OK\n";
        else
            std::cout << "FAIL\n";
    }

    {
        float deg = 0.0f;
        float rad = radians(deg);
        std::cout << deg << " degrees = " << rad << " radians\n";
    }

    {
        float deg = -45.0f;
        float rad = radians(deg);
        std::cout << deg << " degrees = " << rad << " radians\n";
    }
}

void test_rotation()
{
    Matrix<4, 4, float> I(1.0f); 

    Vector<3, float> axisZ{0.0f, 0.0f, 1.0f};
    float angle = radians(90.0f);

    Matrix<4, 4, float> Rz = rotate(I, angle, axisZ);

    Vector<4, float> vec{1.0f, 0.0f, 0.0f, 1.0f};
    Vector<4, float> rotatedVec;
    
    // Multiply matrix Rz * vec
    for(int i=0; i<4; ++i)
    {
        rotatedVec[i] = 0.0f;
        for(int j=0; j<4; ++j)
            rotatedVec[i] += Rz(i,j) * vec[j];
    }

    std::cout << "Original vector: (" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")\n";
    std::cout << "Rotated 90 deg around Z: (" 
              << rotatedVec[0] << ", " 
              << rotatedVec[1] << ", " 
              << rotatedVec[2] << ")\n";
}