/* Name- Kazi Shadman Sakib */
/* Roll- 97 */
#include<iostream>
#include<bits/stdc++.h>
#include  <fstream>
using namespace std;

#define SIZE_OF_HASH 12005

int hashTable[SIZE_OF_HASH];
int setOfKeys[10000];
int insertSeq[10000];
int searchSeq[3000];
int insertSearchSeq[10000];
int insertProbes[7000];
int searchProbes[3000];
int insertProbesCount = 0;
int searchProbesCount = 0;

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

int h1(int key){
	return key % SIZE_OF_HASH;
}

int h2(int key){
	return 1 + (key % (SIZE_OF_HASH - 1));
}

void insertHash(int hashTable[SIZE_OF_HASH], int key){
	int i = 0;
	int hash1 = h1(key);

	if(hashTable[hash1] == 0){
		hashTable[hash1] = key;
		insertProbes[insertProbesCount] = ++i;
		insertProbesCount++;
	}
	else{
		while(i<SIZE_OF_HASH){
			int hash2 = h2(key);
			int hash = (hash1 + (i * hash2)) % SIZE_OF_HASH;
			if(hashTable[hash] != 0){
				i++;
			}
			else{
				hashTable[hash] = key;
				insertProbes[insertProbesCount] = ++i;
				insertProbesCount++;
				break;
			}
		}

	}

}

void searchHash(int hashTable[SIZE_OF_HASH], int key){
	int i = 0;
	int hash1 = h1(key);

	if(hashTable[hash1] == key){
		searchProbes[searchProbesCount] = ++i;
		searchProbesCount++; 
	}
	else if(hashTable[hash1] == 0){
		searchProbes[searchProbesCount] = ++i;
		searchProbesCount++;
	}
	else{
		while(i<SIZE_OF_HASH){
			int hash2 = h2(key);
			int hash = (hash1 + (i * hash2)) % SIZE_OF_HASH;
			if(hashTable[hash] != key){
				i++;
			}
			else if(hashTable[hash] == 0){
				searchProbes[searchProbesCount] = ++i;
				searchProbesCount++;
				break;
			}
			else{
				searchProbes[searchProbesCount] = ++i;
				searchProbesCount++;
				break;
			}
		}

	}

}

int main()
{
	init();
	int j = 0, k = 0;
	int operations = (sizeof(insertSearchSeq)/sizeof(insertSearchSeq[0]));
	for(int i=0; i<operations;i++){

		if(insertSearchSeq[i] == 1){
			int temp1 = insertSeq[j];
			j++;
			int key = setOfKeys[temp1];
			insertHash(hashTable, key); 
		}
		else{
			int key = searchSeq[k];
			k++;
			searchHash(hashTable, key);
		}
	}

	int sum1 = 0, sum2 = 0;
	int n1 = (sizeof(insertProbes)/sizeof(insertProbes[0]));
   	sum1 = accumulate(insertProbes, insertProbes+n1, sum1);

   	int n2 = (sizeof(searchProbes)/sizeof(searchProbes[0]));
   	sum2 = accumulate(searchProbes, searchProbes+n2, sum2);
   	
   	cout<< "Sum = " << (sum1+sum2) << endl;
	cout<< "Max from search probes = " << *max_element(searchProbes, searchProbes + n2) << endl;
   	cout<< "Max from insert probes = " << *max_element(insertProbes, insertProbes + n1) << endl;
   	double average = (double) (sum1+sum2)/ (double) operations;
   	cout<< "Average probes for Double Hashing per operation = " << average << endl;
	return 0;
}