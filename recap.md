# Recap: C++ 

## C++ Template Basics ( *cpp-template-vector.cpp*)
- Template functions
- Template classes  
- Containers (covered in other courses)

## C++ Functions (*cpp-template-vector.cpp*)
- Function objects (classes)
  - Useful for interpolation and similar operations
- Lambda function objects
- `std::function<return_type(arg_type)>`
- `std::vector<>`
- `std::transform(inputBegin, inputEnd, outputBegin, function);`
- `std::for_each(begin, end, function);`
- `std::tuple<Type1, Type2, ...> tuple_name = { value1, value2, ... };`
- `std::tie(var1, var2, ...) = tuple_expression;`

## C++ Eigen Basics (*some-eigen.cpp*) [eigen-doc-Quick-Reference-Guide]
[eigen-doc-Quick-Reference-Guide]: https://eigen.tuxfamily.org/dox/group__QuickRefPage.html

#### Matrix Operations
- `.transpose()`: Transpose matrix
- `.inverse()`: Invert matrix
- `.determinant()`: Calculate determinant
- `.trace()`: Sum of diagonal elements
- `.sum()`, `.mean()`: Sum/average of all elements
- `.minCoeff()`, `.maxCoeff()`: Min/max element
- `.diagonal()`: Extract diagonal
- `.block(i,j,m,n)`: Extract submatrix
- `.array()`, `.matrix()`: Convert to/from array
- `.cwiseProduct()`, `.cwiseQuotient()`: Element-wise multiplication/division
- `.norm()`, `.normalized()`: Calculate norm/normalize

#### Vector Operations
- `.dot(v)`: Dot product
- `.cross(v)`: Cross product (3D vectors)
- `.squaredNorm()`: Squared L2 norm
- `.asDiagonal()`: Create diagonal matrix from vector
- `.segment(i,n)`: Extract subvector

#### Norms
- L1: `.lpNorm<1>()`
- L2: `.norm()` or `.lpNorm<2>()`
- L-infinity: `.lpNorm<Eigen::Infinity>()`
- Custom p: `.lpNorm<p>()`

#### Initialization
- `dynMat_t<double>::Zero(rows,cols)`
- `dynMat_t<double>::Ones(rows,cols)`
- `dynMat_t<double>::Identity(rows,cols)`
- `dynMat_t<double>::Random(rows,cols)`
- `dynColVec_t<double>::LinSpaced(size, start, end)`

#### Type Aliases
```cpp
template<typename Scalar>
using dynMat_t = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>;
using dynColVec_t = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;
using dynRowVec_t = Eigen::Matrix<Scalar, 1, Eigen::Dynamic>;
using index_t = typename Eigen::Index;
using entry_t = typename dynMat_t<Scalar>::Scalar;





