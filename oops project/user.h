// ---------------------- user.h ----------------------
#ifndef USER_H
#define USER_H

#include "person.h"
#include "song.h"
#include <vector>
#include <iostream>

class User : public Person {
private:
    std::vector<Song> playlist;
    std::vector<Song> likedSongs;
    std::string username;

public:
    User(std::string uname, std::string e);
    void displayMenu(std::vector<Song>& globalSongs) override;
    void browseSongs(const std::vector<Song>& globalSongs);
    void playFromPlaylist();
    void removeFromPlaylist();
    void likeSong(std::vector<Song>& globalSongs);
    void addToPlaylist(const std::vector<Song>& globalSongs);
    void playPlaylist();
    std::string getRole() override { return "User"; }
    void loadUserData();
    void saveUserData();
    void showLikedSongs();
    void sortPlaylist();
    void shufflePlaylist();
    void showPlaylist() const;
    void searchByTitle(const std::string& keyword) const;
};

#endif