#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
};
void insert(node *&head,int val){
    cout<<"Enter n:";
    cin>>n;
    node *head =NULL;
    node *nn=new node;
    nn->data=val;
    nn->next=head;
    head=nn;
    node*temp=head;
    for(int i=0;i<n;i++){
        cout<<"Enter "(i+1)<<"node"<<endl;
        node*nn=new node;
        cin>>nn->data=data;
        nn->next=temp;
    }
    for temp=temp->next;
    
}
int main(){
int sum=0;
    node *head = NULL;
    insert(head,67);
    insert(head,100);
    node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        sum+=temp->data;
        temp=temp->next;
    }
    cout<<"\n";
    cout<<"Sum= "<<sum<<endl;
    cout<<"\n";
return 0;
}
