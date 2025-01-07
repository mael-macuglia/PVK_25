#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <vector>

using namespace Eigen;
using namespace std;

// Template function that can work with any solver type (Note trty to understand the following )
template<typename SolverType, typename MatrixType>
void solve_and_print(const MatrixType& A, const Matrix< typename MatrixType::Scalar,Dynamic,1> & b) {
    
    SolverType solver;
    solver.compute(A); 
    Vector3d x = solver.solve(b);

    
    cout << "\nSolving with " << typeid(SolverType).name() << endl;
    cout << "Solution x = \n" << x << endl;
    cout << "Verification A*x = \n" << A*x << endl;
    cout << "Error: " << (A*x - b).norm() << endl;
}


template<typename DerivedMatrix>
std::vector<Eigen::Triplet<typename DerivedMatrix::Scalar>> matrix_to_triplets(
    const Eigen::MatrixBase<DerivedMatrix>& mat, 
    double threshold = 1e-10) 
{
    std::vector<Eigen::Triplet<typename DerivedMatrix::Scalar>> triplets;
    
    // Reserve space for potential maximum number of non-zeros
    triplets.reserve(mat.rows() * mat.cols());
    
    // Iterate through the matrix
    for(int i = 0; i < mat.rows(); ++i) {
        for(int j = 0; j < mat.cols(); ++j) {
            // Add only non-zero elements (using threshold for floating point)
            if(std::abs(mat(i,j)) > threshold) {
                triplets.emplace_back(i, j, mat(i,j));
            }
        }
    }
    
    return triplets;
}






int main() {
    // Create a positive definite matrix for testing
    Matrix3d A;
    A << 4, -1, 0,
         -1, 4, -1,
          0, -1, 4;
    
    Vector3d b;
    b << 1, 0, 1;
    
    // Test different solvers: https://eigen.tuxfamily.org/dox/classEigen_1_1FullPivLU.html

    solve_and_print<LLT<Matrix3d>,Matrix3d>(A, b);           // Cholesky decomposition
    solve_and_print<LDLT<Matrix3d>,Matrix3d>(A, b);          // LDL^T decomposition
    solve_and_print<PartialPivLU<Matrix3d>,Matrix3d>(A, b);  // LU decomposition with partial pivoting
    solve_and_print<FullPivLU<Matrix3d>,Matrix3d>(A, b);     // LU decomposition with full pivoting
    
    // For non-symmetric matrices, you might also use:
    // solve_and_print<HouseholderQR<Matrix3d>>(A, b);      // QR decomposition
    // solve_and_print<ColPivHouseholderQR<Matrix3d>>(A, b);// QR with column pivoting
    
    // use auto typ 
    auto lu_solver = A.lu(); 

    // SPARSE format 
        // Convert to triplets
    std::vector<Eigen::Triplet<double>> triplets = matrix_to_triplets(A);
    
    // Print the triplets
    std::cout << "Triplets format:" << std::endl;
    for(const auto& t : triplets) {
        std::cout << "(" << t.row() << ", " << t.col() << ") = " 
                 << t.value() << std::endl;
    }
    
    // Demonstrate conversion back to sparse matrix
    Eigen::SparseMatrix<double> sparse(3,3);
    sparse.setFromTriplets(triplets.begin(), triplets.end());
    
    std::cout << "\nConverted back to sparse matrix:" << std::endl;
    std::cout << sparse << std::endl;






    return 0;
}