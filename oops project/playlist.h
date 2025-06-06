#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include <vector>
#include <string>

class Playlist {
private:
    std::string name;
    std::vector<Song> songs;

public:
    Playlist(std::string n = "My Playlist");
    void addSong(const Song& song);
    void removeSong(std::string title);
    void displaySongs() const;
    void playAll() const;
};

#endif
