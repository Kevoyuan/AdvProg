#include <iostream>
#include <cmath>
#include <cassert>
#include <typeinfo>

double sum(double a, double b)
{
    return a+b;
}
double subtract (double a, double b)
{
    return a-b;
}

double multiply(double a, double b)
{
    return a*b;
}
double divide(double a, double b)
{
    assert(b!=0.0);
    return a/b;
}
double mean(double a, double b)
{
    return sum(a,b)/2.0;
}
double divide(int a, int b)
{
    assert(b!=0);
    // If we just write a/b, 1/2 would give 0 (truncation error).
    return (a/b);
    // Casting one of the operands to double is enough.
    // return (static_cast<double>(a)/b);
}

int main() {
    double a = 0, b = 0;
    std::string oper;
    std::cout<<"Your Simple Calculator!"<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"The Calculator Provides Following Functionalities: "<<std::endl;
    std::cout<<"(1) Sum (+)"<<std::endl;
    std::cout<<"(2) Subtract (-)"<<std::endl;
    std::cout<<"(3) Multiply (*)"<<std::endl;
    std::cout<<"(4) Divide (/)"<<std::endl;
    std::cout<<"(5) Integer division (intdiv)"<<std::endl;
    std::cout<<"(6) Mean (mean)"<<std::endl;
    std::cout<<"(7) tan (tan)"<<std::endl;
    std::cout<<"(8) sin (sin)"<<std::endl;
    std::cout<<"(9) cos (cos)"<<std::endl;
    std::cout<<"(10) Square (square)"<<std::endl;
    std::cout<<"-------------------------------------"<<std::endl;
    std::cout<<"Enter the First Number: ";
    std::cin>>a;
    std::cout<<"Enter the Operation: ";
    std::cin>>oper;
    if (oper!="sin" && oper!="cos" && oper!="tan" && oper!="square")
    {
        std::cout<<"Enter the Second Number: ";
        std::cin>>b;
    }
    if(oper == "/" && b == 0){
        std::cout<<"Attempted division by zero."<<std::endl;
        std::cout<<"Restart the program and try another value for Second Number"<<std::endl;
        std::cout<<"---------------------------------------------------------------------------------"<<std::endl;
        return 100;
    }
    else if (typeid(a)== typeid(int) && typeid(b)==typeid(int) && oper == "/")
    {
        std::cout<<"Result = "<<divide(a,b)<<std::endl;
        std::cout<<"-------------------------------------"<<std::endl;
    }
    else if(oper == "*" || oper == "/" || oper == "intdiv" || oper == "+" || oper == "-" || oper == "mean" || oper == "sin" || oper == "cos" || oper == "tan" || oper == "square")
    {
        double result;

        if (oper == "*")
        {
            result = multiply(a,b);
        }
        else if (oper == "+")
        {
            result = sum(a,b);
        }
        else if (oper == "-")
        {
            result = subtract(a,b);
        }
        else if (oper == "/")
        {
            result = divide(a,b);
        }
        else if (oper == "intdiv")
        {
            // Here we convert a and b to doubles only to showcase the call to divide(int, int).
            result = divide(static_cast<int>(a),static_cast<int>(b));
        }
        else if (oper == "mean")
        {
            result = mean(a,b);
        }
        else if (oper == "sin")
        {
            result = sin(M_PI*a);
        }
        else if (oper == "cos")
        {
            result = cos(M_PI*a);
        }
        else if (oper == "tan")
        {
            result = tan(M_PI*a);
        }
        else if (oper == "square")
        {
            result = pow(static_cast<double>(a),2.0);
        }
        std::cout<<"Result = "<<result<<std::endl;
        std::cout<<"-------------------------------------"<<std::endl;
    }
    else
    {
        std::cout<<"No appropriate operator implementation found. Please restart the program and select an appropriate operator"<<std::endl;
        std::cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<std::endl;
        return 100;
    }
    return 0;
}