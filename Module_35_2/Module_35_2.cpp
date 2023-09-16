#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>


int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 3, 2, 5 };

    auto lambda= [] (const std::vector<int>& numbers) {
        std::unordered_set<int> uniqueNumbers;
        std::unique_ptr<std::vector<int>> result = std::make_unique<std::vector<int>>();

        for (const auto& number : numbers) {
            if (uniqueNumbers.find(number) == uniqueNumbers.end()) {
                uniqueNumbers.insert(number);
                result->push_back(number);
            }
        }

        return result;
    };


    std::unique_ptr<std::vector<int>> uniqueNumbers = lambda(numbers);


    for (const auto& number : *uniqueNumbers) {
        std::cout << number << " ";
    }

    return 0;
}

