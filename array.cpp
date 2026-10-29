#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<unordered_map>
using namespace std;
int main()
{
    vector<int> v;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    find_largest(v);//time complexity --O(n)
    find_second_lar(v);//time complexity --O(n)
    check_sort(v);//time complexity --O(n)
    remove_dup(v);//time complexity --O(n^2)
    rotate_left(v);//time comp O(n)
    rotate_left_d(v,d);//O(n)
    end_zero(v);//O(n)
    union_(v);//O(n)
    missing_no(v);//O(n)
    max_ones(v);//O(n)
    ones_twice(v);//O(n)
    long_Sum(v,k);//O(n)
    two_sum(v,target);
    sum_max(v);
    sign(v);
    stock(v);
    next_per(v);
    cons_subarray(v);
    matrix(v[v]);
    tranpose_matrix();//to rotate a matrx by 90 degree
    #max_subarray(v);//to find the max sum of subarray 
    spiral_matrix();//aukat se bahar spiral way
    count_subarray(v,sum);//to count the no of subarray which has sum 
}
void find_largest(vector<int> &v)
{
    int max = v[0];
    for (auto i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
            max = v[i];
    }
    cout << "The MAXIMUM NO IS:" << max << end;
}
void find_second_lar(vector<int> &v)
{
    int max = v[0];
    for (auto i = 0; i < v.size(); i++) // time complexity of erase an remove O(n)   {
    {
        if (max < v[i])
            max = v[i];
    }
    remove(v.begin(), v.end(), max);
    for (auto i = 0; i < v.size(); i++) // time complexity of erase an dremove O(n)   {
    {
        if (max < v[i])
            max = v[i];
    }
    cout<<"Second largest element is:"<<max<<endl;
}
void check_sort(vector <int> &v){
     int c=0;//check for both ascending and descending order
     if (a[0]>a[1]){
       for(auto i=0;i<v.size();i++){
        if (v[i+1]>v[i]){ c++; break;}
     } 
     }
     else if(a[0]<a[1]){
     for(auto i=0;i<v.size();i++){
        if (v[i+1]<v[i]){ c++; break;}
     }}
     else{
        c++;
     }
     if(c==0) cout<<"SORTED ARRAY"<<endl;
     else cout<<"NOT SORTED"<<endl;
}
void remove_dup(vector<int> &v){
    //set<int> s;
    for(auto i=0;i<v.size();i++){
      //  s.insert(v[i]);//costly operation as evry insert O(n) and loop is also running n times
       
    }
    for(i=0;i<s.size();i++){
        cout<<s[i];
    }
}
void rotate_left(vector<int>&v){
    temp=v[0];
    for(auto i=1;i<v.size();i++){
         v[i-1]=v[i];
    }v[n]=v[0];
    cout<<"Array after rotating left"<<endl;
    for(auto i=0;i<v.size();i++){
       cout<<v[i]<<endl;
    }
}
void rotate_left_d(vector<int> &v,int d){//2 3 4 5 6 7 6--> 4 5 6 7 6 2 3  
    int c=0,i=0;
    vector<int> temp(v.size());
    while (i<v.size()){
    if (i-d>=0){
       temp[i-d]=(v[i]);
       
    }
    else{
        temp[v.size()-d+i]=(v[i]);
    }i++;
}
for(i=0;i<v.size();i++) cout<<v[i]<<endl;
}

void end_zero(vector<int> &v){
    vector<int > temp(v.size());
    for(int i=0;i<v.size;i++){
        if(v[i]!=0) {temp[c]=v[i];
            c++;}
    }
    for(auto i=0;i<v.size();i++) cout<<temp[i];
}

void union_(vector <int> v,vector <int> v1){//sorted array must be input
    int l2=0,c=0;
    vector<int> temp;
    for(auto i=0;i<v.size();(c==1)?c=0:i++){
       if(v[i]>=v1[l2]){
          temp.push_back(v[i]);
       }
       else{
        temp.push_back(v1[l2]);
        l2++;c=1;
       }}
 for(auto i=0;i<temp.size();i++)  cout<<temp[i];
    
}
void missing_no(vector<int> &v){
    auto i,pos;
    for(auto i=0;i<v.size();i++){
       if(v[i]!=i+1) {
        pos=i+1; break;
       } 
    }cout<<pos<<endl;
 }

 
//maximum co=nsecur=tive ones
void max_ones(vector<int> &v){//the vector only consist of 0  and 1
    int c=0,max=0;
    for(auto i=0;i<v.size();i++)   {
        if(v[i]==1){
            c++;
            if (max<c) max=c;
        }
        else{
            c=0;
        }
    }


}

void ones_twice(vector<int> &v){
    map<int,int> m;
    for(auto i=0;i<v.size();i++)   {
        m[v[i]]++;
    }
    for(auto it:m){
        if(m[it]==1)   cout<<it<<endl; break;
    }
}

void long_sum(vector <int> &v,int k){//to find the maximum no of elements such that it makes the sum k
    sort(v.begin(),v.end());//numbers can be both positive and negative
    for(auto i=0;i<v.size();i++)  {
        sum+=v[i];
        if(sum==k){ cout<<i<<endl;break;}
    }if(sum!=k) cout<<0<<endl;
}



//to find two integers from the array so that its sum is equal to the target--time 0(n^2)--space O()
void two_sum(vector<int> v, int target){
    int i,j,sum=0;
    for(auto i=0;i<v.size()-1;i++)   {
        for(auto j=i+1;j<v.size();j++)   {
             sum=v[i]+v[j];
             if (sum==target){
                cout<<"YES"<<endl;
                break;
             }
        }
    }
     if(sum!=target)  cout<<"NO"<<endl;

     
     //better method-using  hashmap(unordered) time complexity reduces total O(1) in best and avg case
    unordered_map<int,int> m;
    for(i=0;i<n;i++){
        if(m.find(target-v[i])!=m.end()){//maximum time complexity(n logn)
            cout<<"yes"<<endl;
            break;
        }

    }
    int l=0,r=v.size()-1;//average and worst log n and best O(1) only complexity
    //in case of sorted array only dont try with non sorted array O(n^2)
    while (l>=r){
       if(v[l]+v[r]>target)
       r--;
       else if(v[l]+v[r]<target)
       l++;
       else{
        cout<<'Yes'<<endl;
        break;
       }
    }
}

//hash map are implemeneted by unordered list
void sum_max(vector <int> &v){
    //sort(v.begin(),v.end(),greater <int> ())--time complexity 0(n^2)
    //using hash map --O(n logn)
    //for only three distinct values use dutch national flag algorithm   
    int mid=0,low=0,high=v.size()-1;
    while (mid<high){
        if(v[mid]==0){
            swap(v[low],v[mid])
            low++;
            mid++;
        }
        else if(v[mid]==1){
            mid++;
        }
        else if (v[mid]==2){
            swap(v[mid],v[high]);//tiem complexity of swap O(1)
            high--;
        }
    }
}

//arrange by sign altenative positive and negative
void sign(vector<int> &v){
    vector<int> neg;
    vector<int > pos;
    int c=0,d=0;
    
    for(auto i=0;i<v.size();i++){
        if (v[i]<0)  neg.push_back(v[i]);
        else pos.push_back(v[i]);
    }if(v[0]>0) c=1;
    for(i=0;i<pos.size();i++){
       if (c==1){
        v[d++]=pos[i];
        v[d++]=neg[i];
       }
       else{
        v[d++]=neg[i];
        v[d++]=pos[i];
       }
    }
    for(i=0;i<v.size();i++) cout<<v[i];
}
//stock buy and sell for maximum profit 
void stock(vector<int> &v){
    int max=0,dif;
    for(auto i=0;i<v.size()-1;i++){
        for(auto j=i+1;j<v.size();j++){
            dif=v[i]-v[j];
            if (max<dif) max=dif;
        }
    }cout<<max<<endl;
}

//to arrange in next permutation--time complexity O(1)
void next_per(vector<int> &v){
    int c=0;
    do{if (c==1){
       for(auto i:v) 
       cout<<i;
    break;}  c++; 
    }while(next_permutation(v.begin(),v.end()))

    //time complexity of next_permutation O(N N!) for all permutation
    //for single permutation worst -O(n)   best and average O(1)
}

//longest consecutive subarray--time complexity O(n Logn)
void cons_subarray(vector <int> &v){
    sort(v.begin(),v.end());//works on quick sort
    int c=max=0;
    for(auto i=1;i<v.size();i++){
        if (v[i]-1==v[i-1]){
            c++;
        }else c=0;
        if (max<c) max=c;
    }
}

void matrix(vector<vector<int>> &v){
    int l;
    vector<int> pos_r;
    //vector<int> pos_c;
    for(auto i=0;i<v.size();i++){
        l=v[i].size();
        for(auto j=0;j<l;j++){
            if(v[i][j]==0){
                vector <int>temp(l,0);
                v[i]=temp;
                pos_r.push_back(j);
            }
        }
    }
    for(auto i=0;i<v.size();i++){
        for(auto j=0;j<pos_r.size();j++)
        v[i][j]=0;
    }
    for(auto i=0;i<v.size();i++){
        for(auto j=0;j<v[i].size();j++){
            cout<<v[i][j];
        }cout<<endl;
    }
}

void tranpose_matrix(){
    int r,c;
    cin>>r;
    vector <int> v[r][r];
    vector <int> temp[r][r];
    for(auto i=0;i<r;i++){
        for(auto j=0;j<r;i++){
            cin>>v[i][j];
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
          temp[i][j]=v[n-j-1][i];//imp line to remember ,incorrect logic 
          // rotates anticlockwise
        }
    }
    
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            cout<<temp[i][j];
    }cout<<""<<endl;
}
}

void max_subarray(vector <int> v){
     int i,j;
     int sum=0,max=0;
     for(i=0;i<v.size();i++){//iterating thru every subarrray and time complexity O(n^3)
        for(j=i+1;j<v.size();j++){
            sum=0;
            for(k=i;k<j;k++)
            sum+=v[k];
        }if(sum>max) max=sum;
     }cout<<max<<endl;
     //for O(n^2) we can also iterate j fromm end to i +1 


     //KADANE'S algorithm --states that if sum <0 then start the subarray to sum again O(n)
     //used to find the max sum in asubarray
     int sum=0;//if we take sum less than 0 if all element are -ve then also s=0
     int max=INT8_MIN;//-2 -1 -3 9
     vector<int> sub_array;
     for(i=0;i<n;i++){
        sum+=v[i];//stores the sum of subarray 
        sub_array.push_back(v[i]);
        if (sum<0){ sum=0;
            sub_array.clear();//O(n)
        if(max<sum){//checks whether sum is max   or not
            max=sum;
        }
        cout<<max<<endl;
        for(i=0;i<sub_array.size();i++){
            cout<<sub_array[i];
        }
     }//if in ques it is mentioned to take empty subarray then iniitialize max with .
}

void spiral_matrix(){
//A kind of spiral printing of matrix 
// 1  2  3  4  5
//16 17 18 19  6
//15 22 21 20  7 
//14 23 24 25  8
//13 12 11 10  9 
//we have to use something like recursive in reducing the order of the matrix by 1
int n;
cin>>n;
vector<vector<int>> v(n(n));
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
       cin>>v[i][j];
    }
} 
//i will delete the first and last row and first and last colunm
spiral(v);
}

void spiral(vector<vector<int>> v){
    int i=0;
    while (v.size()>i){
        
    }
}


void count_subarray(vector <int> &v,int sum){
      //kadane algorithm --states how to find the max sum of subarray,this logic not used 
      // time complexity O(n^2)
      int c=0,s;
      for(i=0;i<v.size();i++){
        s=0;//to count the sum
        
        for(int j=i;j<v.size();j++){
            s+=arr[j];
            if(s==sum)
            {
                c++;
                s=0;
            }
        }
      }
      cout<<c<<endl;

}
