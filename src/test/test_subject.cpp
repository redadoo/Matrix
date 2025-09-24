#include "Maft.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cassert>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

inline int g_passed = 0;
inline int g_failed = 0;

#define TEST_ASSERT(cond) \
	do { \
		if (!(cond)) { \
			g_failed++; \
			std::cerr << RED << "[FAIL] " << __FILE__ << ":" << __LINE__ \
					  << " | Condition: " << #cond << RESET << std::endl; \
		} else { \
			g_passed++; \
			std::cout << GREEN << "[PASS]" << RESET << " " << #cond << std::endl; \
		} \
	} while(0)


using namespace Maft;

void print_colored_test(const char * test_name, const char * color)
{
	std::cout << RESET << color << "===== Test " << test_name << "=====\n" << RESET << "\n";
}

void test_vector_operations() 
{
	print_colored_test("Vector operations", YELLOW);
	print_colored_test(".Add()", BLUE);

	{
		Vector2i v1{2, 3};
		Vector2i v2{5, 7};
		std::cout << "[int] v1: " << v1 << "\n";
		std::cout << "[int] v2: " << v2 << "\n";
		v1.Add(v2);
		TEST_ASSERT((v1 == Vector2i{7, 10}));
	}

	{
		Vector2f v1{2.5f, 3.2f};
		Vector2f v2{5.0f, 7.0f};
		std::cout << "[float] v1: " << v1 << "\n";
		std::cout << "[float] v2: " << v2 << "\n";
		v1.Add(v2);
		TEST_ASSERT((v1 == Vector2f{7.5f, 10.2f}));
	}

	{
		Vector2d v1{2.0, 3.0};
		const Vector2d v2{5.0, 7.0};
		std::cout << "[double] v1: " << v1 << "\n";
		std::cout << "[double] v2: " << v2 << "\n";
		v1.Add(v2);
		std::cout << "[double] v1 after Add(v2): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2d{7.0, 10.0}));
	}

	print_colored_test(".Subtract()", BLUE);

	{
		Vector2i v1{2, 3};
		Vector2i v2{5, 7};
		std::cout << "[int] v1: " << v1 << "\n";
		std::cout << "[int] v2: " << v2 << "\n";
		v1.Subtract(v2);
		std::cout << "[int] v1 after Subtract(v2): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2i{-3, -4}));
	}

	{
		Vector2f v1{2.0f, 3.0f};
		Vector2f v2{5.0f, 7.0f};
		std::cout << "[float] v1: " << v1 << "\n";
		std::cout << "[float] v2: " << v2 << "\n";
		v1.Subtract(v2);
		std::cout << "[float] v1 after Subtract(v2): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2f{-3.0f, -4.0f}));
	}

	{
		Vector2d v1{2.0, 3.0};
		Vector2d v2{5.0, 7.0};
		std::cout << "[double] v1: " << v1 << "\n";
		std::cout << "[double] v2: " << v2 << "\n";
		v1.Subtract(v2);
		std::cout << "[double] v1 after Subtract(v2): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2d{-3.0, -4.0}));
	}

	print_colored_test(".Scale()", BLUE);

	{
		Vector2i v1{2, 3};
		std::cout << "[int] v1: " << v1 << "\n";
		v1.Scale(2);
		std::cout << "[int] v1 after Scale(2): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2i{4, 6}));
	}

	{
		Vector2f v1{2.0f, 3.0f};
		std::cout << "[float] v1: " << v1 << "\n";
		v1.Scale(2.0f);
		std::cout << "[float] v1 after Scale(2.0f): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2f{4.0f, 6.0f}));
	}

	{
		Vector2d v1{2.0, 3.0};
		std::cout << "[double] v1: " << v1 << "\n";
		v1.Scale(2.0);
		std::cout << "[double] v1 after Scale(2.0): " << v1 << "\n";
		TEST_ASSERT((v1 == Vector2d{4.0, 6.0}));
	}
}

void test_matrix_operations() 
{
	print_colored_test("Matrix operations", YELLOW);
	print_colored_test(".Add()", BLUE);
	{
		Matrix2x2i mat1{
			1, 2,
			3, 4
		};
		Matrix2x2i mat2{
			7, 4,
			-2, 2
		};

		std::cout << "[int] mat1: \n" << mat1 << std::endl;
		std::cout << "[int] mat2: \n" << mat2 << std::endl;

		mat1.Add(mat2);

		std::cout << "[int] mat1 after Add(mat2): \n" << mat1 << std::endl;
		TEST_ASSERT((mat1 == Matrix2x2i{
			8, 6,
			1, 6
		}));
	}

	{
		Matrix2x2f mat1{
			1.f, 2.f,
			3.f, 4.f
		};
		Matrix2x2f mat2{
			7.f, 4.f,
			-2.f, 2.f
		};

		std::cout << "[float] mat1: \n" << mat1 << std::endl;
		std::cout << "[float] mat2: \n" << mat2 << std::endl;

		mat1.Add(mat2);

		std::cout << "[float] mat1 after Add(mat2): \n" << mat1 << std::endl;
		TEST_ASSERT((mat1 == Matrix2x2f{
			8.f, 6.f,
			1.f, 6.f
		}));
	}
	print_colored_test(".Subtract()", BLUE);

	{
		Matrix2x2i mat1{
			1, 2,
			3, 4
		};
		Matrix2x2i mat2{
			7, 4,
			-2, 2
		};

		std::cout << "[int] mat1: \n" << mat1 << std::endl;
		std::cout << "[int] mat2: \n" << mat2 << std::endl;

		mat1.Subtract(mat2);

		std::cout << "[int] mat1 after Subtract(mat2): \n" << mat1 << std::endl;
		TEST_ASSERT((mat1 == Matrix2x2i{
			-6, -2,
			5, 2
		}));
	}

	{
		Matrix2x2f mat1{
			1.f, 2.f,
			3.f, 4.f
		};
		Matrix2x2f mat2{
			7.f, 4.f,
			-2.f, 2.f
		};

		std::cout << "[float] mat1: \n" << mat1 << std::endl;
		std::cout << "[float] mat2: \n" << mat2 << std::endl;

		mat1.Subtract(mat2);

		std::cout << "[float] mat1 after Subtract(mat2): \n" << mat1 << std::endl;
		TEST_ASSERT((mat1 == Matrix2x2f{
			-6.f, -2.f,
			5.f, 2.f
		}));
	}

	{
		Matrix2x2d mat1{
			1., 2.,
			3., 4.
		};

		Matrix2x2d mat2{
			7., 4.,
			-2., 2.
		};

		std::cout << "[double] mat1: \n" << mat1 << std::endl;
		std::cout << "[double] mat2: \n" << mat2 << std::endl;

		mat1.Subtract(mat2);

		std::cout << "[double] mat1 after Subtract(mat2): \n" << mat1 << std::endl;
		TEST_ASSERT((mat1 == Matrix2x2d{
			-6., -2.,
			5., 2.
		}));
	}

	print_colored_test(".Scale()", BLUE);

	{
		Matrix2x2i mat{
			1, 2,
			3, 4
		};
		std::cout << "[int] mat before Scale: \n" << mat << std::endl;

		mat.Scale(2);

		std::cout << "[int] mat after Scale(2): \n" << mat << std::endl;
		TEST_ASSERT((mat == Matrix2x2i{
			2, 4,
			6, 8
		}));
	}

	{
		Matrix2x2f mat{
			1.f, 2.f,
			3.f, 4.f
		};
		std::cout << "[float] mat before Scale: \n" << mat << std::endl;

		mat.Scale(2.f);

		std::cout << "[float] mat after Scale(2.f): \n" << mat << std::endl;
		TEST_ASSERT((mat == Matrix2x2f{
			2.f, 4.f,
			6.f, 8.f
		}));
	}

	{
		Matrix2x2d mat{
			1., 2.,
			3., 4.
		};
		std::cout << "[double] mat before Scale: \n" << mat << std::endl;

		mat.Scale(2.);

		std::cout << "[double] mat after Scale(2.): \n" << mat << std::endl;
		TEST_ASSERT((mat == Matrix2x2d{
			2., 4.,
			6., 8.
		}));
	}
}

void test_linear_combination() 
{
	print_colored_test("linear_combination", YELLOW);

	Vector3f e1{1.f, 0.f, 0.f};
	Vector3f e2{0.f, 1.f, 0.f};
	Vector3f e3{0.f, 0.f, 1.f};
	Vector3f v1{1.f, 2.f, 3.f};
	Vector3f v2{0.f, 10.f, -100.f};

	{
		std::vector<Vector3f> basis1 = {e1, e2, e3};
		auto res1 = Vector3f::LinearCombination(basis1, {10.f, -2.f, 0.5f});
		std::cout << "res1 = " << res1 << "\n";
		TEST_ASSERT((res1 == Vector3f{10.f, -2.f, 0.5f}));
	}

	{
		std::vector<Vector3f> basis2 = {v1, v2};
		auto res2 = Vector3f::LinearCombination(basis2, {10.f, -2.f});
		std::cout << "res2 = " << res2 << "\n";
		TEST_ASSERT((res2 == Vector3f{10.f, 0.f, 230.f}));
	}
}

void test_lerp()
{
	print_colored_test("lerp", YELLOW);
	print_colored_test("vector lerp", BLUE);

	Vector2f v1{2.f, 1.f};
	Vector2f v2{4.f, 2.f};
	float t = 0.3f;

	Vector2f v_lerp = Vector2f::Lerp(v1, v2, t);
	
	std::cout << "v1: " << v1 << "\n";
	std::cout << "v2: " << v2 << "\n";
	std::cout << "lerped vector by " << t << " : " << v_lerp << "\n";

	TEST_ASSERT((v_lerp == Vector2f{2.6f, 1.3f}));

	print_colored_test("matrix lerp", BLUE);

	Matrix2x2f m1{
		2.f, 1.f, 
		3.f, 4.f
	};
	Matrix2x2f m2{
		20.f, 10.f, 
		30.f, 40.f
	};
	
	t += 0.2;

	Matrix2x2f m_lerp = Matrix2x2f::Lerp(m1, m2, t);

	std::cout << "m1: \n" << m1 << "\n";
	std::cout << "m2: \n" << m2 << "\n";
	std::cout << "lerped matrix by " << t << " : " << m_lerp << "\n";

	TEST_ASSERT((m_lerp == Matrix2x2f{11.f, 5.5f, 16.5f, 22.f}));
}

void test_dot()
{
	print_colored_test("dot_product", YELLOW);

	Vector2f v1{0.0f, 0.0f};
	Vector2f v2{1.0f, 1.0f};
	std::cout << v1 << " · " << v2 << " = " << v1.Dot(v2) << "\n";
	TEST_ASSERT(v1.Dot(v2) == 0.0f);

	Vector2f v3{1.0f, 1.0f};
	Vector2f v4{1.0f, 1.0f};
	std::cout << v3 << " · " << v4 << " = " << v3.Dot(v4) << "\n";
	TEST_ASSERT(v3.Dot(v4) == 2.0f);

	Vector2f v5{-1.0f, 6.0f};
	Vector2f v6{3.0f, 2.0f};
	std::cout << v5 << " · " << v6 << " = " << v5.Dot(v6) << "\n";
	TEST_ASSERT(v5.Dot(v6) == 9.0f);
}

void test_norm()
{
	print_colored_test("norm", YELLOW);

	Vector3f v1{0., 0., 0.};
	std::cout << "v1: " << v1 << "\n";
	std::cout << "norm_1: " << v1.norm_1() 
			  << ", norm_2: " << v1.norm() 
			  << ", norm_inf: " << v1.norm_inf() << "\n";
	TEST_ASSERT(v1.norm_1() == 0.);
	TEST_ASSERT(v1.norm() == 0.);
	TEST_ASSERT(v1.norm_inf() == 0.);

	Vector3f v2{1., 2., 3.};
	std::cout << "v2: " << v2 << "\n";
	std::cout << "norm_1: " << v2.norm_1() 
			  << ", norm_2: " << v2.norm() 
			  << ", norm_inf: " << v2.norm_inf() << "\n";
	TEST_ASSERT(v2.norm_1() == 6.);
	TEST_ASSERT(v2.norm() == sqrt(14.0f));
	TEST_ASSERT(v2.norm_inf() == 3.);

	Vector2f v3{-1., -2.};
	std::cout << "v3: " << v3 << "\n";
	std::cout << "norm_1: " << v3.norm_1() 
			  << ", norm_2: " << v3.norm() 
			  << ", norm_inf: " << v3.norm_inf() << "\n";
	TEST_ASSERT(v3.norm_1() == 3.);
	TEST_ASSERT(v3.norm() == sqrt(5.0f));
	TEST_ASSERT(v3.norm_inf() == 2.);
}

void test_angle_cos()
{
	print_colored_test("angle cosine", YELLOW);

	{
		Vector2f u1{1.0f, 0.0f};
		Vector2f v1{1.0f, 0.0f};
		std::cout << "u1 : " << u1 << "  " << "v1 : " << v1 << "\n";
		float cos1 = Vector2f::angle_cos(u1, v1);
		std::cout << "cos1 = " << cos1 << "\n";
		TEST_ASSERT(cos1 == 1.0f);
	}

	{
		Vector2f u1{1.0f, 0.0f};
		Vector2f v1{0.0f, 1.0f};
		std::cout << "u1 : " << u1 << "  " << "v1 : " << v1 << "\n";
		float cos1 = Vector2f::angle_cos(u1, v1);
		std::cout << "cos1 = " << cos1 << "\n";
		TEST_ASSERT(cos1 == 0.0f);
	}

	{
		Vector2d u1{-1.0f, 1.0f};
		Vector2d v1{1.0f, -1.0f};
		std::cout << "u1 : " << u1 << "  " << "v1 : " << v1 << "\n";
		float cos1 = Vector2d::angle_cos(u1, v1);
		std::cout << "cos1 = " << cos1 << "\n";
		TEST_ASSERT(cos1 == -1.0f);
	}
}

void test_cross_product()
{
	print_colored_test("cross product", YELLOW);

	{
		Vector3f u1{0.0f, 0.0f, 1.0f};
		Vector3f v1{1.0f, 0.0f, 0.0f};
		std::cout << "u1 : " << u1 << "  " << "v1 : " << v1 << "\n";
		Vector3f cross1 = Vector3f::cross_product(u1, v1);
		std::cout << "cross1 = " << cross1 << "\n";
		TEST_ASSERT((cross1 == Vector3f{0.0f, 1.0f, 0.0f}));
	}

	{
		Vector3f u1{1.0f, 2.0f, 3.0f};
		Vector3f v1{4.0f, 5.0f, 6.0f};
		std::cout << "u1 : " << u1 << "  " << "v1 : " << v1 << "\n";
		Vector3f cross1 = Vector3f::cross_product(u1, v1);
		std::cout << "cross1 = " << cross1 << "\n";
		TEST_ASSERT((cross1 == Vector3f{-3.0f, 6.0f, -3.0f}));
	}

	{
		Vector3f u1{4.0f, 2.0f, -3.0f};
		Vector3f v1{-2.0f, -5.0f, 16.0f};
		std::cout << "u1 : " << u1 << "  " << "v1 : " << v1 << "\n";
		Vector3f cross1 = Vector3f::cross_product(u1, v1);
		std::cout << "cross1 = " << cross1 << "\n";
		TEST_ASSERT((cross1 == Vector3f{17.0f, -58.0f, -16.0f}));
	}

}

void test_matrix_multiplication()
{
	print_colored_test("Matrix multiplication", YELLOW);

	{
		Matrix2x2f u = Matrix2x2f::Identity();
		Vector2f v{4.f, 2.f};
		Vector2f res = u.multiply_vector(v);
		std::cout << "u : \n" << u << "\n";
		std::cout << "v : " << v << "\n";
		std::cout << "res = " << res << "\n";
		TEST_ASSERT((res == Vector2f{4.f, 2.f}));
	}

	{
		Matrix2x2f u(
			2.f, 0.f, 
			0.f, 2.f
		);
		Vector2f v{4.f, 2.f};
		Vector2f res = u.multiply_vector(v);
		std::cout << "u : \n" << u << "\n";
		std::cout << "v : " << v << "\n";
		std::cout << "res = " << res << "\n";
		TEST_ASSERT((res == Vector2f{8.f, 4.f}));
	}

	{
		Matrix2x2f u(
			2.f, -2.f,
			-2.f, 2.f
		);
		Vector2f v{4.f, 2.f};
		Vector2f res = u.multiply_vector(v);
		std::cout << "u : \n" << u << "\n";
		std::cout << "v : " << v << "\n";
		std::cout << "res = " << res << "\n";
		TEST_ASSERT((res == Vector2f{4.f, -4.f}));
	}

	{
		Matrix2x2f u = Matrix2x2f::Identity();
		Matrix2x2f v = Matrix2x2f::Identity();
		Matrix2x2f res = u.multiply_matrix(v);
		std::cout << "u : \n" << u << "\n";
		std::cout << "v : \n" << v << "\n";
		std::cout << "res = \n" << res << "\n";
		TEST_ASSERT((res == Matrix2x2f::Identity()));
	}

	{
		Matrix2x2f u = Matrix2x2f::Identity();
		Matrix2x2f v(
			2.f, 1.f,
			4.f, 2.f
		);
		Matrix2x2f res = u.multiply_matrix(v);
		std::cout << "u : \n" << u << "\n";
		std::cout << "v : \n" << v << "\n";
		std::cout << "res = \n" << res << "\n";
		TEST_ASSERT((res == v));
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
		Matrix2x2f res = u.multiply_matrix(v);
		std::cout << "u : \n" << u << "\n";
		std::cout << "v : \n" << v << "\n";
		std::cout << "res6 = \n" << res << "\n";
		TEST_ASSERT((res == Matrix2x2f{-14.f, -7.f, 44.f, 22.f}));
	}
}

void test_trace()
{
	print_colored_test("Matrix trace", YELLOW);

	{
		Matrix2x2f u1(
			1.0, 0.0,
			0.0, 1.0
		);
		float tr1 = u1.trace();
		std::cout << "u1:\n" << u1 << "\n";
		std::cout << "trace = " << tr1 << "\n";
		TEST_ASSERT(tr1 == 2.0);
	}

	{
		Matrix3x3f u2(
			2.0, -5.0, 0.0,
			4.0,  3.0, 7.0,
		   -2.0,  3.0, 4.0
		);
		float tr2 = u2.trace();
		std::cout << "u2:\n" << u2 << "\n";
		std::cout << "trace = " << tr2 << "\n";
		TEST_ASSERT(tr2 == 9.0);
	}

	{
		Matrix3x3f u3(
			-2.0, -8.0,  4.0,
			 1.0, -23.0, 4.0,
			 0.0,  6.0,  4.0
		);
		float tr3 = u3.trace();
		std::cout << "u3:\n" << u3 << "\n";
		std::cout << "trace = " << tr3 << "\n";
		TEST_ASSERT(tr3 == -21);
	}
}

void test_transpose()
{
	print_colored_test("Matrix transpose", YELLOW);

	{
		Maft::Matrix<3, 2, float> m{
			1.0, 3.0, 5.0,
			2.0, 4.0, 6.0
		};

		std::cout << "m:\n" << m << "\n";

		auto t = m.transpose();

		std::cout << "transpose(m2):\n" << t << "\n";

		TEST_ASSERT((t == Maft::Matrix<2, 3, float>{
			1,2,
			3,4,
			5,6
		}));
	}

	{
		Maft::Matrix<2, 3, float> m{
			-1.0, 4.0,
			-2.0, 5.0,
			-3.0, 6.0 
		};

		auto t = m.transpose();

		std::cout << "m:\n" << m << "\n";
		std::cout << "transpose(m3):\n" << t << "\n";

		TEST_ASSERT((t == Maft::Matrix<3, 2, float>{
			-1,-2,-3,
			4,5,6
		}));
	}
}

void test_row_echelon()
{

	print_colored_test("Matrix row echelon form", YELLOW);

	{
		Matrix2x2f u(
			2, 3,
			4, 5
		);

		std::cout << "u: \n" << u << "\n\n";
		Matrix2x2f res = u.row_echelon();
		std::cout << "row echelon form\n" << res << "\n\n";

		TEST_ASSERT(res == Matrix2x2f(
			2, 3,
			0, -1
		));

	}

	{
		Matrix2x2f u(
			1, 2,
			3, 4
		);
		std::cout << "u: \n" << u << "\n\n";
		Matrix2x2f res = u.row_echelon();
		std::cout << "row echelon form\n" << res << "\n\n";

		TEST_ASSERT(res == Matrix2x2f(
			1, 2,
			0, -2
		));
	}
	
	{
		Matrix2x2f u(
			1, 2,
			2, 4
		);
		
		std::cout << "u: \n" << u << "\n\n";
		Matrix2x2f res = u.row_echelon();
		std::cout << "row echelon form\n" << res << "\n\n";

		TEST_ASSERT(res == Matrix2x2f(
			1, 2,
			0, 0
		));	}

	{
		Matrix3x3f u = Matrix3x3f::Identity();
		
		std::cout << "u: \n" << u << "\n\n";
		Matrix3x3f res = u.row_echelon();
		std::cout << "row echelon form\n" << res << "\n\n";

		TEST_ASSERT(res == Matrix3x3f::Identity());	
	}	
}

void test_determinant()
{
	print_colored_test("matrix Determinant", YELLOW);

	{
		Matrix2x2f u(
			1.0, -1.0,
			-1.0,  1.0
		);

		std::cout << "matrix: \n"<< u << "\n"; 
		auto res = u.determinant();
		TEST_ASSERT(res == 0);
	}

	{
		Matrix3x3f u(
			2.0, 0.0, 0.0,
			0.0, 2.0, 0.0,
			0.0, 0.0, 2.0
		);

		std::cout << "matrix: \n"<< u << "\n"; 
		auto res = u.determinant();
		TEST_ASSERT(res == 8);
	}

	{
		Matrix3x3f u(
			8.0, 5.0, -2.0,
			4.0, 7.0, 20.0,
			7.0, 6.0, 1.0
		);

		std::cout << "matrix: \n"<< u << "\n"; 
		auto res = u.determinant();
		TEST_ASSERT(res == -174);
	}

	{
		Matrix4x4f u(
			8.0,  5.0, -2.0,  4.0,
			4.0,  2.5, 20.0,  4.0,
			8.0,  5.0,  1.0,  4.0,
			28.0, -4.0, 17.0,  1.0
		);

		std::cout << "matrix: \n"<< u << "\n"; 
		auto res = u.determinant();
		TEST_ASSERT(res == 1032);
	}
}

void test_inverse()
{
	print_colored_test("matrix inverse", YELLOW);

	{
		Matrix3x3f u = Matrix3x3f::Identity(); 
		std::cout << u << "\n\n";
		Matrix3x3f inverse = u.inverse(); 
		std::cout << inverse << "\n\n";
		TEST_ASSERT((inverse == Matrix3x3f::Identity()));
	}

	{
		Matrix3x3f u(
			2.0f, 0.0f, 0.0f,
			0.0f, 2.0f, 0.0f,
			0.0f, 0.0f, 2.0f		
		);
		std::cout << u << "\n\n";
		Matrix3x3f inverse = u.inverse(); 
		std::cout << inverse << "\n\n";
		TEST_ASSERT((inverse == Matrix3x3f(
			0.5f, 0.0f, 0.0f,
			0.0f, 0.5f, 0.0f,
			0.0f, 0.0f, 0.5f 
		)));
	}

	{
		Matrix3x3d u(
			8.0f, 5.0f, -2.0f,
			4.0f, 7.0f, 20.0f,
			7.0f, 6.0f, 1.0f		
		);
		std::cout << u << "\n\n";
		Matrix3x3d inverse = u.inverse(); 
		std::cout << inverse << "\n\n";
		// TEST_ASSERT((inverse == Matrix3x3d(
		// 	0.649425, 0.0977011, -0.655172,
		// 	-0.781609, -0.126437, 0.965517,
		// 	0.143678, 0.0747126, -0.206897 
		// )));
	}
}

void test_rank()
{
	print_colored_test("matrix rank", YELLOW);

	{
		Matrix3x3f u = Matrix3x3f::Identity(); 
		std::cout << u << "\n\n";
		auto rank = u.rank();
		TEST_ASSERT(rank == 3);
	}

	//TODO: fix
	{
		Matrix<3, 4, float> u{
			1.0f, 2.0f, 0.0f, 0.0f,
			2.0f, 4.0f, 0.0f, 0.0f,
		   -1.0f, 2.0f, 1.0f, 1.0f
		};
		std::cout << u << "\n\n";
		auto rank = u.rank();
		TEST_ASSERT(rank == 2);
	}

	{
		Matrix<4, 3, float> u{
			 8.f,  5.f, -2.f,
			 4.f,  7.f, 20.f,
			 7.f,  6.f,  1.f,
			21.f, 18.f,  7.f
		};
		std::cout << u << "\n\n";
		auto rank = u.rank();
		TEST_ASSERT(rank == 3);
	}

	// {
	// 	Matrix3x3f u{
	// 		0.f, 0.f, 0.f,
	// 		0.f, 0.f, 0.f,
	// 		0.f, 0.f, 0.f
	// 	};
	// 	std::cout << u << "\n\n";
	// 	auto rank = u.rank();
	// 	TEST_ASSERT(rank == 0);
	// }

	// {
	// 	Matrix3x3f u{
	// 		1.f, 2.f, 3.f,
	// 		4.f, 5.f, 6.f,
	// 		5.f, 7.f, 9.f
	// 	};

	// 	std::cout << u << "\n\n";
	// 	auto rank = u.rank();
	// 	TEST_ASSERT(rank == 2);
	// }

	// {
	// 	Matrix<2, 4, float> u{
	// 		1.f, 0.f, 1.f, 0.f,
	// 		0.f, 1.f, 0.f, 1.f
	// 	};

	// 	std::cout << u << "\n\n";
	// 	auto rank = u.rank();
	// 	TEST_ASSERT(rank == 2);
	// }
}

void all_test()
{
	test_vector_operations();
	test_matrix_operations();
	test_linear_combination();
	test_lerp();
	test_dot();
	test_norm();
	test_angle_cos();
	test_cross_product();
	test_matrix_multiplication();
	test_trace();
	test_transpose();
	test_row_echelon();
	test_determinant();
	test_inverse();
	test_rank();

	
	std::cout << "\n===== SUMMARY =====\n";
	std::cout << YELLOW << " Total test : " << g_failed + g_passed << "\n" << GREEN << g_passed << " passed" << RESET << ", "
			  << RED   << g_failed << " failed" << RESET << "\n";
}