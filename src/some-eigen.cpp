#include <iostream>
#include <cmath>
#include <Eigen/Dense>

//CHEATSHEET
    // Common Eigen matrix operations:
    // .transpose()    - Transpose matrix
    // .inverse()      - Invert matrix
    // .determinant()  - Calculate determinant
    // .trace()        - Sum of diagonal elements
    // .sum()          - Sum of all elements
    // .mean()         - Average of all elements
    // .minCoeff()     - Minimum element
    // .maxCoeff()     - Maximum element
    // .diagonal()     - Extract diagonal
    // .block(i,j,m,n) - Extract submatrix
    // .array()        - Convert to array for element-wise ops
    // .matrix()       - Convert array back to matrix
    // .cwiseProduct() - Element-wise multiplication
    // .cwiseQuotient()- Element-wise division
    // .norm()         - Calculate norm 
    // .normalized()   - Normalize vector/matrix

    // Vector operations:
    // .dot(v)         - Dot product
    // .cross(v)       - Cross product (3D vectors)
    // .normalized()   - Unit vector
    // .squaredNorm()  - Squared L2 norm
    // .asDiagonal()   - Create diagonal matrix from vector
    // .segment(i,n)   - Extract subvector

    // L1 norm: matrix.lpNorm<1>()
    // L2 norm: matrix.norm() or matrix.lpNorm<2>()
    // L-infinity norm: matrix.lpNorm<Eigen::Infinity>()
    // Custom p-norm: matrix.lpNorm<p>()


// Generic print template
template <typename T>
void print(const std::string& message ,const T& value) {
    std::cout<< "\n------------------\n";
    std::cout << message <<":\n"<<"\n"<< value << std::endl;
    std::cout<< "------------------\n";
}


//  Dynamic (variable size) matrices
template<typename Scalar>
using dynMat_t = Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic>; 
// Dynamic (variable size) column vectors
template<typename Scalar>
using dynColVec_t = Eigen::Matrix<Scalar ,Eigen::Dynamic,1>;
// Dynamic (variable size) row vectors
template<typename Scalar>
using dynRowVec_t = Eigen::Matrix<Scalar ,1,Eigen::Dynamic>;

// Using Eigen::Index ensures Eigen can handle large matrices and vectors without integer overflow issues
using index_t = typename Eigen::Index;
// Note: Scalar is used in two contexts here:
// 1. As a template parameter for dynMat_t
// 2. As an internal typedef in Eigen::Matrix (accessed via ::Scalar)
// This definition allows entry_t to match the scalar type of dynMat_t
template<typename Scalar>
using entry_t = typename dynMat_t<Scalar>::Scalar;

int main() {
    index_t rows = 3;
    index_t cols = 4;
    // EXAMPLE:    Initializing special matrices in EIGEN
    //------------------------------------------
    dynMat_t<double> A = dynMat_t<double>::Zero(rows,cols);
    print("Zeros Matrix: ", A);
    
    dynMat_t<double> B = dynMat_t<double>::Ones(rows,cols);
    print("Ones Matrix: ", B);

    dynMat_t<double> I = dynMat_t<double>::Identity(rows,cols);
    print("Identity Matrix: ", I);
    
    dynMat_t<double> R = dynMat_t<double>::Random(rows,cols);
    print("Random Matrix: ", R);

    
    // Matrix -> array for entriwise operations Array->Matrix
    // ensure positive entries  
    dynMat_t<double> log_R = (100* (R.array().abs()) ).log().matrix();
    print("matrix to array-log-array to matrix ",log_R);
    // Same operations BUT using the matrix.unaryExpr()
    // declare the function object 
    auto f = [](entry_t<double> x){
        return std::log(std::abs(x)*100);
    };
    dynMat_t<double> log_R_2 = R.unaryExpr(f);
    print("matrix unaryExpr and functor ",log_R);

 
// Simple initialization (fixed size, known at compile time)
    Eigen::Matrix3d m = Eigen::Matrix3d::Random();
    Eigen::Vector3d v ;
    v << 1,2,3;  
    Eigen::Vector3d mv = m * v; 
// Most common initalisation of vector 
    dynColVec_t<double> v1 = dynColVec_t<double>::LinSpaced(cols,0,1); 
    dynColVec_t<double> R_v1 = R*v1 ; 
    print("R_v1", R_v1);
    print("l1-norm R_v1", R_v1.lpNorm<1>());
    print("l2-norm R_v1", R_v1.lpNorm<2>());
    


    return 0;
}
