#include <iostream>
#include <utility>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int main(){
} 
void explain_pair(){
    //stl pair is can store two  values of two data dat types can be same or different 
    //for including pair in program ,no different header is there 
    pair <int,double> p={1,2.34};
    //for accessing the elments p.first and p.second are used
    cout<<p.first<<" "<<p.second;
    //by default ,when sorting in pair the first value gets compared if it is same then second one.
    //we can also compare two pairs
    //we can also use nested pairs
    //swaping pairs {swap(p1,p2)} it is a algorithm
    //pairs are mutable and can be changed
    //pairs are also used with sets ,vector and map

}
void explain_vector(){
    //arrays are static and size can't be changed this is why vector is used
    vector <int> v;//creates an empty vector with no index defined
    //in this vector elements can't be added like v[0]=2 as vector size is not defined
    //if we define like vector <int> v(n,0)--then size n and all elements wil be 0
    //vector is mutable i.e it can be modified
    v.size();//returns an signed integer
    v.empty();//return true or false
    v.resize(n,m)//resizes the vector to size n with all elements as m default is 0
    v.push_back(3);
    v.emplace_back(10);//it is faster than push back for objects
    v.insert(v.begin()+i,38)//inserts 38 at i th position and shifts the next element
    v.insert(v.begin()+i,3,7)//inserts 3 copies of 7 at ith position 
    v.pop_back();//removes last element
    v.erase(v.begin()+i)//removes element as ith position
    v.erase(v.begin()+i,v.begin()+i+7)//to remove the range of elements from vector
    v.clear();//to remove  all the elements of vector
    //access the elements of vector
    for (auto &x : v)
    cin >> x;
    sort(v.begin(),v.end(),greater<int>());//sort in descending order
    //data() return a pointer with the contagious memory 
    int *p=v.data();//pointer becomes invalid if reallocation of memory occurs
    reverse(v.begin(),v.end());
    vector <int> ::iterator it =v.begin();//syntax of an iterator , it points to the memory address of the first element of vector
    cout<<*(it)<<endl; //to access the element 
    vector <int> iterator it=v.end();//it points to memory address just after the last element of the vector
    it--; cout<<*it<<endl;//to access the last element
    for(vector <int>:: iterator it=v.begin() ;it!=v.end();it++) cout<<*(it)<<endl;
    for(auto it=v.begin();it!=v.begin();it++) cout<<*(it)<<endl;
    //iterator is a general pointer that iterates through the members of the vector
    //auto is akeyword which determines the data type itself automatically
    auto s="raj";//auto automatically assigns s to be a string data type 
    v1.swap(v2);
    //time complexity of 
    //insert and remove at end --O(1)  at any position --O(n)
    //erase -O(n)
    //empty-O(1) but clear-O(n)
    //swap-O(1)
    //reverse O(n)
}
//for (int i = 0; i < v.size(); i++)  // ❌ warning: signed vs unsigned
//for (auto i = 0; i < v.size(); i++) // i deduced correctly use of auto
//263510072680
void explain_list(){
    //all function are same as vector 
    //,pushback,begin,end,clear,end,insert,size,swap,sort,size
    list<int> l;
    l.push_front(4);
    l.embrace_back(45);
    //but we cant directly access elements in list like vector
}
void explain_deque(){
    deque <int> dq;
    //all funcion are same for deque also
    //works on FIFO
}
void explain_stack(){
    stack <int> st,st1;//based on LIFO
    st.push(1);//1
    st.push(2) ;//in stack the element is pushed from the beginning  2 1 
    st.emplace(5);//5 2 1 
    cout<<st.top();//to access the first element  prints 5
    //we can't access any index by []operator
    st.pop();//2 1 
    cout<<st.size();//2
    cout<<st.empty();//true or false
    st.swap(st1);
}
void explain_queue(){
    queue <int> q;//works on FIFO
    q.push(1);//1
    q.push(2);//1 2
    q.emplace(4);//1 2 4 
    q.back+=4;//1 2 8
    q.pop();//2 8
    cout<<q.front();//2
    //swap, size,empty
}
void explain_priority(){
    priority_queue <int> p;//just like queue but it is placed according to the value
    p.push(2);//2
    p.push(5);//5 2 
    p.emplace(1);//5 2 1
    cout<<p.top();//print 5
    //remember data is not stored in a linear fashion probably like trees
    priority_queue<int,vector<int>,greater <int>> p1;//to store minimum element first in order
    //time complexity 
        //push--log n
        //top --O(1)
        //pop --log n
}
void set(){
    set <int>s;
    //stores unique elements in a sorted ordered way
    s.insert(1);//1
    s.emplace(2);//1 2
    s.insert(5);//1 2 5 
    s.emplace(4);//1 2 4 5 
    //begin(),end(),size(),empty(),swap() are same 
    auto it =s.find(2);//returns an iterator pointing to the position of 2
    //if element not found then returns s.end() which points after the last element
    s.erase(5);
    int c=s.count(1);
    auto it1=s.find(2);
    auto it2=s.find(5);
    s.erase(it1,it2);//removes the element between the two iterator 
    //iterator and memory address are different because it is raw location in RAM but iterator is a container element
    //time complexity of every function in set-log n
    //even if set time complexity is less set uses pointer jump from element to element 
}
void explain multiset(){
    //everything is same as set but stores duplicate element also
    multiset<int> m;
    m.insert(1);//1
    m.insert(2);//1 2 
    m.insert(1);//1 1 2
    m.erase(1);//all 1 erased and removed
    cout<<m.count(1)<<endl;
   // m.erase(&1,&2);--it is wrong iterator to be use dby find method
   //for all classes time complexity of set is O(1)
}
//there is an class of unordered set which stores distinct element and does not sort as in set
//it is very special as it only takes O(1) for insert remove or find operation in average case 
//but worst is O(n) alwaysly better tahn vector in terms of time complexity 
//but in sets it takes more space complexityu
void map(){
   //just like dictionary in python
   //keys are sorted and does not depend on indexing and similar keys are not allowed
   map<int ,int> m;
   m[1]=2;
   m.emplace({3,1});
   m.insert({2,3});
   map <pair<int,int>,int> mp;
   mp({2,4})=10;
   for(auto it :m) cout<<(it).first<<(it).second<<endl;//accessing like pair 
   //in this  method t access ,(it) is a element of teh contianer
   auto it =m.find(1);//element are found on the basis of key only and this is an iterator now
   auto it =m.find(5);//if 5 is  not there , the iterator points to m.end()
   cout<<m[3];// prints 1
   cout<<m[2];//prints 3
   //erase , swap, size are same
   //map works on log n time complexity
   //storing or fetching any element from a map time complexity is log n 
   //unordered map has constant time complexity of 0(1)(best and average) and worst O(n)
   //so always prefer unordered map instead of non ordered one no tin cp
}
//in unordered map every function time complexity is O(1) in average and best case but o(n) in worst case
//o(n) is where all element add up to the same key
//but in maps i cant modify the keys once allocated
void multimap(){
    multimap<int,int> mmp;
    //everything is same as map but here keys with multiple name is allowed
}

//ques--sort a map by the increasing order of second element if the second element is same 
//then sort by decreasing order of first element

//this can be done by comparator and sort function 
//sort(a,a+n,comp);
//comparator is nothing but a user defined rule which passes true /false to sort function 
//which checks it before swapping , if passes true then swaps accordinf=g to the condition
bool comp(pair <int,int> p1,pair <int,int>p2){
    if (p1.second<p2.second) return true;
    
    else if (p1.second==p2.second){
            if (p1.first >p2.first) return true ;
            else false;}
    else
    return false;        
}
//to print all permutations of a string
string s="123";
do{
    cout<<s<<endl;
}while (next_permutation(s.begin(),s.end()));
//to print all permutation start from the sorted string

//euclidean algorithm
//gcd(a,b)= gcd(a%b,b) where a>b
//applying this till any one no. becomes zero
