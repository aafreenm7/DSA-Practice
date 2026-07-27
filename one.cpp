#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string title;
    int id;
    string author;
    string status;
    Node *next;
    Node(string t,int i,string a){
        title=t;
        id=i;
        author=a;
        status="Available";
        next=NULL;
    }


};
class Books{
    private:
    Node *head;
    public:
        Books(){
        head=NULL;
    }
    void getData(string &title,int &id,string &author){
        cout<<"Enter Book title: ";
        getline(cin,title);
        cout<<"Enter Book ID: ";
        cin>>id;
        cin.ignore();
        cout<<"Enter Book author: ";
        getline(cin,author);
       
    }
    void insert_end(string &title,int &id,string &author){
        Node *nn =new Node(title,id,author);
        if (head==NULL){
            head=nn;
        cout<<title<<" successfully added as the first element!!"<<endl;
        }
        else{
            Node*temp=head;
            while (temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
        cout<<title<<" successfully added at the end!!"<<endl;
        }
       
    }
    void insert_beg(string &title,int &id,string &author){
        Node *nn =new Node(title,id,author);
        nn->next=head;
        head=nn;
        cout<<title<<" successfully added at the beginning!!"<<endl;
    }
    void insert_mid(string &title,int &id,string &author,string after_book){
        Node *nn =new Node(title,id,author);
        Node *temp=head;
        while(temp!=NULL && temp->title!=after_book){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Book not found\n";
            return;
        }
        Node *var=temp->next;
        temp->next=nn;
        nn->next=var;
        cout<<title<<" successfully added after "<<after_book<<"!!"<<endl;
    }
    void insert_pos(string &title,int &id,string &author,int pos){
        Node *nn =new Node(title,id,author);
        Node *temp=head;
        int count=0;
        while(temp!=NULL && count!=pos){
            temp=temp->next;
            count++;
        }
        if (temp==NULL){
            cout<<"Invalid Postion"<<endl;
            return;
        }
        Node *var=temp->next;
        temp->next=nn;
        nn->next=var;
        cout<<title<<" successfully added at the position "<<pos<<"!!"<<endl;
    }
    void count(){
        Node *temp=head;
        int count=0;
        while ( temp!=NULL){
            count++;
            temp=temp->next;
        }
        cout<<"COUNT= "<<count<<endl;
    }
    void delete_book(string &title){
        Node *temp=head;
        Node *prev=NULL;
        while (temp!=NULL && temp->title!=title){
            prev=temp;
            temp=temp->next;
        }
        if (temp==NULL){
            cout<<"Book record not found"<<endl;
            return;
        }
        else if (temp==head){
            head=head->next;
            cout<<title<<" successfully delted the first item!!"<<endl;
        }
        else{
            prev->next=temp->next;
        }
        delete temp;
        cout<<title<<" successfully deleted!!"<<endl;
    }
    void deletefirst(){
        if (head==NULL){
            cout<<"Catalog is EMPTY"<<endl;
            return;
        }
        Node *temp=head;
        head=head->next;
        delete temp;
        cout<<"First book deleted successfully."<<endl;
    }
    void deleteLast(){
        Node *temp=head;
        if(head==NULL){
            cout<<"Catalog is EMPTY"<<endl;
            return;
        }
        if(head->next==NULL){
            delete head;
            head=NULL;
            return;
        }
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node *last=temp->next;
        temp->next=NULL;
        delete last;
        cout<<"Last book deleted successfully."<<endl;
    }
    void search(int search_id){
        Node *temp=head;
        int pos=1;
        while (temp!=NULL && temp->id!=search_id){
            temp=temp->next;
            pos++;
        }
        if(temp==NULL){
            cout<<"Book not found"<<endl;
        }
        else{
            cout<<temp->id<<" found at position "<<pos<<endl;
            cout<<"Book found at position "<<pos<<endl;
            cout<<"Title : "<<temp->title<<endl;
            cout<<"ID    : "<<temp->id<<endl;
            cout<<"Author: "<<temp->author<<endl;
            cout<<"Status: "<<temp->status<<endl;
        }
    }
    void display(){
        Node *temp=head;
        if (head==NULL){
            cout<<"Catalog is EMPTY"<<endl;
            return;
        }
        while (temp!=NULL){
            cout<<"Title: "<<temp->title<<endl;
            cout<<"ID: "<<temp->id<<endl;
            cout<<"Author: "<<temp->author<<endl;
            cout<<"Status: "<<temp->status<<endl;
            cout<<"------------*-----------------"<<endl;
            temp=temp->next;
        }
        cout<<"---------------*******--------------"<<endl;
        cout<<"\n";
    }/*
    void reverse_new(Books &book1){
        Node *temp=head;
        while(temp!=NULL){
            book1.insert_mid(string &title,int &id,string &author,string after_book);
            temp=temp->next;
        }
    }
        */
    void reverse_noNewMem(){
        Node *prev=NULL;
        Node *curr=head;
        Node *temp=NULL;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head=prev;
        cout<<"----------REVERSED LIST: ----------"<<endl;
        //.display();
    }
};
int main(){
    Books book;
    int choice,search_id;
    string title,author,after_book;
    int id,pos;
    do{
        cout<<"\n========CATALOG BOOKS======="<<endl;
        cout<<"1. Add Book\n";
        cout<<"2. Add Book at the begining\n";
        cout<<"3. Add Book at the Middle\n";
        cout<<"4.Add Book at a postion\n";
        cout<<"5. Count Book\n";
        cout<<"6. Delete Book\n";
        cout<<"7. Delete first book\n";
        cout<<"8. Delete last book\n";
        cout<<"9.Search Book: \n";
        cout<<"10. Display \n";
        cout<<"11. Reverse and make a new list\n";
        cout<<"12. Reverse the orginal list\n";
        cout<<"13.EXIT"<<endl;
        cout<<"ENTER CHOICE: ";
        cin>>choice;
        cin.ignore();


        switch (choice){
            case 1:
            book.getData(title,id,author);
            book.insert_end(title,id,author);
            break;
            case 2:
            book.getData(title,id,author);
            book.insert_beg(title,id,author);
            break;
            case 3:
            book.getData(title,id,author);
            cout<<"Insert after which book(title): ";
            getline(cin,after_book);
            book.insert_mid(title,id,author,after_book);
            break;
            case 4:
            book.getData(title,id,author);
            cout<<"Insert after position: ";
            cin>>pos;
            book.insert_pos(title,id,author,pos);
            break;
            case 5:
            book.count();
            break;
            case 6:
            cout<<"Enter which book record would you like to delete from title: ";
            getline(cin,title);
            book.delete_book(title);
            break;
            case 7:
            book.deletefirst();
            break;
            case 8:
            book.deleteLast();
            break;
            case 9:
            cout<<"Enter which book record would you ike to search from its ID";
            cin>>search_id;
            book.search(search_id);
            break;
            case 10:
            book.display();
            break;
            case 11:
            cout<<"Reverse to make a new list";
            //book1.reverse_new();
            break;
            case 12:
            cout<<"Reverse the Original List";
            book.reverse_noNewMem();
            book.display();
            break;
           
        }


    }while (choice!=13);
    return 0;


}



