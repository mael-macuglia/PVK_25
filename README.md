# Numerical Methods in Computer Science - C++ Examples

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg?style=flat&logo=c%2B%2B)](https://en.cppreference.com/w/cpp/17)
[![CMake](https://img.shields.io/badge/CMake-3.10%2B-green.svg?style=flat&logo=cmake)](https://cmake.org/)
[![Eigen](https://img.shields.io/badge/Eigen-3.4.0-orange.svg?style=flat)](https://eigen.tuxfamily.org/)

A comprehensive collection of C++ programming examples covering essential concepts for numerical computing and linear algebra, designed for computer science engineering students.

## 📋 Overview

This repository contains educational C++ code examples demonstrating:

- **C++ Template Programming**: Generic programming with function and class templates
- **Modern C++ Features**: Function objects, lambda expressions, STL containers and algorithms
- **Eigen Library Integration**: Matrix operations, linear algebra, and numerical computations
- **Linear System Solvers**: Both square and general (over/under-determined) linear systems
- **Advanced Linear Algebra**: SVD decomposition, matrix analysis, and numerical stability

## 🗂️ Repository Structure

```
PVK_25_code/
├── src/                           # Source code files
│   ├── cpp-template-vector-basic.cpp  # C++ templates and custom vector implementation
│   ├── cpp-functions.cpp              # Function objects, lambdas, and STL algorithms  
│   ├── some-eigen.cpp                 # Eigen library basics and matrix operations
│   ├── square-lin-sys.cpp             # Square linear system solvers
│   └── general-lin-sys.cpp            # General linear systems with SVD analysis
├── include/                       # Header files (if any)
├── CMakeLists.txt                # CMake build configuration
└── recap.md                      # Quick reference guide
```

## 🚀 Getting Started

### Prerequisites

- **C++ Compiler**: Supporting C++17 standard (GCC 7+, Clang 5+, MSVC 2017+)
- **CMake**: Version 3.10 or higher
- **Eigen Library**: Version 3.4.0 or higher

### Installation

#### On macOS (using Homebrew)
```bash
brew install cmake eigen
```

#### On Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install cmake libeigen3-dev
```

#### On Windows
- Download CMake from [cmake.org](https://cmake.org/download/)
- Download Eigen from [eigen.tuxfamily.org](https://eigen.tuxfamily.org/)

### Building the Project

1. **Clone the repository:**
   ```bash
   git clone https://github.com/yourusername/PVK_25_code.git
   cd PVK_25_code
   ```

2. **Create build directory:**
   ```bash
   mkdir build && cd build
   ```

3. **Configure and build:**
   ```bash
   cmake ..
   make
   ```

4. **Run examples:**
   ```bash
   ./cpp-template-vector-basic
   ./cpp-functions
   ./some-eigen
   ./square-lin-sys
   ./general-lin-sys
   ```

## 📚 Code Examples

### 1. C++ Templates (`cpp-template-vector-basic.cpp`)
- **Function Templates**: Generic functions with type parameters
- **Class Templates**: Custom vector implementation with dynamic memory management
- **Eigen Integration**: Template functions for linear algebra operations
- **SAXPY Operation**: Demonstrates `y = ax + y` computation

**Key Learning Points:**
- Template syntax and instantiation
- Memory management in C++
- Generic programming principles

### 2. Function Objects & STL (`cpp-functions.cpp`)
- **Function Objects**: Classes with `operator()` overload
- **Lambda Expressions**: Anonymous function objects
- **STL Algorithms**: `std::transform`, `std::for_each`
- **Tuple Operations**: `std::tuple`, `std::tie` for multiple return values

**Key Learning Points:**
- Functional programming in C++
- STL container manipulation
- Modern C++ features

### 3. Eigen Library Basics (`some-eigen.cpp`)
- **Matrix Operations**: Transpose, inverse, determinant, trace
- **Vector Operations**: Dot product, cross product, norms
- **Matrix Norms**: L1, L2, L∞, and custom p-norms
- **Type Aliases**: Dynamic matrices and vectors

**Key Learning Points:**
- Eigen library fundamentals
- Linear algebra operations
- Numerical computing concepts

### 4. Square Linear Systems (`square-lin-sys.cpp`)
- **Direct Solvers**: LU, QR, Cholesky decompositions
- **Iterative Methods**: Demonstrated through generic solver interface
- **Sparse Matrices**: Triplet format and sparse matrix operations
- **Performance Comparison**: Different solver approaches

**Key Learning Points:**
- Linear system solution methods
- Sparse vs. dense matrix operations
- Numerical solver selection

### 5. General Linear Systems (`general-lin-sys.cpp`)
- **SVD Decomposition**: Full and thin SVD computations
- **Rank Analysis**: Numerical rank determination
- **System Classification**: Over-determined, under-determined, and consistent systems
- **Least Squares Solutions**: Pseudo-inverse computations

**Key Learning Points:**
- SVD theory and applications
- Linear system analysis
- Numerical stability considerations

## 🎯 Learning Objectives

After studying these examples, students will understand:

1. **Template Programming**: How to write generic, reusable C++ code
2. **Modern C++ Features**: Effective use of STL and C++17 features
3. **Linear Algebra**: Practical implementation of matrix operations
4. **Numerical Methods**: Different approaches to solving linear systems
5. **Software Engineering**: Code organization, building, and documentation

## 📖 Quick Reference

The `recap.md` file contains a comprehensive cheat sheet covering:
- Eigen library quick reference
- Common matrix and vector operations
- Template syntax reminders
- STL algorithm usage patterns

## 🔧 Configuration Notes

- The project is configured to use **Debug mode** with debugging symbols
- **Eigen path** is set for Homebrew installation on macOS
- For different systems, modify the `EIGEN3_INCLUDE_DIR` in `CMakeLists.txt`

## 🤝 Contributing

This is an educational repository. For suggestions or improvements:
1. Fork the repository
2. Create a feature branch
3. Submit a pull request with detailed description

## 📄 License

This project is released under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍🏫 Academic Context

This repository was developed as supplementary material for a **Numerical Methods in Computer Science Engineering** course, focusing on practical C++ implementations of mathematical concepts essential for computational science and engineering applications.

---

**Note**: This repository demonstrates educational examples and may not be optimized for production use. The focus is on clarity and learning rather than performance optimization.