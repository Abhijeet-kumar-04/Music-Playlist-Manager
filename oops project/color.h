#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <iostream>

// Removed: using namespace std;

// Color formatting functions
inline std::string orange(const std::string& text) {
    return "\033[38;2;255;165;0m" + text + "\033[0m";
}

inline std::string brown(const std::string& text) {
    return "\033[38;2;165;42;42m" + text + "\033[0m";
}

inline std::string bold(const std::string& text) {
    return "\033[1m" + text + "\033[0m";
}

inline std::string italic(const std::string& text) {
    return "\033[3m" + text + "\033[0m";
}

inline std::string green(const std::string& text) {
    return "\033[32m" + text + "\033[0m";
}


inline std::string cyan(const std::string& text) {
    return "\033[36m" + text + "\033[0m";
}

inline std::string yellow(const std::string& text) {
    return "\033[33m" + text + "\033[0m";
}

inline std::string red(const std::string& text) {
    return "\033[31m" + text + "\033[0m";
}

inline std::string blue(const std::string& text) {
    return "\033[34m" + text + "\033[0m";
}

inline std::string magenta(const std::string& text) {
    return "\033[35m" + text + "\033[0m";
}

inline std::string white(const std::string& text) {
    return "\033[37m" + text + "\033[0m";
}



inline std::string purple(const std::string& text) {
    return "\033[38;2;128;0;128m" + text + "\033[0m";
}

inline std::string gray(const std::string& text) {
    return "\033[38;2;128;128;128m" + text + "\033[0m";
}

inline std::string neonGreen(const std::string& text) {
    return "\033[38;2;57;255;20m" + text + "\033[0m";
}

inline std::string deepBlue(const std::string& text) {
    return "\033[38;2;0;0;139m" + text + "\033[0m";
}

// RGB Colors
inline std::string lightCream(const std::string& text) {
    return "\033[38;2;255;253;208m" + text + "\033[0m";
}

inline std::string lightPink(const std::string& text) {
    return "\033[38;2;255;182;193m" + text + "\033[0m";
}

inline std::string lightBlue(const std::string& text) {
    return "\033[38;2;173;216;230m" + text + "\033[0m";
}
// Extra RGB Colors

// Light Variants
inline std::string lightRed(const std::string& text) {
    return "\033[38;2;255;102;102m" + text + "\033[0m";
}

inline std::string lightGreen(const std::string& text) {
    return "\033[38;2;144;238;144m" + text + "\033[0m";
}

inline std::string lightYellow(const std::string& text) {
    return "\033[38;2;255;255;153m" + text + "\033[0m";
}

inline std::string lightPurple(const std::string& text) {
    return "\033[38;2;204;153;255m" + text + "\033[0m";
}

inline std::string lightOrange(const std::string& text) {
    return "\033[38;2;255;200;124m" + text + "\033[0m";
}

inline std::string lightGray(const std::string& text) {
    return "\033[38;2;211;211;211m" + text + "\033[0m";
}

inline std::string pastelBlue(const std::string& text) {
    return "\033[38;2;174;198;207m" + text + "\033[0m";
}
inline std::string silver(const std::string& text) {
    return "\033[38;2;192;192;192m" + text + "\033[0m";
}



// Additional Colors
inline std::string teal(const std::string& text) {
    return "\033[38;2;0;128;128m" + text + "\033[0m";
}

inline std::string gold(const std::string& text) {
    return "\033[38;2;255;215;0m" + text + "\033[0m";
}

inline std::string coral(const std::string& text) {
    return "\033[38;2;255;127;80m" + text + "\033[0m";
}

inline std::string olive(const std::string& text) {
    return "\033[38;2;128;128;0m" + text + "\033[0m";
}

inline std::string navy(const std::string& text) {
    return "\033[38;2;0;0;128m" + text + "\033[0m";
}

inline std::string maroon(const std::string& text) {
    return "\033[38;2;128;0;0m" + text + "\033[0m";
}

inline std::string lime(const std::string& text) {
    return "\033[38;2;0;255;0m" + text + "\033[0m";
}

inline std::string skyBlue(const std::string& text) {
    return "\033[38;2;135;206;235m" + text + "\033[0m";
}

// Divider
inline void printDivider() {
    std::cout << std::string(72, '-') << "\n";
}

#endif // COLOR_H
