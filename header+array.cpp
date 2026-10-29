#include <iostream>
//to include the input /output stream library in program
#include <iomanip> 
//to format the output
/*setw--to set the output of width
setprecision-- to set the deciaml precision
left--for lest aligning
right--for right aligning*/
//float pi=3.1456767;
//cout>>pi>>setprecision(3);
#include <cmath>
/*sqrt(x)--to calculate the square root of x
pow(x,y)--to calculate the power of x raised to y
abs(x)-- to calculate the absolute value
ceil(x)--to round off to lowest integer more than that no.
floor(x)-- to round off to greatest integer les than that no. */

#include <string>
//an array of characters
/*s.length()--
s.substr(ini,len)--to find the substring
s,find("..")-- to find the substring or string and also return error if not found
s.replace(ini,final,"..")-- can replace the required substring to given
can be used to conacatenate and then s.empty()-- to clear and to access element just like array*/
#include <vector>
//#include "start.cpp"// for using cpp files in this program use"" instead of <>
//using.cpp for larger program may cause error so use .h instead
// if using this file everything of this file wil come into this program and hence you cant write main function again
//array
// aray is a collection of similar data tyes located in continiuos memory location, it is mutable and can be changed after defining
#include <algorithm>
//can be used in arrays  as well as vectors,deque
//all algoritm work under iterators(begin(),end())
//find(),find_if(),find_if_not()--find element and three paramenter for _if and for_if_not the condition is passed
//count(),count_if()--counts the no of occurances of element and gives 3 paramenters
//copy(),copy_if()--copy range of value
//replace() ,replace_if()-- four parameters are given as input
//sort(),is_sorted()--sort uses introsort and sorts in ascending, and checks whether sorted or not, two parameters input
//binary_search(),lower_bound(),upper_bound()--these fuunctons work on sorted ,takes three parameters
//min(),max()--takes two parameeters(not range of value) and tels the max or min
// max_element(),min_element()--takes range of value and tells the max or  min between them
/*an important way to produce permutations of a no arrangedin ascending using next_permutations
 v={1,2,3} must be arranged in ascending order
 do{
 for (int i:v)cout<<i;
 cout<<endl;
 }while (next_permutations(v.begin(),v.end()))
when after the last element the next_permutation returns false*/
//swap,swap_ranges(),reverse(),shuffle()--takes only two parametes
//set_union(),set_intersection(),set_differnece(),set_symmetric_differnence()--set function taht can be used later
using namespace std;
int main(){
    // float n,n1,n2;
    // string st;
    // float f;
    // cout<<"enter a no in decimal format";
    // cin>>f;
    // n=sqrt(f);
    // n1=pow(n,f);
    // n2=ceil(f);
    // cout<<"Enter a string"<<"\n";
    // //cin>>st; only single word is taken as input 
    // getline(cin>>ws,st);//ws used to rermove the trailing whitespaces before 
    // cout<<st.length()<<endl;
    // cout<<st.substr(0,3)<<endl;
    // cout<<st.find("a")<<endl;
    // cout<<setw(4)<<n<<endl;
    // cout<<setprecision(3)<<f<<endl;
    int arr[8]={2,1,3,4,5,6,7,8};
    // in arrays , the address of first element can also be given by the name of the array 
    arr[4]
=5;
    int *p=arr;// in array the address is defined automatically not ot use the & opeartor
    cout<<arr<<"\n";
    cout<<p<<"\n";
    p++;
    cout<<p<<"\n";
    //address of new element can be found by =addressof current element + (size of data type)*(no f elements difference)
    p+=4*sizeof(int);
    cout<<p;
}
//in call by value -- whenever the argument is passed in the function even if the function changes its value, the original value of variable doesn't changes 
//in call by reference -- whenver the variable is passed it is passed with its address so that if the function changes the value , the original variable will also be affected
// in case of arrays the address is automatically passed 