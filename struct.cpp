#include <iostream>
#include <stdlib.h> 
using namespace std;

//ALlows dynamic memory allocation for user (malloc, calloc,free) and also provides searching and sorting algorithms
//(bubble sort and binary search)
//a structure is a user defined data type for different data type 
typedef struct info{
    int rollno;//4
    string name;//4
    float cg;//4
}i;//typedef used to use the data type as alais 
//total size of struct -12
//union--all members share the same memory unlike struct
//provides better memory allocation ,used when only one is used in all data types
union money{
    int rice;//can be measured in kg of rice
    float dollar;// can be measured in terms of dollar
    char cars;//can be measured in terms of cars
};
//total memory allocation is given by the maximum no. of bytes the data types present 
//enum-- a user defined data type that is used for integral constants and provides readablity
//defined within the main class
int main() {
   enum m1{re,blue,green};
   cout<<re;
   i electrical[10];
   union money m1;
   m1.cars='c';//IF TWO MEMBERS ARE USED of union THEN the last value will be actual otherwise garbage value as memory is shared 
   cout<<"Enter the roll no. , name and cgpa of students: \n";
   for (int i=0;i<100;i++){
    cin>>electrical[0].rollno;
    getline(cin,electrical[i].name);
    cin>>electrical[i].cg;
   }
   return 0;
}