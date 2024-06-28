#include<iostream>
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
	void buildTree(int n, int);
	void Add(int _data, string s);
	node* tafsir(string s);
	node* search(node* root, int key);
	void transplant(node* u, node* v);
	void tree_delete(node* z);
	node* tree_minimum(node* root);
	void tree_delete1(string s);
	void tree_delete2(int key);
	void print();
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
void binary_tree::buildTree(int n, int root_w) {
	string tmp;
	int tmp2;
	root = new node();
	root->data = root_w;
	root->left = NULL;
	root->right = NULL;
	root->p = NULL;

	node* x = root;
	for (int i = 0; i < n - 1; i++)
	{
		int j;
		cin >> tmp >> tmp2;
		for (j = 0; j < tmp.size() - 1; j++)
		{
			if (tmp[j] == 'l')
				x = x->left;
			else
				x = x->right;
		}
		buildNode(tmp2, x, tmp[j]);
		x = root;
	}
}
void binary_tree::Add(int _data, string s)
{
	int j;
	node* x = root;
	for (j = 0; j < s.size() - 1; j++)
	{
		if (s[j] == 'l')
			x = x->left;
		else
			x = x->right;
	}
	buildNode(_data, x, s[j]);
}
node* binary_tree::tafsir(string s)
{
	int j;
	node* r = root;
	for (j = 0; j < s.size(); j++)
	{
		if (s[j] == 'l')
			r = r->left;
		else
			r = r->right;
	}
	return r;
}
node* binary_tree::search(node* root, int key)
{
	if (root == NULL || key == root->data)
		return root;
	if (key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
	/*if (root == NULL)
		return NULL;
	if (root -> data == key)
		return root;

	root = search(root->left, key);

	if (root->data == key)
		return root;

	root = search(root->right, key);
	return root;*/
}
void binary_tree::transplant(node* u, node* v)
{
	if (u->p == NULL)
		root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	if (v != NULL)
		v->p = u->p;
}
void binary_tree::tree_delete(node* z)
{
	node* y = new node();
	if (z->left == NULL)
		transplant(z, z->right);

	else if (z->right == NULL)
		transplant(z, z->left);
	else
	{
		y = tree_minimum(z->right);
		if (y->p != z)
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->p = y;
	}
}
void binary_tree::tree_delete1(string s)
{
	node* tmp;
	tmp = tafsir(s);
	tree_delete(tmp);
}
void binary_tree::tree_delete2(int key)
{
	node* tmp;
	tmp = search(root, key);
	tree_delete(tmp);
}
node* binary_tree::tree_minimum(node* root)
{
	while (root->left != NULL)
		root = root->left;
	return root;
}

void binary_tree::print()
{
	node* tmp;
	node* r;
	tmp = tafsir("rr");
	int n = tmp->data;
	cout << n;
	tree_delete2(3);
	Add(30, "rrl");
	r = tafsir("l");
	cout << r->data;
}
int main()
{
	int n, w_root;
	cin >> n >> w_root;
	binary_tree treee;
	treee.buildTree(n, w_root);
	treee.print();
}
