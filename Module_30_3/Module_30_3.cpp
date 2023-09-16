#include <iostream>
#include <cpr/cpr.h>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::string> arguments;

    std::string argName; //Название
    std::string argValue; //Значение

    //Заполнение карты параметрами ввода и ключевые условия ввода запросов http для выхода из цикла
    while (true) {
        std::cout << "Enter the name of the argument (or post/get to send): ";
        std::cin >> argName;

        if (argName == "post" || argName == "get") {
            break;
        }

        std::cout << "Enter the value of the argument: ";
        std::cin >> argValue;
        arguments.insert({argName, argValue});
    }

    //Конструктор для инициализации в pair
    std::map<std::string, std::string>::iterator it;
    std::vector<cpr::Pair> pairs;
    for (it = arguments.begin(); it != arguments.end(); it++) {
        pairs.push_back(cpr::Pair((std::string)it->first, (std::string)it->second));
    }

    //Условия обращения к запросам http - get/post
    if (argName == "post") {
        cpr::Payload payload (pairs.begin(), pairs.end());
        auto response = cpr::Post(cpr::Url("https://httpbin.org/post"), payload);
        std::cout << "Server Response (POST): " << response.text << std::endl;
    } else if (argName == "get") {
        std::string url = "https://httpbin.org/get?";
        for (const auto& argument : arguments) {
            url += argument.first + "=" + argument.second + "&";
        }
        auto response = cpr::Get(cpr::Url(url));
        std::cout << "Server Response (GET): " << response.text << std::endl;
    }

    return 0;
}