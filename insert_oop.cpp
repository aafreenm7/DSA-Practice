#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class LinkList{
    private:
    Node *head;
    public:
    LinkList(){
        head=NULL;
    }
    void insert(int data){
            Node *nn=new Node(data);
            if (head == NULL) {
            head = nn;
        }
        else{
            Node*temp=temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }    
cout << data << " successfully added!!" << endl;

}
void insert_beg(int data){
    Node *nn=new Node(data);
    
    nn->next=head;
    head=nn;
    cout << data << " successfully added at the begining!!" << endl;

}
void insert_mid(int data,int val){
    Node *nn=new Node(data);
    Node *temp=head;
    while (temp != NULL && temp->data != val){
        temp = temp->next;
    }
    if (temp != NULL) {
        Node *aad = temp->next; 
        temp->next = nn;        
        nn->next = aad;         
        }
    cout << data << " successfully added!!" << endl;
    }
void display(){
    Node *temp = head;
    cout<<"\nLINKEDLIST:";
    while(temp!=NULL){
        cout<<temp->data<<" ";

        temp=temp->next;
    }
    cout<<"\n"<<endl;;
}
void delete_val(int val){
    Node *temp = head;
    Node *prev=NULL;
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

};

int main(){

    LinkList list;
    list.insert(67);
    list.insert(200);
    list.display();

    list.insert_beg(100);
    list.display();

    list.insert(700);

    list.insert_mid(550, 67);
    list.display();

    list.delete_val(200);
    list.display();

return 0;
}
