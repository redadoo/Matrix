#include "Maft.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cassert>

using namespace Maft;
//TODO: rewrite tests


void test_vector_operations() 
{
	std::cout << "===== Test Add =====\n";

	// int
	{
		Vector2i v1{2, 3};
		const Vector2i v2{5, 7};
		std::cout << "[int] v1: " << v1 << "\n";
		std::cout << "[int] v2: " << v2 << "\n";
		v1.Add(v2);
		std::cout << "[int] v1 after Add(v2): " << v1 << "\n";
		assert((v1 == Vector2i{7, 10}));
	}

	// float
	{
		Vector2f v1{2.0f, 3.0f};
		const Vector2f v2{5.0f, 7.0f};
		std::cout << "[float] v1: " << v1 << "\n";
		std::cout << "[float] v2: " << v2 << "\n";
		v1.Add(v2);
		std::cout << "[float] v1 after Add(v2): " << v1 << "\n";
		assert((v1 == Vector2f{7.0f, 10.0f}));
	}

	// double
	{
		Vector2d v1{2.0, 3.0};
		const Vector2d v2{5.0, 7.0};
		std::cout << "[double] v1: " << v1 << "\n";
		std::cout << "[double] v2: " << v2 << "\n";
		v1.Add(v2);
		std::cout << "[double] v1 after Add(v2): " << v1 << "\n";
		assert((v1 == Vector2d{7.0, 10.0}));
	}

	std::cout << "\n===== Test Subtract =====\n";

	// int
	{
		Vector2i v1{2, 3};
		const Vector2i v2{5, 7};
		std::cout << "[int] v1: " << v1 << "\n";
		std::cout << "[int] v2: " << v2 << "\n";
		v1.Subtract(v2);
		std::cout << "[int] v1 after Subtract(v2): " << v1 << "\n";
		assert((v1 == Vector2i{-3, -4}));
	}

	// float
	{
		Vector2f v1{2.0f, 3.0f};
		const Vector2f v2{5.0f, 7.0f};
		std::cout << "[float] v1: " << v1 << "\n";
		std::cout << "[float] v2: " << v2 << "\n";
		v1.Subtract(v2);
		std::cout << "[float] v1 after Subtract(v2): " << v1 << "\n";
		assert((v1 == Vector2f{-3.0f, -4.0f}));
	}

	// double
	{
		Vector2d v1{2.0, 3.0};
		const Vector2d v2{5.0, 7.0};
		std::cout << "[double] v1: " << v1 << "\n";
		std::cout << "[double] v2: " << v2 << "\n";
		v1.Subtract(v2);
		std::cout << "[double] v1 after Subtract(v2): " << v1 << "\n";
		assert((v1 == Vector2d{-3.0, -4.0}));
	}

	std::cout << "\n===== Test Scale =====\n";

	// int
	{
		Vector2i v1{2, 3};
		std::cout << "[int] v1: " << v1 << "\n";
		v1.Scale(2);
		std::cout << "[int] v1 after Scale(2): " << v1 << "\n";
		assert((v1 == Vector2i{4, 6}));
	}

	// float
	{
		Vector2f v1{2.0f, 3.0f};
		std::cout << "[float] v1: " << v1 << "\n";
		v1.Scale(2.0f);
		std::cout << "[float] v1 after Scale(2.0f): " << v1 << "\n";
		assert((v1 == Vector2f{4.0f, 6.0f}));
	}

	// double
	{
		Vector2d v1{2.0, 3.0};
		std::cout << "[double] v1: " << v1 << "\n";
		v1.Scale(2.0);
		std::cout << "[double] v1 after Scale(2.0): " << v1 << "\n";
		assert((v1 == Vector2d{4.0, 6.0}));
	}
}

void test_matrix_operations() 
{
	std::cout << "===== Test Add =====\n";

	// int
	{
		Matrix2x2i mat1{
			1, 2,
			3, 4
		};
		Matrix2x2i mat2{
			7, 4,
			-2, 2
		};

		std::cout << "[int] mat1 before Add: " << mat1 << std::endl;
		std::cout << "[int] mat2: " << mat2 << std::endl;

		mat1.Add(mat2);

		std::cout << "[int] mat1 after Add(mat2): " << mat1 << std::endl;
		assert((mat1 == Matrix2x2i{
			8, 6,
			1, 6
		}));
	}

	// float
	{
		Matrix2x2f mat1{
			1.f, 2.f,
			3.f, 4.f
		};
		Matrix2x2f mat2{
			7.f, 4.f,
			-2.f, 2.f
		};

		std::cout << "[float] mat1 before Add: " << mat1 << std::endl;
		std::cout << "[float] mat2: " << mat2 << std::endl;

		mat1.Add(mat2);

		std::cout << "[float] mat1 after Add(mat2): " << mat1 << std::endl;
		assert((mat1 == Matrix2x2f{
			8.f, 6.f,
			1.f, 6.f
		}));
	}

	// double
	{
		Matrix2x2d mat1{
			1., 2.,
			3., 4.
		};
		Matrix2x2d mat2{
			7., 4.,
			-2., 2.
		};

		std::cout << "[double] mat1 before Add: " << mat1 << std::endl;
		std::cout << "[double] mat2: " << mat2 << std::endl;

		mat1.Add(mat2);

		std::cout << "[double] mat1 after Add(mat2): " << mat1 << std::endl;
		assert((mat1 == Matrix2x2d{
			8., 6.,
			1., 6.
		}));
	}

	std::cout << "\n===== Test Subtract =====\n";

	// int
	{
		Matrix2x2i mat1{
			1, 2,
			3, 4
		};
		Matrix2x2i mat2{
			7, 4,
			-2, 2
		};

		std::cout << "[int] mat1 before Subtract: " << mat1 << std::endl;
		std::cout << "[int] mat2: " << mat2 << std::endl;

		mat1.Subtract(mat2);

		std::cout << "[int] mat1 after Subtract(mat2): " << mat1 << std::endl;
		assert((mat1 == Matrix2x2i{
			-6, -2,
			5, 2
		}));
	}

	// float
	{
		Matrix2x2f mat1{
			1.f, 2.f,
			3.f, 4.f
		};
		Matrix2x2f mat2{
			7.f, 4.f,
			-2.f, 2.f
		};

		std::cout << "[float] mat1 before Subtract: " << mat1 << std::endl;
		std::cout << "[float] mat2: " << mat2 << std::endl;

		mat1.Subtract(mat2);

		std::cout << "[float] mat1 after Subtract(mat2): " << mat1 << std::endl;
		assert((mat1 == Matrix2x2f{
			-6.f, -2.f,
			5.f, 2.f
		}));
	}

	// double
	{
		Matrix2x2d mat1{
			1., 2.,
			3., 4.
		};

		Matrix2x2d mat2{
			7., 4.,
			-2., 2.
		};

		std::cout << "[double] mat1 before Subtract: " << mat1 << std::endl;
		std::cout << "[double] mat2: " << mat2 << std::endl;

		mat1.Subtract(mat2);

		std::cout << "[double] mat1 after Subtract(mat2): " << mat1 << std::endl;
		assert((mat1 == Matrix2x2d{
			-6., -2.,
			5., 2.
		}));
	}

	std::cout << "\n===== Test Scale =====\n";

	// int
	{
		Matrix2x2i mat{
			1, 2,
			3, 4
		};
		std::cout << "[int] mat before Scale: " << mat << std::endl;

		mat.Scale(2);

		std::cout << "[int] mat after Scale(2): " << mat << std::endl;
		assert((mat == Matrix2x2i{
			2, 4,
			6, 8
		}));
	}

	// float
	{
		Matrix2x2f mat{
			1.f, 2.f,
			3.f, 4.f
		};
		std::cout << "[float] mat before Scale: " << mat << std::endl;

		mat.Scale(2.f);

		std::cout << "[float] mat after Scale(2.f): " << mat << std::endl;
		assert((mat == Matrix2x2f{
			2.f, 4.f,
			6.f, 8.f
		}));
	}

	// double
	{
		Matrix2x2d mat{
			1., 2.,
			3., 4.
		};
		std::cout << "[double] mat before Scale: " << mat << std::endl;

		mat.Scale(2.);

		std::cout << "[double] mat after Scale(2.): " << mat << std::endl;
		assert((mat == Matrix2x2d{
			2., 4.,
			6., 8.
		}));
	}
}

void test_linear_combination() {
	Vector3f e1{1.f, 0.f, 0.f};
	Vector3f e2{0.f, 1.f, 0.f};
	Vector3f e3{0.f, 0.f, 1.f};

	Vector3f v1{1.f, 2.f, 3.f};
	Vector3f v2{0.f, 10.f, -100.f};

	std::vector<Vector3f> basis = {e1, e2, e3};
	Vector3f scalars1 = {10.f, -2.f, 0.5f};

	auto res1 = Vector3f::LinearCombination(basis, scalars1);
	std::cout << "Linear combination 1: " << res1 << std::endl;
}

void test_lerp()
{
	Vector2f v1{2.f, 1.f};
	Vector2f v2{4.f, 2.f};
	std::cout << Vector2f::Lerp(v1, v2, 0.3f) << "\n";           

	Matrix2x2f m1{2.f, 1.f, 3.f, 4.f};
	Matrix2x2f m2{20.f, 10.f, 30.f, 40.f};
	std::cout << Matrix2x2f::Lerp(m1, m2, 0.5f) << "\n";        
}

void test_dot()
{
	Vector2f v1{0.0, 0.0};
	Vector2f v2{1.0, 1.0};
	std::cout << v1.Dot(v2) << std::endl;

	Vector2f v3{1.0, 1.0};
	Vector2f v4{1.0, 1.0};
	std::cout << v3.Dot(v4) << std::endl;

	Vector2f v5{-1.0, 6.0};
	Vector2f v6{3.0, 2.0};
	std::cout << v5.Dot(v6) << std::endl;
}

void test_norm()
{
	std::cout << std::fixed << std::setprecision(8);

	Vector3f v1{0., 0., 0.};
	std::cout << v1.norm_1() << " " << v1.norm() << " " << v1.norm_inf() << std::endl;

	Vector3f v2{1., 2., 3.};
	std::cout << v2.norm_1() << " " << v2.norm() << " " << v2.norm_inf() << std::endl;

	Vector2f v3{-1., -2.};
	std::cout << v3.norm_1() << " " << v3.norm() << " " << v3.norm_inf() << std::endl;
}

void test_angle_cos()
{
	std::cout << std::fixed << std::setprecision(8);

	Vector2f u1{1.0f, 0.0f};
	Vector2f v1{1.0f, 0.0f};
	std::cout << Vector2f::angle_cos(u1, v1) << std::endl;
	Vector2f u2{1.0f, 0.0f};
	Vector2f v2{0.0f, 1.0f};
	std::cout << Vector2f::angle_cos(u2, v2) << std::endl;
	Vector2f u3{-1.0f, 1.0f};
	Vector2f v3{1.0f, -1.0f};
	std::cout << Vector2f::angle_cos(u3, v3) << std::endl;
}

void test_cross_product()
{
	Vector3f u1{0.0f, 0.0f, 1.0f};
	Vector3f v1{1.0f, 0.0f, 0.0f};

	std::cout << Vector3f::cross_product(u1, v1) << std::endl;

	Vector3f u2{1.0f, 2.0f, 3.0f};
	Vector3f v2{4.0f, 5.0f, 6.0f};

	std::cout << Vector3f::cross_product(u2, v2) << std::endl;

	Vector3f u3{4.0f, 2.0f, -3.0f};
	Vector3f v3{-2.0f, -5.0f, 16.0f};

	std::cout << Vector3f::cross_product(u3, v3) << std::endl;
}

void test_matrix_multiplication()
{
	{
		Matrix2x2f u(
			1.f, 0.f,
			0.f, 1.f
		);

		Vector2f v{4.f, 2.f};
		std::cout << u.multiply_vector(v) << "\n";
	}

	{
		Matrix2x2f u(
			2.f, 0.f,
			0.f, 2.f
		);

		Vector2f v{4.f, 2.f};
		std::cout << u.multiply_vector(v) << "\n";
	}

	{
		Matrix2x2f u(
			2.f, -2.f,
			-2.f, 2.f
		);
		
		Vector2f v{4.f, 2.f};
		std::cout << u.multiply_vector(v) << "\n\n";
	}

	{
		Matrix2x2f u(
			1.f, 0.f,
			0.f, 1.f
		);

		Matrix2x2f v(
			1.f, 0.f,
			0.f, 1.f
		);
		std::cout << u.multiply_matrix(v) << "\n\n";
	}

	{
		Matrix2x2f u(
			1.f, 0.f,
			0.f, 1.f
		);
		
		Matrix2x2f v(
			2.f, 1.f,
			4.f, 2.f
		);
		std::cout << u.multiply_matrix(v) << "\n\n";
	}

	{
		Matrix2x2f u(
			3.f, -5.f,
			6.f, 8.f
		);
		
		Matrix2x2f v(
			2.f, 1.f,
			4.f, 2.f
		);
		std::cout << u.multiply_matrix(v) << "\n\n";
	}


	Matrix<2, 3, float> A;
	A(0,0) = 1; A(0,1) = 2; A(0,2) = 3;
	A(1,0) = 4; A(1,1) = 5; A(1,2) = 6;

	Matrix<3, 2, float> B;
	B(0,0) = 7;  B(0,1) = 8;
	B(1,0) = 9;  B(1,1) = 10;
	B(2,0) = 11; B(2,1) = 12;

	auto C = A.multiply_matrix(B);

	std::cout << "Matrix A:\n" << A;
	std::cout << "Matrix B:\n" << B;
	std::cout << "A * B =\n" << C << "\n";
}

void test_trace()
{
	Matrix<2, 2, double> u1(
		1.0, 0.0,
		0.0, 1.0
	);
	std::cout << u1.trace() << "\n";

	Matrix<3, 3, double> u2(
		2.0, -5.0, 0.0,
		4.0,  3.0, 7.0,
	   -2.0,  3.0, 4.0
	);
	std::cout << u2.trace() << "\n";

	Matrix<3, 3, double> u3(
		-2.0, -8.0,  4.0,
		 1.0, -23.0, 4.0,
		 0.0,   6.0, 4.0
	);
	std::cout << u3.trace() << "\n";
}

void test_transpose()
{
	{
		Maft::Matrix<3, 2, double> m2;
		m2(0, 0) = 1; m2(0, 1) = 2;
		m2(1, 0) = 3; m2(1, 1) = 4;
		m2(2, 0) = 5; m2(2, 1) = 6;

		auto t2 = m2.transpose();

		std::cout << "m2:\n" << m2 << "\n";
		std::cout << "transpose(m2):\n" << t2 << "\n";

		assert(t2(0, 0) == 1);
		assert(t2(1, 0) == 2);
		assert(t2(0, 1) == 3);
		assert(t2(1, 1) == 4);
		assert(t2(0, 2) == 5);
		assert(t2(1, 2) == 6);
	}

	{
		Maft::Matrix<2, 3, double> m3;
		m3(0, 0) = -1; m3(0, 1) = -2; m3(0, 2) = -3;
		m3(1, 0) = 4;  m3(1, 1) = 5;  m3(1, 2) = 6;

		auto t3 = m3.transpose();

		std::cout << "m3:\n" << m3 << "\n";
		std::cout << "transpose(m3):\n" << t3 << "\n";

		assert(t3(0, 0) == -1);
		assert(t3(1, 0) == -2);
		assert(t3(2, 0) == -3);
		assert(t3(0, 1) == 4);
		assert(t3(1, 1) == 5);
		assert(t3(2, 1) == 6);
	}

	std::cout << "All transpose() tests passed!\n";
}

void test_swap()
{
	Matrix<3, 2, float> B;
	B(0,0) = 7;  B(0,1) = 8;
	B(1,0) = 9;  B(1,1) = 10;
	B(2,0) = 11; B(2,1) = 12;

	std::cout << "Original:\n" << B << "\n";

	// Test column swap
	B.swap_column(0, 1);
	std::cout << "After swap_column(0,1):\n" << B << "\n";
	// Expected:
	//  8   7
	// 10   9
	// 12  11

	// Swap back to original
	B.swap_column(0, 1);

	// Test row swap
	B.swap_row(0, 2);
	std::cout << "After swap_row(0,2):\n" << B << "\n";
	// Expected:
	// 11  12
	//  9  10
	//  7   8
}

void test_row_echelon()
{
	{
	    Matrix<2, 2, float> u;
	    u(0,0) = 2; u(0,1) = 3;
	    u(1,0) = 4; u(1,1) = 5;
	    std::cout << u.row_echelon() << "\n\n";
	}
	{
	    Matrix<2, 2, float> u;
	    u(0,0) = 1; u(0,1) = 2;
	    u(1,0) = 3; u(1,1) = 4;
	    std::cout << u.row_echelon() << "\n\n";
	}
	
	{
	    Matrix<2, 2, float> u;
	    u(0,0) = 1; u(0,1) = 2;
	    u(1,0) = 2; u(1,1) = 4;
	    std::cout << u.row_echelon() << "\n\n";
	}

	{
	    Matrix<2, 2, float> u;
	    u(0,0) = 0; u(0,1) = 5;
	    u(1,0) = 2; u(1,1) = 0;
	    std::cout << u.row_echelon() << "\n\n";
	}

	{
	    Matrix<2, 2, float> u;
	    u(0,0) = 0; u(0,1) = 0;
	    u(1,0) = 0; u(1,1) = 0;
	    std::cout << u.row_echelon() << "\n\n";
	}

	{
	    Matrix<2, 2, float> u;
	    u(0,0) = 1; u(0,1) = 0;
	    u(1,0) = 0; u(1,1) = 0;
	    std::cout << u.row_echelon() << "\n\n";
	}

	{
	    Matrix<3, 3, double> u;
	    u(0,0) = 1; u(0,1) = 0; u(0,2) = 0;
	    u(1,0) = 0; u(1,1) = 1; u(1,2) = 0;
	    u(2,0) = 0; u(2,1) = 0; u(2,2) = 1;
	    std::cout << u.row_echelon() << "\n\n";
	}

	{
	    Matrix<3, 5, double> u;
	    u(0,0) = 8;   u(0,1) = 5;   u(0,2) = -2;  u(0,3) = 4;  u(0,4) = 28;
	    u(1,0) = 4;   u(1,1) = 2.5; u(1,2) = 20;  u(1,3) = 4;  u(1,4) = -4;
	    u(2,0) = 8;   u(2,1) = 5;   u(2,2) = 1;   u(2,3) = 4;  u(2,4) = 17;
		std::cout << u << "\n\n";
		std::cout << u.row_echelon() << "\n\n";
	}
}

void test_determinant()
{
	Matrix2x2f u1(
		1.0, -1.0,
		-1.0,  1.0
	);
	std::cout << u1.determinant() << "\n"; 

	Matrix3x3f u2(
		2.0, 0.0, 0.0,
		0.0, 2.0, 0.0,
		0.0, 0.0, 2.0
	);
	std::cout << u2.determinant() << "\n";

	Matrix3x3f u3(
		8.0, 5.0, -2.0,
		4.0, 7.0, 20.0,
		7.0, 6.0, 1.0
	);

	std::cout << u3.determinant() << "\n";

	Matrix4x4f u4(
		8.0,  5.0, -2.0,  4.0,
		4.0,  2.5, 20.0,  4.0,
		8.0,  5.0,  1.0,  4.0,
		28.0, -4.0, 17.0,  1.0
	);
	std::cout << u4.determinant() << "\n"; 
}

void test_inverse()
{
	{
	    Matrix3x3f u = Matrix3x3f::Identity();
		std::cout << u << "\n\n";
		u.inverse();
		std::cout << u << "\n\n";
	}
// 	let u = Matrix::from([
// [1., 0., 0.],
// [0., 1., 0.],
// [0., 0., 1.],
// ]);
// println!("{}", u.inverse());
// // [1.0, 0.0, 0.0]
// // [0.0, 1.0, 0.0]
// // [0.0, 0.0, 1.0]
// let u = Matrix::from([
// [2., 0., 0.],
// [0., 2., 0.],
// [0., 0., 2.],
// ]);
// println!("{}", u.inverse());
// // [0.5, 0.0, 0.0]
// // [0.0, 0.5, 0.0]
// // [0.0, 0.0, 0.5]
// let u = Matrix::from([
// [8., 5., -2.],
// [4., 7., 20.],
// [7., 6., 1.],
// ]);
// println!("{}", u.inverse());
// // [0.649425287, 0.097701149, -0.655172414]
// // [-0.781609195, -0.126436782, 0.965517241]
// // [0.143678161, 0.074712644, -0.206896552]
// 50

}