
#include "Vector.hpp"
#include "Matrix.hpp"

#include <iostream>

int main(void)
{
    vec<2,int> v1{2,3};
    const vec<2,int> v2{5,7};
    v1.Add(v2);

    std::cout << "Vector Add: " << v1 << std::endl;
    
    vec<2,int> v3{2,3};
    const vec<2,int> v4{5,7};
    v3.Subtract(v4);
    
    std::cout << "Vector Subtract: " << v3 << std::endl;
    
    vec<2,float> v5{2.,3.};
    v5.Scale(2.);
    
    std::cout << "Vector Scale: " << v5 << std::endl;

    mat<2,2,int> mat1{
        1,2,
        3,4
    };

    mat<2,2,int> mat2{
        7,4,
        -2,2
    };

    mat1.Add(mat2);

    std::cout << "matrix Add: " << mat1 << std::endl;

    mat<2,2,float> mat3 {
        1., 2.,
        3., 4.
    };

    mat<2,2,float> mat4 {
        7., 4.,
        -2., 2.
    };

    mat3.Subtract(mat4);

    std::cout << "matrix Subtract : " << mat3 << std::endl;


    mat<2,2,float> mat5 {
        1., 2.,
        3., 4.
    };

    mat5.Scale(2.);

    std::cout << "matrix Scale : " << mat5 << std::endl;

    return 0;
}