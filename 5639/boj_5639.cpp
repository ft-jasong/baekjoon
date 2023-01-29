#include <iostream>

using namespace std;

class Node
{
private:
	int	_key;
	Node* _left_child;
	Node* _right_child;
	Node* _parent;
public:
	Node() : _key(-1), _left_child(NULL), _right_child(NULL), _parent(NULL) {}
	Node(int key) : _key(key), _left_child(NULL), _right_child(NULL), _parent(NULL) {}
	Node(const Node& node)
	{
		*this = node;
	}
	Node& operator=(const Node& node)
	{
		if (this == &node)
			return *this;
		_key = node._key;
		return *this;
	}
	int key(void)
	{
		return _key;
	}
	Node* left(void)
	{
		return _left_child;
	}
	Node* right(void)
	{
		return _right_child;
	}
	Node* parent(void)
	{
		return _parent;
	}
	void setLeftchild(Node *nodePtr)
	{
		_left_child = nodePtr;
	}
	void setRightchild(Node *nodePtr)
	{
		_right_child = nodePtr;
	}
	void setParent(Node *nodePtr)
	{
		_parent = nodePtr;
	}
	virtual ~Node() {}
};

class BinaryTree
{
private:
	Node *_root;
public:
	BinaryTree() : _root(NULL) {}
	~BinaryTree()
	{
		clear(_root);
	}
	void clear(Node* nodePtr)
	{
		if (!nodePtr)
			return ;
		clear(nodePtr->left());
		clear(nodePtr->right());
		delete nodePtr;
	}
	void	insert(Node* root, int key)
	{
		if (root->key() > key)
		{
			if (!root->left())
			{
				Node* node = new Node(key);
				node->setParent(root);
				root->setLeftchild(node);
			}
			else
				insert(root->left(), key);
		}
		else
		{
			if (!root->right())
			{
				Node* node = new Node(key);
				node->setParent(root);
				root->setRightchild(node);
			}
			else
				insert(root->right(), key);
		}
	}
	void makeTree()
	{
		int input;
		cin >> input;
		_root = new Node(input);
		Node* current = _root;
		while (true)
		{
			cin >> input;
			if (cin.fail())
				break ;
			insert(_root, input);
		}
		if (cin.eof())
			return ;
	}
	void postorderTraversal(Node* root)
	{
		if (!root)
			return ;
		postorderTraversal(root->left());
		postorderTraversal(root->right());
		cout << root->key() << '\n';
	}
	void postorderTraversal()
	{
		postorderTraversal(_root);
	}
};

int	main(void)
{
	BinaryTree btree;

	btree.makeTree();
	btree.postorderTraversal();
	return (0);
}
