#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //vector is a dynamic memory allocation user defined data type . it is mutable like arrays but provides much more built_in function unlike arrays
    //dynamic memory means it can shrink or grow at runtime
    vector <int> v;//doing this will initialize all the 5 indexes
    v.push_back(10);
    v.push_back(24);
    v.push_back(36);
    v.push_back(45);
    v.push_back(53);
    //v.push_back(23);//when vector is initialized of size 5 and 6 elements are entered--> error std out of range
    for (int i=0;i<v.size();i++)
    cout<<v.at(i)<<" ";
    // v.pop_back();//automatically removes last element no aramenter to input
    // cout<<v.capacity();
    // v.insert(v.begin(),16);
    // v.insert(v.begin(),22);
    // v.pop_back();
    // v.erase(v.begin());//removes the element at given positions
    // sort(v.begin(),v.end());
}