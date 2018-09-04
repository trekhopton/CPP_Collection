#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

struct Node{
	Node(int v){
		value = v;
		height = 1;
		left = NULL;
		right = NULL;
	}
	int value;
	int height;
	Node* left;
	Node* right;
};

class AVLTree{
public:

	AVLTree(){
		root = NULL;
	}

	void insertVal(int v){
		root = recInsert(root, v);
	}

	void deleteVal(int v){
		root = recDelete(root, v);
	}

	void print(std::string order){

		if(root == NULL){
			std::cout << "EMPTY" << std::endl;
		} else if(order == "PRE"){
			printPre(root);
			std::cout << std::endl;
		} else if(order == "POST"){
			printPost(root);
			std::cout << std::endl;
		} else if(order == "IN"){
			printIn(root);
			std::cout << std::endl;
		}
	}

private:

	Node* root;

	void printPre(Node* n){
		if(n != NULL){
			std::cout << n->value << " ";
			printPre(n->left);
			printPre(n->right);
		}
		return;
	}

	void printPost(Node* n){
		if(n != NULL){
			printPost(n->left);
			printPost(n->right);
			std::cout << n->value << " ";
		}
		return;
	}

	void printIn(Node* n){
		if(n != NULL){
			printIn(n->left);
			std::cout << n->value << " ";
			printIn(n->right);
		}
		return;
	}

	Node* find(int v, Node* n){
		if(n == NULL){
			return NULL;
		} else if(v == n->value){
			return n;
		} else if(v < n->value){
			return find(v, n->left);
		} else if(v > n->value){
			return find(v, n->left);
		}
		return NULL;
	}

	Node* findParent(int v, Node* n, Node* p){
		if(n == NULL){
			return NULL;
		} else if(v == n->value){
			return p;
		} else if(v < n->value){
			return findParent(v, n->left, n);
		} else if(v > n->value){
			return findParent(v, n->left, n);
		}
		return NULL;
	}

	int findAndDelMin(Node* n){
		if(n->left == NULL){
			int toReturn = n->value;
			delete n;
			return toReturn;
		} else {
			return findAndDelMin(n->left);
		}
	}

	int getHeight(Node *N){
		if(N == NULL){
			return 0;
		}
		return N->height;
	}

	Node* RotR(Node *b){
		Node *a = b->left;
		Node *otherTree = a->right;
		a->right = b;
		b->left = otherTree;
		b->height = std::max(getHeight(b->left), getHeight(b->right)) + 1;
		a->height = std::max(getHeight(a->left), getHeight(a->right)) + 1;
		return a;
	}
	
	Node* RotL(Node *a){
		Node *b = a->right;
		Node *otherTree = b->left;
		b->left = a;
		a->right = otherTree;
		a->height = std::max(getHeight(a->left), getHeight(a->right)) + 1;
		b->height = std::max(getHeight(b->left), getHeight(b->right)) + 1;
		return b;
	}
	
	int balance(Node *n){
		if(n == NULL){
			return 0;
		}
		return getHeight(n->left) - getHeight(n->right);
	}

	Node* recInsert(Node* n, int value){
		if(n == NULL){
			return new Node(value);
		}
		if(value < n->value){
			n->left  = recInsert(n->left, value);
		} else if(value > n->value){
			n->right = recInsert(n->right, value);
		} else {
			return n;
		}

		n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
	 
		int bal = balance(n);
	 
		if(bal > 1 && value < n->left->value){
			return RotR(n);
		}
		if(bal < -1 && value > n->right->value){
			return RotL(n);
		}
		if(bal > 1 && value > n->left->value){
			n->left =  RotL(n->left);
			return RotR(n);
		}
	 
		if(bal < -1 && value < n->right->value){
			n->right = RotR(n->right);
			return RotL(n);
		}
	 
		return n;
	}

	Node* findMin(Node* n){
		Node* temp = n;
	 
		while (temp->left != NULL){
			temp = temp->left;
		}

		return temp;
	}

	Node* recDelete(Node* n, int value){
		if(n == NULL){
			return n;
		}

		if(value < n->value){
			n->left = recDelete(n->left, value);
		} else if(value > n->value){
			n->right = recDelete(n->right, value);
		} else {
			if((n->left == NULL) || (n->right == NULL)){
				Node *temp = n->left ? n->left : n->right;
	 
				if(temp == NULL){
					temp = n;
					n = NULL;
				} else {
					*n = *temp;
				}

				free(temp);

			} else {
				Node* temp = findMin(n->right);
	 
				n->value = temp->value;
	 
				n->right = recDelete(n->right, temp->value);
			}
		}
	 
		if(n == NULL)
		  return n;
	 
		n->height = 1 + std::max(getHeight(n->left), getHeight(n->right));
	 
		int bal = balance(n);

		if(bal > 1 && balance(n->left) >= 0){
			return RotR(n);
		}
		if(bal > 1 && balance(n->left) < 0){
			n->left = RotL(n->left);
			return RotR(n);
		}
		if(bal < -1 && balance(n->right) <= 0){
			return RotL(n);
		}
		if(bal < -1 && balance(n->right) > 0){
			n->right = RotR(n->right);
			return RotL(n);
		}
	 
		return n;
	}

};

int main(){
	
	//getline of input
	std::string inputline;
	getline(std::cin, inputline);

	//seperate line into vector of strings
	std::istringstream iss(inputline);
	std::vector<std::string> input;
	std::string temp;
	while(iss >> temp){
		input.push_back(temp);
	}
	
	std::string order = input.back();
	input.pop_back();

	AVLTree t;
	
	for(int i = 0; i < input.size(); i++)
	{
		int value = stoi(input[i].substr(1, input[i].length() - 1));
		if(input[i][0] == 'A'){
			t.insertVal(value);
		} else if(input[i][0] == 'D'){
			t.deleteVal(value);
		}
	}
	
	t.print(order);

	return 0;
}