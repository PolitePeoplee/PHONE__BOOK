#include"test.h"
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
