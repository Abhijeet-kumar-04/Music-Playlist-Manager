// ---------------------- artist.cpp ----------------------
#include "artist.h"

#include "color.h" // Include color.h for color formatting
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip> // for std::setw
#include <windows.h> // for PlaySound
#include <mmsystem.h> // for PlaySound
#include <cstdlib> // for system("cls")
#include <algorithm> // for std::sort and std::random_shuffle
#include <random>
#include <sstream>
#include <limits> // for std::numeric_limits
#include <conio.h> // for _getch()
#include <cstdio> // for std::remove
#include <cstdlib> // for std::system

Artist::Artist(std::string n, std::string e, std::string u, std::string p)
    : Person(n, e), username(u), password(p) {}

std::string Artist::getUsername() const { return username; }
std::string Artist::getPassword() const { return password; }

bool Artist::login(std::string u, std::string p) {
    return (u == username && p == password);
}

void Artist::uploadSong(std::vector<Song>& globalSongs) {
    std::string title, genre, filepath;
    std::cout << lightCream("Enter song title: ");
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << lightCream("Enter genre: ");
    std::getline(std::cin, genre);
    std::cout << lightCream("Enter file path: ");
    std::getline(std::cin, filepath);

    Song newSong(title, name, genre, filepath);
    uploadedSongs.push_back(newSong);
    globalSongs.push_back(newSong);

    // ✅ Save song to file
    std::ofstream fout("songs.txt", std::ios::app);
    fout << title << std::endl;
    fout << name << std::endl;
    fout << genre << std::endl;
    fout << filepath << std::endl;
    fout.close();
    saveUploadedSong(username, newSong);  
    std::cout << italic(lightGreen("Song uploaded successfully!\n"));
}

void Artist::deleteSong() {
    std::string title;
    std::cout << lightCream("Enter song title to delete: ");
    std::cin.ignore(); std::getline(std::cin, title);

    for (auto it = uploadedSongs.begin(); it != uploadedSongs.end(); ++it) {
        if (it->getTitle() == title) {
            uploadedSongs.erase(it);
            std::cout << italic(lightRed("Song deleted.\n"));
            return;
        }
    }
    std::cout << italic(red("Song not found.\n"));
}

void Artist::viewUploadedSongs() {
    if (uploadedSongs.empty()) {
        std::cout << italic(lightPink("No uploaded songs.\n"));
        return;
    }
    for (auto& s : uploadedSongs)
        s.display();
}

void Artist::displayMenu(std::vector<Song>& globalSongs) {
    loadUploadedSongs(username, uploadedSongs);
    int choice;
    do {
        std::cout << orange(bold("\n-----------Artist Panel-------------\n  ")) << bold(teal("WELCOME --->  ")) << bold(lime(name)) << " \n";
        std::cout << cyan("1. Upload Song\n2. Delete Song\n3. View Uploaded Songs\n0. Logout") << silver("\nChoice: ");
        std::cin >> choice;
        switch (choice) {
            case 1: uploadSong(globalSongs); break;
            case 2: deleteSong(); break;
            case 3: viewUploadedSongs(); break;
            case 0: std::cout << italic(lightPink("Logging out...\n")); break;
            default: std::cout << italic(red("Invalid choice.\n"));
        }
    } while (choice != 0);
}

bool Artist::loadArtistFromFile(Artist& artist) {
    std::ifstream fin("artists.txt");
    std::string name, email, username, password;

    while (std::getline(fin, name) && std::getline(fin, email) &&
           std::getline(fin, username) && std::getline(fin, password)) {
        if (username == artist.getUsername() && password == artist.getPassword()) {
            artist = Artist(name, email, username, password);
            return true;
        }
    }
    return false;
}

void Artist::saveArtistToFile(const Artist& artist) {
    std::ofstream fout("artists.txt", std::ios::app);
    fout << artist.getName() << std::endl;
    fout << artist.getEmail() << std::endl;
    fout << artist.getUsername() << std::endl;
    fout << artist.getPassword() << std::endl;
    fout.close();
}

void Artist::saveUploadedSong(const std::string& username, const Song& song) {
    std::ofstream fout(username + "_songs.txt", std::ios::app);
    if (!fout.is_open()) return;

    fout << song.getTitle() << '\n'
         << song.getArtist()  << '\n'
         << song.getFilePath()<< '\n';
    fout.close();
}

void Artist::loadUploadedSongs(const std::string& username, std::vector<Song>& globalSongs) {
    std::ifstream fin(username + "_songs.txt");
    if (!fin.is_open()) return;
    std::string title, artist, path;

    while (std::getline(fin, title) && std::getline(fin, artist) && std::getline(fin, path)) {
        Song s(title, artist, "", path); // genre left empty
        uploadedSongs.push_back(s);
        globalSongs.push_back(s);
    }
    fin.close();
}

// ---------------------- artist.cpp ----------------------