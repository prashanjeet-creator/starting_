#include<iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i, j;
    int n=5;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++)
          if (i==j)
           cout<<"*";
          else cout<<" ";
        cout<<"\n";  
    }
    cout<<sizeof(int)<<"\n";
    cout<<sizeof(uint8_t)<<"\n";
    cout<<sizeof(char);
    return 0;
}   
/* for input from user--cin>>
for inputing any data type, we can declare  the variable of its data type and store directly 
but for multi word strings  we have to USE getline(cin,s);
WE USE using keyword to replace any data type or keyword in java into easy variable.like using namepace std
{} is used as a seperator and we must use ; after a single line of code ends for the compler to understand
 for creating alias we have to use "using" , it repalces the keyword into another alias which we can use in the program like"using i=int"" 
 #define --preproccesor directive used to define anything not to replace the compiler doen't checksand it is available for the program globally
 whenever somethong is inputted it takes some memory and gets stored in some memory unit of the system 
 so the differnce between define and int v=9 is that in define the compiler assumes treats to be 9 and doesn't store it in memory 
 so using #define is the fastest but not in modern compilers(due to its many disadvantages)
 but when #define is used the variable doesn't respects scope ,compiler also doesn't check type safety(in case of data type another data type is used) 
 uint8_t -- uses only 1byte sram and is faster compared to int 
 pointer -- a variable that stores memory locaton of another variable "*"--valuea at address "&"--address of
 ::-- tells which scope the variable belongs to std::cin<<c
 namespace avoids clashes between same vaiables name but different scopes
 operator precedence--if in any operation there are different operators then we have to perform operation using operator precedence 
 operator asociativity-- if in operation if the operator precendence is same hen we use operator associativity (leftto right) in all cases
 but in some cases such as ternary opertor, shorthand ,postfix ,prefix (right  to left) also postfix>>prefix
 for loop--initialization;condition;execution; increment(or any operation)
 the compiler always starts from the main function of the program and differnt function should be defined above the main function
 sizeof()--to print the size of operator
 we can also write value of a variaBLE WITH F OR L to tell whether it is long or float
 sizeof(34.4f)--4bytes   sizeof(34.4l)--8 bytes
 reference variable -- a variable that has same value and on changing this value that value also changes (int &x=y). x is the reference variable */

//new keyword is used to create dynamic memory allocation and returns a pointer
//<type> <var name>=new <type>(value);
// <type> <var name>=new <type>[n];--for array
//delete --to remove the memory and make thememory address free

//whenver we store variables one after another they are also not random they are contagious like array

//when compile time memory allocation occurs , the memory is allocated by the compiler before the program runs
//size fixed ,very fast ,can waste memory
//runtime memory alloaction (dynamic) ,memory allocated when the program  runs
//flexible size,slower comparitively ,efficient memory storage