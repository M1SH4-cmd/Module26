#include <iostream>
#include <fstream>
#define FILE_PATH "..//phone_numbers"

class Contact {
private:
    std::string name;
    std::string number;
    friend class Phone;
};

class Phone{
public:
    void add() {
        std::ofstream file(FILE_PATH, std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        Contact contact;
        std::cout << "Enter name: ";
        std::getline(std::cin, contact.name);
        std::cout << "Enter number: ";
        std::getline(std::cin, contact.number);
        file << contact.name << ":" << contact.number << std::endl;
        file.close();
    }

    void call() {
        std::cout << "Enter your contact's name or phone number:" << std::endl;
        std::string search;
        std::getline(std::cin, search);
        std::ifstream file(FILE_PATH);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        while(!file.eof()) {
            bool found = false;
            std::string buffer;
            std::getline(file, buffer, '\n');
            for (int i = 0; i < buffer.length(); ++i) {
                if (buffer[i] == ':') {
                    std::string name = buffer.substr(0, i);
                    std::string number = buffer.substr(i + 1);
                    if (name == search || number == search) {
                        found = true;
                        std::cout << "Calling " << name << number << "..." << std::endl;
                        break;
                    }
                }
            }

            if(!found) {
                std::cout << "Calling " << buffer << "..." << std::endl;
            }
        }
    }

    void sms() {
        std::cout << "Enter your contact's name or phone number:" << std::endl;
        std::string search;
        std::getline(std::cin, search);
        std::ifstream file(FILE_PATH);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        while(!file.eof()) {
            bool found = false;
            std::string buffer;
            std::getline(file, buffer, '\n');
            for (int i = 0; i < buffer.length(); ++i) {
                if (buffer[i] == ':') {
                    std::string name = buffer.substr(0, i);
                    std::string number = buffer.substr(i + 1);
                    if (name == search || number == search) {
                        found = true;
                        std::cout << "Type in your message:" << std::endl;
                        std::string message;
                        std::cin >> message;
                        break;
                    }
                }
            }
            if(!found) {
                std::cout << "Type in your message:" << std::endl;
                std::string message;
                std::cin >> message;
            }
        }
    }

    void exit() {
        std::cout << "Exiting..." << std::endl;
        std::exit(0);
    }
};

int main() {

    while(true) {
        std::cout << "\nPhone Menu:\n";
        std::cout << "1. Add contact\n";
        std::cout << "2. Call contact\n";
        std::cout << "3. Send SMS\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cin >> choice;

        Phone phone;
        switch(choice) {
            case 1:
                phone.add();
                break;
            case 2:
                phone.call();
                break;
            case 3:
                phone.sms();
                break;
            case 4:
                phone.exit();
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}