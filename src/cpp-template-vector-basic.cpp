#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

// TEMPLATES
// 1. basic function template
template <typename T>
T max(const T& a, const T& b) {
    return (a>b)?a:b ;
}
// 1.1 Eigen specific function template example
template <typename Scalar, typename Vector>
Vector saxpy(Scalar a, const Vector& x, const Vector& y){
    return a*x + y ;
}


// 2. basic Class template
/**
 * Class Template: Defines a class parameterized by one or more type parameters
 *
 * @tparam T The type of elements stored in the vector
 *
 * @note This is a simplified vector implementation to demonstrate
 * basic template class concepts and resource management
 *
 * @details Key features:
 * - Dynamic memory allocation
 * - Deep copy semantics
 * - Basic element access
 * - Supports different element types
 *
 * @note template<class> and template<typename> are equivalent in C++
 */
template<typename T>
class myVector{
private:
        size_t size_;
        T* data_;
public:
    //constructor
    explicit myVector(size_t n=0 ): size_(n), data_(nullptr){
        if (size_>0){
            data_ = new T[size_];
            for (size_t i=0; i<size_; ++i) data_[i]= T(0);
        }
    }
    // constructor from array
    myVector(const T* arr, size_t size): size_(size), data_(new T[size]){
        std::copy(arr, arr+size,data_);
    }
    // copy constructor
    myVector(const myVector& other): size_(other.size_), data_(nullptr){
        if (size_>0) {
            data_ = new T[size_];
            for(size_t i=0; i<size_ ; ++i) data_[i] = other.data_[i];
        }
    }
    // Destructor
    ~myVector() {
        if (data_ != nullptr) delete[] data_;
    }
    
    // Access operator
    T& operator()(size_t i) { return data_[i]; }
    
    // for cout
    friend std::ostream& operator<<(std::ostream& os, const myVector& v) {
       os << "[";
       for(size_t i = 0; i < v.size_; ++i) {
           os << v.data_[i];
           if(i < v.size_ - 1) os << ", ";
       }
       return os << "]";
    }
    
};




// Generic print template
template <typename T>
void print(const std::string& message ,const T& value) {
    std::cout<< "\n------------------\n";
    std::cout << message <<":\n"<<"\n"<< value << std::endl;
    std::cout<< "------------------\n";
}


int main() {
// 1. basic function template
    int result = max(5,3);
    double dresult = max(5.5,5.6);
    print("result",result);
    print("dresult",dresult);
// 1.1 Eigen specific function template example
    VectorXf x,y;
    x = VectorXf::Ones(4);
    y = VectorXf::Ones(4);
    double a = 1.5;
    VectorXf z = saxpy<double,VectorXf>(a,x,y);
    print("saxpy", z);
//  Note:automatic detection
    print("saxpy", saxpy(a,x,y));
// 1.2 basic Class template
    myVector<double> v1(4);
    double arr[] = {1,1,1};
    myVector<double> v2(arr,3);
    print("myVector v1",v1);
    return 0;
}
