#include "ngraph.h"

namespace avhw13
{
    Ngraph::Ngraph() { for (size_t i = 0; i < SIZE; i++) { for (size_t j = 0; j < SIZE; j++) { matrix[i][j] = false; } } }

    void Ngraph::addUser(std::string name) { users.insert({ getNextId(),name }); }

    void Ngraph::addLink(size_t id1, size_t id2)
    {
        matrix[id1][id2] = true;
        matrix[id2][id1] = true;
    }

    void Ngraph::delUser(size_t id)
    {
        for (size_t i = 0; i < SIZE; i++) { delLink(i, id); }
        users.erase(id);
    }

    void Ngraph::delLink(size_t id1, size_t id2)
    {
        matrix[id1][id2] = false;
        matrix[id2][id1] = false;
    }

    std::string Ngraph::getNameById(size_t id) { return users.count(id) ? users.at(id) : std::string{}; }

    std::stringstream Ngraph::show3stepConnected()
    {
        std::stringstream ss;
        // проверка, что количество пользователей больше 1
        if (users.size() < 2)
        {
            ss << "\nНедостаточное количество пользователей" << std::endl;
            return ss;
        }

        // вычисление матрицы 3-х ступенчатых связей
        bool matrix3s[SIZE][SIZE];
        size_t idmax = users.rbegin()->first;   // получение ключа последнего элемента массива пользователей
        // копирование матрицы прямых связей
        for (size_t id1 = 0; id1 <= idmax; id1++)
        {
            matrix3s[id1][id1] = false;
            for (size_t id2 = id1 + 1; id2 <= idmax; id2++)
            {
                bool v = matrix[id1][id2];
                matrix3s[id1][id2] = v;
                matrix3s[id2][id1] = v;
            }
        }
        // фиксация 2-х ступенчатых связей
        for (size_t id1 = 0; id1 <= idmax; id1++)
        {
            for (size_t id2 = id1 + 1; id2 <= idmax; id2++)
            {
                if (matrix3s[id1][id2])
                {
                    for (size_t i = 0; i <= idmax; i++)
                    {
                        if (i != id1 && i != id2 && matrix[id2][i])
                        {
                            matrix3s[id1][i] = true;
                            matrix3s[i][id1] = true;
                        }
                    }

                }
            }
        }
        // фиксация 3-х ступенчатых связей
        for (size_t id1 = 0; id1 <= idmax; id1++)
        {
            for (size_t id2 = id1 + 1; id2 <= idmax; id2++)
            {
                if (matrix3s[id1][id2])
                {
                    for (size_t i = 0; i <= idmax; i++)
                    {
                        if (i != id1 && i != id2 && matrix[id2][i])
                        {
                            matrix3s[id1][i] = true;
                            matrix3s[i][id1] = true;
                        }
                    }

                }
            }
        }

        // вывод списка пар пользователей, имеющих связи в пределах 3-х ступеней
        for (size_t id1 = 0; id1 <= idmax; id1++)
        {
            for (size_t id2 = id1 + 1; id2 <= idmax; id2++)
            {
                if(matrix3s[id1][id2]) ss << "\n" << getNameById(id1) << " - " << getNameById(id2);
            }
        }

        ss << std::endl;
        return ss;
    }

    bool Ngraph::areLinked(size_t id1, size_t id2) { return matrix[id1][id2] == true; }

    bool Ngraph::userExists(size_t id) { return users.count(id) == 1; }

    size_t Ngraph::getNextId()
    {
        bool id_ok;
        size_t id = 0;
        for (; id < SIZE; id++)
        {
            id_ok = true;
            for (const auto& entry : users)
            {
                if (entry.first == id)
                {
                    id_ok = false;
                    break;
                }
            }
            if (id_ok) break;
        }
        if (!id_ok) throw std::out_of_range("превышено предельное количество пользователей");
        return id;
    }

}