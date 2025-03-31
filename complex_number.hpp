#pragma once

/*This code creates a class for complex numbers expressed in the algebric form, which is:
                                    z = a + i*b 
Where:
- a is the real part of the complex number
- b is the real part of the complex number
- i = sqrt(-1) is the imaginary unit 
*/

template<typename t>
class complex_number{
    t real;
    t imaginary;

public:
    //Creating the default constructor that initalises the complex number to z = 0 + i*0 = 0 
    complex_number()
        : real(0), imaginary(0)
    {}

    /* Creating the user-defined constructor that initalises the complex number to z = re + i*im,
     where <re> and <im> are numbers */
    complex_number(t re, t im)
        : real(re), imaginary(im)
    {}

    /*Creating a user-defined constructor for the instances where we want to create a complex number with just the real part,
     therefore we use the `explicit` keyword in order to avoid creating a "converting constructor" */
    explicit complex_number(t re)
        : real(re), imaginary(0)
    {}

    //Creating a method that gives the real part of the complex number as its output 
    t give_real(void) const{
        return real;
    }

    //Creating a method that gives the imaginary part of the complex number as its output
    t give_imaginary(void) const{
        return imaginary;
    }

    //Creating a method that gives the conjugate of the complex number as its output 
    complex_number conjugate(void) const {
        return complex_number(real,-imaginary);
    }
};

/*Overloading the operator<< in order to print the complex numbers the correct way*/
template<typename t>
    std::ostream& operator<<(std::ostream& os, const complex_number<t>& cn) {
    t im_part = cn.give_imaginary();
    if (im_part != 0){
        // When the imaginary part is positive, we ought to add the sign before the value
        if (im_part > 0){
            os << cn.give_real() << "+" << cn.give_imaginary() << "i";
        }
        // When the imaginary part is positive, we ought to add the sign before the valu
        else{
            os << cn.give_real() << cn.give_imaginary() << "i";
        }
    }
    else{
        os << cn.give_real();
    }

    return os;
}
