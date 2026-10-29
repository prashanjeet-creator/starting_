#include<bits/stdc++.h>
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high =nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {return search;}
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        if(low>high) return -1;
    }
};
int main(){
    int n,t;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>t;
    cout<<Solution::search(v,t)<<endl;
}