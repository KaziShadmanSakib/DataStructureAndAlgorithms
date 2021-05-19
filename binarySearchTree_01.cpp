/* Name- Kazi Shadman Sakib */
/* Roll- 97 */
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
	node(){
	}
	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
struct binarySearchTree{
	node *root;
	binarySearchTree(){
		root = NULL;
	}
	node *search(int data){
		return searchData(root,data);
	}
	node *searchData(node *root,int data){
		if(root == NULL){
			return NULL;
		}
		if(root->data == data){
			return root;
		}
		if(data>root->data){
			return searchData(root->right,data);
		}
		else{
			return searchData(root->left,data);
		}
	}
	void insert(int data){
		root = insertData(root,data);
	}
	node *insertData(node *root,int data){
		node *cur = new node(data);
		if(root == NULL){
			root = cur;
			return root;
		}
		if(data>root->data){
			root->right = insertData(root->right,data);
		}
		else{
			root->left = insertData(root->left,data);
		}
		return root;
	}
	void remove(int data){
		root = removeData(root,data);
	}
	node *removeData(node *root,int data){
		if(root==NULL){
			return root;
		}
		if(data>root->data){
			root->right = removeData(root->right,data);
		}
		else if(data<root->data){
			root->left = removeData(root->left,data);
		}
		else{
			node *temp = root;
			if(root->right== NULL && root->left == NULL){
				root = NULL;
				delete (temp);
			}
			else if(root->right==NULL){
				root = root->left;
				delete (temp);
			}
			else if(root->left==NULL){
				root = root->right;
				delete (temp);
			}
			else{
				node *tempCopy = findMin(root);
				root->data = tempCopy->data;
				tempCopy = removeData(tempCopy,root->data);
			}
		}
		return root;
	}
	node *findMin(node *cur){
		while(1){
			if(cur->left == NULL){
				return cur;
			}
			else{
				cur = cur->left;
			}
		}
	}
	node *findMax(node *cur){
		while(1){
			if(cur->right == NULL){
				return cur;
			}
			else{
				cur = cur->right;
			}
		}
	}
	node *upperBound(int data){
		node *ans = upperBoundOfData(root,data);
		if(ans==NULL){
			return findMax(root);
		}
		else{
			return ans;
		}
	}
	node *upperBoundOfData(node *root,int data){
		if(root==NULL){
			return NULL;
		}
		if(data>=root->data){
			return upperBoundOfData(root->right,data);
		}
		else{
			node *temp = upperBoundOfData(root->left,data);
			if(temp==NULL){
				return root;
			}
			return temp;
		}
		return root;
	}
	node *lowerBound(int data){
		node *ans = lowerBoundOfData(root,data);
		if(ans==NULL){
			return findMax(root);
		}
		else{
			return ans;
		}
	}
	node *lowerBoundOfData(node *root,int data){
		if(root==NULL){
			return NULL;
		}
		if(data == root->data){
			return root;
		}
		if(data>root->data){
			return lowerBoundOfData(root->right,data);
		}
		else{
			node *temp = lowerBoundOfData(root->left,data);
			if(temp==NULL){
				return root;
			}
			return temp;
		}
		return root;
	}
	void printInorderTraversal(){
		printInorderTraversalRoot(root);
		cout<<endl;
	}
	void printInorderTraversalRoot(node *root){
		if(root==NULL){
			return;
		}
		printInorderTraversalRoot(root->left);
		cout<<root->data<<" ";
		printInorderTraversalRoot(root->right);
	}
};
int main()
{
	binarySearchTree a;
	a.insert(15);
	a.insert(36);
	a.insert(7);
	a.insert(45);
	a.insert(20);
	a.insert(9);
	a.insert(4);
	a.insert(50);
	a.insert(37);
	a.insert(10);
	a.insert(8);
	a.insert(5);
	a.insert(1);
	a.printInorderTraversal();
	a.remove(20);
	a.printInorderTraversal();
	if(a.upperBound(7)){
		printf("UpperBound is %d\n",a.upperBound(7)->data);
	}
	if(a.lowerBound(7)){
		printf("LowerBound is %d\n",a.lowerBound(7)->data);	
	}
	if(a.upperBound(100)){
		printf("UpperBound is %d\n",a.upperBound(100)->data);
	}
	if(a.lowerBound(123)){
		printf("LowerBound is %d\n",a.lowerBound(123)->data);
	}
	return 0;
}