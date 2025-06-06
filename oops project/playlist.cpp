#include "playlist.h"
#include <iostream>
#include <windows.h> // For PlaySound
#include <mmsystem.h>
#include "color.h"

Playlist::Playlist(std::string n) {
    name = n;
}

void Playlist::addSong(const Song& song) {
    songs.push_back(song);
    std::cout << italic(lightGreen("Song added to playlist.\n"));
}

void Playlist::removeSong(std::string title) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (it->getTitle() == title) {
            songs.erase(it);
            std::cout << italic(lightRed("Song removed from playlist.\n"));
            return;
        }
    }
    std::cout << italic(red("Song not found.\n"));
}

void Playlist::displaySongs() const {
    if (songs.empty()) {
        std::cout << italic(lightRed("Playlist is empty.\n"));
        return;
    }

    for (const auto& song : songs)
        song.display();
}

void Playlist::playAll() const {
    for (const auto& song : songs) {
        std::cout << italic(gray("Playing: ")) << song.getTitle() << "...\n";
        PlaySound(song.getFilePath().c_str(), NULL, SND_FILENAME);
    }
}
// Note: PlaySound requires the file path to be a valid sound file path. Ensure the file exists.
// This code is for demonstration purposes and may require additional error handling in a production environment.