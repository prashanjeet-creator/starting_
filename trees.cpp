#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef map<ll,ll> m;
typedef vector<pair<ll, ll>> vpll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define in(n) ll n;  cin >> n
#define inn(n, k) ll n, k;   cin >> n >> k
#define inv(v, a, b)  for (ll i = a; i < b; i++) cin >> v[i]
#define f(i, l, r) for (ll i = l; i < r; i++)
#define rf(i, l, r) for (ll i = l; i >= r; i--)
#define outa(arr, a, b) for (ll i = a; i < b; i++) cout <<arr[i]<<' '
#define out(n) cout << n << endl
#define yes cout <<YES<< endl
#define no cout <<NO<< endl
class tree{
    public:
    ll data;
    tree* left; 
    tree* right; 
    tree(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
void preorder(tree* node){
    if(node==nullptr) return;
    out(node->data);
    preorder(node->left);
    preorder(node->right);
}
void inorder(tree* node){
    if(node==nullptr) return;
    inorder(node->left);
    out(node->data);
    inorder(node->right);
}
void postorder(tree* node){
    if(node==nullptr) return ;
    postorder(node->left);
    postorder(node->right);
    out(node->data);
}
vvi bfs(tree* node){
    //also known as level order traversal only in trees nut in graphs it is called bfs
    //in this we have to traverse every level from left to right 
    vvi v;
    deque<tree*> s;
    s.push_front(node);
    while(!s.empty()){
        int size=s.size();
        vector<ll> v1;
        for(int i=0;i<size;i++){
            tree* l=s.back();
            s.pop_back();
            v1.push_back(l->data);
            if(l->left) s.push_front(l->left);
            if(l->right) s.push_front(l->right);
        }
        v.push_back(v1);
    } 
    return v;
}
vi preorder_i(tree* node){
    if(node==NULL) return {};
    vi v;
    stack<tree*> x;
    x.push(node);
    while(!x.empty()){
        tree* n=x.top();
        x.pop();
        v.push_back(n->data);
        if(n->right) x.push(n->right);
        if(n->left) x.push(n->left);
    }
    return v;
}
vi inorder_i(tree* node){
    if(node==NULL) return {};
    vi v;
    stack<tree*> x;
    //x.push(node);
    while(true){
        if(node) {x.push(node); node=node->left;}
        else{
            if(x.empty()) break;
            node=x.top();
            x.pop();
            v.push_back(node->data);
            node=node->right;
        }
    }
    return v;
}
vi postorder_i(tree* node){
    if(node==nullptr) return {};
    stack<tree*> x1,x2;
    x1.push(node);
    while(!x1.empty()){
        node=x1.top();
        x1.pop();
        if(node->left) x1.push(node->left);
        if(node->right) x1.push(node->right);
        x2.push(node);
    }
    vi v;
    while(!x2.empty()){
        v.push_back(x2.top()->data);
        x2.pop();
    }
    return v;
}
class Solution {
public:
    // Function to get the Preorder, Inorder and Postorder traversal Of Binary Tree in One traversal
    vector<vector<int>> preInPostTraversal(tree* root) {
        // Vectors to store traversals
        vector<int> pre, in, post;

        // If the tree is empty, return empty traversals
        if (root == NULL) {
            return {};
        }
        // Stack to maintain nodes and their traversal state
        stack<pair<tree*, ll>> st;

        // Start with the root node and state 1 (preorder)
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            // this is part of pre
            if (it.second == 1) {
                // Store the node's data
                // in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2
                // (inorder) for this node
                it.second = 2;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push left child onto
                // the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data
                // in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3
                // (postorder) for this node
                it.second = 3;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push right child onto
                // the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else {
                // Store the node's data
                // in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};
int main(){
    fastio;
    tree* root=new tree(1);
    root->left=new tree(2);
    root->right=new tree(3);
    root->left->right=new tree(5);
    root->left->left=new tree(7);
    root->right->left=new tree(99);
    root->right->right=new tree(949);
    root->right->right->right= new tree(1000);
    // out("preorder");
    // preorder(root);
    // out("");
    // out("inorder");
    // inorder(root);
    // out("");
    // out("Postorder");
    // postorder(root);
    // out("");
    Solution a;
    auto k=a.preInPostTraversal(root);
    for(auto i:k){ for(auto j:i) cout<<j<<" "; out("");}
    //time complexity of all these is O(n)
return 0;
}

//binary trees is an hierarchial data structure in which every node can have maximum two nodes or children 
//every fundamental unit of a tree is node and every connecting unit is called edge and starting node is called the root of the binary tree and its parts are called children 
//leaf node is the last node of the binary tree
//depth -- the no of edges from root down a specific node 
//height -- the no of edges on the longest path from the root to the leaf node
//types of binary tree 

//full bt -- every node will either have 0 or 2 children
//complete bt -- all levels are completely filled except the last level and if the last level is not filled , it has all nodes left as possible
//perfect  bt -- all leaf node must be in same level (it is like full binary tree when every node has 2 children)
//degenrate trees -- it is the same as skew trees (same as linked list 1D data)

//for any operation to perform must learn traversal of the tree (bfs /dfs)
//DEPTH FIRST SEARCH
// inorder traversal   -- left root right (first go to the extreme left subtree and then write the order mentioned then come out then root then next right )
// preorder traversal  -- root left right (first the root then left subtree root then left subtree elements and then right)
// postorder traversal -- left right root (first go to extreme left and then right and then root)
//BREADTH FIRST SEARCH
//in this the traversal goes one by one in level
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
       stack<TreeNode*> s;
       s.push(root); 
       int c=0;
       while(!s.empty()){
        root=s.top(); s.pop();
        if(root->right) {s.push(root->right); c++;}
        if(root->left) {s.push(root->left); c++;}
        if(c==1) break;
        else c=0;
       }
       if(c) return false;
       else return true;
    }
};//code for complete binary tree;
