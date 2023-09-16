#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
int filmQuantity = 6;

int main() {
   json dictRoot;
   for(int i = 1; i < filmQuantity; i++) {
       static int sch = 1, sch1 = 2;
       std::string name = std::to_string(sch++), name_role = std::to_string(sch1++);
       json movieData;
       movieData["title"] = "Name film " + name;
       movieData["country"] = "Country create film "  + name;
       movieData["release_date"] = "Date create film "  + name;
       movieData["studio"] = "Studio, who conducted the shooting "  + name;
       movieData["screenwriter"] = "Author script "  + name;
       movieData["director"] = "Film regisseur "  + name;
       movieData["producer"] = "Film producer "  + name;


       json cast;
       json actor1, actor2;
       actor1["name"] = "Name actor " + name;
       actor1["character"] = "Name role " + name_role;

       cast.push_back(actor1);

       movieData["cast"] = cast;
       dictRoot["film " + std::to_string(i)] = movieData;
   }




    std::ofstream outputFile("movie_data.json");
    outputFile << dictRoot.dump(4);
    outputFile.close();

    std::cout << "JSON-the document has been successfully created and written to a file movie_data.json" << std::endl;

    return 0;
}