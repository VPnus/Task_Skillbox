#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class Elf {
public:
    std::string name;
    std::string position;
    Elf(std::string _name, std::string _pos) : name(_name), position(_pos) {}
};

class Branch {
public:
    std::vector<Elf> elves;
    std::vector<Branch> branches;
    Branch* parent;
    Branch(Branch* _parent) : parent(_parent) {}

    // Рекурсивная функция поиска ветки по пути
    Branch* findBranch(std::vector<int> path) {
        if (path.empty()) return this;
        int current = path.front();
        path.erase(path.begin());
        return branches[current].findBranch(path);
    }

    // Функция, которая возвращает true, если эльф имеет указанное имя
    static bool elfNameIs(Elf elf, std::string name) {
        return elf.name == name;
    }

    // Функция, которая находит ветку, в которой находится указанный эльф
    Branch* findElfBranch(std::string name) {
        auto it = std::find_if(elves.begin(), elves.end(), [&](Elf elf) {
            return elfNameIs(elf, name);
        });
        if (it != elves.end()) return this;
        for (auto& b : branches) {
            Branch* found = b.findElfBranch(name);
            if (found != nullptr) {
                return found;
            }
        }
        return nullptr;
    }

    // Функция, которая находит количество эльфов, живущих на одной ветке, что и указанный эльф
    int countNeighbors(std::string name) {
        Branch* targetBranch = findElfBranch(name);
        if (targetBranch == nullptr) return 0;
        int count = 0;
        for (auto& branch : targetBranch->branches) {
            if (&branch != targetBranch) {
                count += branch.elves.size();
            }
        }
        return count;
    }
};



int main() {
    srand(time(0));
    std::vector<Branch> trees(5, Branch(nullptr));
    for (auto& tree : trees) {
        int bigCount = rand() % 3 + 3;
        for (int i = 0; i < bigCount; i++) {
            int midCount = rand() % 2 + 2;
            Branch bigBranch(&tree);
            for (int j = 0; j < midCount; j++) {
                Branch midBranch(&bigBranch);
                bigBranch.branches.push_back(midBranch);
            }
            tree.branches.push_back(bigBranch);
        }
    }

    for (auto& tree : trees) {
        std::cout << "Tree" << std::endl;
        for (auto& branch : tree.branches) {
            std::cout << "\tBig branch" << std::endl;
                for (int i = 1; i <= 1; i++) {
                    static int sch = 1;
                    std::string name = std::to_string(sch++);
                    if (sch%5 == 0)  // каждый пятый
                        name = "None";
                    std::cout << "\tElf " << name << std::endl;
                    if (name != "None") {
                        Elf elf(name, (i == 1 ? "Big" : "Mid"));
                        branch.elves.push_back(elf);
                    }
                }

            for (auto& midBranch : branch.branches) {
                std::cout << "\t\tMid branch" << std::endl;
                for (int i = 1; i <= 1; i++) {
                    static int sch = 1;
                    std::string name = std::to_string(sch++);
                    if (sch%5 == 0)  // каждый пятый
                        name = "None";
                    std::cout << "\t\t\tElf " << name << std::endl;
                    if (name != "None") {
                        Elf elf(name, (i == 1 ? "Big" : "Mid"));
                        midBranch.elves.push_back(elf);
                    }
                }
                branch.elves.reserve(branch.elves.size() + midBranch.elves.size());
                branch.elves.insert(branch.elves.end(), midBranch.elves.begin(), midBranch.elves.end());
            }
        }
    }

    std::string name;
    std::cout << "Enter the name of the elf you want to search for: ";
    std::cin >> name;
    for (auto& tree : trees) {
        Branch* elfBranch = tree.findElfBranch(name);
        if (elfBranch != nullptr) {
            int count = elfBranch->countNeighbors(name);
            std::cout << "Number of neighbors on the same branch: " << count << std::endl;
            return 0;
        }
    }
    std::cout << "Elf not found" << std::endl;
    return 0;
}