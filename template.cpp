#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
 
//tempelate is a keyword which provides flexiblity to ochange the data type of an class or function,works on DRY principle
//typename and class are tempelates--they detect the type automatically
/*tempelate arguments can be used as an data type
tempelates are also known as parameterized classes as
template <typename T>//for function typename is used
void add(T a,T b){
T sum=a+b;
cout<<sum<<endl;
}
add(2,5);*/
//this is a pointer to current object 
//this differnces between parameter and data member even if they are of same name
//this helps in returning object
template <typename T>
class MyArray {
    int size;     // number of elements
    T* data;      // dynamically allocated array

public:
    // constructor
    MyArray(int size) {
        this->size = size;        // using 'this'
        data = new T[size];       // dynamic memory allocation
    }//new always returns a pointer

    // function to set value at index
    void set(int index, T value) {
        if (index < size) {
            this->data[index] = value;
        }
    }

    // function to get value
    T get(int index) {
        return this->data[index];
    }

    //takes the object and makes it reference   to use and this is done by call by reference
    T sumWith(MyArray<T>& other) {//now whenever use class name always use the template
        T sum = 0;//the & declares the parameter type as a reference
        for (int i = 0; i < size; i++) {
            sum += this->data[i] + other.data[i];
        }
        return sum;
    }

    // destructor
    ~MyArray() {// always call a destructor by ~
        delete[] data;   //always free memory 
    }
};

int main() {
    MyArray<int> a1(3);     // template + class
    MyArray<int> a2(3);

    a1.set(0, 10);
    a1.set(1, 20);
    a1.set(2, 30);

    a2.set(0, 1);
    a2.set(1, 2);
    a2.set(2, 3);

    cout << a1.sumWith(a2);
}

//*--value at address
//&--address of
//two ways to pass an object in cpp:-
///1. call by value
    //the full copy of object is directly passed to the class/function
    //copy constructor is called and new memory is created for object as any changes made by it will not reflect in the original object
    // it is more time and memory consuming
//2.pass by reference
    // the original object is passed in the class/ function
    //copy constructor called and less memory used as both are same and any changes made will reflect in the original object
    //above is the example

