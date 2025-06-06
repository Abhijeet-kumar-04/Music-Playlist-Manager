// ---------------------- song.h ----------------------
#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>
#include <iostream>
#include <windows.h>

class Song {
private:
    std::string title;
    std::string artist;
    std::string genre;
    std::string filePath;
    std::string path; 
    int likes;

public:
    Song(std::string t = "", std::string a = "", std::string g = "", std::string f = "");
    std::string getTitle() const;
    void display() const;
    void play() const;
    void like();
    std::string getFilePath() const; // Getter for filePath
    static void loadSongsFromFile(std::vector<Song>& globalSongs);
    std::string getArtist() const { return artist; } 
    std::string getGenre() const { return genre; }
    int getLikes() const { return likes; }
    std::string getPath() const { return path; }
};

#endif