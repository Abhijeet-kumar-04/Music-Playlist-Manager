// ---------------------- artist.h ----------------------
#ifndef ARTIST_H
#define ARTIST_H

#include "person.h"
#include "song.h"
#include <vector>
#include <string>

class Artist : public Person {
private:
    std::vector<Song> uploadedSongs;
    std::string username;
    std::string password;

public:
    Artist(std::string n = "", std::string e = "", std::string u = "", std::string p = "");
    std::string getUsername() const;
    std::string getPassword() const;
    bool login(std::string u, std::string p);

    void uploadSong(std::vector<Song>& globalSongs);
    void deleteSong();
    void viewUploadedSongs();
    void displayMenu(std::vector<Song>& globalSongs) override;
    std::string getRole() override { return "Artist"; }

    static bool loadArtistFromFile(Artist& artist);
    static void saveArtistToFile(const Artist& artist);
    void saveUploadedSong(const std::string& username, const Song& song);
    void loadUploadedSongs(const std::string& username, std::vector<Song>& globalSongs);

};

#endif
