#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	try{
		Form a("a1", 0, 1);
		std::cout << a << std::endl;
	}catch(std::exception &e){
		std::cout << "a1 execption " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		Form a("a2", 1, 0);
		std::cout << a;
	} catch (std::exception &e){
		std::cout << "a2 execption " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		Form a("a3", 1, 151);
		std::cout << a;
	} catch (std::exception &e){
		std::cout << "a3 execption " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		Form a("a4", 151, 1);
		std::cout << a;
	} catch (std::exception &e){
		std::cout << "a4 execption " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		Bureaucrat jin = Bureaucrat("jin", 1);
		Form f("a1", 150, 150);

		std::cout << f << std::endl;
		jin.signForm(f);
		std::cout << f << std::endl;
		jin.executeForm(f);
		std::cout << f << std::endl;
	} catch (std::exception &e){
		std::cout << "jin execption " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try{
		Bureaucrat jon = Bureaucrat("jon", 150);
		Form f("a2", 1, 1);
		std::cout << f << std::endl;
		jon.signForm(f);
		std::cout<< f << std::endl;
		jon.executeForm(f);
		std::cout << f << std::endl;
	} catch (std::exception &e){
		std::cout << "jon execption " << e.what() << std::endl;
	}

	std::cout << std::endl;
	


}