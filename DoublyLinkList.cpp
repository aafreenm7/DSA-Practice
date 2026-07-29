#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value ){
        data=value;
        next=NULL;
        prev=NULL;
    }
};
class DoubleLinkList{
private:
    Node *head;
public:
    DoubleLinkList(){
        head=NULL;
    }
    void insert(int data){
        Node *nn=new Node(data);
        if(head==NULL){
            head=nn;
            cout<<"Successfully inserted "<<data<<" as first node: "<<endl;
        }
        else{
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }            
            temp->next=nn;
            nn->prev=temp;
            cout<<"Successfully inserted "<<data<<" last node: "<<endl;
        }
    }
    void delete_val(int value){
        Node *temp=head;
        while(temp!=NULL && temp->data!=value){
            temp=temp->next;
        }
        if (temp==head){
            head=head->next;
            if (head!=NULL){
                head->prev=NULL;
                cout<<"Successfully deleted first node: "<<value<<"!!"<<endl;
            }
            delete temp;
        }
        else if (temp->next==NULL){
            temp->prev->next=NULL;
            cout<<"Successfully deleted last node: "<<value<<"!!"<<endl;
            delete temp;
        }
        else {
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            cout<<"Successfully deleted middle node: "<<value<<"!!"<<endl;	
            delete temp;
        }
    }
    void display(){
        Node *temp=head;
        cout<<"------------------------------DOUBLY-LINKEDLIST------------------------------"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;       
    }
    void reverse(){
        Node *temp=NULL;
        Node *curr=head;
        while(curr!=NULL){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        if (temp!=NULL){
            head=temp->prev;
        }
        cout<<"REVERSED SUCCESSFULLY"<<endl;
        
        
    }
};
int main (){
    DoubleLinkList d;
    d.insert(10);
    d.insert (20);
    d.insert (30);
    d.insert (40);
    d.insert (50);
    d.display();   
    d.reverse();
    d.display(); 
    d.delete_val(10);
    d.delete_val(30);
    d.delete_val(50);
    d.display();
    d.reverse();
    d.display();
    
    return 0;	
    
}
