//ques given is there are many n workers which qork in some days in a month of 30 days 
//we have to find a pair that works most in all the days of the month 
//we will use bitmasking ,it means concept of bit in no of days and store it in int or lomng long so it can be limited
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cstdint>
using namespace std;
string output(vector<int> &v){
    string s;
    int t=1,i=0;
    while(t<30){
        if(t==v[i]){
           i++;
           s+="1";
        }
        else {
            s+="0";
            s.pop_front();
        }
        t++;
    }
}
int main(){
    int i,n,temp,j,t;
    cin>>t;//no of workers
    vector <string> s(t);
    for(i=0;i<t;i++){
        cin>>n;
        vector<int> v(n);
        for(j=0;j<n;j++)
            cin>>v[j];
        s[i]+=output(v);    
    }
    int m,mx=INT16_MIN;
    for(i=0;i<t;i++){
        for(j=i+1;j<t;j++){
           //m=(stoi(s[j])&stoi(s[i])).count (1);
        }
        if(m>mx) mx=m;
    }
}    

//1's compliment -- flip all the bits
//2's compliment -- first take 1's compliment and add 1 ; 
//if 1+1 =0 and also carry over 1 to next place

//bit masking means to manipulate the bit for given operation 
//in xor - if no of ones even -- 0
//         if no of ones odd  --1

//right shift n>>k -- n/pow(2,k)
//left shift n<<K  -- n*pow(2,k)
//pow(2,31)-1<<1 --integer overflow
//for negative no we take 2's compliment of the positive no
//for a negative no , the last bit is always 1(31th)
//computer stores the negative no in 2's compliment
//for a positve no, the most significant bit is 0
//as an integer has 32 bit the last bit is used for sign so
//max value of an int pow(2,30)+ pow(2,29)+  ....+  pow(2,0) --INT_MAX=pow(2,31)-1
//2^n = 2^(n-1) + 2^(n-2) + 2^(n-3) + ......... + 2^0 
//~ operator --first flips all bit 
//then check positve or negative--if negative the last bit will decide the sign
//then take 2's compliment leaving the neagive sign
//~(101)--11111111111111111111111111111010--10000000000000000000000000000110--(-6)

//swap two numbers --a,b
//a= a^b;
//b=a^b;
//a=a^b;

//to check whether the ith bit is set(1) or not--can be both done by left and right shift
//n=12 ,i=1; bit starts from 0 
//(n>>(i))&1=1 --then bit is set(using right shift)
//          =0 --then ibit is 0
//(n&(1<<i))==1 then bit is set(using left shift)

//to set the ith bit 
//n=12,i=1
//n=n|(1<<i) after setting the ith bit 

//to clear the ith bit
//n=12,i=1
//n&(!(1<<i)) -and with all bits 1 except the ith bit

//to toggle the ith bit
//n^(1<<i) --taking xor ifat ith bit 1- 0 else 0-1


//to remove the last set bit
//n=40--101000  n=39--100111
//n=16--1000    n=15-111
//n=51-110011   n=50-110010
//by observation taking & of n and n-1--we can remove the last set bit
//n&(n-1) 

//check if the no is a power of 2
//for this only one bit must be set and all other bit must be 0
//so on taking n&(n-1)=0//removed last digit and all digits are 0 or builtin_popcount should be 1

//count the no of set bits 
//another method will remove all set bits(gives less time complexity)

//to convert a number using minimum bit flips
//take xor of start and goal and count the no of ones
//tc --O(log(start^end))

//to divide a number and the divisor is non zero and find the quotient 
//we will go on finding the the largest power of 2 which can be subtracted from the dividend and then subtract it
/*while(n>=d){
  int c=0;
  while(n>(d<<(c+1))) c++;
  ans+=1<<c;
  n-=d<<c;
  }*/
//time complexity (logn)^2

//try to use left shift and right shift and not to use pow of 2

//power set is possible subset of all elements


//question given that in an array there are n integers in which only one is single 
//and all exist in triplets so you have to find the no.
//can use hash map to first stor and count the occurances then traverse through hash map
//time complexity --O(n log m)
//another method using bit manipulation 
//count the no of ones in every bit and check whether it is divisible by 3 
//because the single no 'bits woulnot be divisible by zero
//we would store the bits which are not zero
/*n is the lenght of array and p is the single no 
for(int b=0;b<=31;b++){
c=0;
for(int i=0;i<n;i++) if(v[i]&(1<<i)) c++;
if(c%3) ans+=1<<b;
}
cout<<ans<<endl;
*/
//time complexity -O(32*n)

//another methdo will be bucket filling';






//how to find maximum xor of element between two given numbers l and r 
// the ans could be more than or less than or equal to r (upper limit)
//we will check till how many bits of number is the upper limit present .
//i will try to make most of the digits to be 1
//check till the umbers are same and when different make it 1 with r dif bit=1 and l dif bit =0 and then put all bits of l to 1 and r to be 0 
//to find both the numbers
//to keep the most significant bit and unset all
// int max_xor(int l,int r){
//     int i,a,b,r1=r,m_x;
//     for(i=31;i>=0;i--){
//         if(((l>>i)&1) != ((r>>i)&1)) {break;}
//         a+=((l>>i)&1)<<i;
//         b+=((r>>i)&1)<<i;
//     }b+=((r>>i)&1)<<i;
//     for(int j=i-1;j>=0;j--){
//         a+=1>>j;
//     }cout<<"no for which maximum xor is possible "<<endl;
// }
//__builtin_clz--tells the no of leading (pehle se) zeros in a 32 bit integer 


//important formula 
//a+b=a^b +2*(a&b)
//~a=-a-1

//find the no of a's that follows the eqn --a^x> x 
//and a belongs to 0<a<x
//for thsi a must have more bits set 
//logic -first start from most significant bit of x by using __builtin_clzll(for long long) and set it to 0 and 
//check every bit of x if unset make it set and then combination will arise 
//see when the first bit is toggled after the msb then they all possible combination will be more than x and a will be less than x
//__builtin_popcount--tells the no of set bits O(1)
//multiply or divide a no by 2^k