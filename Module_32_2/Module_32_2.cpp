#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;
int SIZE = 6;

struct Record
{
    std::string name, surname, film, role;
};

void generate_json_file()
{
    json dictRoot;
    for(int i = 1; i< SIZE; ++i)
    {
        static int sch = 1;
        std::string numb = std::to_string(sch++);
        json film;
        film["name"] = "name " + numb;
        film["surname"] = "surname " + numb;
        film["film"]  = "film " + numb;
        film["role"] = "role " + numb;

        dictRoot["film " + std::to_string(i)] = film;
    }

    std::ofstream file ("movie_data.json");
    file << dictRoot.dump(4);
    file.close();

}


void searchActor(const std::string& actorName) {
    Record record;
    std::ifstream file("movie_data.json");
    json dict;
    file >> dict;
    for(const auto& u : dict)
    {
        if(actorName == u["name"])
        {
            record.name = u["name"];
            record.surname = u["surname"];
            record.film = u["film"];
            record.role = u["role"];
        }
    }
    std::cout << record.name << "\n" << record.surname << "\n" << record.film << "\n" << record.role << std::endl;
    file.close();
}

int main() {
    generate_json_file();

    std::string actorName;
    std::cout << "Enter actor name or surname: ";
    getline(std::cin,actorName);

    std::cout << std::endl;

    searchActor(actorName);

    return 0;
}