// ---------------------- main.cpp ----------------------


#include "artist.h"     // Include artist.h for Artist class

#include "person.h"     // Include person.h for Person class
#include "user.h"       // Include user.h for User class
#include "song.h"       // Include song.h for Song class
#include "color.h"      // Include color.h for color formatting functions   
#include <iostream>     // Include iostream for input/output
#include <vector>       // Include vector for using std::vector     
#include <string>       // Include string for using std::string
#include <iomanip>      // Include iomanip for std::setw
#define byte win_byte
#include <windows.h>    // Include windows.h for PlaySound
#undef byte

#include <mmsystem.h>   // Include mmsystem.h for PlaySound
#include <fstream>      // Include fstream for file operations
#include <conio.h>      // Include conio.h for _getch()
#include <limits>       // Include limits for std::numeric_limits
#include <cstdlib>      // Include cstdlib for system("cls")
#include <sstream>      // Include sstream for stringstream
#include <vector>       // Include vector for using std::vector
// Removed: using namespace std;

std::vector<Song> globalSongs;

#pragma comment(lib, "winmm.lib")

void artistPanel(Artist& artist) {
    artist.displayMenu(globalSongs);
}

// ✅ Load all songs from file
void loadSongsFromFile() {
    std::ifstream fin("songs.txt");
    std::string title, artist, genre, path;

    while (std::getline(fin, title) && std::getline(fin, artist) &&
           std::getline(fin, genre) && std::getline(fin, path)) {
        globalSongs.emplace_back(title, artist, genre, path);
    }
    fin.close();
}
// ✅ Save one song to file (append)
void saveSongToFile(const Song& s) {
    std::ofstream fout("songs.txt", std::ios::app);
    fout << s.getTitle() << std::endl;
    fout << s.getArtist() << std::endl;
    fout << s.getGenre() << std::endl;
    fout << s.getPath() << std::endl;
    fout.close();
}
void artistLoginOrRegister() {
    int choice;
    std::cout << orange(bold("\n ------Artist Menu--------\n")) << cyan("1. Register\n2. Login\n") << silver("Choice: ");
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::string name, email, username, password;
        std::cout << lightCream("Enter Name: ");      std::getline(std::cin, name);
        std::cout << lightCream("Enter Email: ");     std::getline(std::cin, email);
        std::cout << lightCream("Choose Username: "); std::getline(std::cin, username);
        std::cout << lightCream("Choose Password: "); std::getline(std::cin, password);

        Artist newArtist(name, email, username, password);
        Artist::saveArtistToFile(newArtist);
        std::cout << italic(lightGreen("Artist registered successfully!\n"));
        artistPanel(newArtist);

    } else if (choice == 2) {
        std::string username, password;
        std::cout << lightCream("Enter Username: "); std::getline(std::cin, username);
        std::cout << lightCream("Enter Password: "); std::getline(std::cin, password);

        Artist loggedInArtist("", "", username, password);
        if (Artist::loadArtistFromFile(loggedInArtist)) {
            std::cout << italic(lightGreen("Login successful. Welcome ")) << bold(orange(loggedInArtist.getName())) << italic(lightGreen("!\n"));
            artistPanel(loggedInArtist);
        } else {
            std::cout << italic(red("Login failed. Invalid credentials.\n"));
        }
    } else {
        std::cout << italic(red("Invalid choice.\n"));
    }
}

void userPanel(std::vector<Song>& globalSongs) {
    std::string name = "", email;
    std::string x;
    std::cout << orange(bold("\n ------ USER___LOGIN --------\n"));
    std::cout << bold(lightBlue("Enter User Name:"));
    std::cout << neonGreen(italic("(#click space button than enter u name ) : "));
    std::cin.ignore();
    std::getline(std::cin, x);
    name = " " + x;
    std::cout << bold(lightBlue("Enter Email: "));
    std::getline(std::cin, email);
    User user(name, email);

    user.loadUserData(); //  Load liked songs and playlist from file

    int choice;
    do {
        user.displayMenu(globalSongs);  //  Updated to pass globalSongs
        choice = 0;
    } while (choice != 0);

    user.saveUserData(); //  Save liked songs and playlist to file
}

int main() {
    Song::loadSongsFromFile(globalSongs);  //  Load existing songs
    int option;
    do {
        // system("cls"); // Clear the console screen
        
        std::cout << bold(magenta("=========================================\n"));
        std::cout << bold(magenta("|                                       |\n"));
        std::cout << bold(magenta("|    Welcome to Music Playlist Manager  |\n"));
        std::cout << bold(magenta("|                                       |\n"));       
        std::cout << bold(magenta("=========================================\n"));
        std::cout << bold(magenta("-------------------------------------------------------\n"));
        
        std::cout << bold(lightYellow("1. Artist Login/Register\n2. User Login\n0. Exit\n")) << silver("Choice: ");
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1: artistLoginOrRegister(); break;
            case 2: userPanel(globalSongs); break;
            case 0: std::cout << italic(bold(gold("___________>>>>>>>____"))) << bold(lightBlue("Goodbye!")) << italic(bold(gold("____<<<<<<<___________\n"))); break;
            default: std::cout << italic(red("Invalid option.\n"));
        }
    } while (option != 0);

    return 0;
}
// This code implements a simple music playlist manager with artist and user functionalities.