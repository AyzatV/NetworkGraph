#include "ngraph.h"

int main()
{
	SetConsoleOutputCP(1251);
	// �������� ����� ���� � ���������� ������������� � ������ ������
	avhw13::Ngraph ng;
	ng.addUser("����");
	ng.addUser("����");
	ng.addUser("�����");
	ng.addUser("������");
	ng.addUser("�����");
	ng.addUser("��������");
	ng.addUser("����");
	ng.addUser("����������");
	ng.addUser("����");
	ng.addUser("��������");
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
	// ����� 3-� ����������� ������
	std::cout << "������ ��� �������������, ������� ����� � �������� 3-� ��������:" << std::endl;
	std::cout << ng.show3stepConnected().str();

	std::cin.get();
	return 0;
}