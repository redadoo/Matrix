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
    Matrix<4, 4, float> I = Matrix<4,4,float>::Identity(); 
    
    Vector<3, float> axisZ{0.0f, 0.0f, 1.0f};
    float angle = radians(90.0f);

    Matrix<4, 4, float> Rz = rotate(I, angle, axisZ);

    Vector<4, float> vec{1.0f, 0.0f, 0.0f, 1.0f};
    Vector<4, float> rotatedVec;
    
    for(int i=0; i<4; ++i)
    {
        rotatedVec[i] = 0.0f;
        for(int j=0; j<4; ++j)
            rotatedVec[i] += Rz(i,j) * vec[j];
    }

    std::cout << "Original vector: " << vec << "\n";
    std::cout << "Rotated: " << rotatedVec << "\n";
}

void test_lookat()
{
    using T = float;

    Vector<3, T> eye{0.0f, 0.0f, 5.0f};    
    Vector<3, T> center{0.0f, 0.0f, 0.0f}; 
    Vector<3, T> up{0.0f, 1.0f, 0.0f};     

    Matrix<4, 4, T> view = lookAtRH(eye, center, up);

    std::cout << "\n" << view << "\n";

    Vector<4, T> target{center.x, center.y, center.z, 1.0f};
    Vector<4, T> transformed;
    for(int i=0; i<4; ++i)
    {
        transformed[i] = 0.0f;
        for(int j=0; j<4; ++j)
            transformed[i] += view(i,j) * target[j];
    }

    std::cout << transformed << "\n";

}

void test_perspective()
{
    float fovy   = radians(90.0f); 
    float aspect = 16.0f / 9.0f;   
    float zNear  = 0.1f;
    float zFar   = 100.0f;

    Matrix<4, 4, float> proj = perspectiveRH_ZO(fovy, aspect, zNear, zFar);

    std::cout << "\n" << proj << "\n";

    Vector<4, float> point{0.0f, 0.0f, -1.0f, 1.0f};
    Vector<4, float> projected;

    for (int i = 0; i < 4; ++i)
    {
        projected[i] = 0.0f;
        for (int j = 0; j < 4; ++j)
            projected[i] += proj(i, j) * point[j];
    }

    std::cout << projected << "\n";
}
