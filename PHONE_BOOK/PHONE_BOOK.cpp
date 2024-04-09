#include "name.h"
#include "user.h"
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
