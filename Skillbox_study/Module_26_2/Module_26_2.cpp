#include <iostream>
#include <map>

class PhoneNumber
{
private:
    std::string number;

public:
    PhoneNumber(std::string number) {
        if (number.length() == 12 && number[0] == '+' && number[1] == '7') {
            this->number = number;
        }
        else {
            this->number = "";
        }
    }
    std::string getNumber() {
        return number;
    }

};

class AddressBook
{
private:
    std::map<std::string, std::string> contacts;

public:
    void addEntry(std::string name, std::string number) {
        PhoneNumber phoneNumber(number);
        std::string phone = phoneNumber.getNumber();
        if (phone != "") {
            contacts[name] = phone;
        }
    }
    void call(std::string nameOrNumber) {
        if (contacts.find(nameOrNumber) != contacts.end()) {
            std::cout << "CALL " << contacts[nameOrNumber] << std::endl;
        }
        else {
            PhoneNumber phoneNumber(nameOrNumber);
            std::string phone = phoneNumber.getNumber();
            if (phone != "") {
                std::cout << "CALL " << phone << std::endl;
            }
            else {
                std::cout << "Invalid phone number or contact name!" << std::endl;
            }
        }
    }
    void sendSMS(std::string nameOrNumber, std::string message) {
        if (contacts.find(nameOrNumber) != contacts.end()) {
            std::cout << "Sending SMS to " << contacts[nameOrNumber] << ": " << message << std::endl;
        }
        else {
            PhoneNumber phoneNumber(nameOrNumber);
            std::string phone = phoneNumber.getNumber();
            if (phone != "") {
                std::cout << "Sending SMS to " << phone << ": " << message << std::endl;
            }
            else {
                std::cout << "Invalid phone number or contact name!" << std::endl;
            }
        }
    }
};

int main() {
    AddressBook addressBook;
    std::string command;
    while (true) {
        std::cout << "Enter command (add, call, sms, exit): ";
        std::cin >> command;
        if (command == "add") {
            std::string name, number;
            std::cout << "Enter name and phone number: ";
            std::cin >> name >> number;
            addressBook.addEntry(name, number);
        }
        else if (command == "call") {
            std::string nameOrNumber;
            std::cout << "Enter name or phone number: ";
            std::cin >> nameOrNumber;
            addressBook.call(nameOrNumber);
        }
        else if (command == "sms") {
            std::string nameOrNumber, message;
            std::cout << "Enter name or phone number and message: ";
            std::cin >> nameOrNumber >> message;
            addressBook.sendSMS(nameOrNumber, message);
        }
        else if (command == "exit") {
            break;
        }
    }
    return 0;
}
