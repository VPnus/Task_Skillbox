#include <iostream>
#include <thread>
#include <mutex>

std::mutex station_mutex;

// Прибытие на вокзал
void arrival(std::string train_name, int travel_time) {
    std::this_thread::sleep_for(std::chrono::seconds(travel_time));
    std::cout << train_name << " arrived at the station. Time: " << travel_time << std::endl;

    std::string depart;
    std::cout << train_name << " is waiting for a free spot at the station." << std::endl;
    station_mutex.lock();
    std::cerr << "Permission to enter the station is expected - depart \n";
    std::cin >> depart;
    while (depart != "depart") {
        std::cerr << "Invalid command, input again command - depart\n";
        std::cin >> depart;
    }
    std::cout << "Leaving the station: " << train_name << std::endl;
    station_mutex.unlock();
}

// Отбытия с вокзала
void departure(std::string train_name) {
    std::cout << train_name << " departed from the station." << std::endl;
    station_mutex.unlock();
}

int main() {
    // Время в пути
    int travel_time_a, travel_time_b, travel_time_c;

    std::cout << "Enter travel time for train A (in seconds): ";
    std::cin >> travel_time_a;

    std::cout << "Enter travel time for train B (in seconds): ";
    std::cin >> travel_time_b;

    std::cout << "Enter travel time for train C (in seconds): ";
    std::cin >> travel_time_c;

    // Стартуем три потока
    std::thread thread_a(arrival, "Train A", travel_time_a);
    std::thread thread_b(arrival, "Train B", travel_time_b);
    std::thread thread_c(arrival, "Train C", travel_time_c);

    // Ожидаем завершения каждого потока

    thread_a.join();
    std::cout << "Train A has visited the station." << std::endl;

    thread_b.join();
    std::cout << "Train B has visited the station." << std::endl;

    thread_c.join();
    std::cout << "Train C has visited the station.\n" << std::endl;

    // Освобождаем мьютекс после отбытия последнего поезда
    departure("Train A");
    departure("Train B");
    departure("Train C");

    return 0;
}