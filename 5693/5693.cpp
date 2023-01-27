#include <iostream>

typedef struct s_node
{
	int				_data;
	struct s_node	*left_child;
	struct s_node	*right_child;
}Node;

void	makeSearchTree(Node *root)
{
	int		data;
	Node	*new_node = new Node;

	std::cin >> data;
	new_node->_data = data;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	if (root->_data > data)
	{
		if (root->left_child == NULL)
			root->left_child = new_node;
		else
			makeSearchTree(root->left_child);
	}
	else
	{
		if (root->right_child == NULL)
			root->right_child = new_node;
		else
			makeSearchTree(root->right_child);
	}
}

int	main(void)
{
	int		data;
	Node	*root = new Node;

	std::cin >> data;
	root->_data = data;
	root->left_child = NULL;
	root->right_child = NULL;
}