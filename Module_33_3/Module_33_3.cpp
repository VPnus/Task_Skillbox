#include <iostream>
#include <vector>

template<typename KeyType, typename ValueType>
class Registry
{
private:
    struct Entry
    {
        KeyType key;
        ValueType value;
    };

    std::vector<Entry> entries;

public:
    void add(const KeyType& key, const ValueType& value)
    {
        Entry entry;
        entry.key = key;
        entry.value = value;
        entries.push_back(entry);
    }

    void remove(const KeyType& key) //Удаление по ключу
    {
        for(auto it = entries.begin(); it != entries.end();)
        {
            if(it->key == key)
            {
                it = entries.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    void print() //Вывод
    {
        for(const auto& entry : entries)
        {
            std::cout << "Key: " << entry.key << ", Value: " << entry.value << std::endl;
        }
    }

    void find(const KeyType& key) //Поиск по ключу
    {
        bool found = false;
        for(const auto& entry : entries)
        {
            if(entry.key == key)
            {
                std::cout << "Value: " << entry.value << std::endl;
                found = true;
            }
        }

        if(!found)
        {
            std::cout << "No entries found with key: " << key << std::endl;
        }
    }
};

int main()
{
    Registry<int, std::string> registry;

    std::string command;
    std::cout << "Input command: ";
    while(std::cin >> command, std::cout << "Command ")
    {

        if(command == "add")
        {
            int key;
            std::cout << "add key and value: ";
            std::string value;
            std::cin >> key >> value;
            registry.add(key, value);
        }
        else if(command == "remove")
        {
            int key;
            std::cout << "remove key: ";
            std::cin >> key;
            registry.remove(key);
        }
        else if(command == "print")
        {
            std::cout << "Print: " << std::endl;
            registry.print();
        }
        else if(command == "find")
        {
            int key;
            std::cout << "find key: ";
            std::cin >> key;
            registry.find(key);
        }
        std::cout << "Input command: ";
    }

    return 0;
}
