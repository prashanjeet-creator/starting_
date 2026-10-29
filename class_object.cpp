/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// calling a member function wihtin a member function
class nitjsr // declaration of class
{            // by default in a class the variables and functions are declared private
             // the private variables can't be accessed in a main function and can't be changed by user
private:     // can't be changed and accessed outside the class
    int a, b, c;
public: // access specifier
    int d, e;
    void setdata(int a, int b, int c); // member function
    void getdata(void)
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
        cout << "The value of d is " << d << endl;
        cout << "The value of e is " << e << endl;
    }
} nj; // typedef of class declaration automatic
void nitjsr::setdata(int a1, int b1, int c1)
{ // how another is defined outside the class which is declared inside the class
    a = a1;
    b = b1;
    c = c1;
}
int main()
{
    // class is blueprint of objects . it has data (variables) and functions.
    // main focus is on data rather than on functions
    // data abstraction --focus on important info only like if we name a function and tell that it performs this task we can directly
    // encapsulation -- wrapping data and function into sinle unit and hiding data from outside(public,private,protected)
    // inheritance--properties in which a class inherits the properties of another class--helps in reusablity
    // polymorphism--func overloading
    // even after using structure ,we will be able to use data then also we use class becuse it provides security(publoc in struct) and no function
    // class is extension of structures
    nitjsr electrical; // object created
    electrical.d = 90; //public members can be easily accesed 
    electrical.e = 45; // we cannot declare a ,b or c like this because it is private
    // electrical.setdata(1,23,33);
    electrical.getdata();//
    return 0;
}*/
//23   
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
class shop{
 private:
 vector <int> price;
 vector <int> itemid;
 public:
 shop(void){
    price={};
    itemid={};
 }
 shop(shop &obj)//copy constructor
{  cout<<"copy constructor called"<<endl;
    price=obj.price;
    itemid=obj.itemid; 
 }
 ~shop(){//deconsrtuctor defination
cout<<"DESTRUCTOR CALLED"<<endl;//cleans the object after use it is automatvcally called
 }
 int c=0;
 void setprice(void);
 void display_price(void); 
 friend shop cal_price(shop c);//declaration of friend between class and function
};
void shop::setprice(void){
    int item,p;
    string s="Y";
    while (s=="y"||s=="Y"){
    cout<<"Enter the item id"<<endl;
    cin>>item;
    cout<<"Enter the price of item"<<endl;
    cin>>p;
    price.push_back(p);
    itemid.push_back(item);
    c++;
    cout<<"DO you want to enter more items (y/n)";
    cin>>s;}

}
void shop:: display_price(void){
    cout<<"TOTAL no of items are"<<c<<endl;
    cout<<"The item id and corresponding prices are "<<endl;
    for(int i=0;i<itemid.size();i++){
    cout<<itemid[i]<<"\t"<<price[i]<<endl;
    }

}
shop cal_price(shop cust1){//friend function
    int sum=0;
    vector <int>v=cust1.price;
    for(int i=0;i<v.size();i++)
    sum+=v[i];
    cout<<"Total amount"<<sum<<endl;
}
int main(){
    shop cust1;//can also declare many objects like this,see how class is used as a data type
    //also see you cant access the vectors price and itemid
    //cout<<price[1]; as now class behaves as a data type we can also pass objects in function
    cust1.setprice();
    cust1.display_price();
    // shop cust[100];//array of oject
    // for (int i=0;i<100;i++){
    //     cust[i].setprice();
    //     cust[i].display_price();
    // }
    shop cust2(cust1);//how copy constructor si used
    cust2.display_price();
    cal_price(cust1);
    cout<<cust1.c<<endl;
    return 0;
    shop cust3;
   // shop *ptr=&cust3;//accessing object via pointer
    //(*ptr).setprice();//always use parenthesis as .operator has more precedence than * operator
    //(*ptr).display_price();
    shop *ptr=new shop;//another way of creating a pointer object
    (*ptr).setprice();//is exactly same as ptr->setprice()
    (*ptr).display_price();
//-> operator--is used to access members of a class using pointer
     shop *ptr1=new shop[7];
//in this case the pointer stores the memory address of the first position of the object and on incementing(+1) the pointer ,we can access the next obhjcts      
}
//1.freind function can access all the private members function and variables of class
//2.friebd function can be declared inside privateor public in class 
//always input an object of the same class in a member function 
//the friend can also change the private variables of the class (data hiding)
//remember in professional we can't give access to our class ,so always give access to that function which you know everything 
// constuctor are the functionin classes which are automatically called .it has same same of the class and used to in initialize
//no return type of constuctor and it should be delared in the public sectionof class
//types of constructor--default constructor(which doesnat take any pparameter)
//parameterised constructor-
//copy constructor --when a copyopf object is to be made then the object is passed to copy constructor 
//by default cpp provides a copy constructor if we dont make .
//whenever we pass an object in a class copy constructor is called(by default or used defined)
//deconstructor is used to destruct object and free up memory for large programs
//it never takes an argument and never returns any value
//deconstuctor always automatically called at the end when the compilr checks it has no use in the program
//comstructor can also be initialized this way--initialization section 
/*class test{
int x;
int y;
public:
test(int a,int b) :x(a),y(b)
test(int a,int b) :x(a),y(b+x)//correct syntax
test(int a,int b) :y(b),x(a)//wrong syntax bcz as x is declared first as int it must be assigned first  
{//body of constuctor
}
};*/



// this function will point to the object which called the member function  
 //THIS KEYWORD is a pointer used for distinguishing data members from parameter and consructor
 /*class student
 {int age;
 public getdata(int age){
 this->age=age;
 }
 };*/
 //also helps to rturn the object
 //helps in method chaining
 /*clas Box{
 int l;
 public;
 Box& set(int l){//Box& return a reference to the same object ,if we use Box then the copy of object will be passed
 this->l=l;
 return *this;}};
 */

