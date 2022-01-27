#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(){
	const Animal * meta = new Animal();
	const Animal * j = new Dog();
	const Animal * i = new Cat();

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	

	const WrongAnimal * meta1 = new WrongAnimal();
	const WrongAnimal * i1 = new WrongCat();

	std::cout << i1->getType() << " " << std::endl;
	i1->makeSound();
	meta1->makeSound();	
}