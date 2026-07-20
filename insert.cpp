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
cout << data << " successfully added!!" << endl;

}
void insert_beg(node *&head,int data){
    node *nn=new node;
    
    nn->data=data;
    nn->next=head;
    head=nn;
    cout << data << " successfully added at the begining!!" << endl;

}
void insert_mid(node*&head,int data,int val){
    node *nn=new node;
    nn->data=data;
    nn->next=NULL;
    node*temp=head;
    while (temp != NULL && temp->data != val){
        temp = temp->next;
    }
    if (temp != NULL) {
        node *aad = temp->next; 
        temp->next = nn;        
        nn->next = aad;         
        }
    cout << data << " successfully added!!" << endl;
    }
void display(node *head){
    node *temp = head;
    cout<<"\n";
    cout<<"LINKEDLIST:";
    while(temp!=NULL){
        cout<<temp->data<<" ";

        temp=temp->next;
    }
    cout<<"\n"<<endl;;
}
void delete_val(node *&head,int val){
    node *temp = head;
    node *prev=NULL;
    while (temp != NULL && temp->data != val){
        prev=temp;
        temp = temp->next;
}
    if (temp!=NULL){
        prev->next=temp->next;
        delete temp;
    }
    cout << val << " successfully deleted!!" << endl;

    }

int main(){

    node *head = NULL;
    insert(head,67);
    insert(head,200);
    display(head);
    insert_beg(head,100);
    display(head);
    insert(head,700);
    insert_mid(head,550,67);
    display(head);
    delete_val(head,200);
    display(head);
return 0;
}
