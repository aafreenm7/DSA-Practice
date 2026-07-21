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
    while(temp != NULL && temp->song_name != new_song){
    temp = temp->next;
}
    if(temp == NULL){
        cout << "Song not found!\n";
        delete nn;
        return;
    }
    Node *aad = temp->next;
    temp->next = nn;
    nn->next = aad;
    cout << song_name << " successfully added!!" << endl;
    }

void delete_val(string song_name){
    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL && temp->song_name != song_name){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Song not found!\n";
        return;
    }

    if(temp == head){
        head = head->next;
    }
    else{
        prev->next = temp->next;
    }

    delete temp;

    cout << song_name << " successfully deleted!!" << endl;
}
void display(){
    Node *temp = head;
    if(head==NULL){
    cout<<"Playlist Empty\n";
    return;
    }
    else{
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

int main() {

    LinkList list;

    int choice;
    string song_name, artist, new_song;
    float duration;

    do {
        cout << "\n====== MUSIC PLAYLIST ======\n";
        cout << "1. Add Song\n";
        cout << "2. Add Song at Beginning\n";
        cout << "3. Add Song After Another Song\n";
        cout << "4. Delete Song\n";
        cout << "5. Display Playlist\n";
        cout << "6. Play Song\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {

        case 1:
            cout << "Enter Song Name: ";
            getline(cin, song_name);

            cout << "Enter Artist Name: ";
            getline(cin, artist);

            cout << "Enter Duration: ";
            cin >> duration;

            list.add_song(song_name, artist, duration);
            break;

        case 2:
            cout << "Enter Song Name: ";
            cin.ignore();
            getline(cin, song_name);

            cout << "Enter Artist Name: ";
            getline(cin, artist);

            cout << "Enter Duration: ";
            cin >> duration;

            list.add_song_beg(song_name, artist, duration);
            break;

        case 3:
            cout << "Enter Song Name: ";
            cin.ignore();
            getline(cin, song_name);

            cout << "Enter Artist Name: ";
            getline(cin, artist);

            cout << "Enter Duration: ";
            cin >> duration;

            cout << "Insert After Which Song? ";
            getline(cin, new_song);

            list.add_song_mid(song_name, artist, duration, new_song);
            break;

        case 4:
            cout << "Enter Song Name to Delete: ";
            cin.ignore();
            getline(cin, song_name);

            list.delete_val(song_name);
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Enter Song Name to Play: ";
            cin.ignore();
            getline(cin, song_name);

            list.Play_song(song_name);
            break;

        case 7:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}
