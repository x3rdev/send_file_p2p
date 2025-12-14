#include <iostream>
#include <string>

int main() {
    std::cout << "Starting program" << std::endl;
    bool exit = false;

    while (!exit) {
        std::string input;
        std::cout << "Select an option" << std::endl;
        std::cout << "[q] - Quit" << std::endl;
        std::cout << std::endl;
        std::cout << "> ";
        getline(std::cin, input);

        switch (input[0]) {
            case 'q':
                exit = true;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }

    }
    return 0;
}