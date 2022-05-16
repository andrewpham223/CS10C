#include "Playlist.h"

#include <iostream>
using namespace std;

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    nextNodePtr = nullptr;
}

void PlaylistNode::SetNext(PlaylistNode *node) {
    nextNodePtr = node;
}

void PlaylistNode::InsertAfter(PlaylistNode *node) {
    PlaylistNode *tempNode = this->nextNodePtr;
    node->SetNext(tempNode);
    this->SetNext(node);
}

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist() : head(nullptr), tail(nullptr) { }

void Playlist::OutputFull(string title) const {
    cout << title << " - OUTPUT FULL PLAYLIST" << endl;
    if(head == nullptr) {
        cout << "Playlist is empty" << endl;
    }
    else {
        PlaylistNode *tempNode = head;
        int count = 1;
        while(tempNode != nullptr) {
            cout << count << "." << endl;
            tempNode->PrintPlaylistNode();
            if(tempNode->GetNext() != nullptr) {
                cout << endl;
            }
            tempNode = tempNode->GetNext();
            count++;
        }
    }
}

void Playlist::AddSong(PlaylistNode *newNode) {
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->SetNext(newNode);
        tail = newNode;
    }
}

PlaylistNode* Playlist::RemoveSong(string uID) {
    PlaylistNode *prev = nullptr;
    PlaylistNode *curr = head;
    while(curr != nullptr && curr->GetID() != uID) {
        prev = curr;
        curr = curr->GetNext();
    }
    if(curr != nullptr) {
        if(curr != head) {
            prev->SetNext(curr->GetNext());
        }
        else {
            head = curr->GetNext();
        }
        if(curr == tail) {
            tail = prev;
        }
        return curr;
    }
    else {
        return nullptr;
    }
}

void Playlist::ChangePos(int initPos, int newPos) {

    int index = 1;

    PlaylistNode* prev = nullptr;
    PlaylistNode* curr = head;
    
    /* If initPos parameter is not within the constraints of the function, terminate function. */
    if (initPos < 1) {
        cout << "Invalid  position." << endl;
        return;
    }
    
    /* Find the node you need to move, by traversing the list. By the termination of this loop, curr should be pointing to the target node;
    OR, if the end of the list is reached before the initial position is reached, you can tell that the initial position is not within 1 - n,
    where n is the number of elements in the list. */
    while (index < initPos) {
        if (curr != nullptr) {
            prev = curr;
            curr = curr->GetNext();
            index++;

            if (curr == nullptr) {
                cout << "Invalid position." << endl;
                return;
            }
        }
        else {
            cout << "Invalid position." << endl;
            return;
        }
    }

    /* The method for changing the position is as follows. First, you have to remove the node in question. Then, place it at the correct position. */

    /* If curr is head, remove curr by setting the head to the next node. If curr is tail, remove curr by setting tail to the node before (prev). */
    if (prev != nullptr) {
        prev->SetNext(curr->GetNext());
    }
    else {
        head = curr->GetNext();
    }

    if (curr == tail) {
        tail = prev;
    }

    /* Now, we've got to put the node back in. */
    if (newPos <= 1) { /* If newPos is 1 or less, you're putting the node at the beginning of the list (making it the head) */
        if (head == nullptr) { 
            tail = curr;
        }

        curr->SetNext(head);
        head = curr;
        cout << '"' << curr->GetSongName() << '"' << " moved to position 1" << endl;
    }
    else {
        if (head == nullptr) {
            this->AddSong(curr);
            cout << '"' << curr->GetSongName() << '"' << " moved to position 1" << endl;
        }
        else {
            int index2 = 1;
            PlaylistNode *prev2 = nullptr;
            PlaylistNode *curr2 = head;
            while (index2 < newPos && curr2) { /* We do this to get curr2 to point to the node before the place we want to put our original curr node */
                prev2 = curr2;
                curr2 = curr2->GetNext();
                index2++;
            }

            prev2->InsertAfter(curr);

            if (curr2 == nullptr) {
                tail = curr;
            }
            cout << '"' << curr->GetSongName() << '"' << " moved to position " << newPos << endl;
        }
    }
}

void Playlist::OutputByArtist(string name) const {
    int count = 1;
    int artistCount = 0;
    int artistPrintCount = 0;

    PlaylistNode *temp = head;
    while(temp != nullptr) {
        if(temp->GetArtistName() == name) {
            artistCount++;
        }
        temp = temp->GetNext();
    }
    temp = head;
    while(temp != nullptr) {
        if(temp->GetArtistName() == name) {
            cout << count << "." << endl;
            temp->PrintPlaylistNode();
            artistPrintCount++;
            if(artistPrintCount < artistCount) {
                cout << endl;
            }
        }
        temp = temp->GetNext();
        count++;
    }

}

int Playlist::TotalTime() const {
    int count = 0;
    PlaylistNode *temp = head;
    while(temp != nullptr) {
        count += temp->GetSongLength();
        temp = temp->GetNext();
    }
    return count;
}


