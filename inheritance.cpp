#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
// class Employee{
//     float salary;
//     public:
//     int empid;
//     string name;
//     Employee(){
//         empid=0;
//         name="";
//         salary=0.0;
//     }
//     void getdata(int id,string n,float sal){
//         empid=id;
//         name=n;
//         salary=sal;
//     }
//     void display(){
//         cout<<"NAME OF TEH EMPLOYEE:"<<name;
//         cout<<"EMPLOYEE ID:"<<empid;
//         cout<<"SALARY OF THE EMPLOYEE:"<<salary;
//     }
// }//derived class syntax --> class <<derived class>> :<<visiblity mode>> <<base class>>
// //by default , the visiblity mode is private
// //priavte mode-->the public variables of base class becomes private in derives class
// //public mode-->the public memebers of base class are made public members of derived class
// //the private members of base class are not accessible even in inheritance
// class programmer:public Employee {
//     public :
//     string lang ;
//     int rank;
//     void ranking(int r,string l){
//        rank=r;
//        lang=l;
//     }
//     void show (){
//         cout<<name<<empid<<lang<<rank<<endl;
//     }
//     };
// int main(){
//     programmer pras;
//     pras()
// } //inhretance is used for reusability of code 
//the existing calss is called is called base class and 
//the class using its features is derived class 
//different types of inheritance--
//single--where one base class and onederived clas is present 
//multiple--where two base class (parent) and one derived class(child)
//hierachical--where two or more classes are derived from single base class(parent)
//multilevel--whre a class is derived from a class which is already derived(animal-->mammal-->cow)
//hybrid--more tahn one type of inheritance 
/*single inheritance
class Base{
    int data1;
    public :
    int data2;
    void getdata();
    int show_data1();
    int show_data2();
};
void Base ::getdata(void){
    data1=2;
    data2=3;
}
int  Base::show_data1(){
return data1;}
int Base::show_data2(){
return data2;}
class derived:public Base{
    int data3;
    public :
    void getdata3();
    void display();
};
void derived:: getdata3(){
data3=5;}
void derived::display(){
    cout<<"The value of data1 is:"<<show_data1()<<endl;
    cout<<"The value of data2 is:"<<show_data2()<<endl;
    cout<<"The value of data3 is:"<<data3<<endl;
}
int main(){
    derived b1;
    b1.getdata();
    b1.getdata3();
    b1.display();
}*/
//protected -- access specifier in which the member of a class is only accessible to the inherited class
/*                   private derivation    protected derivation   public derivation
   private member    not accessible to any|not accessible to any |not accessible
   protected member  private               protected              protected
   public member     private               protected              public
*/
/*multiple inheritance
class employee{
    protected:
    int empid;
    string name1;
    int salary;
    public :
    employee(){
        empid=0;
        name1="";
        salary=0;
    }
    void get_details(int id,string n,int sal){
        empid=id;
        name1=n;
        salary=sal;
    }
   

};
class person{
    protected:
    int age;
    string name;
    char gender;
    public:
    void get_info(int a,string n,char g){
        age=a;
        name=n;
        gender=g;
    }

};
class programmer:public person ,public employee{
    string lang;
    int ranking;
    public:
    void get(int r,string l){
        lang=l;
        ranking=r;
    }
    void show_details(){
        cout<<"Name:"<<name<<endl;
        cout<<"Age :"<<age<<endl;
        cout<<"Gender:"<<gender<<endl;
        cout<<"Employee ID:"<<empid<<endl;
        cout<<"Salary:"<<salary<<endl;
        cout<<"Programming language:"<<lang<<endl;
        cout<<"Ranking"<<ranking<<endl
;    }
};
int main
(){
    programmer jeet;
    jeet.get_details(123,"jeet",234455);
    jeet.get_info(19,"Jeet",'M');
    jeet.get(122344,"cpp");
    jeet.show_details();
}*/
/*suppose you made a class studdent and derived two classes Test and sports and then derived result as multiple inheritance of teest and sports classes
then the data members of student will be inherited to test and sports and then both classes will pass the data members of student to inherited class result 
which will cause ambiguity because the data members are obtained from both test and result 
to remove this confusion virtual base cl;ass is used*/
class student {
    protected:
    int roll_no;
    string name;
    public:
    void get_details(int r,string s){
        roll_no=r;
        name=s;
    }

};
class Test:virtual public student{//making virtual public class
   protected:
   float maths,physics;
   public:
   void get_marks(int p,int m){
    maths=m;
    physics=p;}
    void display_marks()
   {
    cout<<"maths marks"<<maths<<endl<<"physics marks"<<physics<<endl;
   }
};
class sports:virtual public student{
   protected:
   float score;
   public:
   void set_score(float s){
    score =s;
   }
   void print(){
    cout<<"your pt score is:"<<score<<endl; 
   }

};
class result :public sports,public Test{
    private:float  total;
    public: 
    void display(){
        total=maths+physics+score;
        display_marks();
        print();
        cout<<"total:"<<total<<endl;
    }
}
;
int main(){
    result harry;
    harry.get_details(12,"JEET");
    harry.get_marks(90,90);
    harry.set_score(45);
    harry.display();
}//if we use without virtual , then the member method of student can't be accesed as it will be ambigious
//we can also use consructors in derived class
//even if derived class doesn't have any argument and base class have arguments then the object of derived class must pass argument
//if both derived and base class have constructor then the constructor of base class is called first
//in multiple and multilevel inheritance , the constructors are executed in the order of class        declaration 
/*
syntax if both classes have constructors
s:base class
b:derived class
b b1(object of derived class)(23,45)
b(int a,int b) :a(int a){
x=b;}
*/
/*case1:
class A:public B ,public C{}
order of exexcution -->B()--C()--A()

case 2:
class a:public B,virtual public C{}
order of execution of constructor--C()--B()--A()
*/