#include "Playlist.h"
#include <iostream>

using namespace std;

void PrintMenu(string);

Playlist* myPlaylist;

int main() {
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    
    myPlaylist = new Playlist();
    PrintMenu(title);

    return 0;
}

void PrintMenu(string title) {
    cout << endl << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;

    string option;
    getline(cin, option);

    if(option == "a") {
        string newID, newSongName, newArtistName;
        int newLength;
        cout << "ADD SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, newID);
        cout << "Enter song's name:" << endl;
        getline(cin, newSongName);
        cout << "Enter artist's name:" << endl;
        getline(cin, newArtistName);
        cout << "Enter song's length (in seconds):" << endl;
        cin >> newLength;
        cin.ignore();
        
        PlaylistNode *newSong = new PlaylistNode(newID, newSongName, newArtistName, newLength);
        myPlaylist->AddSong(newSong);
        PrintMenu(title);
    }
    else if(option == "d") {
        string id;
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, id);
        PlaylistNode *removeNode = myPlaylist->RemoveSong(id);
        if(removeNode != nullptr) {
            cout << "\"" << removeNode->GetSongName() << "\"" << " removed.";
        }
        else {
            cout << "Song with unique ID " << id << " not found!" << endl;
        }
        cout << endl;
        PrintMenu(title);
    }
    else if(option == "c") {
        int initPos, newPos;
        cout << "CHANGE POSITION OF SONG" << endl;
        cout << "Enter song's current position:" << endl;
        cin >> initPos;
        cout << "Enter new position for song:" << endl;
        cin >> newPos;
        cin.ignore();

        myPlaylist->ChangePos(initPos, newPos);
        PrintMenu(title);
    }
    else if(option == "s") {
        string name;
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        getline(cin, name);
        cout << endl;
        myPlaylist->OutputByArtist(name);
        PrintMenu(title);
    }
    else if(option == "t") {
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        cout << "Total time: " << myPlaylist->TotalTime() << " seconds" << endl;
        PrintMenu(title);
    }
    else if(option == "o") {
        myPlaylist->OutputFull(title);
        PrintMenu(title);
    }
    else if(option == "q") {
    }

    else {
        cout << "Invalid selection." << endl;
        PrintMenu(title);
    }

}
