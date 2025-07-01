
#include "Vector.hpp"
#include "Matrix.hpp"

#include <iostream>

int main(void)
{
    vec<2,int> v1{2,3};
    const vec<2,int> v2{5,7};
    v1.Add(v2);

    std::cout << "Vector : " << v1 << std::endl;
    
    vec<2,int> v3{2,3};
    const vec<2,int> v4{5,7};
    v3.Subtract(v4);
    
    std::cout << "Vector : " << v3 << std::endl;
    
    vec<2,float> v5{2.,3.};
    v5.Scale(2.);
    
    std::cout << "Vector : " << v5 << std::endl;

    mat<2,2,int> mat1{
        1,2,
        3,4
    };

    mat<2,2,int> mat2{
        7,4,
        -2,2
    };

    mat1.Add(mat2);

    std::cout << "matrix : " << mat1 << std::endl;

    return 0;
}