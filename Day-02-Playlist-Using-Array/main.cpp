#include<iostream>
#include<string>
using namespace std;
class song{
public:
string songname,artist,duration;
int n;
void getdata(){
    cout<<"Song name: ";
    cin>>songname;
    cout<<"Artist: ";
    cin>>artist;
    cout<<"Duration in minutes";
    cin>>duration;
}
void display(){
    cout<<"-------------------PLAYLIST-------------------"<<endl;
    cout<<"Song name: "<<songname;
    cout<<"Artist: "<<artist;
    cout<<"Duration: "<<duration;
}
};
int main(){
    int n,choice,count=0;
    cout<<"Enter maximum number of song in your playlist: "<<endl;
    cin>>n;
    song s[n];
    cout<<"\n========= MUSIC PLAYER ========="<<endl;
    cout<<"1. Add Songs"<<endl;
    cout<<"2. Remove Song"<<endl;
    cout<<"3. Display Playlist"<<endl;
    cout<<"4. Play Song"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter choice: "<<endl;
    cin>>choice;
    while (choice!=5){
    switch(choice){
        case 1:
            s[count].getdata();
            count++;
        break;
        case 2:
        if(count==0){
                cout<<"No songs in the playlist"<<endl;
            }
            else{

                int pos;

                cout<<"Enter song number to remove: ";
                cin>>pos;

                if(pos>=1 && pos<=count){

                    for(int i=pos-1;i<count-1;i++){
                        s[i]=s[i+1];
                    }

                    count--;

                    cout<<"Song Removed Successfully!"<<endl;
                }
                else{
                    cout<<"Invalid Song Number"<<endl;
                }
            }

            break;

        case 3:

            if(count==0){
                cout<<"Playlist is Empty"<<endl;
            }
            else{

                for(int i=0;i<count;i++){

                    cout<<"\nSong "<<i+1<<endl;
                    s[i].display();
                }
            }

            break;

        case 4:

            if(count==0){
                cout<<"Playlist is Empty"<<endl;
            }
            else{

                int play;

                cout<<"Enter song number to play: ";
                cin>>play;

                if(play>=1 && play<=count){

                    cout<<"\nNow Playing...\n";
                    s[play-1].display();
                }
                else{
                    cout<<"Invalid Song Number"<<endl;
                }
            }

            break;

        case 5:

            cout<<"Thank You!"<<endl;
            break;

        default:

            cout<<"Invalid Choice"<<endl;
        }

    return 0;
}