#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal
{
public:
	virtual void makeSound() = 0;

	virtual ~Animal()
	{
		cout << "Animal is Delete!" << endl;
	};
protected:

};

class Dog : public Animal
{
public:
	Dog()
	{
		cout << "Dog 기본 생성자 호출!" << endl;
	}
	void makeSound()
	{
		cout << "Dog Sound! Mung! Mung!" << endl;
	}
	~Dog()
	{
		cout << "Dog 소멸자 호출!" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat()
	{
		cout << "Cat 기본 생성자 호출!" << endl;
	}
	void makeSound()
	{
		cout << "Cat Sound! Meow! Meow!" << endl;
	}
	~Cat()
	{
		cout << "Cat 소멸자 호출!" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow()
	{
		cout << "Cow 기본 생성자 호출!" << endl;
	}
	void makeSound()
	{
		cout << "Cow Sound! Omme! Omme!" << endl;
	}
	~Cow()
	{
		cout << "Cow 소멸자 호출!" << endl;
	}
};


class Zoo {
private:
	int animalCount = 0;
	Animal* animals[10];
public:
	void addAnimal(Animal* animal)
	{
		if (animalCount < 10)
		{
			animals[animalCount] = animal;
			animalCount++;
		}
		else
		{
			cout << "더 이상 동물원에 동물을 추가할 수 없습니다." << endl;
		}
	}

	void performActions()
	{
		cout << "All Animals Make Sound!!!" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (animals[i] != NULL) {
				animals[i]->makeSound();
			}
		}
	}

	~Zoo()
	{
		for (int i = 0; i < animalCount; i++)
		{
			delete animals[i];
		}
		cout << "zoo delete!!!" << endl;
	}
};

Animal* createRandomAnimal()
{
	int randomInt = rand() % 3;

	if (randomInt == 0)
	{
		Animal* myAnimal;
		myAnimal = new Dog();
		return myAnimal;
	}

	if (randomInt == 1)
	{
		Animal* myAnimal;
		myAnimal = new Cat();
		return myAnimal;
	}

	if (randomInt == 2)
	{
		Animal* myAnimal;
		myAnimal = new Cow();
		return myAnimal;
	}
}

int main()
{
	Zoo *zoo = new Zoo();
	for (int i = 0; i < 10; i++)
	{
		Animal* randomAnimal = createRandomAnimal();
		zoo->addAnimal(randomAnimal);
	}

	zoo->performActions();
	zoo->~Zoo();

	return 0;
}
 