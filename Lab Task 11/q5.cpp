#include<iostream>
using namespace std;
const int table_size=15;
class StudentHashTable{
	int rollNumber[table_size];
	string name[table_size];
	bool occupied[table_size];
	public:
		StudentHashTable(){
			for(int i=0;i<15;i++){
				rollNumber[i]=0;
				name[i]="";
				occupied[i]=false;
			}
		}
		int hashFunction(int key){
			return key % table_size;
		}
		void insert(int rn,string n){
			int index=hashFunction(rn);
			int i=1;
			while(occupied[index]){
				index=(index+(i*i)%table_size);
			i++;
			if(index>table_size){
				cout<<"Table Full!"<<endl;
			}
			}
			rollNumber[index]=rn;
			name[index]=n;
			occupied[true];
		}
};
