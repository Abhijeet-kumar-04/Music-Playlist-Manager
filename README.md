# Music Playlist Manager 🎵

A C++ console application for managing music playlists with support for **Artists** (who can upload songs) and **Users** (who can browse, like, and play songs). Features include colorful terminal UI, file-based persistence, and Windows audio playback.

## Features

- **Artist Panel:**  
  - Register/Login  
  - Upload songs (title, genre, file path)  
  - View and delete uploaded songs

- **User Panel:**  
  - Register/Login  
  - Browse all songs  
  - Like songs  
  - Create and manage playlists  
  - Play songs (WAV format, Windows only)  
  - Sort and shuffle playlists

- **Colorful Terminal Output** using ANSI escape codes

## How to Run

1. **Requirements:**  
   - Windows OS  
   - C++17 compatible compiler (e.g., g++)

2. **Build:**
     Open your terminal (Command Prompt, PowerShell, or VS Code terminal), navigate to your project folder, and run:
   ```sh
   g++ -std=c++17 main.cpp user.cpp artist.cpp song.cpp playlist.cpp person.cpp -o MusicApp.exe -lwinmm
   ```

4. **Run:**
     After successful compilation, run:
   ```sh
   ./MusicApp.exe
   ```

6. **Add Songs:**  
   - Place your `.wav` files in the `song/` directory.
   - Add song details to `songs.txt` (or use the Artist panel to upload).

## File Structure

```
/Oops project
  |-- main.cpp
  |-- user.cpp/h
  |-- artist.cpp/h
  |-- song.cpp/h
  |-- playlist.cpp/h
  |-- person.cpp/h
  |-- color.h
  |-- songs.txt
  |-- song/ (folder with .wav files)
```

## About

This project was created as an Object-Oriented Programming (OOPs) assignment.  
It demonstrates class inheritance, file I/O, and basic UI/UX in a C++ console app.

---

**Note:**  
- Only `.wav` files are supported for playback (Windows API).
- Color output may not work in all Windows terminals.

---

## License

[MIT](LICENSE)
