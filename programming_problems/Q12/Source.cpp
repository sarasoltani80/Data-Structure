#include <iostream>
#include<vector>
using namespace std;

vector<int>::iterator search(int key, vector<int>& v) {
    vector<int>::iterator it = v.begin();
    for (; it != v.end(); it++)
    {
        if (*it == key)
            return it;
    }
    return it;
}
class node {
    int data;
    node* left, * right, * p;
    friend class binary_tree;
};

class binary_tree {
    node* root;
public:
    binary_tree();
    void buildNode(int _data, node* parent, char pos);
    void buildTree(vector<int>& in, vector<int>& post);
    node* buildTree2(vector<int>& in, vector<int>& post);
    void preOrder(node* _root, int val);
};

binary_tree::binary_tree() {
    root = NULL;
}
void binary_tree::buildNode(int _data, node* parent, char pos) {
    node* tmp = new node();
    tmp->data = _data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->p = parent;
    if (pos == 'l')
        parent->left = tmp;
    else
        parent->right = tmp;
}
void binary_tree::buildTree(vector<int>& in, vector<int>& post) {
    int rootKey = post.back();
    root = new node();
    root->data = rootKey;
    root->left = root->right = root->p = NULL;

    vector<int>::iterator root_pos = search(rootKey, in);
    vector<int> lc_in(in.begin(), root_pos);
    vector<int>::iterator endLeft = post.begin();
    for (int i = 0; i < lc_in.size(); i++)
        endLeft++;
    vector<int> lc_post(post.begin(), endLeft);

    node* leftChild = buildTree2(lc_in, lc_post);
    root->left = leftChild;

    vector<int> rc_in(++root_pos, in.end());
    vector<int> rc_post(endLeft, --post.end());

    node* rightChild = buildTree2(rc_in, rc_post);
    root->right = rightChild;
}
node* binary_tree::buildTree2(vector<int>& in, vector<int>& post) {
    if (post.empty())
        return NULL;
    int rootKey = post.back();
    node* _root = new node();
    _root->data = rootKey;
    _root->left = _root->right = _root->p = NULL;

    if (post.size() == 1)
        return _root;

    vector<int>::iterator root_pos = search(rootKey, in);
    vector<int> lc_in(in.begin(), root_pos);
    vector<int>::iterator endLeft = post.begin();
    for (int i = 0; i < lc_in.size(); i++)
        endLeft++;
    vector<int> lc_post(post.begin(), endLeft);

    node* leftChild = buildTree2(lc_in, lc_post);
    _root->left = leftChild;

    vector<int> rc_in(++root_pos, in.end());
    vector<int> rc_post(endLeft, --post.end());
    node* rightChild = buildTree2(rc_in, rc_post);
    _root->right = rightChild;

    return _root;

}
void binary_tree::preOrder(node* _root, int val = 0)
{
    if (val == 1)
        _root = root;

    if (_root == NULL)
        return;

    cout << _root->data << " ";
    preOrder(_root->left);
    preOrder(_root->right);
}

int main() {
    int n;
    cin >> n;
    if (n < 1)
    {
        cout << 0;
        return 0;
    }
    vector<int> in;
    vector<int> post;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        in.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        post.push_back(tmp);
    }
    binary_tree treee;
    treee.buildTree(in, post);

    treee.preOrder(NULL, 1);
    return 0;
}