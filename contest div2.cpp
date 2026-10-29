#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    int c,i,j,n,t;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        string s="";
        cin>>s;
        if(n<=2){
            int t=(1>=count(s.begin(),s.end(),'1'))?1:count(s.begin(),s.end(),'1');
            cout<<t<<endl;
        }
        else {
        for(j=1;j<n-1;j++){
            if(s[j-1]=='0' && s[j+1]=='0' && s[j]=='0') s[j]='1'; 
        }
        c=count(s.begin(),s.end(),'1');
        cout<<c<<endl;
    }
} }

// #include <iostream>
// #include<vector>
// #include<string>
// #include <algorithm>
// using namespace std;
// int main(){
//     int i,j,t,n;
//     cin>>t;
//     for(i=0;i<t;i++){
//         cin>>n;
//         vector<long long > v(n);
//         vector<long long> temp(n);
//         for(j=0;j<n;j++){
//             cin>>v[j];
//         }
//         temp=v;
//         sort(temp.begin(),temp.end());
//         if(temp==v) cout<<-1<<endl;
//         else {
//         int dif=0,mx=0;
//         for(j=0;j<n;j++){
//             dif=abs(v[j]-temp[j]);
//             if(dif>mx)  mx=dif;
//         }
//         cout<<mx<<endl;}
//     }
// } 

#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int main(){
    int i,j,t;
    unsigned long long x,y;
    cin>>t;
    for(i=0;i<t;i++){
        cin>>x>>y;
    unsigned long long p,q;
    if(x&1) {
      p=x-1; q=y;
    }
    else {
      p=x;  
      q=y;
    }
    cout<<p<<" "<<q<<endl;
} }