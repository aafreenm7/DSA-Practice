#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
};
void insert(node *&head,int data){
    node *nn=new node;
       
    nn->data=data;
    nn->next=NULL;
    if (head==NULL){
        head=nn;
    }
    else{
        node*temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            
        }
        temp->next=nn;
    }    
}
int main(){
int sum=0;
    node *head = NULL;
    insert(head,67);
    insert(head,100);
    insert(head,700);
    insert(head,200);
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
