#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *root; 
int maxElement = -9999;

void insertTree(Node **aNode, int data){
	if (!(*aNode)){		// add new element
		(*aNode) = new Node;
		(*aNode)->value = data;
		(*aNode)->left = NULL;
		(*aNode)->right = NULL;
	}
	else{
	if (data < (*aNode)->value) insertTree(&(*aNode)->left,data);
	else insertTree(&(*aNode)->right, data);
	}
	return;
}

void printTree(Node *aNode){ // display tree
	if (aNode){
		printTree(aNode->left);
		cout<<aNode->value<<"  ";
		printTree(aNode->right);
	}
	return;
}

void findMaxElement(Node *aNode){
	if (aNode){
		if (aNode->value > maxElement)
			maxElement = aNode->value;
		findMaxElement(aNode->left);
		findMaxElement(aNode->right);
	}
	return;
}

void main(){
	srand(time(NULL));
	setlocale(LC_CTYPE,"rus");
	for(int i = 0;i < 10;i++){
		insertTree(&root,rand() % 50 - 25);
	}
	cout << Elements of tree: " << endl;
	printTree(root);
	findMaxElement(root);
	cout << endl << endl << "Maximal element of tree = " << maxElement << endl;
	cout << endl;
	system("pause");
}
