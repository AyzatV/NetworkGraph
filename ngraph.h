#pragma once
#include <map>
#include <sstream>
#include <iostream>
#include <Windows.h>

#define SIZE 20 // ������������ ������ ���� (���������� �������������)

namespace avhw13
{
    class Ngraph
    {
    public:
        Ngraph();
        // ���������� ������������
        void addUser(std::string name);
        // ���������� ������ �����
        void addLink(size_t id1, size_t id2);
        // �������� ������������
        void delUser(size_t id);
        // �������� ������ �����
        void delLink(size_t id1, size_t id2);
        // ��������� ����� �� id
        std::string getNameById(size_t id);
        // ����� � ����� ��� ������������� � �������� 3-� ����������� ������
        std::stringstream show3stepConnected();
    private:
        bool areLinked(size_t id1, size_t id2);
        bool userExists(size_t id);
        size_t getNextId();                 // ��������� ���������� ���������� id ������������

        bool matrix[SIZE][SIZE];            // ������� ������ ������
        std::map<size_t, std::string> users;// ������������� ������ �������������
    };
}