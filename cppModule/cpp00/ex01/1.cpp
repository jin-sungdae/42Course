#include <iostream>
#include <iomanip>


class example{
public:
	std :: string first_name;
	std :: string last_name;
	std :: string nick_name;
	std :: string postal_address;
	std :: string email_address;
	std :: string phone_number;
	std :: string birthday_date;
	std :: string favorite_meal;
	std :: string underwear_color;
	std :: string darkest_secret;
public:
	void getInfo();
	void showInfo();
};

void example::getInfo()
{
	std::cin >> first_name;
	std::cin >> last_name;
	std::cin >> nick_name;
	std::cin >> postal_address;
	std::cin >> email_address;
	std::cin >> phone_number;
	std::cin >> birthday_date;
	std::cin >> favorite_meal;
	std::cin >> underwear_color;
	std::cin >> darkest_secret;
}

void example::showInfo ()
{
	std::cout << first_name << std::endl;
	std::cout << last_name << std::endl;
	std::cout << nick_name << std::endl;
	std::cout << postal_address << std::endl;
	std::cout << email_address << std::endl;
	std::cout << phone_number << std::endl;
	std::cout << birthday_date << std::endl;
	std::cout << favorite_meal << std::endl;
	std::cout << underwear_color << std::endl;
	std::cout << darkest_secret << std::endl;

}

int main()
{
	//exmaple ex1;
	example ex1;
	ex1.getInfo();
	ex1.showInfo ();
	//std :: cout << "결과 = " << std :: setw(10) << "hello" << std :: endl;

}