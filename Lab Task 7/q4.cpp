#include<iostream>
using namespace std;
class Product{
	public:
	string name;
	double price;
	string description;
	bool availability;
		Product(){
			name="";
			price=0.0;
			description="";
			availability=false;
		}
		Product(string n,double p,string d,bool a){
			name=n;
			price=p;
			description=d;
			availability=a;
		}
};
int partition(Product p[],int low,int high){
	int pivot=p[low].price;
	int i=low+1;
	int j=high;
	
	while(i<=j){
		while(i<=j && p[i].price<=pivot){
			i++;
		}
		while(i<=j && p[j].price>pivot){
			j--;
		}
		if(i<j){
			Product temp=p[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
	Product temp=p[low];
	p[low]=p[j];
	p[j]=temp;
	return j;
}
void quickSort(Product p[],int low,int high){
	if(low<high){
		int pi=partition(p,low,high);
		quickSort(p,low,pi-1);
		quickSort(p,pi+1,high);
			}
}
int main(){
	Product p[3]={
	Product("Product 1",10.99,"This is product 1.",true),
	Product("Product 2",5.99,"This is product 2.",false),
	Product("Product 3",2.99,"This is product 3.",true)
	};
	quickSort(p,0,2);
	cout<<"Products sorted by price:"<<endl;
	for(int i=0;i<3;i++){
	cout<<p[i].name<<" - $"<<p[i].price<<endl;
	}
}