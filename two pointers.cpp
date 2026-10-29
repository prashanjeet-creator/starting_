#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void longest_subarray_bf();
void longest_subarray_sw();
int main(){
    //longest subarray with sum less than k
    //given an array and a no k
    //longest_subarray_bf();
    //in sliding window the l and r are always used ,window can shrink or expand
    //shrink from the left and expand fromt he right 
    //first if sumless than k --> expand from the right || else sum> k --> shrink from the left
    longest_subarray_sw();
}
void longest_subarray_bf(){//O(n^2)
    //idea generate all subarrays and check whether the sum si less than k or not
    ll n,k,ans=0,mx=0;cin>>n>>k;
    vector<ll> v (n);
    vector<ll> ps (n+1);
    for(ll i=0;i<n;i++ ) {cin>>v[i]; if(i==0) ps[1]=v[0]; else ps[i+1]=ps[i]+v[i];}
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll s=ps[j]-ps[i];
            if(s<=k) mx=max(mx,j-i);
            else if((s>k)) break;
        }
    }cout<<mx<<endl;
}

void longest_subarray_sw(){
    ll n,k,s=0,ans=0,mx=0;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin>>v[i];
    int l=0,r=0;
    s=0;
    //better solution (pattern 2)
    while(r<n){//O(n+n)
        // if(s+v[r]<=k) {s+=v[r]; r++; ans++;}
        // else {s-=v[l]; l++; ans--;}
        // mx=max(mx,ans); time complexity more thna n
        s+=v[r]; ans++; while(s>k) {s-=v[l]; l++; ans--;}
        mx=max(mx,ans); r++;//is max subsequence is asked then we have to store tthe subarray by storing the indices r and l when max is changed
    }
    cout<<mx<<endl;
    //most optimal solution 
    //like if we find the max length to be mx ,we wouldnt shrink less than mx size even if s is more than k and look for answers that have more mx
    while(r<n){
        s+=v[r]; ans++;
        while(s>k && r-l+1>=mx) {s-=v[l]; l++; ans--;}
        mx=max(mx,ans); r++;
    } cout<<mx<<endl;
}

void number_subarray(){
    //in this we have to calculate the no of subarray with sum ==k
}