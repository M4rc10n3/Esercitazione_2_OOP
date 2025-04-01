#pragma once

/*This code creates a class for complex numbers expressed in the algebric form, which is:

                                    z = a + i*b 

Where:
- a is the real part of the complex number
- b is the real part of the complex number
- i = sqrt(-1) is the imaginary unit 
*/

template<typename type> requires std::floating_point<type>
class complex_number{
    // The attributes of a complex number are its real and its imaginary part
    type real;
    type imaginary;

public:

    //Creating the default constructor that initalises the complex number to z = 0 + i*0 = 0 
    complex_number()
        : real(0), imaginary(0)
    {}

    /* Creating the user-defined constructor that initalises the complex number to z = re + i*im,
     where <re> and <im> are floating_point numbers */
    complex_number(type re, type im)
        : real(re), imaginary(im)
    {}

    /*Creating a user-defined constructor for the instances where we want to create a complex number with just the real part,
     therefore we use the `explicit` keyword in order to avoid creating a "converting constructor" */
    explicit complex_number(type re)
        : real(re), imaginary(0)
    {}

    //Creating a method that gives the real part of the complex number as its output 
    type give_real(void) const{
        return real;
    }

    //Creating a method that gives the imaginary part of the complex number as its output
    type give_imaginary(void) const{
        return imaginary;
    }

    //Creating a method that gives the conjugate of the complex number as its output 
    complex_number conjugate(void) const {
        return complex_number(real, -imaginary);
    }

    //Overloading the operator+= in order to sum properly two complex numbers 
    complex_number& operator+=(const complex_number& other){
        type a = real;
        type b = imaginary;
        type c = other.give_real();
        type d = other.give_imaginary();
        real = a + c ;
        imaginary = b + d ;
        return *this;
    }

    // Overloading the operator+ using the operator+= defined above
    complex_number operator+(const complex_number& other) const{
        complex_number cn = *this;
        cn += other;
        return cn;
    }

    // Overloading the operator+= and the operator+ in order to sum properly a complex number and a float/double
    complex_number& operator+=(const type& other){
        real += other;
        return *this;
    }
    complex_number operator+(const type& other) const{
        complex_number cn = *this;
        cn += other;
        return cn;
    }

    //Overloading the operator*= in order to multiply properly two complex numbers 
    complex_number& operator*=(const complex_number& other){
        type a = real;
        type b = imaginary;
        type c = other.give_real();
        type d = other.give_imaginary();
        real = a * c - b * d ;
        imaginary = b * c + a * d ;
        return *this;
    }

    // Overloading the operator* using the operator*= defined above
    complex_number operator*(const complex_number& other) const{
        complex_number cn = *this;
        cn *= other;
        return cn;
    }

    // Overloading the operator*= and the operator* in order to multiply properly a complex number and a float/double
    complex_number& operator*=(const type& other){
        real *= other;
        imaginary *= other;
        return *this;
    }
    complex_number operator*(const type& other) const{
        complex_number cn = *this;
        cn *= other;
        return cn;
    }

};

//Overloading the operator+ and the operator* so that their commutativity is preserved
template<typename type> requires std::floating_point<type>
complex_number<type> operator+(const type& num, const complex_number<type>& cn){
    // We simply invert the order of the factors
    return cn + num;
}
template<typename type> requires std::floating_point<type>
complex_number<type> operator*(const type& num, const complex_number<type>& cn){
    return cn * num;
}

/*Overloading the operator<< in order to print the complex numbers the correct way*/
template<typename type> requires std::floating_point<type>
    std::ostream& operator<<(std::ostream& os, const complex_number<type>& cn) {
    type im_part = cn.give_imaginary();
    if (im_part != 0){
        // When the imaginary part is positive, we ought to add the sign before the value
        if (im_part > 0){
            os << cn.give_real() << "+" << cn.give_imaginary() << "i";
        }
        // When the imaginary part is positive, we ought to add the sign before the value
        else{
            os << cn.give_real() << cn.give_imaginary() << "i";
        }
    }
    else{
        os << cn.give_real();
    }

    return os;
}
