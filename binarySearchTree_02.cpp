#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *leftChild;
	node *rightChild;
	node(){}
	
	node(int data){
		this->data = data;
		leftChild = NULL;
		rightChild = NULL;
	}
};

struct binarySearchTree{
	node *root;
	binarySearchTree(){
		root = NULL;
	}
	
	void insert(int data){
		root = insertData(root, data);
	}
	/*inserts the number X in the list*/
	node *insertData(node *root, int data){
		node *cur = new node(data);
		if(root == NULL){
			root = cur;
			return root;
		}
		if(data > root->data){
			root->rightChild = insertData(root->rightChild, data);
		}
		else{
			root->leftChild = insertData(root->leftChild, data);
		}
		return root;
	}
	
	int greaterThan(int data, int cnt){
		cnt = greaterThanFromRoot(root, data, cnt);
		return cnt;
	}
	/*Finds how many numbers greater than X are on the list L*/
	int greaterThanFromRoot(node *root, int data, int cnt){
		if(root == NULL){
			return cnt;
		}
		else if(root->data > data){
			cnt++;
		}
		cnt = greaterThanFromRoot(root->leftChild, data, cnt);
		cnt = greaterThanFromRoot(root->rightChild, data, cnt);
		return cnt;
	}
	
	int LessThanOrEquals(int data, int cnt){
		cnt = LessThanOrEqualsFromRoot(root, data, cnt);
		return cnt;
	}
	/*Finds how many numbers less than or equal to X are on the list L*/
	int LessThanOrEqualsFromRoot(node *root, int data, int cnt){
		if(root == NULL){
			return cnt;
		}
		else if(root->data <= data){
			cnt++;
		}
		cnt = LessThanOrEqualsFromRoot(root->leftChild, data, cnt);
		cnt = LessThanOrEqualsFromRoot(root->rightChild, data, cnt);
		return cnt;
	}
};

int main()
{
	binarySearchTree bst;
	int n, query;
	cin>> n >> query;
	for(int i=0;i<n;i++){
		int data;
		cin>> data;
		bst.insert(data);
	}
	for(int i=0;i<query;i++){
		string op;
		int x;
		cin>> op >> x;
		if(op == "I"){
			bst.insert(x);
		}
		else if(op == "U"){
			int cnt = 0;
			int total = bst.greaterThan(x, cnt);
			cout << total << endl;
		}
		else if(op == "L"){
			int cnt = 0;
			int total = bst.LessThanOrEquals(x, cnt);
			cout << total << endl;
		}
	}
	return 0;
}
/*Thank you*/

