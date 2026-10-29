#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    //binary exponenetiation--to find powers of higher number and higher power also
    int n,p;//if p is odd then result *2 else n is squared and power is halved 
    long long result=1;
    cin>>n>>p;
    /*while (p!=0){
         if (p%1==0){
            result *=n;
            p=p-1;}
         else {
            p/=2; 
            n*=n;
        }
    }cout<<result<<endl; */
    //(a*b)%m=((a%m)*(b%m))%m
    //now if we have to calculate some a^b which is a very  large no. //
    //,we wont store it in a variable first we will calculate it step by step so that it does not become big
    int mod;//this will now calculate the modulus of theat number
    cin>>mod;
    while (p!=0){
         if (p%1==0){
            result =(result*n)%mod;
            p=p-1;}
         else {
            p/=2; 
            n*=n;
        }
    }cout<<result<<endl;     
    //fermat little theorem--this also states to calculate the mod of a very large number
    //b inverse is written as b^(p-2)  it means that modukus of b inverse is equal to modulus of b^(p-2)
    //it states that modulus of a^p is equal to modulus of a if a is not divisible by p and p is prime
    //(a^p)%p=a%p
    //to calculate the mod permutation of a number (nPr)=n!/(n-r)!
    /*for(i=n;i>n-r;i--){
        result =i%p;
    }*/
   
} 