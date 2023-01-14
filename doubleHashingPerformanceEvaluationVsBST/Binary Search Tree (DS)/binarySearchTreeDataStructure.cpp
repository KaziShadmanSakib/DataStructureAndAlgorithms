/* Name- Kazi Shadman Sakib */
/* Roll- 97 */
#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;


int count[10000];
int setOfKeys[10000];
int insertSeq[10000];
int searchSeq[3000];
int insertSearchSeq[10000];
int insertProbes[7000];
int searchProbes[3000];
int insertProbesCount = 0;
int searchProbesCount = 0;
int counter = 0;

void init(){
	fstream file1, file2, file3, file4;
	file1.open("../Dataset/insertionSequence.txt", ios::in);
	if(file1.is_open()){
		int i = 0, temp;
		string line;
		while(!file1.eof()){
			getline(file1, line);
			stringstream ss;
			ss<<line;
			ss>>temp;
			insertSeq[i] = temp;
			i++;
		}
		file1.close();
	}
	file2.open("../Dataset/setOfKeys.txt", ios::in);
	if(file2.is_open()){
		int i = 0, temp;
		string line;
		while(!file2.eof()){
			getline(file2, line);
			stringstream ss;
			ss<<line;
			ss>>temp;
			setOfKeys[i] = temp;
			i++;
		}
		file2.close();
	}
	file3.open("../Dataset/insertSearchSequence.txt", ios::in);
	if(file3.is_open()){
		int i = 0, temp;
		string line;
		while(!file3.eof()){
			getline(file3, line);
			stringstream ss;
			ss<<line;
			ss>>temp;
			insertSearchSeq[i] = temp;
			i++;
		}
		file3.close();
	}
	file4.open("../Dataset/searchSequence.txt", ios::in);
	if(file4.is_open()){
		int i = 0, temp;
		string line;
		while(!file4.eof()){
			getline(file4, line);
			stringstream ss;
			ss<<line;
			ss>>temp;
			searchSeq[i] = temp;
			i++;
		}
		file4.close();
	}
	else{
        cout<<"Couldn't open one or more dataset files\n";
	}
}

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
	int search(int data){
		return searchData(root,data);
	}
	int searchData(node *root,int data){
		int count = 0;
		count++;
		if(root == NULL){
			return count;
		}
		if(root->data == data){
			return count;
		}
		if(data>root->data){
			count = count + searchData(root->right,data);
		}
		else{
			count = count + searchData(root->left,data);
		}
		return count;
	}
	void insert(int data){
		root = insertData(root,data);
	}
	node *insertData(node *root,int data){
		counter++;
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
};

int main()
{
	init();
	binarySearchTree a;
	int j = 0, k = 0;
	int operations = (sizeof(insertSearchSeq)/sizeof(insertSearchSeq[0]));
	for(int i=0; i<operations;i++){
		if(insertSearchSeq[i] == 1){
			int temp1 = insertSeq[j];
			j++;
			int key = setOfKeys[temp1];
			a.insert(key);
		}
		else{
			int key = searchSeq[k];
			k++;
			int count = a.search(key);
			searchProbes[searchProbesCount] = count;
			searchProbesCount++;
		}
	}


	
	int sum = 0;
	int n = (sizeof(searchProbes)/sizeof(searchProbes[0]));
   	sum = accumulate(searchProbes, searchProbes+n, sum);
   	cout<< "Sum = " << sum+counter << endl;

   	cout<< "Max = " << *max_element(searchProbes, searchProbes + n) << endl;

   	double average = (double) (sum+counter)/ (double) operations;
   	cout<< "Average probes for Binary Search Tree per operation = " << average << endl;
	return 0;
}