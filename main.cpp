#include <iostream>
#include <string>
#include "BinaryTree.hpp"

using namespace std;

int main() {
	BinaryTree<int> tree;
	while (true) {
		string cmd;
		cout << '>';
		cin >> cmd;
		
		if (cmd == "quit") {
			break;
		}

		if (cmd == "inorder") {
			tree.InOrder();
		}
		else if (cmd == "print") {
			tree.Print();
		}
		else if (cmd == "insert") {
			int value;
			cin >> value;
			tree.Insert(value);
		}
		else {
			cout << "?" << endl;
		}
	}
}