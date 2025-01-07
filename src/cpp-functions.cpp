#include<iostream>

#include <vector>
#include <algorithm>
#include <functional>

//function objects: Class
class myMultiplierArray{
private:
    double factor_;
public:
    //constructor
    explicit myMultiplierArray(double f): factor_(f){}
    
    //Function call operator
    double* operator()(double * arr, size_t size) const {
        double* res= new double[size];
        for(size_t i =0 ;i <size ; ++i ){
            res[i] = arr[i] * factor_;
        }
        return res;
    }
    
};

// Returns the sum of the vector elements and a new vector with each element multiplied by the sum
template <typename T>
std::tuple<T, std::vector<T>> sumAndMultiply(const std::vector<T>& v) {
    T sum = T();
    std::vector<T> multiplied(v.size());

    for (const T& x : v) {
        sum += x;
    }

    for (size_t i = 0; i < v.size(); i++) {
        multiplied[i] = v[i] * sum;
    }

    return {sum, std::move(multiplied)};
}

int main(){
    // EXAMPLE: simple array
    //------------------------------------------
    double factor = 5.0;
    myMultiplierArray arr_factor(factor);
    double arr[] = {1.0,2.0,3.0};
    const size_t size = sizeof(arr)/sizeof(arr[0]);
    double* res= arr_factor(arr,size);
    for (size_t i=0 ; i<size; ++i ){
        std::cout<< res[i] <<std::endl;
    }
    
    // Function object: lambda function
    auto f = [factor](double* arr, size_t size){
        double *res = new double[size];
        for(size_t i =0 ;i <size ; ++i ){
            res[i] = arr[i] * factor;
        }
        return res;

    };
    
    double* res_lambda = f(arr,size);
    
    for (size_t i=0 ; i<size; ++i ){
        std::cout<< res_lambda[i] <<std::endl;
    }
    //--------------------------------------------
    
    // EXAMPLE: vector addition
    //------------------------------------------
    
    std::vector<double> v = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8};
    double w = 0;
    // Use lambda to perform cumulative sum
    std::for_each(v.begin(), v.end(), [&](double x) { w += x; });
    std::cout << "Sum of vector elements: " << w << std::endl;
    
    
    
    
    //--------------------------------------------
    
    // EXAMPLE: vector element squared and transform
    //------------------------------------------
    
    
    
    // Use lambda to transform vector
    std::vector<double> transformed(v.size());
    std::transform(v.begin(), v.end(), transformed.begin(), [](double x) { return x * x; });

    std::cout << "Transformed vector: ";
    for (double x : transformed) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    
    
    
    //--------------------------------------------
    
    // EXAMPLE: vector element squared with std::function
    // std::function<return type(arg types)>
    //------------------------------------------
    std::vector<double> numbers = {1.2, 2.3, 3.4, 4.5, 5.6};
    std::vector<double> squared;

    std::function<double(double)> func = [](double x) { return x * x; };
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squared), func);

    for (double num : squared) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    
    
    //--------------------------------------------
    
    // EXAMPLE:    Returns the sum of the vector elements and a new vector with each element multiplied by the sum
    //------------------------------------------
    
    std::vector<double> vec = {1, 2, 3, 4, 5};
    double total;
    std::vector<double> multiplied;
    std::tie(total, multiplied) = sumAndMultiply(vec);
    
    std::cout << "Sum: " << total << "\nMultiplied: ";
    for (int num : multiplied) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    

    return 0;
}
