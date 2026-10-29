#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef map<ll,ll> m;
typedef vector<pair<ll, ll>> vpll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define in(n) ll n;  cin >> n
#define inn(n, k) ll n, k;   cin >> n >> k
#define inv(v, a, b)  for (ll i = a; i < b; i++) cin >> v[i]
#define f(i, l, r) for (ll i = l; i < r; i++)
#define rf(i, l, r) for (ll i = l; i >= r; i--)
#define outa(arr, a, b) for (ll i = a; i < b; i++) cout <<arr[i]<<' '
#define out(n) cout << n << endl
#define yes cout <<YES<< endl
#define no cout <<NO<< endl
// class st_imp_array{
//     ll top=-1;
//     int a[1e5]={};
//     void push(ll x){top+=1; a[top]=x;}
//     void pop(){top=top-1;}//not actually deletes element but makes sure it si not visible and can be overwritten if needed
//     int top(){return a[top];}
//     int size(){return top+1;}
// };
// class queue_imp_array{
//     ll start=-1,end=-1;
//     int a[10]={};
//     void push(ll x){end+=1; a[end]=x;}//already assumed that array has sufficient length
//     void pop(){start+=1;}
//     int top(){return a[start];}
//     int size() {return (end-start+1);}
// };
class Node{//acts as a data type
    public ://default - private
    int data;
    Node* next;
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    //multiple constructors to better user interface
};
class stack_imp_ll{
    Node* n =new Node(-1);
    Node* t =n; int c=0;
    public:
    void push(ll x){c++; Node* t1=new Node(x); t1->next=t; t=t1;  }
    void pop(){t=t->next;  c--;}
    int top(){return t->data;}
    int size(){return c;}
};
class queue_imp_ll{
    Node* n=new Node(-1);
    Node* t=n; int c=0;
    public:
    void push(ll x){c++; t->next=new Node(x); t=t->next;}
    void pop(){c--; n->next=n->next->next; }
    int top(){return n->next->data;}
    int size(){return c;}

};
class stack_using_queue{
    queue<ll> s;
    public:
    void push(ll x){int i=s.size();while(i) {s.push(s.front()); s.pop(); i--;} s.push(x);}
    void pop(){s.pop();}
    int top(){return s.front();}
    int size(){return s.size();}
};
class queue_using_stack{
    stack<ll> s;
    public:
    void push(ll x){int i=s.size();while(i) {s.push(s.top()); s.pop(); i--;} s.push(x);}
    void pop(){s.pop();}
    int top(){return s.top();}
    int size(){return s.size();}
};
//to find the smallest elment next to the element this is to be done by stack as we dont know the forward element so using stack to implement
//remember these types of problem to implement 
class Solution {
public:
    vector<int> nextSmallerElements(vector<int>& nums) {
        deque<int> s;
        vector<int> v(nums.size());
        for(int i=nums.size()-1;i>=0;i--) s.push_front(nums[i]);
        for(int i=nums.size()-1;i>=0;i--){
            //s.pop_back();
            while(!s.empty() && s.front()>=nums[i]){
                s.pop_front();
            }
            if(s.empty()) v[i]=(-1);
            else v[i]=s.front();
            s.push_front(nums[i]);
        }
        return v;
    }
};
//for no of element which is greater than thi element we will again use stackk as we dont know about the next elements
class Solution1 {
public:
    vector<int> no_of_nextGreaterElements(vector<int>& nums) {
        deque<int> s;
        vector<int> v(nums.size());
        for(int i=nums.size()-1;i>=0;i--) s.push_front(nums[i]);
        for(int i=nums.size()-1;i>=0;i--){
            //s.pop_back();
            int c=0;
            deque<int> s1=s;
            while(!s1.empty() ){
                if(s1.front()>nums[i]) c++;
                s1.pop_front();
            }
            v[i]=c;
            s.push_front(nums[i]);
        }
        return v;
    }
};
bool balanced_paranthesis(string s){//only this type of bracket { } , [ ]
   //checks whether every bracket is closed symmetrically like if one is oned before and then another type is opened then second type must close before the the first type
   stack<char> st;
   f(i,0,s.size()){if(!st.empty() &&((s[i]==')' && st.top()+1==s[i]) || st.top()+2==s[i])) st.pop();  else st.push(s[i]);}
   if(st.size()) return false;
   else return true;
}//time complexity -O(n) space complexity - O(n)
//remember using stack in a problem does not reduce time complexity rather it can increase so see the constaints of the prblem before implementingg stack 
int main(){
    // stack<ll> s;
    // s.push(1); s.push(5); s.push(7);
    queue_using_stack s; s.push(6); s.push(71); s.push(101);s.push(1011); s.pop(); cout<<s.top();
    //cout<<s.top()<<endl;
    // st_imp_array p=new st_imp_array();  kl padhke aana classes
    //cout<<(balanced_paranthesis("{{}{[]}([]{}){}")); 
}

//a stack is a linear data structure that follows LIFO(lst input first output)
//in stack all operations happen at the top (whether to input or to delete)
//push- add a new element at the top
//pop - deletes a topmost element
//top - retures the value of the top element without removing it
//empty()- checks whether the stack is empty or not
//size() - returs the size of the stack
//if string is in problelm no ned to create stack as it has equivalent functions like back(),pop_back(),push_back()

//QUEUE-first in first out 
//all operations happenn from the front 
//push--add a new element at the back
//pop-delete a new element from the front
//front - to view the front element 
//back- to view the last element
////empty,size,swap--all other normal function of queue
//all operations take log n time

//PRIORITY QUEUE--sorts such that the largest element is at the top .it is implemented by binary heap
//can also change the order for smallest element att the top
//priority_queue<int,vector<int>,greater<int>> minheap
//push and pop takes log n time 
//top ,empty ,size takes O(1) time 

//deque- a two ended queue
//push_front--adds an element to front of the queue
//push_back-- adds an element to the end of the queue
//pop_front--deletes from the front of a linked list if not present error
//pop_back--deletes from the back of a linked list if not present error
//front()--returs the value of first element 
//back()--returns the value of back element
//size()--returns the size
//all these operations use O(1) time complexity


//operator - a mathematical operation which is defined operand - the varables in ehich operator is working
//postfix- used in calculator operator used after the operation
//infix = the human way in  which we write operators between two operands
//prefix- theoperator used before the operands 
//this is how computers operation works they will shift infix to postfix and then perform operation

//conversion of infix to postfix operator 
//first take the overall calculation in string a+b*c-(d*e^f)
//first write the operand one by one if the priority order is lower and pop out the last element from the stack containing operators
//if bracket comes and ends then make sure to pop out till the priority is still bigger than the contents between the brackets
//abc*+def^*- -->postfix operator for the following

//conversion of infix to prefix --first convert int o postfix and then reverse for postfix
