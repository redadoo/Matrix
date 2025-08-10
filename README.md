# Matrix

![GitHub repo size](https://img.shields.io/github/repo-size/redadoo/matrix)
![GitHub contributors](https://img.shields.io/github/contributors/redadoo/matrix)
![GitHub stars](https://img.shields.io/github/stars/redadoo/matrix?style=social)
![GitHub forks](https://img.shields.io/github/forks/redadoo/matrix?style=social)

---

## Table of Contents

* [About](#about)
* [Project Requirements](#project-requirements)
* [Technical Constraints](#technical-constraints)
* [Usage](#usage)
* [Resources](#resources)
* [Articles & Further Reading](#articles--further-reading)
* [Other Math Libraries](#other-math-libraries)

---

## About

This project is part of the 42 curriculum and serves as an introduction to **linear algebra**, implemented in **C++**.
It provides a foundational understanding of vectors, matrices, linear maps, and related algebraic operations, essential for fields like computer graphics, physics simulations, and data science.

The purpose is to implement your own linear algebra library by recreating core vector and matrix operations, without using external math libraries.

Read the [Subject](./en.subject.pdf) for the full details.

## Project Requirements

* Implement a generic `Vector` and `Matrix` class using templates.
* Support common linear algebra operations:

  * Add, subtract, and scale vectors/matrices
  * Dot and cross products
  * Norms (L1, L2, ∞)
  * Cosine similarity and linear interpolation
  * Matrix multiplication and transpose
  * Row echelon form and determinant (up to 4×4)
  * Inverse and projection matrix (bonus)
* Provide a `main.cpp` with test cases for each operation.

---

## Technical Constraints

* Language: C++
* No use of math libraries (including standard math libs unless explicitly allowed)
* Must use:

  * Generic types (templates)
  * Pure or consistent function design
* Operator overloading is optional but encouraged
* Respect the stated time and space complexity per exercise
* All matrices must use **column-major order**
* Provide a working `Makefile`

---

## Usage

To build the project:

```bash
make
```

To build and run the test executable:

```bash
make run
```
---

## Resources

* [Essence of Linear Algebra — 3Blue1Brown](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
* [Linear Algebra in C++](https://www.youtube.com/watch?v=VofMMbD2QtQ&list=PL3WoIG-PLjSv9vFx2dg0BqzDZH_6qzF8-)

---

## Articles & Further Reading

* [Vector Math Library Codegen in Debug](https://aras-p.info/blog/2024/09/14/Vector-math-library-codegen-in-Debug/)
* [Vector Types and Debug Performance](https://blog.s-schoener.com/2025-08-07-vector-debug-codegen/)
* [simd](http://const.me/articles/simd/simd.pdf)

---

## Other Math Libraries

For further reading and reference, here are some math and linear algebra libraries:

* **[GLM](https://github.com/g-truc/glm)**
* **[HLSL++](https://github.com/redorav/hlslpp)**
* **[linalg](https://github.com/sgorsten/linalg)**
* **[lyah](https://github.com/atalantestudio/lyah)**
