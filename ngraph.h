#pragma once
#include <map>
#include <sstream>
#include <iostream>
#include <Windows.h>

#define SIZE 20 // максимальный размер сети (количество пользователей)

namespace avhw13
{
    class Ngraph
    {
    public:
        Ngraph();
        // добавление пользователя
        void addUser(std::string name);
        // добавление прямой связи
        void addLink(size_t id1, size_t id2);
        // удаление пользователя
        void delUser(size_t id);
        // удаление прямой связи
        void delLink(size_t id1, size_t id2);
        // получение имени по id
        std::string getNameById(size_t id);
        // вывод в поток пар пользователей в пределах 3-х ступенчатых связей
        std::stringstream show3stepConnected();
    private:
        bool areLinked(size_t id1, size_t id2);
        bool userExists(size_t id);
        size_t getNextId();                 // получение очередного свободного id пользователя

        bool matrix[SIZE][SIZE];            // матрица прямых связей
        std::map<size_t, std::string> users;// сортированный массив пользователей
    };
}