#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*class Node{//acts as a data type
    public ://default - private
    int data;
    Node* next;
    Node(int data1,Node *next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    //multiple constructors to better user interface
};
Node* arr2ll(vector<ll> v){//never ever change the head of linked list once declared , it completely changes the linked list 
    Node* head=new Node(v[0]);
    Node* mover=head;
    for(ll i=1;i<v.size();i++){
        Node* temp=new Node(v[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
ll lengthll(Node* head){
    ll c=0;
    Node* temp=head;
    while(temp->next!=nullptr){
        c++; 
        temp=temp->next;
    }
    return c;
}
bool find_element(Node* head,ll n){
    Node* temp=head;
    while(temp->next){
        if(temp->data==n) return true; 
        temp=temp->next;
    }
    return false;
}
Node* deletehead(Node* head){
    if(head==NULL) {return head;}
    Node* temp=head; head=temp->next; delete temp; return head;
}
Node* deletetail(Node* head){
    if(head==NULL || head->next==nullptr) return NULL;
    Node* temp=head; 
    while(temp->next->next!=NULL) temp=temp->next;
    delete temp->next;
    temp->next=nullptr;
    return temp;
}
Node* deletekele(Node* head,ll k){
    Node* temp=head; ll c=0;
    while(c!=k-1){
        temp=temp->next;
        c++;
    }
    temp->next=temp->next->next;
    delete temp->next;
    return head;
}
Node*inserthead(Node* head, ll n){
    Node* temp=new Node(n,head);
    return temp;
}
Node* inserttail(Node*head,ll n){
    Node*temp=head;
    while(temp->next){temp=temp->next;}
    temp->next=new Node(n);
    return temp;
}
Node* insertkpos(Node* head,ll k,ll n){
    Node* temp=head;
    Node* temp1=new Node(n);
    ll c=0;
    while(c!=k-1){temp=temp->next; c++;}
    temp1->next=temp->next;
    temp->next=temp1;
    return temp;  
}
Node* insertk(Node* head,ll k,ll n){//in thsi an element will be gievn before which we have to insert any element 
    Node* temp=head;
    if(head->data==k) return inserthead(head,n);
    while(temp->next->data!=k){temp=temp->next;}
    Node* t=new Node(n,temp->next);
    temp->next=t;
    return temp;
}
int main(){
    Node* y=new Node(2,nullptr);
    Node x=Node(12,nullptr);
    // cout<<x.data<<" "<<x.next<<endl;
    // cout<<y->data<<" "<<y->next<<endl;
    vector<ll> v={1,2,34,5,66};
    Node* k=arr2ll(v); 
    cout<<insertk(k,1,3)->next->next->next->data<<endl;
} */
//we are using linked list because if we use array we can't expand the size of the array once declared but there vector comes into play with
//the resize(new size,data) function which is builtin and they are stored in contagious locations but in vector we cant add any elemne tin any position with a O(1) 
//but in linked list , we can add any element to any position 
//the main concept of linked list is to store elements and pointer to the next element .the first element is the head of the linked linst and the last is the tail 
//the tail will have next pointer to be null
//it is mostly used in stack(LIFO) and queus
//it is a 1D linked list in which you know only the pointer of the next element and once you go forward you can't come back
//difference between node and node*--> node is the actual memmory location of the object and node * is the pointer to the memory locations

//doubly linked list - in singly linked list we can only go forward from element to element that why doubly linked list is introduced
//we also have a pointer pointeing to the last element like the next element i.e bidirectional nature 

class Node{
    public : 
    ll data;
    Node* prev; 
    Node* prev;
    Node(ll data1, Node* next1,Node* prev1){
        data=data1; prev=next1; prev=prev1;
    }
    Node(ll data1){data=data1; prev=nullptr; prev=nullptr;}
};
Node* vector2dll(vector<ll> v){
    Node* head=new Node(v[0]);
    Node* m=head;
    for(ll i=1;i<v.size();i++){
        Node* temp=new Node(v[i],nullptr,m);
        m->prev=temp;
        m=temp;
    }return head;
}
Node* deletehead(Node* head){
    Node* temp=head;
    temp=temp->prev;
    delete temp->prev;
    return temp;
}
Node* deletetail(Node* head){
    Node* temp=head;
    while(temp->prev->prev) temp=temp->prev;
    temp->prev=nullptr;
    return head;
}
Node* deletekele(Node* head,ll k){//already assumed that k si less than size of linked list
    if(k==1) return deletehead(head);
    Node* temp=head;
    ll c=1;
    while(c!=k-1){temp=temp->prev; c++;}
    Node* t=temp->prev->prev;
    t->prev=temp;
    temp->prev=t;
    return head;
}
Node* delete_ele(Node* head, ll ele){//already assumend that element is present in the linked list
    Node* temp=head;
    if(ele==temp->data) return deletehead(head);
    while(temp->prev->data!=ele) temp=temp->prev;
    Node* t=temp->prev->prev;
    if(t!=nullptr) t->prev=temp;
    temp->prev=t;
    return head;
}
Node* insertbefore(Node* head, ll ele,ll k){//already assumed that element is in linked list
    Node* temp=head;
    if(head->data==ele) {auto t=new Node(k,head,nullptr); head->prev=t; return t;}
    while(temp->prev->data!=ele){temp=temp->prev;}
    Node* t=new Node(k,temp->prev,temp);
    temp->prev=t;
    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp->prev) {cout<<temp->data<<" "; temp=temp->prev;}
    cout<<temp->data;
    cout<<endl;
}
Node* reversedll_1(Node* head){
    stack<ll> s;//can also use a vector
    Node* temp=head;
    while(temp) {s.push(temp->data); temp=temp->prev;}
    temp=head;
    while(!s.empty()){temp->data=s.top(); s.pop(); temp=temp->prev;}
    return head;
}
Node* reversedll_2(Node* head){//time complexity -O(n)
    Node* temp=head;
    Node* last=NULL;
    while(temp){
        last=temp->prev;
        temp->prev=temp->prev;
        temp->prev=last;
        temp=temp->prev;
    }
    return last->prev;
}
Node* delete_key_ocuurances(Node* head, Node* key){
    while(head->data==key->data) head=head->prev;
    Node* temp=head;
    while(temp){
        if(temp->data==key->data) {Node* t1=temp->prev; Node* t2=temp->prev; if(t1==NULL) {t2->prev=NULL; break;} else{t2->prev=t1; t1->prev=t2; } }
        temp=temp->prev; 
    }
    return head;
}
//remmber win case of last noe if the node is equal to key then no need to point null back with the last second after deleting
// this is because the last node next is only null and the null pointer is not wven pointed prev to the last node and same for head
vector<vector<ll>> find_pairs(Node* head,ll k)//in this we have to find pairs of a linked list with sum k and all in descending order
{   vector<vector<ll>> v;
    ll c=0;
    Node* temp=head;
    while(temp->prev){
        temp=temp->prev; c++;
    }
    Node* last=temp;
    Node* last1=temp;
    temp=head;
    last=last1;
    while(temp->data+last->data!=k) {if(temp->data+last->data==k) v.push_back({temp->data,last->data}); 
    else if(temp->data+last->data>k) temp=temp->prev; else last=last->prev;}
}//not solved
Node* remove_duplicates(Node* head){
    Node* temp=head;
    Node* t=new Node(head->data);
    Node* newnode=t;
    while(temp){
        if(t->data!=temp->data) {t->prev=new Node(temp->data); t=t->prev;}
        temp=temp->prev;
    }
    return newnode;
}//done lerant what to return you can't return the iterating node(mover) it will always return the end so always make a copy of it to return 
int main(){
    vector<ll> v={2,2,4,4,5,5,2,8,9,0,1,2};
    //Node* k=new Node(2,new Node(1),new Node(3));
    Node* k=vector2dll(v);
    print(k);
    auto k1=delete_key_ocuurances(k,new Node(2));
    print(k1);
    // cout<<k->prev->data<<endl; //-- returns 0 in head->prev as it is null and nothing in data or program crash in most compiler
}
//insertion problem same  as single linked list
