#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
//merge sort--divide and merge
void merge_sort(int *a,int low,int high){//auto never works in function
    int mid;
     if(high==low) return ;
     mid=(high+low)/2;
     merge_sort(a,low,mid);
     merge_sort(a,(mid+1),high);
     m(a,low,mid,high);
}
void m(int *a,int low,int mid,int high){
    vector <int> temp;
    int i,left=low,right=mid+1;
    while(left<=mid && right <=high){
        if(a[left]<a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    } while (left<=mid)  {//if element of left array is not finished
        temp.push_back(a[left]);
    }
    while (right>=mid+1){//if element of right array is not finished
        temp.push_back(a[right]);
    }
    for(i=low;i<=high;i++){//to store the elements of temp array in original array
        a[i]=temp[i-low];
    }
}
int main(){
    int n;
    cin>>n;
    int i,j;
    int a[n]={};
    for(i=0;i<n;i++){
        cin>>a[i];
    }/*//selection sort is in which 
    we have to select the minimum elemnt and place it at the front of the selected array
    for(i=0;i<n-1;i++){
        mn=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(mn>a[j])
            {   
                mn=a[j];
                pos=j;
            }
        }
        a[pos]=a[i];
        a[i]=mn;
    }
    for(i=0;i<n;i++)
    cout<<a[i]<<endl;
    //best and average nad worst case of time complexity --O(n^2)
    //because for every exmaple it runs i loop runs n-1 times and j loop n+1/2

*/
  //bubble sort-- pushes the min to the first by adjacent swapping
  /*for(i=0;i<n-1;i++){
    int s=0;//added this if the list is already sorted then best case O(n)
    for(j=i;j<n;j++){
        if(a[j]>a[j+1])
        swap(a[j+1],a[j]);
        s++;
    }if (s==0) break;
  }
  for(i=0;i<n;i++)
  cout<<a[i]<<endl;
  //worst and average time complexity--n^2*/



  //insertion sort --takes an element and inserts it in correct position
  /*for(i=1;i<n;i++)
  { 
    for(j=i;j>=0;j--)
    {
        if(a[j+1]<a[j])
        swap(a[j+1],a[j]);
    }
  }*/// time complexity of best and average case--O(n^2)
  
  //time complexity of best case if while loop with condition a[j]>a[j+1] used then O(n)
   
  merge_sort(a,0,(sizeof(a)/sizeof(int)-1));
  for(i=0;i<n;i++)
  cout<<a[i]<<endl;  
} 

void quick_sort(int *a[],int low,int high){
    int p,n=sizeof(a)/sizeof(int);
    if(low<high){
          p=pos(a,low,high);
          quicksort(a,low,p);
          quicksort(a,p+1,high);
    }
}
int pos(int *a,int low,int high){
    int i=low,j=high;
    int pivot=a[0];
    while (i<j){
        while (a[i]<pivot && i<high){
            i++;
        }
        while (a[j]>pivot && j>low){
            j--;
        }
        a[i]=a[i]+a[j];
        a[j]=a[i]-a[j];
        a[i]-=a[j];
    }
}

