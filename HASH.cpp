#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <map>
#include <set>
//#include <bits/stdc++.h>
using namespace std;
int main(){
    /*//number hashing
    int arr[9]={1,2,3,4,1,2,3,5,6};
    //map <int,int> m;
    //int c=0;
    // for(auto i=0;i<arr.length();i++){
    //     if (arr[i]!=map.first)  
    // }
    int n=13,number;//element till 12 can be counted and if array has element bigger we would take bigger size
    int hash[n]={0};//declared all element 0
    for(auto i=0;i<9;i++){
        hash[arr[i]]+=1;
    }
    char c;
    do{cout<<"Enter a number to find"<<endl;
        cin>>number;
        cout<<hash[number];
        cout<<"Do you want to enter more numvbers(y/n)"<<endl;
        cin>>c;
    }while (c=='y');

    //character hashing
    int hash_ch[26]={0};//this declared an array with 26 elements as 0
    string s="prashanjeet";//only for small letters
    for(int i=0;i<s.size();i++){
        hash_ch[s[i]-97]+=1;
    }
    char c;
    do{ char ch;
        cin>>ch;
        cout<<hash_ch[ch-97]<<endl;
        cout<<"Do you want to enter more characters(y/n)"<<endl;
        cin>>c;
    } while (c=='y');
} */
//brute force -- a type of solution in which one correct answer is to given among many possible solution 
//#include <bits/stdc++.h> --includes all cp libraries
//hasing is a method in which prestoring and fetching is done
//inside main function int array can be declared at a max size of 1e6
//to declare of more size declare it globally


/*  time complexity
denoted by 0()--big O notation it is not the time taken by the program to compile ehich depends on the system and internet
--it tells how much time will it take for running algorithm
1. Constant time 0(1)
    -this does not depend on input size 
    -for example allocation of memory int x=a[5];
2. Linear time complexity O(n)
    -it grows linearly with input size
    -for loop,while loop
    -if n operation ->time complexity (k) ,then n*100 operation ->time complexity k*100
3.Quadraric time complexity O(n^2)
    -for nested loops grows square with input size
    -used in bubble sort , selection sort
4.Logarithmic time complexity (log n)
    -used in ehere input size gets halved every step
    -used in binary seach ,euclidean algorithm 
    -very fast comparitively
5.O(nlog n)
    -combination of linear and log     
    -used when every operation is haLVeD and performed n times
6.O(n!)
    -worst time complexity  takes much time 
maximum value of n for time complexity
O(1)-for all integers
O(n)-10^7
O(n^2)-10^4
O(log n)-10^9
O(nlog n)-10^6
O(n!)-10
O(2^n)-20    
*/


//as we know hashing is available in array and numbers must be less than 10^7
//so for bigger no we will prefer another method like in which we will iterate only 
//through the numbers which are in the array 
int arr[]={1,3,4,55,6,6,7,8,99,43,3,5,6,677,88,99,9};
set <int> m;
for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
    m.emplace(arr[i]);
}
map <int,int> c;//declaration of map no length required and values are automayically declared 0
for(int i=0;i<(sizeof(arr)/sizeof(int));i++){
    c[arr[i]]++;
}//values already declared 0 important for map
int a;
char ch;
//how this returns 0 if no are not present even even if the key of that no is not found
do{ 
        cin>>a;
        cout<<c[a]<<endl;
        cout<<"Do you want to enter more characters(y/n)"<<endl;
        cin>>ch;
    } while (ch=='y');
}