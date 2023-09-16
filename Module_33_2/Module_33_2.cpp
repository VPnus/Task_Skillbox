#include <iostream>
#include <cstdlib>
#include <ctime>

class Fish {};
class Boot {};

struct Sector {
    Fish* fish = nullptr;
    Boot* boot = nullptr;
};

void throwFishingRod(Sector* field) {
    int sector;
    std::cout << "Enter the sector number to throw the fishing rod: ";
    std::cin >> sector;

    if (field[sector].fish != nullptr) {
        throw Fish();
    }

    if (field[sector].boot != nullptr) {
        throw Boot();
    }
}

int main() {
    std::srand(std::time(nullptr));

    Sector field[9];

    // Generate random fish and boots placement
    int fishSector = std::rand() % 9;
    field[fishSector].fish = new Fish();

    int bootSector1, bootSector2, bootSector3;
    do {
        bootSector1 = std::rand() % 9;
        bootSector2 = std::rand() % 9;
        bootSector3 = std::rand() % 9;
    } while (bootSector1 == fishSector || bootSector2 == fishSector ||
             bootSector3 == fishSector || bootSector1 == bootSector2 ||
             bootSector1 == bootSector3 || bootSector2 == bootSector3);

    field[bootSector1].boot = new Boot();
    field[bootSector2].boot = new Boot();
    field[bootSector3].boot = new Boot();

    int attempts = 0;
    try {
        while (true) {
            throwFishingRod(field);
            attempts++;
        }
    } catch (Fish&) {
        std::cout << "Congratulations! You've caught the fish in " << attempts << " attempts." << std::endl;
    } catch (Boot&) {
        std::cout << "Oops! You've caught a boot. Better luck next time!" << std::endl;
    }

    // Clean up memory
    delete field[fishSector].fish;
    delete field[bootSector1].boot;
    delete field[bootSector2].boot;
    delete field[bootSector3].boot;

    return 0;
}