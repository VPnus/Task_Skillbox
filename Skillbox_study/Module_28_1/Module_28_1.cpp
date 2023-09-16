#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

// Мьютекс для синхронизации вывода
std::mutex cout_mutex;


class Swimmer {
private:
    std::string name;
    float speed;
    float distance_swam;


public:
    Swimmer(std::string name_, float speed_) : name(name_), speed(speed_), distance_swam(0) {}

    // Метод для движения пловца на 1 секунду
    void swim_one_second() {
        distance_swam += speed;
    }

    std::string get_name() const {
        return name;
    }

    // Метод для получения итогового времени заплыва
    float get_final_time() const {
        return 100 / speed;
    }

    // Метод для получения расстояния, которое проплыл пловец
    float get_distance_swam() const {
        return distance_swam;
    }
};

// Функция, которую будут выполнять потоки


void swimmer_thread_func(Swimmer& swimmer, std::vector<Swimmer>&result) {
    while (swimmer.get_distance_swam() < 100) {
        swimmer.swim_one_second();
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "Swimmer: " << swimmer.get_name() << " swam by " << swimmer.get_distance_swam() << " meters" << std::endl;
    }
    result.push_back(swimmer);

}

int main() {

    srand(time(nullptr));
    std::vector<Swimmer> swimmers;
    for (int i = 1; i <= 6; ++i) {
        std::cout << "Enter name and speed swimmers (m/s) #" << i << ": ";
        static int sch = 1;
        std::string name = std::to_string(sch++);
        float speed = 1 + rand() % 10;
        swimmers.emplace_back(name, speed);
    }

    // Потоки для каждого пловца
    std::vector<std::thread> threads;
    std::vector<Swimmer>result;
    for (auto& swimmer : swimmers) {
        threads.emplace_back(swimmer_thread_func, std::ref(swimmer), std::ref(result));
    }
    // завершение всех потоков
    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Table swimmers:" << std::endl;
    for(auto i = 0; i <result.size(); i++ ) {
        std::cout << " Name " << result[i].get_name() << " seconds " << result[i].get_final_time() << '\n';
    }
    return 0;
}