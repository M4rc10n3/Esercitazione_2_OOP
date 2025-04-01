#include <iostream>
#include "complex_number.hpp"

using namespace std;

int main(void){
    complex_number<float> cn1(2,5);
    complex_number<float> cn2(3,7);
    complex_number<double> cn3(4);
    cout << "cn1 is: " << cn1 << ", cn2 is: " << cn2 << " and cn3 is: " << cn3 << endl;
    cout << "The real parts of each one are: " << cn1.give_real() << ", " << cn2.give_real() << " and " << cn3.give_real() << endl;
    cout << "The imaginary parts of each one are: " << cn1.give_imaginary() << ", " << cn2.give_imaginary() 
                << " and " << cn3.give_imaginary() << endl;
    cout << "The conjugates are: " << cn1.conjugate() << ", " << cn2.conjugate() << " and " << cn3.conjugate() << endl;
    float f = 1.248;
    double d = 2.4816;
    cout << "The float number is f: " << f << " , while the double number is d: " << d << endl;
    cout << "The sum of cn1 and cn2 is: " << cn1 + cn2 << " ; their product is: " << cn1 * cn2 << endl;
    cout << "The sum of cn1 and f is: " << cn1 + f << " , which is the same as the sum of f and cn1: " << f + cn1 << endl;
    cout << "The sum of cn3 and d is: " << cn3 + d << " , which is the same as the sum of d and cn3: " << d + cn3 << endl;
    cout << "The product of cn1 and f is: " << cn1 * f << " , which is the same as the product of f and cn1: " << f * cn1 << endl;
    cout << "The product of cn3 and d is: " << cn3 * d << " , which is the same as the product of d and cn3: " << d * cn3 << endl;
    return 0;
}
