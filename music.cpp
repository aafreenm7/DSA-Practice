#include<iostream>
using namespace std;
class Node {
    public:
    string song_name;
    string artist;
    float duration;
    Node *next;
    Node(string s,string a,float d){
        song_name=s;
        artist=a;
        duration=d;
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
    void add_song(string song_name,string artist,float duration){
            Node *nn=new Node(song_name,artist,duration);
            if (head == NULL) {
            head = nn;
        }
        else{
            Node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    }    
cout << song_name << " successfully added!!" << endl;

}
void add_song_beg(string song_name,string artist,float duration){
    Node *nn=new Node(song_name,artist,duration);
    
    nn->next=head;
    head=nn;
    cout << song_name << " successfully added at the begining!!" << endl;

}
void add_song_mid(string song_name,string artist,float duration,string new_song){
    Node *nn=new Node(song_name,artist,duration);
    Node *temp=head;
    while (temp != NULL && temp->song_name != new_song){
        temp = temp->next;
    }
    if (temp != NULL) {
        Node *aad = temp->next; 
        temp->next = nn;        
        nn->next = aad;         
        }
    cout << song_name << " successfully added!!" << endl;
    }
void delete_val(string song_name){
    Node *temp = head;
    Node *prev=NULL;
    while (temp != NULL && temp->song_name != song_name){
        prev=temp;
        temp = temp->next;
}
    if (temp!=NULL){
        prev->next=temp->next;
        delete temp;
    }
    cout << song_name << " successfully deleted!!" << endl;

    }
void display(){
    Node *temp = head;
    cout<<"\nLINKEDLIST:";
    while(temp!=NULL){
        cout<<"Title : "<<temp->song_name<<endl;
        cout<<"Artist : "<<temp->artist<<endl;
        cout<<"Duration : "<<temp->duration<<" min"<<endl;
        cout<<"-------------------------"<<endl;
        temp=temp->next;
    }
    cout<<"\n"<<endl;;
}
void Play_song(string song_name){
    Node *temp = head;
    while(temp != NULL && temp->song_name != song_name){
        temp = temp->next;
    }

    if(temp != NULL){
        cout<<"\nNow Playing...\n";
        cout<<"Title : "<<temp->song_name<<endl;
        cout<<"Artist : "<<temp->artist<<endl;
        cout<<"Duration : "<<temp->duration<<" min"<<endl;
    }
    else{
        cout<<"Song not found!"<<endl;
    }
}

};

int main(){

    LinkList list;
    list.add_song("Believer","Imagine Dragons",3.4);
    list.add_song("Perfect","Ed Sheeran",4.2);
    list.add_song("Shape of You","Ed Sheeran",3.9);
    list.display();
    list.Play_song("Perfect");
    list.delete_val("Believer");
    list.display();

return 0;
}
