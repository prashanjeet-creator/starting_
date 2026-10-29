#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
//time complexity -log n
void insert(vector<int> v,int target);
void floor_ciel(vector<int> v,int target);
void count_occurance(vector<int> v,int target);
void first_last(vector<int> v,int target);
void min_rotated_array(vector<int> v);
void sq(int n);
void n_root(int n,int m);
int b_s(vector<int> v,int low,int high,int target){   
    int mid=low+(high-low)/2;
    if(low>high)        return -1;
    else if(v[mid]==target)  return mid;
    else if(v[mid]<target)   low=mid+1;
    else                     high=mid-1;
    b_s(v,low,high,target);  //clear removes all the element from the vector
}//this is the recursive function method
int main(){
    int pos,n,s,i;
    cin>>n>>s;//size of array
    n_root(n,s);
    //vector<int> v(n);
    //for(i=0;i<n;i++){
    //    cin>>v[i];
    //}
    //cin>>s;//we can do by another method by while loop
    //count_occurance(v,s);
    //min_rotated_array(v);
    //first_last(v,s);
    //floor_ciel(v,s);
    //insert(v,s);
    //pos=b_s(v,0,n-1,s);
    //cout<<pos<<endl;
    //int ans=n;
    //lower bound--O(log2 n)--same for upper bound 
    /*while(low<=high){
        int mid=low+(high-low)/2;//this step is very impoertant for larger arrays 
        if(v[mid]>=s) {high=mid-1; ans=mid;}// as in lower bound number must be greater than x
        else           low=mid+1;
    }
    cout<<ans<<endl;*/
} 
//lower bound--smallest index such that arr[index] is greater than or equal to x in a sorted array
//if number is found in the same array then the position of the number will be the lower bound 
//else it will be the smallest number which is greater then x
//for ex arr=[2,4,5,67,88,90]
//x=62   lower bound for this example is 3(index of 65) 
//x=91   lower bound is the end of this arr last hypothetical index -this is the reason we initialize ans to be size of vector 
//we can find lower bound with an average time comp of O(n) and best case being O(1)
//another approach is we have to use direct inbuilt function
//lower_bound(arr.begin(),arr.end(),x)-arr.begin() --- this will return an iterator pointing to lower bound of x 

//upper bound -smallest integer which is less than x 
//a=[12,33,43,55,66]
//if x=22 then upper bound index 1
//if x=11 then upper bound index 0
//simply lower bound if no not found else then  next integer 
//upper_bound(a.begin(),a.end(),x)-a.begin -- direct inbuilt function for upper bound
//these upper_bound and lower_bound return the integer no the position and take log n 


//to find insert position 
//in this we have to put an elemnent in its pos
void insert(vector<int> v,int target){
    auto pos=upper_bound(v.begin(),v.end(),target)-v.begin();
    cout<<pos<<endl;
}

void floor_ciel(vector<int> v,int target){
    //log n--O(n)
    int low=0,high=v.size()-1,f=-1,c=v.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==target)     {f=mid;c=mid; break;}
        else if(v[mid]>target) {c=mid; high=mid-1;}
        else {f=mid; low=mid+1;}
    }
    cout<<v[f]<<" "<<v[c]<<endl;
}


//first and last occurance of a no if it is present multiple times else both will be same 
void count_occurance(vector<int> v,int target){
    //we will find the index of lowerbound and upperbound and diference it 
    int l=lower_bound(v.begin(),v.end(),target)-v.begin();
    int u=upper_bound(v.begin(),v.end(),target)-v.begin();//to find the index of upper bound of target
    cout<<u-l<<endl;
}

void first_last(vector<int> v,int target){
    int l=lower_bound(v.begin(),v.end(),target)-v.begin();
    int u=upper_bound(v.begin(),v.end(),target)-v.begin();
    cout<<l<<" "<<u-1<<endl;
}

//search element in a rotatyed sorted array 
//in this we have first check whether the left part or right part is sorted or not 
//identify the portion which to eliminate
//in this all elements are unique
void rotated_array(vector<int> v,int target){
    int low=0,high=v.size()-1,pos=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==target) {pos=mid; break;}
        else if(v[mid]>=v[low])//left part is sorted
        {
            if(v[mid]<target && v[high]>target)  low=mid+1;
            else                                 high=mid-1;
        }
        else {//right part is sorted
            if(v[low]<target && v[mid]>target) high=mid-1;
            else low=mid+1;
        }
    }
    cout<<pos;
}


void min_rotated_array(vector<int> v){
    int low=0,high=v.size()-1,mid,mn=INT16_MAX;
    while(low<high){
        mid=low+(high-low)/2;
        if(v[mid]<v[low]) //right sorted array
        {   if(v[mid]<=mn) mn=v[mid];
            high=-1+mid;
        }
        else {//left sorted 
            if(mn>=v[low]) mn=v[low];
            low=1+mid;
        }
    }
    cout<<mn;
}

void sq(int n){//tc--log n
    //as we know square root of a no lies between half of the no and 1 always 
    //and all elements are sorted between so we can use inary ysearch
    int low=1,high =n,ans=0;
    while(low<=high){
        int mid =(low+high)/2;
        if(mid*mid==n) {ans=mid; break;}
        else if(mid*mid<n) low=mid+1;
        else  high=mid-1;
    }
    cout<<ans<<endl;
    //prints 0 if sqrt if the  no is not an integer
}

void n_root(int n,int m){
    //as we know nth root of no lies between 1 to m and all positions are sorted
    int low=1,high=n,ans=0;
    while(low<=high){
        long long mid=(low+high)/2;
        long long p=1,m1=m,val=mid;
        while(m1>0){
            if(m1&1) { p*=val; m1--;}
            else     {m1/=2; val*=val;}
            if(p>n)  { break;}
        }
        if(p==n) {ans=mid; break;}
        else if(p<n) low=mid+1;
        else high=mid-1;;
    }
    cout<<ans;
}

void koko_eating_banana(vector<int> v,int h){
    int sm=0;
    for(int i=0;i<n;i++) sm+=v[i];
    int l=0,high=sm,s=0,ans;
    while(l<high) {
        int mid=(l+high)/2,s=0;
        for(int i=0;i<n;i++)  s+=ceil(double(v[i])/mid);
        if(s>=h) {ans=mid; high=mid-1;}
        else  l=mid+1;
    }  
}