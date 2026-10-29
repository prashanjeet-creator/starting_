#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cmath>
using namespace std;
/*class point{
    int x,y;
    public:
    point(void){//constructor can also be overloaded -- gives better initialization control and enhances flexiblity
     x=0;
     y=0;
    }
    void input(int a,int b){

        x=a;
        y=b;
    }
    void display(void){
        cout<<"("<<x<<","<<y<<") is the point"<<endl;
    }friend void cal_distance (point d1,point d2);
};
void cal_distance(point d1, point d2){
    float d;
    d=sqrt(pow((d1.x-d2.x),2)+pow((d1.y-d2.y),2));
    cout<<"The distance between ("<<d1.x<<","<<d1.y<<") and ("<<d2.x<<","<<d2.y<<") is "<<d<<endl;
}
int main(){
    point p1;
    p1.input(2,3);

    point p2;
    p2.input(3,5);
    cal_distance(p1,p2);

} */
// class Simplecalculator{
//      protected :
//      double a,b;
//      double sum,dif,mul,div;
//      public:
//      void get_data1(double a1,double b1){
//        a=a1;
//        b=b1;
//      }
//      void process_simp()
//      {  sum=a+b;
//         dif=a-b;
//         mul=a*b;
//         div=a/b;
//      }
//      void dispay_simp(){
//         process_simp();
//         cout<<"The value of "<<a<<"+"<<b<<":"<<sum<<endl;
//         cout<<"The value of "<<a<<"-"<<b<<":"<<dif<<endl;
//         cout<<"The value of "<<a<<"*"<<b<<":"<<mul<<endl;
//         cout<<"The value of "<<a<<"/"<<b<<":"<<div<<endl;
//      }

// }simp;
// class Scientificcalculatoe{
//    protected:
//    double a,b;
//    double power,root,mod,logr;
//    public:
//    void get_data2(double a1,double b1){
//     a=a1;
//     b=b1;
//    }
//    void process(){
//       power=pow(a,b);
//       root=pow(a,1/b);
//       mod=int(a)%int(b);//in modulus operator only int can be used
//       logr=log(a)/log(b);
//    }
//    void display_sci(){
//     process();
//     cout<<"The power of "<<a<<" raised to "<<b<<":"<<power<<endl;
//     cout<<"The root of "<<a<<" over "<<b<<":"<<root<<endl;
//     cout<<"The mod of "<<a<<" % "<<b<<":"<<mod<<endl;
//     cout<<"The log of "<<a<<" and "<<b<<":"<<logr<<endl;
//    }
// };
// class Hybridcalculator :public Scientificcalculatoe,public Simplecalculator{
//   public : 
//   void  get (double a,double b){
//      get_data2(a,b);
//      get_data1(a,b);
//      display_sci();
//      dispay_simp();
//   }
// };
// int main(){
//     Hybridcalculator h;
//     h.get(3,2);
// }
//if both base class will have a same function name and when an object of derived class call the function , it causes a ambiguity
//to resolve it ,assuming for the above example both the baw classes have same function display and it is caled by the derived class 
/*then in Hybridcalculator {
void display:
scientificcalculator::display()
}
this makes sure that if display is called then display of scien cal is calculated
ambiguity removed*/



// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//     int a;
//     long long b;
//     char c;
//     double d;
//     double e;
//     cin>>a>>b>>c>>d>>e;
//     cout<<a<<endl;
//     cout<<b<<endl;
//     cout<<c<<endl;
//     cout<<d<<endl;
//     cout<<e<<endl;
//     return 0;
// }


int main(){
    int a=34;
    int b=9;
    cout<<&a<<endl<<&b<<endl;//stored in continious memeory location
    
}
    
