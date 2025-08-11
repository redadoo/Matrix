#pragma once

#define MAFT_CXX98_FLAG   (1 << 1)
#define MAFT_CXX03_FLAG   (1 << 2)
#define MAFT_CXX0X_FLAG   (1 << 3)
#define MAFT_CXX11_FLAG   (1 << 4)
#define MAFT_CXX14_FLAG   (1 << 5)
#define MAFT_CXX17_FLAG   (1 << 6)
#define MAFT_CXX20_FLAG   (1 << 7)

#define MAFT_CXX98        MAFT_CXX98_FLAG
#define MAFT_CXX03        (MAFT_CXX98 | MAFT_CXX03_FLAG)
#define MAFT_CXX0X        (MAFT_CXX03 | MAFT_CXX0X_FLAG)
#define MAFT_CXX11        (MAFT_CXX0X | MAFT_CXX11_FLAG)
#define MAFT_CXX14        (MAFT_CXX11 | MAFT_CXX14_FLAG)
#define MAFT_CXX17        (MAFT_CXX14 | MAFT_CXX17_FLAG)
#define MAFT_CXX20        (MAFT_CXX17 | MAFT_CXX20_FLAG)

#if __cplusplus >= 202002L
#   define MAFT_LANG MAFT_CXX20
#elif __cplusplus >= 201703L
#   define MAFT_LANG MAFT_CXX17
#elif __cplusplus >= 201402L
#   define MAFT_LANG MAFT_CXX14
#elif __cplusplus >= 201103L
#   define MAFT_LANG MAFT_CXX11
#else
#   define MAFT_LANG MAFT_CXX98
#endif

#define MAFT_COMPILER_UNKNOWN   0
#define MAFT_COMPILER_CLANG     (1 << 0)
#define MAFT_COMPILER_GCC       (1 << 1)
#define MAFT_COMPILER_MSVC      (1 << 2)

// Detect compiler
#if defined(__clang__)
#   define MAFT_COMPILER MAFT_COMPILER_CLANG
#elif defined(__ICC) || defined(__INTEL_COMPILER)
#   define MAFT_COMPILER MAFT_COMPILER_INTEL
#elif defined(__GNUC__) || defined(__GNUG__)
#   define MAFT_COMPILER MAFT_COMPILER_GCC
#elif defined(_MSC_VER)
#   define MAFT_COMPILER MAFT_COMPILER_MSVC
#else
#   define MAFT_COMPILER MAFT_COMPILER_UNKNOWN
#endif

#define MAFT_PLATFORM_UNKNOWN   0
#define MAFT_PLATFORM_WINDOWS   (1 << 0)
#define MAFT_PLATFORM_LINUX     (1 << 1)
#define MAFT_PLATFORM_MACOS     (1 << 2)

#if defined(_WIN32) || defined(_WIN64)
#   define MAFT_PLATFORM MAFT_PLATFORM_WINDOWS
#elif defined(__APPLE__) && defined(__MACH__)
#   define MAFT_PLATFORM MAFT_PLATFORM_MACOS
#elif defined(__linux__)
#   define MAFT_PLATFORM MAFT_PLATFORM_LINUX
#else
#   define MAFT_PLATFORM MAFT_PLATFORM_UNKNOWN
#endif

// TODO: implement other C++ features like initializer lists, = default, etc.

#if MAFT_LANG & MAFT_CXX17_FLAG
#   define MAFT_NODISCARD [[nodiscard]]
#else
#   define MAFT_NODISCARD
#endif

#if MAFT_COMPILER == MAFT_COMPILER_MSVC
#   define MAFT_FORCE_INLINE __forceinline
#elif MAFT_COMPILER == MAFT_COMPILER_GCC || MAFT_COMPILER == MAFT_COMPILER_CLANG
#   define MAFT_FORCE_INLINE inline __attribute__((always_inline))
#else
#   define MAFT_FORCE_INLINE inline
#endif

#if defined(__clang__)
#   define MAFT_HAS_CONSTEXPR __has_feature(cxx_relaxed_constexpr)
#elif (MAFT_LANG & MAFT_CXX14_FLAG)
#   define MAFT_HAS_CONSTEXPR 1
#else
#   define MAFT_HAS_CONSTEXPR 0
#endif

#if MAFT_HAS_CONSTEXPR
#   define MAFT_CONSTEXPR constexpr
#else
#   define MAFT_CONSTEXPR
#endif
