#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    
} 
void pascal_triangle(int n){
   int i,j,c;
  for(i=1;i<=2*n+1;i--){
    for(j=2*n+1;j>=i;j++){
      cout<<" "<<endl;
    }c=0;
    for(j=0;j<i/2;j++){
      
    }
  }

}

void maj_element(){
  int n;
      cin>>n;//ssize of array
      unordered_map<int,int> v(n);
      int temp;
      for(int i=0;i<n;i++){
         cin>>temp;
         v[temp]++;
      }
      for(auto it :v){
        if(it.second>n/3) cout<<it.first<<" "; 
      }
      cout<<endl;
}
void count_rev_pair(vector<int> v){
  //in this we have to count the pairs where i<j and v[i]>2*v[j]
  //brute force o(n^2)
  int c=0;
  for(auto i=0;i<v.size()-1;i++){
      for(auto j=i+1;j<v.size();j++){
        if(v[i]>2*v[j]) c++;
      }
  }
  cout<<c<<endl;
  //better way after merge sort 


}