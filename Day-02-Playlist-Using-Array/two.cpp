#include<iostream>
using namespace std;
class MaxProduct{
public:
int temp;
int arr[6];
int product1,product2;
void getdata(){       
        cout<<"Enter elements: "<<endl;
        for(int i=0;i<=5;i++){
            cin>>arr[i];
        }   
    }
void sort(){
    for(int i=0;i<=4;i++){
        for(int j=i+1;j<=5;j++){
            if (arr[i]>arr[j]){
             temp=arr[i];
             arr[i]=arr[j];
             arr[j]=temp;
        }
        }
    }
}
void product(){
    product1=arr[3]*arr[4]*arr[5];
    product2=arr[0]*arr[1]*arr[5];
}
void compare(){
if (product1>=product2){
        cout<<"\nMaximum: "<<product1<<endl;
     }
    else{
        cout<<"\nMaximum: "<<product2<<endl;
        }
   }
};
int main(){
    MaxProduct p;
    p.getdata();
    p.sort();
    p.product();
    p.compare();
return 0;
}
