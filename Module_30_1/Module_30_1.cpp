#include <iostream>
#include <cpr\cpr.h>

//Виртуальный класс всех HTTP команд
class Command
{
public:
    virtual void http_command () = 0;
    virtual ~Command() {}
};

// Метод запроса get
class Get : public Command
{
    void http_command ()
    {
        cpr::Response get_response = cpr::Get(cpr::Url("http://httpbin.org/headers"));
        std::cout << get_response.text << std::endl;
    }
    ~Get(){}
};

// Метод запроса Post
class Post : public Command
{
public:
    void http_command()
    {
        cpr::Response post_response = cpr::Post(cpr::Url("http://httpbin.org/post"));
        std::cout << post_response.text << std::endl;
    }
    ~Post (){}
};

//Метод запроса Put
class Put : public Command
{
public:
    void http_command()
    {
        cpr::Response put_response = cpr::Put(cpr::Url("http://httpbin.org/put"));
        std::cout << put_response.text << std::endl;
    }
    ~Put (){}
};

//Метод запроса Delete
class Delete : public Command
{
public:
    void http_command()
    {
        cpr::Response delete_response = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        std::cout << delete_response.text << std::endl;
    }
    ~Delete (){}
};

//Метод запроса Patch
class Patch : public Command
{
public:
    void http_command()
    {
        cpr::Response patch_response = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        std::cout << patch_response.text << std::endl;
    }
    ~Patch (){}
};


//Главная функция
int main() {
   std::string command;
   Command *c = new Get();
   Command *a = new Post();
   Command *o = new Put();
   Command *e = new Delete();
   Command *r = new Patch();

 do {
     std::cout << "Enter command: get/post/put/delete/patch or exit\n";
     std::cin >> command;

     // Исключения ввода
     if (command == "get") {
         c -> http_command();
     } else if (command == "post") {
         a -> http_command();
     } else if (command == "put") {
         o -> http_command();
     } else if (command == "delete") {
         e -> http_command();
     } else if (command == "patch") {
         r -> http_command();
     } else if (command == "exit")
         break;
 }while(true);


   return 0;
}
