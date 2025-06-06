// ---------------------- song.cpp ----------------------
#include "song.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <vector>
#include "color.h"

#pragma comment(lib, "winmm.lib")

Song::Song(std::string t, std::string a, std::string g, std::string f)
    : title(t), artist(a), genre(g), filePath(f), likes(0) {}

std::string Song::getTitle() const {
    return title;
}

void Song::display() const {
    std::cout << lightCream("\nTitle: ") << title
         << lightCream("\nArtist: ")  << artist
         << lightCream("\nGenre: ")   << genre
         << lightCream("\nLikes: ")   << likes << "\n";
}

void Song::play() const {
    std::cout << italic(gray("Playing: ")) << title << italic(gray(" by ")) << artist << std::endl;
    PlaySound(filePath.c_str(), NULL, SND_FILENAME | SND_SYNC);

}

void Song::like() {
    likes++;
}
std::string Song::getFilePath() const {
    return filePath;
}
void Song::loadSongsFromFile(std::vector<Song>& globalSongs) {
    std::ifstream fin("songs.txt");
    std::string title, artist, genre, filepath;

    while (std::getline(fin, title) &&
           std::getline(fin, artist) &&
           std::getline(fin, genre) &&
           std::getline(fin, filepath)) {
        Song s(title, artist, genre, filepath);
        globalSongs.push_back(s);
    }

    fin.close();
    std::cout << "[INFO] Songs loaded from file: " << globalSongs.size() << " song(s)\n";
}
