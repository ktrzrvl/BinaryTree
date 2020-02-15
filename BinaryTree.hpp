#pragma once
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
	struct Node {
		T value; // значение узла
		Node *left; // указатель на левое поддерево
		Node *right; // указатель на правое поддерево
	};

	Node *root; // указатель на корень дерева
	void Insert(Node *&node, const T &value);
	void InOrder(Node *node); // вывод дерева в порядке лево-корень-право
	void Print(Node *node, int level); // вывод дерева в виде дерева
public:
	BinaryTree();
	void Insert(const T &value);
	void InOrder(); //вывод дерева начиная с корня
	void Print(); //вывод дерева начиная с корня
};

template <typename T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <typename T>
void BinaryTree<T>::Insert(Node *&node, const T &value) {
	if (node == NULL) {
		node = new Node;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
		return;
	}
	if (value >= node->value) {
		Insert(node->right, value);
	}
	else {
		Insert(node->left, value);
	}
}

template <typename T>
void BinaryTree<T>::Insert(const T &value) {
	Insert(root, value);
}

template <typename T>
void BinaryTree<T>::InOrder(Node *node) {
	if (node == NULL) {
		return;
	}
	InOrder(node->left);
	cout << node->value << "  ";
	InOrder(node->right);
}

template <typename T>
void BinaryTree<T>::InOrder() {
	InOrder(root);
	cout << endl;
}

template <typename T>
void BinaryTree<T>::Print(Node *node, int level) {
	if (node == NULL) {
		return;
	}

	Print(node->right, level + 1);
	for (int i = 0; i < level; i++) {
		cout << "    ";		
	}
	cout << node->value << endl;
	Print(node->left, level + 1);
}

template <typename T>
void BinaryTree<T>::Print() {
	Print(root, 0);
}