#include <iostream>
#include "solution.h"

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;

	~Animal() 
	{
		cout << "Animal is Delete!" << endl;
	};
};

class Dog : public Animal
{
public:
	void makeSound()
	{
		cout << "Mung! Mung!" << endl;
	}
};

class Cat : public Animal
{
public:
	void makeSound()
	{
		cout << "Meow! Meow!" << endl;
	}
};

class Cow : public Animal
{
public:
	void makeSound()
	{
		cout << "Omme! Omme!" << endl;
	}
};

int main()
{
	Animal *animalArray[3];
	animalArray[0] = new Dog();
	animalArray[1] = new Cat();
	animalArray[2] = new Cow();

	for (int i = 0; i < 3; i++)
	{
		animalArray[i]->makeSound();
	}

	return 0;
}
