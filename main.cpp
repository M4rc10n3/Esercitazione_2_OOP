#include <iostream>
#include "complex_number.hpp"

int main(void){
    complex_number<float> cn1(2,5);
    complex_number<float> cn2(1,-3);
    std::cout << "cn1 is: " << cn1 << " and cn2 is: " << cn2 << std::endl;
    std::cout << "The real parts of each one are: " << cn1.give_real() << " and " << cn2.give_real() << std::endl;
    std::cout << "The imaginary parts of each one are: " << cn1.give_imaginary() << " and " << cn2.give_imaginary() << std::endl;
    std::cout << "The conjugates are: " << cn1.conjugate() << " and " << cn2.conjugate() << std::endl;
    return 0;
}
