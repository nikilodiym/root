#include <iostream>
#include <string>

using namespace std;

struct Node {
	string word;
	string translation;
	int count;	
	Node* left;
	Node* right;
	Node(string word, string translation) {
		this->word = word;
		this->translation = translation;
		this->count = 1;
		this->left = NULL;
		this->right = NULL;
	};
};

class BST {
private:
	Node* root;
	Node* addWord(Node* root, string word, string translation) {
		if (root == NULL) {
			return new Node(word, translation);
		}
		if (root->word == word) {
			root->count++;
		}
		else if (root->word > word) {
			root->left = addWord(root->left, word, translation);
		}
		else {
			root->right = addWord(root->right, word, translation);
		}
		return root;
	}
	void searchWord(Node* root, string word) {
		if (root == NULL) {
			cout << "Word not found" << endl;
			return;
		}
		if (root->word == word) {
			cout << "Word: " << root->word << endl;
			cout << "Translation: " << root->translation << endl;
			cout << "Count: " << root->count << endl;
			return;
		}
		if (root->word > word) {
			searchWord(root->left, word);
		}
		else {
			searchWord(root->right, word);
		}
	}
	void deleteWord(Node* root, string word) {
		if (root == NULL) {
			cout << "Word not found" << endl;
			return;
		}
		if (root->word == word) {
			if (root->count > 1);
		}
	}
public:
	BST() {
		root = NULL;
	}
	void addWord(string word, string translation) {
		root = addWord(root, word, translation);
	}
	void searchWord(string word) {
		searchWord(root, word);
	}
	void deleteWord(string word) {
		deleteWord(root, word);
	}
};

int main() {
	BST bst;

	bst.addWord("apple", "manzana");
	bst.addWord("banana", "platano");

	bst.searchWord("apple");
	bst.searchWord("banana");

	bst.deleteWord("apple");
	bst.deleteWord("banana");

	system("pause");
	return 0;
}