#include "dog.h"
#include <stdexcept>
#include <iostream>

Dog::Dog(std::string name, std::shared_ptr<Toy> toy, int64_t age) : m_name(name), m_lovelyToy(toy)
{
	if (age < 0 || age > 30)
	{
		throw std::out_of_range("Invalid dog age. Age must be between 0 and 30");
	}
	
	m_age = age;
}

//----------------------------------------------------------------------------------------------------------------------

Dog::Dog(std::string name) noexcept : m_lovelyToy(std::make_shared<Toy>("ball")), m_age(0)
{
	if (name == "")
	{
		m_name = "Unnamed";
	}
	else
	{
		m_name = name;
	}
}

//----------------------------------------------------------------------------------------------------------------------

Dog::Dog(int64_t age) : m_name("Unnamed"), m_lovelyToy(std::make_shared<Toy>("ball"))
{
	if (age < 0 || age > 30)
	{
		throw std::out_of_range("Invalid dog age. Age must be between 0 and 30");
	}

	m_age = age;
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::copyLovelyToy(const Dog& other) noexcept
{
	m_lovelyToy = other.m_lovelyToy;
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::setBestie(std::shared_ptr<Dog> bestie) noexcept
{
	m_bestie = bestie;
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::getToy(std::shared_ptr<Toy>& toy) noexcept
{
	if (toy)
	{
		if (toy == m_lovelyToy)
		{
			std::cout << m_name << " already has " << toy->getName() << "\n";
		}
		else if (toy.use_count() > 1)
		{
			std::cout << "Another dog is playing with " << toy->getName() << "\n";
		}
		else
		{
			m_lovelyToy = toy;
			std::cout << m_name << " got a new toy: " << toy->getName() << "\n";
		}
	}
}

//----------------------------------------------------------------------------------------------------------------------

void Dog::dropToy() noexcept
{
	if (m_lovelyToy)
	{
		m_lovelyToy.reset();
	}
	else
	{
		std::cout << "Nothing to drop\n";
	}
}
