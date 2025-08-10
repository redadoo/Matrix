#include "Vector.hpp"
#include <vector>

#include <iostream>
#include <cassert>
#include <chrono>
#include <iomanip>

void RunVectorTest()
{
	constexpr std::size_t iterations = 100000000;
	constexpr std::size_t components = 3;

	using vec3f = Maft::Vector<components, float>;
	
	vec3f a{};
	vec3f b{};
	vec3f scalar{};
	
	for (std::size_t i = 0; i < components; ++i) {
		a[i] = static_cast<float>(i);
		b[i] = static_cast<float>(i + 1);
		scalar[i] = 1.5f;
	}

	std::vector<vec3f> buffer;
	buffer.reserve(iterations);

	auto start = std::chrono::high_resolution_clock::now();

	for (std::size_t i = 0; i < iterations; ++i)
	{
		vec3f temp = a;
		temp.Add(b);
		temp.Subtract(b);
		temp.Scale(scalar);
		buffer.push_back(temp);
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> elapsed = end - start;
	
	std::cout << "Performed " << iterations << " vector operations in "
			  << elapsed.count() << " seconds.\n";

	if (!buffer.empty())
		std::cout << "Last vector result: " << buffer.back() << "\n";
}

// void TestVectorOperations() {
// 	std::cout << "=== Vector Tests ===" << std::endl;

// 	vec<2,int> v1{2,3};
// 	const vec<2,int> v2{5,7};

// 	std::cout << "v1 before Add: " << v1 << std::endl;
// 	std::cout << "v2: " << v2 << std::endl;

// 	v1.Add(v2);
// 	std::cout << "v1 after Add(v2): " << v1 << std::endl;
// 	assert((v1 == vec<2,int>{7, 10}));


// 	vec<2,int> v3{2,3};
// 	const vec<2,int> v4{5,7};

// 	std::cout << "v3 before Subtract: " << v3 << std::endl;
// 	std::cout << "v4: " << v4 << std::endl;

// 	v3.Subtract(v4);
// 	std::cout << "v3 after Subtract(v4): " << v3 << std::endl;
// 	assert((v3 == vec<2,int>{-3, -4}));


// 	vec<2,float> v5{2.,3.};
// 	std::cout << "v5 before Scale: " << v5 << std::endl;

// 	v5.Scale(2.);
// 	std::cout << "v5 after Scale(2): " << v5 << std::endl;
// 	assert((v5 == vec<2,float>{4., 6.}));
// }

// void TestMatrixOperations() {
// 	std::cout << "=== Matrix Tests ===" << std::endl;

// 	mat<2,2,int> mat1{
// 		1,2,
// 		3,4
// 	};
// 	mat<2,2,int> mat2{
// 		7,4,
// 		-2,2
// 	};

// 	std::cout << "mat1 before Add: " << mat1 << std::endl;
// 	std::cout << "mat2: " << mat2 << std::endl;

// 	mat1.Add(mat2);
// 	std::cout << "mat1 after Add(mat2): " << mat1 << std::endl;
// 	assert((mat1 == mat<2,2,int>{
// 		8,6,
// 		1,6
// 	}));


// 	mat<2,2,float> mat3 {
// 		1., 2.,
// 		3., 4.
// 	};
// 	mat<2,2,float> mat4 {
// 		7., 4.,
// 		-2., 2.
// 	};

// 	std::cout << "mat3 before Subtract: " << mat3 << std::endl;
// 	std::cout << "mat4: " << mat4 << std::endl;

// 	mat3.Subtract(mat4);
// 	std::cout << "mat3 after Subtract(mat4): " << mat3 << std::endl;
// 	assert((mat3 == mat<2,2,float>{
// 		-6., -2.,
// 		5., 2.
// 	}));


// 	mat<2,2,float> mat5 {
// 		1., 2.,
// 		3., 4.
// 	};
// 	std::cout << "mat5 before Scale: " << mat5 << std::endl;

// 	mat5.Scale(2.);
// 	std::cout << "mat5 after Scale(2): " << mat5 << std::endl;
// 	assert((mat5 == mat<2,2,float>{
// 		2., 4.,
// 		6., 8.
// 	}));
// }

// void TestLinearCombination() {
// 	vec<3,float> e1{1., 0., 0.};
// 	vec<3,float> e2{0., 1., 0.};
// 	vec<3,float> e3{0., 0., 1.};
// 	vec<3,float> v1{1., 2., 3.};
// 	vec<3,float> v2{0., 10., -100.};

// 	std::vector< vec<3,float> > basis = {e1, e2, e3};
// 	vec<3,float> scalars1 = {10.f, -2.f, 0.5f};
// 	auto res1 = LinearCombination({e1, e2, e3}, scalars1);
// 	std::cout << "Linear combination 1: " << res1 << std::endl;

// 	std::vector< vec<3,float> > vectors = {v1, v2};
// 	vec<3,float> scalars2 = {10.f, -2.f};
// 	auto res2 = LinearCombination(vectors, scalars2);
// 	std::cout << "Linear combination 2: " << res2 << std::endl;
// }

// void TestLerp()
// {
// 	std::cout << Lerp(0.f, 1.f, 0.f) << "\n";          
// 	std::cout << Lerp(0.f, 1.f, 1.f) << "\n";         
// 	std::cout << Lerp(0.f, 1.f, 0.5f) << "\n";        
// 	std::cout << Lerp(21.f, 42.f, 0.3f) << "\n";       

// 	vec<2,float> v1{2.f, 1.f};
// 	vec<2,float> v2{4.f, 2.f};
// 	std::cout << Lerp(v1, v2, 0.3f) << "\n";           

// 	mat<2,2,float> m1{2.f, 1.f, 3.f, 4.f};
// 	mat<2,2,float> m2{20.f, 10.f, 30.f, 40.f};
// 	std::cout << Lerp(m1, m2, 0.5f) << "\n";        
// }

// void TestDot()
// {
// 	vec<2,float> v1{0.0, 0.0};
// 	vec<2,float> v2{1.0, 1.0};
// 	std::cout << v1.Dot(v2) << std::endl;

// 	vec<2,float> v3{1.0, 1.0};
// 	vec<2,float> v4{1.0, 1.0};
// 	std::cout << v3.Dot(v4) << std::endl;

// 	vec<2,float> v5{-1.0, 6.0};
// 	vec<2,float> v6{3.0, 2.0};
// 	std::cout << v5.Dot(v6) << std::endl;
// }

// void TestNorm()
// {
// 	std::cout << std::fixed << std::setprecision(8);

// 	vec<3,float> v1{0., 0., 0.};
// 	std::cout << v1.norm_1() << " " << v1.norm() << " " << v1.norm_inf() << std::endl;

// 	vec<3,float> v2{1., 2., 3.};
// 	std::cout << v2.norm_1() << " " << v2.norm() << " " << v2.norm_inf() << std::endl;

// 	vec<2,float> v3{-1., -2.};
// 	std::cout << v3.norm_1() << " " << v3.norm() << " " << v3.norm_inf() << std::endl;
// }

// void TestAngleCos()
// {
// 	std::cout << std::fixed << std::setprecision(8);

// 	vec<2, float> u1{1.0f, 0.0f};
// 	vec<2, float> v1{1.0f, 0.0f};
// 	std::cout << angle_cos(u1, v1) << std::endl;
// 	vec<2, float> u2{1.0f, 0.0f};
// 	vec<2, float> v2{0.0f, 1.0f};
// 	std::cout << angle_cos(u2, v2) << std::endl;
// 	vec<2, float> u3{-1.0f, 1.0f};
// 	vec<2, float> v3{ 1.0f, -1.0f};
// 	std::cout << angle_cos(u3, v3) << std::endl;
// 	vec<2, float> u4{2.0f, 1.0f};
// 	vec<2, float> v4{4.0f, 2.0f};
// 	std::cout << angle_cos(u4, v4) << std::endl;
// 	vec<3, float> u5{1.0f, 2.0f, 3.0f};
// 	vec<3, float> v5{4.0f, 5.0f, 6.0f};
// 	std::cout << angle_cos(u5, v5) << std::endl;
// }

// void TestDeterminant()
// {
// 	vec<2, float> v1{1.0f, 5.0f};
// 	vec<2, float> v2{3.0f, 4.0f};
// 	std::cout << determinant(v1, v2) << std::endl;
// }

// void TestCrossProduct()
// {
// 	vec<3, float> u1{0., 0., 1.};
// 	vec<3, float> v1{1., 0., 0.};
// 	std::cout << cross_product(u1, v1) << std::endl;

// 	vec<3, float> u2{1., 2., 3.};
// 	vec<3, float> v2{4., 5., 6.};
// 	std::cout << cross_product(u2, v2) << std::endl;

// 	vec<3, float> u3{4., 2., -3.};
// 	vec<3, float> v3{-2., -5., 16.};
// 	std::cout << cross_product(u3, v3) << std::endl;
// }

// void TestMatrixMultiplyVec()
// {
	
// }
