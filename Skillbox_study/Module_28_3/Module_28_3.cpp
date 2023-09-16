#include <iostream>
#include <mutex>
#include <thread>

std::mutex kitchen_mutex;
const int MAX_ORDERS = 10;
static int orders_count = 0, order_delivery = 0;

void waiter_thread()
{
    while (orders_count < MAX_ORDERS) {
        int order = rand() % 5; // сгенерировать случайный заказ
        switch (order) {
            case 0:
                std::cout << "Garcon: pizza order\n";
                break;
            case 1:
                std::cout << "Garcon: soup order\n";
                break;
            case 2:
                std::cout << "Garcon: steak order\n";
                break;
            case 3:
                std::cout << "Garcon: salat order\n";
                break;
            case 4:
                std::cout << "Garcon: sushi order\n";
                break;
        }
        kitchen_mutex.lock();
        orders_count++;
        kitchen_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 6 + 5)); // подождать от 5 до 10 секунд
    }
}

void kitchen_thread()
{
    while (orders_count < MAX_ORDERS)
    {
        kitchen_mutex.lock(); // захватить мьютекс для доступа к кухне
        if (orders_count > 0)
        {
            orders_count--;
            std::cout << "Kitchen: the order is prepared\n";
        }
        kitchen_mutex.unlock(); // освободить мьютекс
        std::this_thread::sleep_for(std::chrono::seconds(rand() % 11 + 5)); // подождать от 5 до 15 секунд
    }
}

void courier_thread ()
{
    while (order_delivery < MAX_ORDERS)
    {
        kitchen_mutex.lock(); // захватить мьютекс для доступа к кухне
        if (orders_count > 0)
        {
            orders_count--;
            order_delivery++;
            std::cout << "Courier: the order has been delivered\n";
        }
        kitchen_mutex.unlock(); // освободить мьютекс
        std::this_thread::sleep_for(std::chrono::seconds(30)); // подождать 30 секунд
    }
}

int main() {
    srand(time(nullptr));

    std::thread waiter(waiter_thread);
    std::thread kitchen(kitchen_thread);
    std::thread courier(courier_thread);

    waiter.join();
    kitchen.join();
    courier.join();


    std::cout << "Create order: " << orders_count;
    std::cout << "Delivery order: " <<  order_delivery;
    return 0;
}
