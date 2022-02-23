#ifndef PHONEBOOK
#define PHONEBOOK

#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class phoneBook{
private:
	int index;
	std :: string first_name;
	std :: string first_name_replace;
	std :: string last_name;
	std :: string last_name_replace;
	std :: string nick_name;
	std :: string nick_name_replace;
	std :: string phone_number;
	std :: string darkest_secret;
public:
	void setInfo(std::string first_name, std::string  last_name, std::string nick_name,
	 std::string phone_number, std::string darkest_secret);
	void showInfo();
	void showsubInfo();
	void setIndex(int i);
	void getInfo();
	void setPhoneNumber(std::string num);
	void setName(std::string _first_name, std::string _last_name, std::string _nick_name);
	void setEtc1(std::string _phone_number);
	void setEtc2(std::string _darkest_secret);
	std::string get0();
	std::string get1();
	std::string get2();
	std::string get3();
	std::string get4();
};

#endif