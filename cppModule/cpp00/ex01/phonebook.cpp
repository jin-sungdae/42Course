#include "phonebook.hpp"

void phoneBook::setName(std::string _first_name, std::string _last_name, std::string _nick_name)
{
	int strlen;

	first_name = _first_name;
	strlen = _first_name.length();
	if(_first_name.length() >= 10)
	{	
		_first_name.replace(9, 9, ".");
		_first_name.replace(10, 10, "\0");
	}
	first_name_replace = _first_name;
	last_name = _last_name;
	strlen = _last_name.length();
	if(_last_name.length() >= 10)
	{	
		_last_name.replace(9, 9, ".");
		_last_name.replace(10, 10, "\0");
	}
	last_name_replace = _last_name;
	nick_name = _nick_name;
	strlen = _nick_name.length();
	if(_nick_name.length() >= 10)
	{	
		_nick_name.replace(9, 9, ".");
		_nick_name.replace(10, 10, "\0");
	}
	nick_name_replace = _nick_name;
}
void phoneBook::setEtc1(std::string _phone_number)
{
	phone_number = _phone_number;
}
void phoneBook::setEtc2(std::string _darkest_secret)
{
	darkest_secret = _darkest_secret;
}

void phoneBook::getInfo ()
{
	std :: string _first_name;
	std :: string _last_name;
	std :: string _nick_name;
	std :: string _phone_number;
	std :: string _darkest_secret;

	std::cout << CYN << "firt_name :" << NC;
	std::cin >> _first_name;
	std::cout << CYN << "last_name :" << NC ;
	std::cin >> _last_name;
	std::cout << CYN << "nick_name :" << NC;
	std::cin >> _nick_name;
	std::cout << CYN << "phone_number :" << NC;
	std::cin >> _phone_number;
	std::cout << CYN << "darkest_secret :" << NC;
	std::cin >> _darkest_secret;
	setName(_first_name,_last_name,_nick_name);
	setEtc1(_phone_number);
	setEtc2(_darkest_secret);
}

void phoneBook::showsubInfo()
{
	std::cout << std::setw(10) << std::right << GRN << index << "|";
	std::cout << std::setw(10) << std::right << first_name_replace << "|";
	std::cout << std::setw(10) << std::right << last_name_replace << "|";
	std::cout << std::setw(10) << std::right << nick_name_replace << "|" << NC <<std::endl;
}

void phoneBook::setIndex(int i)
{
	index = i;
}

void phoneBook::showInfo()
{
	std::cout << GRN << "first name = "  << first_name << std::endl;
	std::cout << "last name = " <<  last_name << std::endl;
	std::cout << "nick name = " <<  nick_name << std::endl;
	std::cout << "phone number = " <<  phone_number << std::endl;
	std::cout << "darkest secrete = " <<  darkest_secret << NC << std::endl;
}

std::string phoneBook::get0(){return first_name;}
std::string phoneBook::get1(){return last_name;}
std::string phoneBook::get2(){return nick_name;}
std::string phoneBook::get3(){return phone_number;}
std::string phoneBook::get4(){return darkest_secret;}
