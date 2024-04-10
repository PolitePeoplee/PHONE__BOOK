#include "user.h"
PHONE_BOOK::PHONE_BOOK()
	{
		first_name = new char[50];
		last_name = new char[50];
		father_s_name = new char[50];
		phone_number = new char[11];
	}
PHONE__BOOK::write_to_file() //метод для записи в файл
	{
		ofstream out("Phone__book.txt", ios::app);
		if (out.is_open())
		{
			out << "==============================================" << endl;
			out << "Данные пользователя::" << endl;
			out << last_name << " " << first_name << " " << father_s_name << endl;
			out << "+7" << phone_number << endl;
			out << "==============================================" << endl;
			out.close();
		}
		else
			cout << "Не удалось открыть файл" << endl;
	}

PHONE_BOOK::enter_fio() //метод для ввода фио
	{
		cout << "Введите Вашу фамилию:" << " ";

		while (true)
		{
			cin >> last_name;
			if (only_letters(last_name) == false)
			{
				cout << "Фамилия введена некорректно." << endl << "Повторите попытку ввода: ";
				delete[] last_name;
			}
			else
			{
				break;
			}
			last_name = new char[50];
		}

		cout << "Введите Ваше имя:" << " ";
		while (true)
		{
			cin >> first_name;
			if (only_letters(first_name) == false)
			{
				cout << "Имя введено некорректно." << endl << "Повторите попытку ввода: ";
				delete[] first_name;
			}
			else
			{
				break;
			}
			first_name = new char[50];
		}
		cout << "Введите Ваше отчество:" << " ";
		while (true)
		{
			cin >> father_s_name;
			if (only_letters(father_s_name) == false)
			{
				cout << "Отчество введено некорректно." << endl << "Повторите попытку ввода: ";
				delete[] father_s_name;
			}
			else
			{
				break;
			}
			father_s_name = new char[50];
		}
	}

PHONE_BOOK::enter_number() //метод для ввода номера
	{
		do
		{
			cout << "Введите Ваш номер телефона (10 цифр): +7";
			cin >> phone_number;
			if (only_digits(phone_number) == false)
			{
				cout << "Некорректный ввод номера." << endl << "Повторите попытку ввода:" << endl;
			}
			else
			{
				cout << "Пользователь записан." << endl;
			}
		} while (strlen(phone_number) != 10);
	}


	PHONE_BOOK::enter_find_word()
	{
		cout << "Введите ФИО пользователя, которого хотите найти: ";
		getline(cin, find_family);
		showuserdata(found(find_family));
	}

PHONE_BOOK::~PHONE_BOOK() //деструктор
	{
		delete[] first_name;
		delete[] last_name;
		delete[] father_s_name;
		delete[] phone_number;
	}
