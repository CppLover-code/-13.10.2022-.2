/*
    Реализовать структуру "Машина" (цвет, модель, номер). 
    Номер машины может представлять из себя или пятизначный
    номер или слово до 8 символов(номер реализовать как 
    объединение). Реализовать заполнение и вывод данных. 
    Создать массив из 10 экземпляров структуры "Машина" =>
    редактировать, вывести на экран все машины,поиск машины
    по номеру.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>
#include "colors.h"

enum struct data_type
{
    NUMBER,
    SYMBOL
};
struct car {
    std::string color;
    std::string model;
    std::string number;
};
car* arr;
int size;

void input_arr()                                                         // функция заполнения массива данными об авто
{
    std::cout << "How many cars do you want to add to the database?\n";  // кол-во характеристик машин будет записано
    std::cin >> size;

    if (size < 1) size = 1;
    arr = new car[size];                                                 // выделение памяти под массив 

    for (int i = 0; i < size; i++)                                       // заполняем массив данными
    {
        std::cout << colors::BLUE_BOLD
            << " Car number "
            << i + 1 << ".\n"
            << colors::RESET;

        std::cout << " Enter color: ";
        std::cin >> arr[i].color;

        std::cout << " Enter model: ";
        std::cin >> arr[i].model;

        std::cout << " Enter number: ";
        std::cin >> arr[i].number;
       
    }
}

void print_rec(int i)                                           // функция вывода данных массива
{
    if (size < 1) std::cout << colors::RED_BRIGHT               // если размер массива меньше 1, то массив не заполнен
        << " Car details not yet filled!"
        << colors::RESET << "\n";
    else                                                        // иначе выводим данные в консоль
    {
        std::cout << colors::BLUE_BOLD
            << " Car number "
            << i + 1 << "\n"
            << colors::RESET

            << "Length           " << arr[i].color << "\n"
            << "Clearance        " << arr[i].model << "\n"
            << "Volume           " << arr[i].number << "\n\n";
    }
}

void output_arr()                                               // функция вывода данных массива на экран консоли
{
    if (size <= 0) std::cout << colors::RED_BRIGHT              // если размер массива меньше <= 0, то массив не заполнен
        << " Car details not yet filled!"
        << colors::RESET << "\n";

    else for (int i = 0; i < size; i++) print_rec(i);           // иначе выводим на экран консоли
}

int search()                                                    // функция поиска автомобиля по данным
{

    if (size < 1) std::cout << colors::RED_BRIGHT               // если размер массива меньше < 1, то массив не заполнен
        << " Car details not yet filled!"
        << colors::RESET << "\n";
    else                                                        // иначе предлагаем выбрать характеристику для поиска
    {
        int menu_s;
        std::cout << "Enter feature number to search\n"
            << "1 - color\n"
            << "2 - model\n"
            << "3 - number\n";

        std::cin >> menu_s;

        //system("pause");
        Sleep(2000);
        system("cls");
        
        std::cout << "Enter data to search\n";

        std::string data;
        std::cin >> data;                             // иначе цвет авто

        int count_s = 0;                                         // счетчик кол-ва найденных авто

        for (int i = 0; i < size; i++)
        {
            std::string temp;

            switch (menu_s)                                      // проверим выбранный пункт меню
            {                                                    // и записываем его значение в временную переменную
            case 1:
                temp = arr[i].color;
                break;
            case 2:
                temp = arr[i].model;
                break;
            case 3:
                temp = arr[i].number;
                break;
            }

            if (temp == data) /// вывод если нашлось
            {
                print_rec(i);
                count_s++;
            }
        }

        return count_s;                                            // возвращаем найденное кол-во авто
    }
    return 0;
}




int main()
{
    system("title Cars data");
    bool work = true;
    int menu;

    do
    {
        std::cout << "MENU\n"
            << "1 - add car details\n"
            << "2 - show car details\n"
            << "3 - data search\n"
            << "Any key - exit\n"
            << "Choose an option: ";
        std::cin >> menu;

        //system("pause");
        Sleep(2000);
        system("cls");

        switch (menu)                                                        // проверяем ввод пользователя
        {                                                                    // и выполняем соотв. функции и действия
        case 1:

            input_arr();
            break;

        case 2:

            output_arr();
            Sleep(2000);
            break;

        case 3:
        {
            int count = search();
            (count < 1) ? std::cout << colors::RED_BRIGHT                    // если функция search() вернула значение < 1, то
                << " Car data not found!"                // совпадений не найдено
                << colors::RESET << "\n" :

                std::cout << colors::GREEN_BRIGHT                  // иначе показываем кол-во найденных авто
                << "Total found: " << count
                << " car(s)" << colors::RESET << "\n";
            Sleep(2000);
            break;
        }

        default:

            work = false;
            break;
        }

        //system("pause");
        Sleep(2000);
        system("cls");

    } while (work);

    delete[] arr;                                                            // освобождение памяти дин. массива



    return 0;
}