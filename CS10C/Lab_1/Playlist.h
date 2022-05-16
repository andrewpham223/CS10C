#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <iostream>
using namespace std;

class PlaylistNode {
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    public:
        PlaylistNode();
        PlaylistNode(string, string, string, int);
        void InsertAfter(PlaylistNode*);
        void SetNext(PlaylistNode*);
        string GetID() const;
        string GetSongName() const;
        string GetArtistName() const;
        int GetSongLength() const;
        PlaylistNode* GetNext() const;
        void PrintPlaylistNode() const;
};

class Playlist {
    private:
        PlaylistNode *head;
        PlaylistNode *tail;
    public:
        Playlist(); 
        void OutputFull(string) const;
        void AddSong(PlaylistNode*);
        PlaylistNode* RemoveSong(string);
        void ChangePos(int, int);
        void OutputByArtist(string) const;
        int TotalTime() const;
};

#endif