#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
//display() function is dynamic binding(ryntime polymorphsm)
//set() function is static binding (compile time polymorphism)
// class Base{
//     int b;
//     public:
//     virtual void display(){
//         cout<<"Base class dissplay is being accessed"<<endl;
//     }
//     void set(){
//         b=1;
//         cout<<"value of base class data is :"<<b<<endl;
//     }
// };
// class derived:public Base{
//     int d;
//     public:
//     void display(){
//         cout<<"Derived class dispaly is being accessed"<<endl;
//     }
//     void set(){
//         d=1;
//         cout<<"value of derived class data is :"<<d<<endl;
//     }
// };
// int main(){
//     Base obj_b;
//     Base *ptr_b;
//     derived obj_d;
//     ptr_b=&obj_d;//pointing pointer of base class to object of derived class
//     //now the base class pointer stores the address of base class subobject inside the derived class object
//     //even if we run display function by this pointer , the base class dispaly will run
//     //function call selection is done according to the static type of the pointer that's why base class is called bcz it is non virtual FUNCTION 
//     (*ptr_b).display();
//     ptr_b->display();//this pointer can only access data members of the base class
//     ptr_b->set();//when virtual function is not set it again , it i sagain static binding
//     //derived *ptr_d;
//     //ptr_d=&obj_b;//can't make a derived class pointer point to base class
//     //ptr_d->display();

// } 
//polymorphism --one name multiple use
//USED IN function overloading like multiple input and same function name
//two types of polymrphism-
   //compile time(static binding)--compiler already knows which function will called by the object before program runs//bind ho jata h
        //function overloading--same function name ,different parameter list
        //operator overloading--redefining the operator by the user defined function like in case of +(c1,c2) compiler sees it as "+" but it is a user defined function
   //runtime(dynamic binding)--function called by object when the program sis running//bind nhi kr pata h
       //virtual function

//static binding --function call is resolved at compile time aND id default by the compiler        
//it is faster , nad uses pointer type not object type

//dynamic binding --function call is resolved at run time and is slower and uses object type  
//happens when function is declared virtual base class

//dynamic binding --virtual class 
//on just adding virtual to the above program the static binding changes into dynamic binding
//whenever a virtual function is created ,a virtual table and virtual ptr is created
//virtual table(vtable) stores the address of virtual function,while virtual pointer(vptr) points the object to virtual table
//objects which belong to different classes point ot the same function

//another example
class Person{
    protected:
    int age;
    string name;
    char gender;
    public:
    Person(int a,string n,char g)
    {
        age=a;
        name=n;
        gender=g;
    } 
    virtual void display()=0;//do nothing --known as pure virtual function
};
class student :public Person{
    string course;
    string college;
    public :
    student(int a, string n,char g,string c1, string c):Person(a,n,g){
        //comstructor in derived class
         course=c1;
         college=c;}
    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"Gender:"<<gender<<endl;
        cout<<"Age :"<<age<<endl;
        cout<<" Name of college:"<<college<<endl;
        cout<<"Course in college:"<<course<<endl;
        }     
};
class worker :public Person{
   int year;
   string company;
   public:
   worker(int a, string n,char g,int y, string c):Person(a,n,g){
        
         year=y;
         company=c;}
    void display(){
        cout<<"Name :"<<name<<endl;
        cout<<"Gender:"<<gender<<endl;
        cout<<"Age :"<<age<<endl;
        cout<<"Name of comapny:"<<company<<endl;
        cout<<"Experience "<<year<<endl;
        }  
} ;
int main(){
    student prashanjeet(19,"Prashanjeet",'M',"Btech","NIT Jamshedpur");
    //prashanjeet.display();
    worker harry(22,"Harry",'M',5,"Google");
  //  harry.display();
  Person* p[2];
  p[0]=&prashanjeet;
  p[1]=&harry;
  p[0]->display();//virtual not used static binding if used dynamic binding 

}
//whenyou call normally without making pointer then the derived class will only run and no static and no dynamoc binding
//even if virtual function is declared then also it might run the code of base class only if the derived class does not have the same function
//to avoid this , the function is to be made pure virtual
//abstact class--abstract base class-- a class which can't create objects(cant be inherited)
// a class which contains atleast one pure virtual function
//VIRTUAL FUNCTION CANNOT BE STATIC