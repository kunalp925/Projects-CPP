//
//  main.cpp
//  CS210_Labs
//
//  Created by Kunal Patel on 8/21/17.
//  Copyright © 2017 Kunal Patel. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class song{
public:
    string getArtist(){
        return artist;
    }
    string getTitle(){
        return title;
    }
    song(string title, string artist){
        this->title = title;
        this->artist = artist;
    }
private:
    string artist, title;
};



void displayPlaylist(vector<song*> Playlist){
    cout << "Displaying Playlist:" <<endl;
    for(int i=0;i<Playlist.size(); i++){
        cout << "Song Title: " <<Playlist.at(i)->getTitle() << '\t'<<  " Artist: " << Playlist.at(i)->getArtist() << endl;
    }
}


int main() {
    
    vector<song*> Playlist;
    int in;
    displayPlaylist(Playlist);
    do {
        cout << endl << "1 to add a song" <<endl;
        cout << "2 to delete a song" <<endl;
        cout << "0 to quit" <<endl;
        cout << "Enter: ";
        cin >> in;
        
        if(in == 1){
            string songTitle, songArtist;
            cout << "Enter song title: ";
            cin >> songTitle;
            cout<< "Enter song artist: ";
            cin >> songArtist;
            Playlist.push_back(new song(songTitle, songArtist));
            cout <<endl;
            displayPlaylist(Playlist);
        }
        else if(in == 2){
            string songTitle, songArtist;
            bool found=false;
            int loc = 0;
            cout << "Enter song title you would like to remove: ";
            cin >> songTitle;
            cout << "Enter the artist of the song: ";
            cin >>songArtist;
            for(int i=0; i< Playlist.size();i++ ){
                if(Playlist.at(i)->getArtist()==songArtist && Playlist.at(i)->getTitle()==songTitle){
                    found =true;
                    loc = i;
                }
            }
            if(found){
                Playlist.erase(Playlist.begin()+loc);
            }
            else{
                cout <<"Song was not found."<<endl;
            }
            displayPlaylist(Playlist);
        }
        else if(in > 2 || in <0){
            cout << "Not a valid input. Please your choice again."<<endl;
        }
        
        
    } while (in != 0);
    cout << endl;
    displayPlaylist(Playlist);
    
    
    return 0;
}
