#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
void parenthesis_string (string s);
void reverse_words();
int main(){
    //parenthesis_string("((()))");
    //parenthesis_string("()(()())(())");
    reverse_words();
} 
void parenthesis_string(string s){
    //valid parenthesis string is wwhich has ( and ) in the begin and ennd
    //primitive valid parenthesis string is  a string  in which it cannot be split into two valid string
    //((()())))-not a primitive valid 
    //now ques is to remove the outermost parenthesis of every primitive valid string
    //my appproach first stored the valid primitive parenthesis string in a vector then erased its first and final index 
    int i,j;
    // string s;
    // cin>>s;
    vector<string> c;
    j=0;
    int pos=0;
    for(i=0;i<s.size();i++) {
        if(s[i]=='(') j+=1;
        else if(s[i]==')')      j-=1;

        if(j==0)   {
            c.emplace_back(s.substr(pos,i+1));
            pos=i+1;
        }
    }
    string temp="";
    for(auto it:c){
        cout<<it<<endl;
        it.erase(it.begin());
        it.erase(it.end()-1);
        temp+=it;
    }
    cout<<temp<<endl;
}
void reverse_words(){
    string s;
    cin>>(s);
    vector<string> v;
    int pos=0;
    for(auto i=0;i<s.size();i++){
        if(s[i]==' '){
            v.push_back(s.substr(pos,i));
            pos=i+1;
        } 
    }
    for(auto i=0;i<v.size();i++){
        cout<<v[v.size()-i-1];
    }
}