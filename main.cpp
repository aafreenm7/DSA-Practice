//create a class mobile having brand model and price
//write a functionm to access  mobile detaills
//display the detaills
//apply 10 % discount
//display the detaills

#include<iostream>
#include<string>
using namespace std;
class mobile{
public:
	int model,price;
    float new_price;
	string brand;
	void getdata(){
    	cout<<"Brand: ";
    	cin>>brand;
    	cout<<"Model: ";
    	cin>>model;
    	cout<<"Price: ";
    	cin>>price;
	}
	void discount(){
	new_price=price-(0.10*price);	 
	}
	void display(){
	cout<<"\nBrand:"<<brand<<endl<<"Model:"<<model<<endl<<"Price:"<<price<<endl<<"New Price:"<<new_price<<endl;
	}
    void compare(mobile m[],int n){
        int max=0,min=0;
        for(int i=1;i<n;i++){
            if(m[i].new_price>m[max].new_price){
                max=i;
            }
            if(m[i].new_price<m[max].new_price){
                min=i;
            }
        }
        cout<<"\nMobile with MAXIMUM discounted price: ";
        m[max].display();
        cout<<"\nMobile with MINIMUM discounted price: ";
        m[min].display();
    }
};
int main(){
    int entries;
	cout<<"Enter entries: ";
	cin>>entries;
	mobile m[entries];
	for (int i=0;i<entries;i++){
	m[i].getdata();
	}
	cout << "\n----- Mobile Details After Discount -----\n";

    for(int i = 0; i < entries; i++)
    {
        m[i].discount();
        m[i].display();
    }
    m[0].compare(m,entries);
	return 0;
    
}
