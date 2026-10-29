#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//when a function calls itself repeatedly until a specified condition then it is recursion
//segmentation when memory limit fails due to stack overflow (when no base condition is matched )
void  f(int n){//backtracking or stack flow structure (always use void)
    if(n<1) return ;
    cout<<n<<" ";
    f(n-1);
    //in this case agar f(n) call kiye to n to 1 output karega 
    //agar hm f(n-1) call kiye to n-1 to 1 output karega 
    //so hmko n pehle output karana padega to make it  same 
}
void print(int n){//recursion works like magic --see no thing in this fuction still 
    if(n<1) return;//base condition 
    print(n-1);//hypothesis - we dont need to know how it works we can write automatically
    cout<<(n)<<" ";//induction 
    //see agar hmko print(n) call kiye then 1 to n output karga 
    //agar hm print(n-1) call kiye to 1 to n-1 kamm karega 
    // so hmko bad me ek n add krna hoga 
}
ll s=1;
void fact(int n){
    if(n==1) {cout<<s<<endl; return ;}
    s*=n;
    fact(n-1);
}
void rec(string s){
    
} 
void insert_vector(vector<ll> &v , int temp){//put an element in the right place before sorting 
    if(v.size()==0 || v[v.size()-1]<temp) {v.push_back(temp); return;}
    int val=v[v.size()-1];
    v.pop_back();
    insert_vector(v,temp);
    v.push_back(val);//backtracking sort of thing 
}
void sort_vector(vector<ll> &v){
    if(v.size()==0) return;
    int temp=v[v.size()-1]; v.pop_back();
    sort_vector(v); insert_vector(v,temp);
}
void insert_stack(stack<ll> &s, ll temp){
    //if uou dont take the memory address of date type in recursion it creates a copy of the data type created and any changes made will not affect 
    if(s.size()==0 || s.top()<=temp) {s.push(temp); return;}
    ll val=s.top();
    s.pop(); insert_stack(s,temp); s.push(val); return;
}
void sort_stack(stack<ll> &s){//in decreasing order
    if(s.size()==0) return;
    ll temp=s.top(); s.pop() ;
    sort_stack(s); insert_stack(s,temp);
    return;
}
void del_mid_ele_of_stack(stack<ll> &v,ll k){
    //if_without size given make another unction to calculate size of stack and then middle element by size/2+1 
    //k is the positon from which the element is to be deleted
    if(k==1) {v.pop();return;}
    ll val=v.top(); v.pop(); del_mid_ele_of_stack(v,k-1); v.push(val);
}
void insert(stack<ll> &v,ll t){
    if(v.size()==0) {v.push(t); return;}
    int temp=v.top(); 
    v.pop(); insert(v,t); v.push(temp);
}
void reverse_stack(stack<ll> &v){//reverse a staack without using extra space
    if(v.size()==0) return;
    ll t=v.top();   v.pop();
    reverse_stack(v); insert(v,t);
}
//in this ques we have been given that s starts with 0 and 0 expand to 01 and 1 expands to 10 in every step so we have to preform n steps and tell the kth character in that n th 
string s1="0";
void expand(int n){
    if(n==1) return ; string s2="";
    for(int i=0;i<s1.size(); i++) if(s1[i]=='0') s2+="01"; else s2+="10";
    s1=s2; expand(n-1);
}
void tower_of_hanoi(int n,int a,int c,int b){
    if(n==1) {cout<<a<<" "<<c<<endl; return;}
    tower_of_hanoi(n-1,a,b,c);
    cout<<a<<" "<<c<<endl;
    tower_of_hanoi(n-1,b,c,a); 
    return;
}
void print_powerset(string in,string op,unordered_set<string> &s){//takes 2^n time complexity 
    if(in==""){ll l=s.size(); s.insert(op); if(l<s.size())cout<<op<<" "; return ;}
    string op1=op,op2=op; op2+=in[0];
    in=in.substr(1);
    print_powerset(in,op1,s);print_powerset(in,op2,s);
}//this is to be done using recursive tree we have decision to either select the first word in input or not(choice) 
void print_substring(string s,int i,int j){//takes 2^n time complexity 
    if(i>=s.size()) return;
    if(j>=s.size()) {print_substring(s,i+1,i+1); return;} 
    cout<<s.substr(i,j-i+1)<<endl;
    print_substring(s,i,j+1);
    return;
}
void permutation_with_spaces(string s,string op){
    //in this question ,,we are given a string and we have to pust spaces in between it we have two choices - either put space between two character or not
    //like a_b_c or a_bc or ab_c or abc
    if(s==""){reverse(op.begin(),op.end()); cout<<op<<endl; return;}
    string op1=op+"_"+s.back(),op2=op+s.back();
    s.pop_back();
    permutation_with_spaces(s,op1);
    permutation_with_spaces(s,op2); 
}
void permutation_with_case_changes(string s,string op){
    //we have to change the case of every letter and make cases--either small or bigger there can be two possiblities
    //and if digits are present we cant do anything
    if(s=="" ) {reverse(op.begin(),op.end()); cout<<op<<endl; return;}
    if(s.back()>='0' && s.back()<='9') {op+=s.back(); s.pop_back(); permutation_with_case_changes(s,op);} 
    else{
    string op1=op,op2=op;
    if(s.back()>='a' && s.back()<='z') {op1+=s.back(); op2+=char(s.back()-32);}
    else if(s.back()>='A' && s.back()<='Z') {op1+=s.back(); op2+=char(s.back()+32);}
    s.pop_back();
    permutation_with_case_changes(s,op1);
    permutation_with_case_changes(s,op2);
    }
}//ip -op method of recursion
void balanced_parenthesis(int o,int c,string s){
    //in this we have to generate balanced parenthesis for given values of (o==c) ==n 
    //observation after drawing recursive tree manually -- when c==o then only opening bracket can be used 
    //one more observation is that once o is zero then use c case and vice versa so put if positive block in else
    if(o==0 && c==0) {cout<<s<<endl; return;}
    if(o==c) {s+='('; balanced_parenthesis(o-1,c,s);}
    else{
        if(o>0) {string s1=s+"("; balanced_parenthesis(o-1,c,s1);}
        if(c>0) {string s2=s+")"; balanced_parenthesis(o,c-1,s2);}
    }
}
int main(){
    // fact(5);
    // print(9);
    //vector<ll> v={3,49,55,6,7,7,89,890}; 
    // stack<ll> s; s.push(10);s.push(1330);s.push(101);s.push(1230);s.push(1110);s.push(101);s.push(1);
    // reverse_stack(s);
    // ll n=s.size();
    // for(ll i=0;i<n;i++) {cout<<s.top()<<" "; s.pop();}
    //expand(4); ll k=2; cout<<s1[k-1];//k is position not index
    // int a=1,b=3,c=2,n; cin>>n; cout<<((1ll<<(n))-1)<<endl; tower_of_hanoi(n,a,b,c);
    //unordered_set<string> s;
    //print_substring("abbc",0,0);
    balanced_parenthesis(4,4,"");
}
//in recursion always remember to use void for single output 
//in recursion input becomes smaller as we come towards the answer 
//actually we take some decision then automatically input becomes smaller
//how to identify whether a problem is of recursion or not  -- choices and decision in every stage like repeating or making input smaller
//no of branches of recursive tree = no of choices 
//input -output method --> we just need to define recursive tree using the choices and decisions and generate input and output
//notice that in every step input becomes smaller and at the end input is NULL
//then code 
//learn recursion well it is used in all data types . it is also used in concepts such as backtracking ,dp , graphs so remember recursion is not a substitution of loop
//4  approaches to solve a recursion problem
//recursive tree- input -output method (if understood the decision)
//base - induction - hypothsis ((making input smaller))
//choice diagram(explained in dp)

//IBH method 
//BASE - what is the simplest condition when we know the output the smallest valid input 
//induction - the actual process (logic)  where the program works
//hypothesis -is the design of the recursive problem in which it works for smaller input as well 
//in hypothesis we assume that the function works same for n and n-1 and then make changes in induction to make them same
//rather than tracing every function call in my mind , using this method is a simpler way
//ibh method is mostly used in trees and linked list

//subsequence-deleting characters in between but not changing the relative order
//subset-selecting one or more character from string ,relative order doesnot matter
//substring-the continous block of characters from the original string(no change in relative order)
//every substring is a subsequence and every subsequence is a subset