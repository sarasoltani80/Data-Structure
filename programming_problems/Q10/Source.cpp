#include <iostream>
#include<map>
#include<vector>
using namespace std;


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
    void buildTree(int n);
    void findcolumn(node* _root, int d, map<int, vector<int>>& cols);
    void rahRast();
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
void binary_tree::buildTree(int n) {
    string tmp;

    root = new node();
    root->data = 0;
    root->left = NULL;
    root->right = NULL;
    root->p = NULL;

    node* x = root;
    for (int i = 0; i < n - 1; i++)
    {
        int j;
        cin >> tmp;
        for (j = 0; j < tmp.size() - 1; j++)
        {
            if (tmp[j] == 'l')
                x = x->left;
            else
                x = x->right;
        }
        buildNode(i + 1, x, tmp[j]);

        x = root;
    }
}
void binary_tree::findcolumn(node* _root, int dis, map<int, vector<int>>& cols)
{
    if (!_root)
        return;

    cols[dis].push_back(_root->data);

    findcolumn(_root->left, dis - 1, cols);

    findcolumn(_root->right, dis + 1, cols);
}
void binary_tree::rahRast()
{
    map<int, vector<int> > cols;
    findcolumn(root, 0, cols);

    int index = cols.begin()->first;
    for (int i = 0; i < cols.size(); i++, index++)
    {
        vector<int> v = cols[index];
        for (int j = 0; j < v.size(); j++)
            cout << v[j] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    if (n < 1)
    {
        cout << 0;
        return 0;
    }

    binary_tree treee;
    treee.buildTree(n);

    treee.rahRast();
    return 0;
}