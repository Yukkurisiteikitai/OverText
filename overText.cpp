#include <iostream>
#include <fstream>
#include <vector>
#include <random>

void fe(int c, std::string& temp_do) {
    std::vector<char> words(26);
    for (int i = 0; i < 26; ++i) {
        words[i] = 'a' + i;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 25);

    for (int i = 0; i < c; ++i) {
        temp_do += words[dis(gen)];
        if (i % (c / 100) == 0) {
            std::cout << "Progress: " << (i * 100 / c) << "%\r" << std::flush;
        }
    }
    std::cout << "\n";
}

int main() {
    std::string temp_do;
    fe(2 * 1000000000, temp_do);
    
    std::ofstream file("tekitou.txt", std::ios::app);
    if (file.is_open()) {
        file << temp_do;
        file.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
    }
    
    return 0;
}