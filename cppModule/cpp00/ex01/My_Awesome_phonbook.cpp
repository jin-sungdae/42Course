#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>

class example{
private:
	int index;
	std :: string first_name;
	std :: string last_name;
	std :: string nick_name;
	std :: string login;
	std :: string postal_address;
	std :: string email_address;
	std :: string phone_number;
	std :: string birthday_date;
	std :: string favorite_meal;
	std :: string underwear_color;
	std :: string darkest_secret;
public:
	void setInfo(std::string first_name, std::string  last_name, std::string nick_name,
	std::string login, std::string postal_address, std::string email_address, std::string phone_number,
	std::string birthday_date, std::string favorite_meal, std::string underwear_color, std::string darkest_secret);
	void showInfo();
	void showsubInfo();
	void setIndex(int i);
	void getInfo();
	void setPhoneNumber(std::string num);
	void setfirstandfive(std::string _first_name, std::string _last_name, std::string _nick_name,
		std::string _login, std::string _postal_address);
	void setsixandeight(std::string _email_address, std::string _phone_number, std::string birthday_date);
	void setnineandele(std::string _favorite_meal, std::string _underwear_color, std::string darkest_secret);
};

void example::setfirstandfive(std::string _first_name, std::string _last_name, std::string _nick_name,
		std::string _login, std::string _postal_address)
{
	int strlen;

	strlen = _first_name.length();
	if(_first_name.length() > 10)
	{	
		_first_name.replace(10, 10, ".");
		_first_name.replace(11, strlen, "\0");
	}
	first_name = _first_name;
	strlen = _last_name.length();
	if(_last_name.length() > 10)
	{	
		_last_name.replace(10, 10, ".");
		_last_name.replace(11, strlen, "\0");
	}
	last_name = _last_name;
	strlen = _nick_name.length();
	if(_nick_name.length() > 10)
	{	
		_nick_name.replace(10, 10, ".");
		_nick_name.replace(11, strlen, "\0");
	}
	nick_name = _nick_name;
	strlen = _login.length();
	if(_login.length() > 10)
	{	
		_login.replace(10, 10, ".");
		_login.replace(11, strlen, "\0");
	}
	login = _login;
	strlen = _postal_address.length();
	if(_postal_address.length() > 10)
	{	
		_postal_address.replace(10, 10, ".");
		_postal_address.replace(11, strlen, "\0");
	}
	postal_address = _postal_address;
}

void example::setsixandeight(std::string _email_address, std::string _phone_number, std::string _birthday_date)
{
	int strlen;

	strlen = _email_address.length();
	if(_email_address.length() > 10)
	{	
		_email_address.replace(10, 10, ".");
		_email_address.replace(11, strlen, "\0");
	}
	email_address = _email_address;
	strlen = _phone_number.length();
	if(_phone_number.length() > 10)
	{	
		_phone_number.replace(10, 10, ".");
		_phone_number.replace(11, strlen, "\0");
	}
	phone_number = _phone_number;
	strlen = _birthday_date.length();
	if(_birthday_date.length() > 10)
	{	
		_birthday_date.replace(10, 10, ".");
		_birthday_date.replace(11, strlen, "\0");
	}
	birthday_date = _birthday_date;
}

void example::setnineandele(std::string _favorite_meal, std::string _underwear_color, std::string _darkest_secret)
{
	int strlen;

	strlen = _favorite_meal.length();
	if(_favorite_meal.length() > 10)
	{	
		_favorite_meal.replace(10, 10, ".");
		_favorite_meal.replace(11, strlen, "\0");
	}
	favorite_meal = _favorite_meal;
	strlen = _underwear_color.length();
	if(_underwear_color.length() > 10)
	{	
		_underwear_color.replace(10, 10, ".");
		_underwear_color.replace(11, strlen, "\0");
	}
	underwear_color = _underwear_color;
	strlen = _darkest_secret.length();
	if(_darkest_secret.length() > 10)
	{	
		_darkest_secret.replace(10, 10, ".");
		_darkest_secret.replace(11, strlen, "\0");
	}
	darkest_secret = _darkest_secret;
}

void example::setPhoneNumber(std::string num)
{
	int strlen;

	strlen = num.length();
	if(num.length() > 10)
	{	
		num.replace(10, 10, ".");
		num.replace(11, strlen, "\0");
	}
	phone_number = num;
}

void example::getInfo ()
{
	std :: string _first_name;
	std :: string _last_name;
	std :: string _nick_name;
	std :: string _login;
	std :: string _postal_address;
	std :: string _email_address;
	std :: string _phone_number;
	std :: string _birthday_date;
	std :: string _favorite_meal;
	std :: string _underwear_color;
	std :: string _darkest_secret;
	
	std::cout << "firt_name :";
	std::cin >> _first_name;
	std::cout << "last_name :";
	std::cin >> _last_name;
	std::cout << "nick_name :";
	std::cin >> _nick_name;
	std::cout << "login :";
	std::cin >> _login;
	std::cout << "postal_address :";
	std::cin >> _postal_address;
	std::cout << "email_address :";
	std::cin >> _email_address;
	std::cout << "phone_number :";
	std::cin >> _phone_number;
	std::cout << "birthday_date :";
	std::cin >> _birthday_date;
	std::cout << "favorite_meal :";
	std::cin >> _favorite_meal;
	std::cout << "underwear_color :";
	std::cin >> _underwear_color;
	std::cout << "darkest_secret :";
	std::cin >> _darkest_secret;
	setfirstandfive(_first_name,_last_name,_nick_name,_login,_postal_address);
	setsixandeight(_email_address, _phone_number, _birthday_date);
	setnineandele(_favorite_meal, _underwear_color, _darkest_secret);
}

void example::showsubInfo()
{
	std::cout << std::setw(10) << std::right << index << "|";
	std::cout << std::setw(10) << std::right << first_name << "|";
	std::cout << std::setw(10) << std::right << last_name << "|";
	std::cout << std::setw(10) << std::right << nick_name << "|" << std::endl;
}

void example::setIndex(int i)
{
	index = i;
}

int add_function(example ex[], int i)
{
	std::cout << "push info" << std::endl;
	ex[i].setIndex(i);
	ex[i].getInfo();
	std::cout << "END" << std::endl;
	return (1);
}

void example::showInfo()
{
	std::cout << "first name = " <<  first_name << std::endl;
	std::cout << "last name = " <<  last_name << std::endl;
	std::cout << "nick name = " <<  nick_name << std::endl;
	std::cout << "login = " <<  login << std::endl;
	std::cout << "postal address = " <<  postal_address << std::endl;
	std::cout << "email address = " <<  email_address << std::endl;
	std::cout << "phone number = " <<  phone_number << std::endl;
	std::cout << "birthday date = " <<  birthday_date << std::endl;
	std::cout << "favorite meal = " <<  favorite_meal << std::endl;
	std::cout << "underwear color = " <<  underwear_color << std::endl;
	std::cout << "darkest secrete = " <<  darkest_secret << std::endl;

}

static bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


void search_function(example ex[], int i)
{
	int j;
	std::string num;
	bool check;
	check = false;
	j = 0;
	while (j < i)
		ex[j++].showsubInfo();
	j = 0;
	while(!check)
	{
		std::cout << "press index : ";
		//std::cin >> j;
		std::getline(std::cin, num);
		std::stringstream geek(num);
		geek >> j;
		if (!is_number(num))
		{
			std::cout << "index not" << std::endl;
			//j = 0;
		}
		else
			check = true;
		
	}
	ex[j].showInfo();
}

int main()
{
	std :: string oper;
	example ex[8];
	int i;

	i = 0;
	while (1)
	{
		std :: cin >> oper;
		if (oper == "SEARCH")
			search_function(ex, i);
		else if (oper == "ADD")
			i += add_function(ex,i);
		else if (oper == "EXIT")
			break;
	}
	return (0);
}