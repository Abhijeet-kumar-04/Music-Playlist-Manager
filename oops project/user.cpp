// ---------------------- user.cpp ----------------------
#include "user.h"
#include "color.h" // Include color.h for color formatting
#include <iostream>
#include <iomanip> // for std::setw
#include <windows.h> // for PlaySound
#include <mmsystem.h> // for PlaySound
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // for std::sort and std::random_shuffle
#include <cstdlib> // for system("cls")
#include <random>
#include <limits>
#include <conio.h> // for _getch()

User::User(std::string uname, std::string e)
  : Person(uname, e), username(uname)
{ 
    loadUserData();
}

void User::displayMenu(std::vector<Song>& globalSongs) {
    int choice;
    do {
        std::cout << orange(bold("\n-----------User Panel-----------\n")) << bold(teal("WELCOME --->  ")) << bold(lime(username)) << std::endl;
        std::cout << cyan("1. Browse Songs\n");
        std::cout << cyan("2. Play from Playlist\n");
        std::cout << cyan("3. Add to Playlist\n");
        std::cout << cyan("4. Remove from Playlist\n");
        std::cout << cyan("5. Show All Liked Songs\n");
        std::cout << cyan("6. Sort Songs by Title\n");
        std::cout << cyan("7. Shuffle Playlist\n");
        std::cout << cyan("8. Show Playlist\n");
        std::cout << cyan("0. Logout\n") << navy("Choice: ");
        std::cin >> choice;

        switch (choice) {
            case 1: browseSongs(globalSongs); break;
            case 2: playFromPlaylist(); break;
            case 3: addToPlaylist(globalSongs); break;
            case 4: removeFromPlaylist(); break;
            case 5: showLikedSongs(); break;
            case 6: sortPlaylist(); break;
            case 7: shufflePlaylist(); break;
            case 8: showPlaylist(); break;
            case 0: saveUserData(); std::cout << italic(lightPink("Logging out...\n")); break;
            default: std::cout << italic(red("Invalid choice.\n"));
        }
    } while (choice != 0);
}

void User::browseSongs(const std::vector<Song>& globalSongs) {
    if (globalSongs.empty()) {
        std::cout << italic(lightRed("No songs available.\n"));
        return;
    }

    std::cout << brown(bold("--------------------- All Songs ---------------------\n"));
    for (int i = 0; i < globalSongs.size(); ++i) {
        std::cout << "  " << std::setw(3) << i + 1 << gray(". ") << std::setw(25) << std::left << globalSongs[i].getTitle()
                  << gray(" by ") << globalSongs[i].getArtist() << std::endl;
    }

    std::cout << lightBlue("\nDo you want to:\n1. Play a Song\n2. Like a Song\n3. Add to Playlist\n4. Back\nEnter your choice: ");
    int choice;
    std::cin >> choice;

    if (choice >= 1 && choice <= 3) {
        std::cout << lightCream("Enter the song number: ");
        int num;
        std::cin >> num;
        if (num < 1 || num > globalSongs.size()) {
            std::cout << italic(red("Invalid song number.\n"));
            return;
        }

        Song selectedSong = globalSongs[num - 1];

        switch (choice) {
            case 1:
                PlaySoundA(globalSongs[num-1].getFilePath().c_str(), NULL, SND_FILENAME | SND_ASYNC);
                std::cout << italic(gray("\nPress any key to stop playback..."));
                _getch();                // <-- waits for any key
                PlaySoundA(NULL, NULL, 0); // stop
                break;
            case 2:
                likedSongs.push_back(selectedSong);
                std::cout << italic(lightGreen("Song liked.\n"));
                break;
            case 3:
                playlist.push_back(selectedSong);
                std::cout << italic(green("Song added to playlist.\n"));
                break;
        }
    }
    else if (choice == 4) {
        std::cout << italic(gray("Going back...\n"));
    } else {
        std::cout << italic(red("Invalid choice.\n"));
    }
    std::cout << bold(white("-----------------------------------------------\n"));
}

void User::playFromPlaylist() {
    if (playlist.empty()) {
        std::cout << italic(lightRed("Playlist is empty.\n"));
        return;
    }
    std::cout << bold(brown("\n------------ Your Playlist ------------\n"));
    for (int i = 0; i < playlist.size(); ++i) {
        std::cout << "  " << std::setw(3) << i + 1 << gray(". ") << std::setw(25) << std::left << playlist[i].getTitle()
                  << gray(" by ") << playlist[i].getArtist() << std::endl;
    }
    int choice;
    std::cout << lightCream("Enter song number to play: ");
    std::cin >> choice;
    if (choice >= 1 && choice <= playlist.size()) {
        PlaySoundA(playlist[choice-1].getFilePath().c_str(), NULL, SND_FILENAME | SND_ASYNC);
        std::cout << italic(gray("\nPress any key to stop playback..."));
        _getch();                // <-- waits for any key
        PlaySoundA(NULL, NULL, 0); // stop
    } else {
        std::cout << italic(red("Invalid selection.\n"));
    }
}

void User::addToPlaylist(const std::vector<Song>& globalSongs) {
    browseSongs(globalSongs);
}

void User::removeFromPlaylist() {
    if (playlist.empty()) {
        std::cout << italic(lightRed("Playlist is empty.\n"));
        return;
    }
    std::cout << bold(brown("\n------------ Your Playlist ------------\n"));
    for (int i = 0; i < playlist.size(); ++i) {
        std::cout << i + 1 << gray(". ") << playlist[i].getTitle() << gray(" by ") << playlist[i].getArtist() << std::endl;
    }
    int choice;
    std::cout << lightCream("Enter song number to remove: ");
    std::cin >> choice;
    if (choice >= 1 && choice <= playlist.size()) {
        playlist.erase(playlist.begin() + choice - 1);
        std::cout << italic(lightRed("Song removed from playlist.\n"));
    } else {
        std::cout << italic(red("Invalid selection.\n"));
    }
}

void User::showLikedSongs() {
    if (likedSongs.empty()) {
        std::cout << italic(lightRed("No liked songs.\n"));
        return;
    }
    std::cout << bold(brown("\n------------ Your All Liked Song ------------\n"));
    for (int i = 0; i < likedSongs.size(); ++i) {
        std::cout << "  " << std::setw(3) << i + 1 << gray(". ") << std::setw(25) << std::left << likedSongs[i].getTitle()
                  << gray(" by ") << likedSongs[i].getArtist() << std::endl;
    }
}

void User::sortPlaylist() {
    std::sort(playlist.begin(), playlist.end(), [](const Song& a, const Song& b) {
        return a.getTitle() < b.getTitle();
    });
    std::cout << italic(lightGreen("Playlist sorted by title.\n"));
}

void User::shufflePlaylist() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(playlist.begin(), playlist.end(), g);
    std::cout << italic(lightGreen("Playlist shuffled.\n"));
}

void User::showPlaylist() const {
    if (playlist.empty()) {
        std::cout << italic(lightRed("Playlist is empty.\n"));
        return;
    }
    std::cout << bold(brown("\n------------ Your Playlist ------------\n"));
    for (int i = 0; i < playlist.size(); ++i) {
        std::cout << "  " << std::setw(3) << i + 1 << gray(". ") << std::setw(25) << std::left << playlist[i].getTitle()
                  << gray(" by ") << playlist[i].getArtist() << std::endl;
    }
}

void User::saveUserData() {
    std::ofstream fout(name + "_data.txt");
    fout << likedSongs.size() << std::endl;
    for (auto& s : likedSongs)
        fout << s.getTitle() << '\n' << s.getArtist() << '\n' << s.getFilePath() << std::endl;

    fout << playlist.size() << std::endl;
    for (auto& s : playlist)
        fout << s.getTitle() << '\n' << s.getArtist() << '\n' << s.getFilePath() << std::endl;

    fout.close();
}

void User::loadUserData() {
    std::ifstream fin(name + "_data.txt");
    if (!fin) return;

    int likedCount;
    fin >> likedCount;
    fin.ignore();
    for (int i = 0; i < likedCount; ++i) {
        std::string t, a, f;
        std::getline(fin, t);
        std::getline(fin, a);
        std::getline(fin, f);
        likedSongs.push_back(Song(t, a, f));
    }

    int playlistCount;
    fin >> playlistCount;
    fin.ignore();
    for (int i = 0; i < playlistCount; ++i) {
        std::string t, a, f;
        std::getline(fin, t);
        std::getline(fin, a);
        std::getline(fin, f);
        playlist.push_back(Song(t, a, f));
    }

    fin.close();
}

// ---------------------- user.cpp ----------------------