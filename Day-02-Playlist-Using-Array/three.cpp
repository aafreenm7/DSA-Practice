#include<iostream>
using namespace std;
class MaxProduct{
public:
int temp,max,p1,p2;
int arr[6];
void getdata(){       
        cout<<"Enter elements: "<<endl;
        for(int i=0;i<=5;i++){
            cin>>arr[i];
        }   
    }
void cal(){
    max=arr[0]*arr[1];
    for(int i=0;i<5;i++){
            temp=arr[i]*arr[i+1];
        if(max<temp){
            max=temp;
            p1=arr[i];
            p2=arr[i+1];
        }
   }
   }
void display(){
    cout<<"Max Product: "<<max<<endl;
    cout<<"Numbers who's maximum product we get: "<<p1<<" and "<<p2<<endl; 
}
};
int main(){
    MaxProduct p;
    p.getdata();
    p.cal();
    p.display();
}
