#include <iostream>
#include <string>
#include <exception>
#include <map>

typedef std::map<std::string, int> Database;

class Cart {
private:
    Database database;
public:
    void addToCart(const std::string& article, int quantity) {
        if (database.find(article) == database.end()) {
            throw std::invalid_argument("Article not found in the database");
        }
        if (quantity > database[article]) {
            throw std::invalid_argument("Quantity exceeds available stock");
        }
    }

    void removeFromCart(const std::string& article, int quantity) {
        if (database.find(article) == database.end()) {
            throw std::invalid_argument("Article not found in the database");
        }

    }
};

int main() {
    Database database;

    Cart cart;

    try {
        cart.addToCart("article1", 3);
        cart.removeFromCart("article1", 2);
        cart.addToCart("article2", 5);
        cart.removeFromCart("article2", 10);
    } catch (std::exception& e) {
        std::cout << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}