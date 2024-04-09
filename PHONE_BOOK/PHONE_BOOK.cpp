#include "name.h"
//#include ""
using namespace std;

void test1()
{
	const char* test_number1 = "4444444444";
	assert(only_digits(test_number1) == true);
	const char* test_number2 = "444 555555";
	assert(only_digits(test_number2) == false);
	const char* test_number3 = "Marina";
	assert(only_digits(test_number3) == false);
	const char* test_number4 = "123";
	assert(only_digits(test_number4) == true);
}

//=================================================================================================================

void test2()
{
	const char* test_name1 = "Max Payn";
	assert(only_letters(test_name1) == true);
	const char* test_name2 = "Niki Doo";
	assert(only_letters(test_name2) == true);
	const char* test_name3 = "Marina O'Con";
	assert(only_letters(test_name3) == true);
	const char* test_name4 = "Andrey123";
	assert(only_letters(test_name4) == false);
}
//=================================================================================================================

class PHONE_BOOK
{
private:
	char* first_name;
	char* last_name;
	char* father_s_name;
	char* phone_number;
	string find_family;

public:

	PHONE_BOOK()
	{
		first_name = new char[50];
		last_name = new char[50];
		father_s_name = new char[50];
		phone_number = new char[11];
	}
	void write_to_file() //метод для записи в файл
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

	void enter_fio() //метод для ввода фио
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

	void enter_number() //метод для ввода номера
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

	void enter_find_word()
	{
		cout << "Введите ФИО пользователя, которого хотите найти: ";
		getline(cin, find_family);
		showuserdata(found(find_family));
	}

	~PHONE_BOOK() //деструктор
	{
		delete[] first_name;
		delete[] last_name;
		delete[] father_s_name;
		delete[] phone_number;
	}
};

int main()
{
	test1();
	test2();
	cout<< "tests_ok" <<endl;
	setlocale(LC_ALL, "rus");
	PHONE_BOOK myPhoneBook;
	int x;
	cout << "Нажмите 1, если хотите записать пользователя в список или 2, если хотите найти его по фамилии: ";
	cin >> x;
	cin.get();
	switch (x)
	{
	case 1:
	{
		char up;
		do
		{
			myPhoneBook.enter_fio();
			myPhoneBook.enter_number();
			myPhoneBook.write_to_file();
			cout << "Хотите добавить еще одну запись? (Y/N): ";
			cin >> up;

		} while (up == 'Y' || up == 'y');
		break;
	}
	case 2:
	{
		myPhoneBook.enter_find_word();
	}
	}
	return 0;
}
