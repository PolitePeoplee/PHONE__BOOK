#include "name.h"
vector<int> found(string find_name)
{
	string text_read;
	ifstream reader("Phone__book.txt");
	vector<int> strnum;
	int i = 0;
	while (getline(reader, text_read))
	{
		if (text_read == find_name)
		{
			strnum.push_back(i);
		}
		i += 1;
	}
	return strnum;
}
void showuserdata(vector<int> nums)//если i соотв одному из номеров строк, то вывод. Далее счит с некст строки, если пред строка подход, то выводит номер телефона
{
	string text_read;
	ifstream reader("Phone__book.txt");
	int i = 0;
	while (getline(reader, text_read))
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if (i - 1 == nums[j])
				cout << "Номер телефона пользователя: " << text_read << std::endl;
			if (i == nums[j])
			{
				cout << "ФИО пользователя: " << text_read << endl;
			}
		}
		i++;
	}
}
bool only_digits(const char* phone_number) //ф-я проверки на отсутствие букв в номере телефона
{

	for (int i = 0; i < strlen(phone_number); i++)
	{
		if (!isdigit(phone_number[i]))
		{
			return false;
		}
	}
	return true;
}
bool only_letters(const char* name) //ф-я проверки на отсутствие цифр в фио
{
	for (int i = 0; i < strlen(name); i++)
	{
		if (!isalpha(name[i]) && name[i] != ' ' && name[i] != '\'')
		{
			return false;
		}
	}
	return true;
}
