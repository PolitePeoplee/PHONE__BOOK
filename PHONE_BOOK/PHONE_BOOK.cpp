#include "user.h"
#include "test.h"
using namespace std;


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
