#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

class node{
    int data;
    node *left, *right, *p;
    friend class binary_tree;
};

class binary_tree{
    node* root;
public:
    binary_tree();
    void buildNode(int _data, node* parent,char pos);
    void buildTree(int n, int);
    int MPS();
    int MaxSum(node* root, int &max);
};

binary_tree::binary_tree(){
    root = NULL;
}
void binary_tree::buildNode(int _data, node* parent, char pos){
    node *tmp = new node();
    tmp->data = _data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->p = parent;
    if(pos == 'l')
        parent->left = tmp;
    else 
        parent->right = tmp;
}
void binary_tree::buildTree(int n, int root_w){
    string tmp;
    int tmp2;
    root = new node();
    root->data = root_w;
    root->left = NULL;
    root->right = NULL;
    root->p = NULL;

    node * x = root;
    for (int i = 0; i < n-1; i++)
    {
        int j;
        cin >> tmp >> tmp2;
        for(j=0 ; j < tmp.size()-1; j++)
        {
            if(tmp[j] == 'l')
                x = x->left;
            else 
                x=x->right;
        }
        buildNode(tmp2,x,tmp[j]);
        x = root;
    }
}
int binary_tree::MPS(){
    int max = INT_MIN; 
  
    MaxSum(root, max); 
    return max; 
}
int binary_tree::MaxSum(node* root, int &maxx) 
{
    if (root == NULL) 
        return 0; 

    int l = MaxSum(root->left,maxx); 
    int r = MaxSum(root->right,maxx); 

    int maxS = max(max(l, r) + root->data, root->data); 
    int maxT = max(maxS, l + r + root->data); 
    maxx = max(maxx, maxT);
    return maxS; 
} 

int main(){
    int n, w_root;
    cin >> n >> w_root;
    binary_tree treee;
    treee.buildTree(n,w_root);
    cout << treee.MPS();
    return 0;
}