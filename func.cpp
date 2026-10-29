#include <iostream>
#include <stdlib.h>
using namespace std
;
double  product(double a, double b){
    cout<<"using the double function\n";
    return a*b;
}
int product(int a ,int b){
    cout<<"using the integer function\n";
    return a*b;  
}//we can also use default argument in our function . if we dont input any argument then the defualt argument would actyt, else the inputted argument would act
// always use the default argument later if a input argument is present
int main(){
    double  a,b;
    cout<<"enter the value of a and b\n";
    cin>>a>>b;
    cout<<product(a,b);
    return 0;
}//in noraml function ,first the arguments are passed in the function ->it takes the formal parameters as actual parameter->
//then used the paramters to return the value where the function is called. a stack forms and push/pop appears
// but we can use inline functions here which directly replace the "product(a,b)" to the code of the function
//use inline only when ythe code is samll(few lines) as the code is stored in cache memory now in compiler for faster acces
//function overloading -- same function with different variables or data type 
