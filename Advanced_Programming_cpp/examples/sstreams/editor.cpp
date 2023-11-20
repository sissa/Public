#include <iostream>
#include <fstream>
#include <string>

void readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void writeFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // appending to file
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::cout << "Enter text to write to the file (enter 'exit' to finish writing):" << std::endl;
    std::string input;
    while (std::getline(std::cin, input) && input != "exit") {
        file << input << std::endl;
    }
    file.close();
}

void modifyFile(const std::string& filename) {
    std::fstream file(filename, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::cout << "Modifying File: " << filename << std::endl;
    std::cout << "Enter the line number to modify and the new text (or 'exit' to finish):" << std::endl;

    std::string newText;
    int lineNumber;
    while (true) {
        std::cin >> lineNumber;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cin.ignore();
        std::getline(std::cin, newText);
        file.seekp((lineNumber - 1) * 40, std::ios::beg); // assuming max 40 chars per line
        file << newText.substr(0, 38); // protecting line boundaries
    }
    file.close();
}

int main() {
    const std::string filename = "example.txt";
    
    int option;
    do {
        std::cout << "Simple File Editor\n";
        std::cout << "1. Read file\n";
        std::cout << "2. Write to file\n";
        std::cout << "3. Modify file\n";
        std::cout << "4. Exit\n";
        std::cout << "Select an option: ";
        std::cin >> option;
        std::cin.ignore();

        switch (option) {
            case 1:
                readFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                modifyFile(filename);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option, try again.\n";
        }
    } while (option != 4);

    return 0;
}

