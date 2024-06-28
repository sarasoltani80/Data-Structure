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
    void rahKaj(node* _root, int d, map<int, vector<int>>& diagonal);
    void dt();
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
void binary_tree::rahKaj(node* _root, int dis, map<int, vector<int>>& diagonals)
{
    if (!_root)
        return;

    diagonals[dis].push_back(_root->data);

    rahKaj(_root->left, dis + 1, diagonals);

    rahKaj(_root->right, dis, diagonals);
}
void binary_tree::dt()
{
    map<int, vector<int> > diagonals;
    rahKaj(root, 0, diagonals);

    for (int i = 0; i < diagonals.size(); i++)
    {
        vector<int> v = diagonals[i];
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

    treee.dt();
    return 0;
}