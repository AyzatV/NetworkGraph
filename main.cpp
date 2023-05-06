#include "ngraph.h"

int main()
{
	SetConsoleOutputCP(1251);
	// создание графа сети и добавление пользователей и прямых связей
	avhw13::Ngraph ng;
	ng.addUser("Иван");
	ng.addUser("Юлия");
	ng.addUser("Семен");
	ng.addUser("Виктор");
	ng.addUser("Елена");
	ng.addUser("Светлана");
	ng.addUser("Юлий");
	ng.addUser("Константин");
	ng.addUser("Анна");
	ng.addUser("Виктория");
	ng.addLink(0, 2);
	ng.addLink(0, 7);
	ng.addLink(1, 4);
	ng.addLink(1, 9);
	ng.addLink(2, 3);
	ng.addLink(3, 8);
	ng.addLink(4, 9);
	ng.addLink(5, 9);
	ng.addLink(6, 7);
	ng.addLink(6, 8);
	// вывод 3-х ступенчатых связей
	std::cout << "Список пар пользователей, имеющих связи в пределах 3-х ступеней:" << std::endl;
	std::cout << ng.show3stepConnected().str();

	std::cin.get();
	return 0;
}