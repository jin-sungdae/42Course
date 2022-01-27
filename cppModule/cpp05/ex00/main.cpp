#include "Bureaucrat.hpp"

int main(){
	try{
		Bureaucrat jon = Bureaucrat("jon", 1);
		
		std::cout << jon << std::endl;
		jon.decreaseGrade(10);
		std::cout << jon << std::endl;
		jon.increaseGrade(11);
		std::cout << jon << std::endl;
		jon.increaseGrade(10);
		std::cout << jon << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		Bureaucrat jin = Bureaucrat("jin", 150);
		std::cout << jin << std::endl;
		jin.increaseGrade(10);
		std::cout << jin << std::endl;
		jin.decreaseGrade(11);
		std::cout << jin << std::endl;
		jin.increaseGrade(10);
		std::cout << jin << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		Bureaucrat jan = Bureaucrat("jan" , 0);
		std::cout << jan << std::endl;
		jan.increaseGrade(1);
		std::cout << jan << std::endl;
		jan.decreaseGrade(2);
		std::cout << jan << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		Bureaucrat jun = Bureaucrat("jun", 151);
		std::cout << jun << std::endl;
		jun.decreaseGrade(1);
		std::cout << jun << std::endl;
		jun.increaseGrade(2);
		std::cout << jun << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


}