#include "stdafx.h"
#include <iostream>	//��������� ����/�����
#include "class.h"	//��� ����� "����������� �����"
#include <fstream> //���������� ��� ������ � �������
#include <conio.h> //����������, ����� ������������� ����
using namespace std;
//������� ������� ��� �������� ��������� ��������
bool menu(char ch, const char *keys, int size)	
{
	for(int i=0;i<size ;i++ )
		if(keys[i] == ch) return true;
	return false;
}
//������� ��� ����, ����� �������� � ���� ������ �����
int getNumber()
{
	char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
	string str;
	char ch;
	while((ch = _getch()) != '\r')//���� ��������� �������� = enter
		if(menu(ch,numbers,10)) //���� ������� ������� menu �����������
		{ 
			str += ch;
			cout << ch;
		}
	cout<<endl;
	return atoi(str.c_str());	//���������� �������� ���
}

int main()
{
	setlocale(LC_ALL, "Russian");	//������������� ������� �����
	setlocale(LC_NUMERIC, "C"); //������������� ������� ����� �� ���������

	Complex a, b;	//������� 2 ���������� ������ ������ Complex
	ifstream file("input.txt"); //��������� ���� ��� ������ ������ ��������
	main1: system("CLS");	//����� ����, ����� � ������ ���� � ��� �������� � ������� �������
	cout << "������ ������� ������� ������ ��� ���������� ��������?\n"
		<< "1.  �� �����.\n"
		<< "2.  �������.\n";
	int numb = getNumber();	//���������� ������� getNumber ����� ��������� ������� �� ����� (��� ��������� ����� ��������������)
		switch(numb) //�������� �������������� ������ ��� ����
		{
			case 1: //���� ������� "�� �����"
				system("CLS");
				file >> a; //���� ������ ������ �� ����� � ���������� � a
				file >> b; //���� ������ ������ �� ����� � ���������� � b
				file.close();	//��������� ����
				break;
			case 2:	//���� ������� "�������"
				system("CLS");
				cout << "������� �������������� � ������ ����� ������� ����� ����� ������" << "\n";
				cin >> a;
				cout << "������� �������������� � ������ ����� ������� ����� ����� ������" << "\n";
				cin >> b;
				cout << "\n" << endl;
				break;
			default:
				system("CLS");
				cout << "������������ �������. �������� ������ �� ������.";
				_getch(); //������������� ���� ��� ��������� (���� �������� ������� ������� enter)
				goto main1;	//������������ � ������� ����
		}
	main2:system("CLS");
	cout << "�������� ���������� �������� � ����?\n"
		<< "1.  ��.\n"
		<< "2.  ���.\n";
	numb = getNumber();
	int k = 0; //���������� ������ ����� ������������ �� ������ ����
	ofstream fileout("output.txt"); //�������� ����� ��� ������ ��������
	switch(numb)
	{
		case 1:
			k = 1;
			break;
		case 2:
			k = 0;
			fileout.close();
			break;
		default:
			system("CLS");
			cout << "������������ �������. �������� ������ �� ������.";
			_getch();
			goto main2;
	}
	for(;;) //����������� ���� ��� ����, ����� ��������� ������������ � ���� ����
	{
		main3: system("CLS");
		cout << "1 ����������� �����" << "\n";
		cout << a << "\n";
		cout << "2 ����������� �����" << "\n";
		cout << b << "\n" << endl;	
		cout << "�������� �������� ������� ����� ���������� ��� ��������:\n"
			<< "1. ��������.\n"
			<< "2. ���������.\n"
			<< "3. ������������.\n"
			<< "4. �������.\n"
			<< "5. ������.\n"
			<< "6. �����������.\n"
			<< "7. ������������ ���������� +=, -=, *=, /=.\n"
			<< "8. ��������� ����������� �����.\n"
			<< "9. ���� ����� ��������.\n"
			<< "10. �����.\n";
		cout << ">>> ";
		numb = getNumber();
		switch(numb)
		{
			case 1:
				cout << "�����:" << "\n";
				cout << a + b << "\n" << endl;
				if(k = 1)	//���� ������������ ������ ��� ����� �������� ������ � ����, �� ���������
				{
					fileout << "�����:" << "\n";
					fileout << a + b << "\n" << endl;
				}
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 2:
				cout << "��������:" << "\n";
				cout << a - b << "\n" << endl;
				if(k = 1)
				{
					fileout << "��������:" << "\n";
					fileout << a - b << "\n" << endl;
				}
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 3:
				cout << "������������:" << "\n";
				cout << a * b << "\n" << endl;
				if(k = 1)
				{
					fileout << "������������:" << "\n";
					fileout << a * b << "\n" << endl;
				}
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 4:
				cout << "�������:" << "\n";
				cout << a / b << "\n" << endl;
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 5:
				cout << "������ 1 ������������ �����:" << "\n";
				cout << a.Abs() << "\n" << endl;
				cout << "������ 2 ������������ �����:" << "\n";
				cout << b.Abs() << "\n" << endl;
				if(k = 1)
				{
					fileout << "������ 1 ������������ �����:" << "\n";
					fileout << a.Abs() << "\n" << endl;
					fileout << "������ 2 ������������ �����:" << "\n";
					fileout << b.Abs() << "\n" << endl;
				}
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 6:
				a.Conj();//���� �����������
				cout << "����������� 1 ������������ �����:" << "\n";
				cout << a << "\n" << endl;
				b.Conj();
				cout << "����������� 2 ������������ �����:" << "\n";
				cout << b << "\n" << endl;
				if(k = 1)
				{
					fileout << "����������� 1 ������������ �����:" << "\n";
					fileout << a << "\n" << endl;
					fileout << "����������� 2 ������������ �����:" << "\n";
					fileout << b << "\n" << endl;
				}
				a.Conj(); //���������� ��� ������� ��������, ����� ������� ����������� ����� � ��������� ����
				b.Conj();
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 7:
				cout << "1 ����� += 2 �����:" << "\n";
				a += b;
				cout << a << "\n" << endl;
				if(k = 1)
				{
					fileout << "1 ����� += 2 �����:" << "\n";
					fileout << a << "\n" << endl;
				}
				cout << "��������� ���� -= 2 �����:" << "\n";
				a -= b;
				cout << a << "\n" << endl;
				if(k = 1)
				{
					fileout << "��������� ���� -= 2 �����:" << "\n";
					fileout << a << "\n" << endl;
				}
				cout << "��������� ���� *= 2 �����:" << "\n";
				a *= b;
				cout << a << "\n" << endl;
				if(k = 1)

				{
					fileout << "��������� ���� *= 2 �����:" << "\n";
					fileout << a << "\n" << endl;
				}
				cout << "��������� ���� /= 2 �����:" << "\n";
				a /= b;
				cout << a << "\n" << endl;
				if(k = 1)
				{
					fileout << "��������� ���� /= 2 �����:" << "\n";
					fileout << a << "\n" << endl;
				}
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 8:
				if(a == b)
				{
					if(k = 1) fileout << "����������� ����� �����" << "\n" << endl;
					cout << "����������� ����� �����" << "\n" << endl;
				}
				if(a != b)
				{
					if(k = 1) fileout << "����������� ����� �� �����" << "\n" << endl;
					cout << "����������� ����� �� �����" << "\n" << endl;
				}
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 9:
				system("CLS");
				cout << "������� �������������� � ������ ����� ������� ����� ����� ������" << "\n";
				cin >> a;
				cout << "������� �������������� � ������ ����� ������� ����� ����� ������" << "\n";
				cin >> b;
				cout << "\n" << endl;
				goto main3;
				cout << "��� ������ ������ ������� ������� enter" << "\n" << endl;
				_getch();
				break;
			case 10:
				exit(0);
			default:
				system("CLS");
				cout << "������������ �������. �������� ������ �� ������.";
				_getch();
				goto main3; //������� � 3 ����
		}
	}
_getch(); //������������� ����
fileout.close(); //��������� ����
return 0;
}