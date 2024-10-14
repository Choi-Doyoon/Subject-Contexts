#include<iostream>
#include "bag.h"
using namespace std;
using namespace BAG;

void check_ages(bag& ages)
{
	int user_input;
	cout << "Type those ages again. Press return after each age:" << endl;
	while (ages.size() > 0)
	{
		cin >> user_input;
		if (ages.erase_one(user_input))
		{
			cout << "Yes. I've found that age and removed it." << endl;
		}
		else
		{
			cout << "No, that age does not occur!" << endl;
		}
	}
}

void get_ages(bag& ages)
{
	int user_input;
	cout << "Type the ages in your family." << endl;
	cout << "Type a negative number when you are done:" << endl;
	cin >> user_input;
	while (user_input >= 0)
	{
		if (ages.size() < ages.CAPACITY)
		{
			ages.insert(user_input);
		}
		else
		{
			cout << "I have run out of room and can't add that age." << endl;
		}
		cin >> user_input;
	}
}
int main()
{
	bag ages;

	get_ages(ages);
	check_ages(ages);
	cout << "The bag is empty." << endl;
	return EXIT_SUCCESS;
}