#include <iostream>
#include <fstream>
#include <string>

void displayFileContent(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    if (file.is_open()) {
        std::cout << "File contents:" << std::endl;
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}

void writeToFile(const std::string& filename) {
    std::ofstream file;
    file.open(filename, std::ios_base::app); // Open in append mode
    std::string input;
    std::cout << "Enter text to write to the file. Enter an empty line to stop:" << std::endl;
    while (getline(std::cin, input) && !input.empty()) {
        file << input << std::endl;
    }
    file.close();
}

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

    int choice = 0;
    do {
        std::cout << "1. Display file content" << std::endl;
        std::cout << "2. Write to file" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer

        switch (choice) {
            case 1:
                displayFileContent(filename);
                break;
            case 2:
                writeToFile(filename);
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice, try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}

