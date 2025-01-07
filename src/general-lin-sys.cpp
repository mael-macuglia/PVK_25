#include <iostream>
#include <Eigen/Dense>

#define EPS Eigen::NumTraits<double>::epsilon()
using namespace Eigen;

std::tuple<MatrixXd,MatrixXd,MatrixXd> svd_full(const MatrixXd& A){

    JacobiSVD<MatrixXd> svd(A, ComputeFullU | ComputeFullV); 
    MatrixXd U = svd.matrixU();
    MatrixXd V = svd.matrixV();
    VectorXd sv = svd.singularValues(); 
    return std::tuple<MatrixXd,VectorXd,MatrixXd> (U,sv,V);
}

std::tuple<MatrixXd,MatrixXd,MatrixXd> svd_thin(const MatrixXd& A){

    JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV); 
    MatrixXd U = svd.matrixU();
    MatrixXd V = svd.matrixV();
    VectorXd sv = svd.singularValues(); 
    return std::tuple<MatrixXd,VectorXd,MatrixXd> (U,sv,V);
}

Index get_rank_svd(const VectorXd& Sigma, double tol = EPS){
    Index p = Sigma.size();
    Index r = 0;
    while((r < p) && (Sigma(r) >= Sigma(0)* tol)) r++ ; 
    return r; 
}



void analyse(const std::string& system_name, const MatrixXd& A , const VectorXd& b){
    std::cout << "\n=== " << system_name << " ===" << std::endl;
    std::cout << "Matrix A (" << A.rows() << "x" << A.cols() << "):" << std::endl;
    std::cout << A << std::endl;
    std::cout << "Vector b:" << std::endl;
    std::cout << b << std::endl;

    // get full SVD 
    MatrixXd U,V;
    VectorXd sv;  
    std::tie(U,sv,V) = svd_full(A); 
    // get rank 
    Index rank = get_rank_svd(sv); 
    std::cout << "Rank: " << rank << std::endl;

    // Analyze dimensions
    Index m = A.rows();
    Index n = A.cols();
    Index p = std::min(m,n); 

    std::cout << "rows, cols , rank: " <<m << n<< rank << std::endl;
    //if full rank, can solve through normal equation 
    if(rank == p ){
        VectorXd x = (A.transpose()*A).ldlt().solve(A.transpose()*b); 
        std::cout << "X from plain Normal Eq " << std::endl << x << std::endl;
        std::cout << "Residual: " << (A * x - b).norm() << std::endl;
    };

    
    // Get Null Space and Image Space 
    MatrixXd A_null = V.rightCols(A.cols()-rank); 
    MatrixXd A_img = U.leftCols(rank);

    // Compute Moore-Penrose solution
    VectorXd x_moore(n);
    MatrixXd Sigma_inv = sv.head(rank).cwiseInverse().asDiagonal();

    x_moore = V.leftCols(rank) * Sigma_inv *U.leftCols(rank).transpose()*b;

    std::cout << "\nMoore-Penrose solution:" << std::endl << x_moore << std::endl;
    std::cout << "Residual: " << (A * x_moore - b).norm() << std::endl;
}



int main() {
    // Case 1: Overdetermined system with full rank
    Eigen::MatrixXd A1(4,2);
    A1 << 1, 0,
          0, 1,
          1, 1,
          2, 1;
    Eigen::Vector4d b1(1, 2, 3, 4);
    analyse("Overdetermined system (full rank)", A1, b1);
    
    // Case 2: Underdetermined system
    Eigen::MatrixXd A2(2,4);
    A2 << 1, 2, 3, 4,
          5, 6, 7, 8;
    Eigen::Vector2d b2(1, 2);
    analyse("Underdetermined system", A2, b2);
    
    // Case 3: Overdetermined system with non-trivial kernel (rank deficient)
    Eigen::MatrixXd A3(4,2);
    A3 << 1, 1,
          2, 2,
          3, 3,
          4, 4;
    Eigen::Vector4d b3(2, 4, 6, 8);
    analyse("Rank deficient system", A3, b3);

    return 0;
}