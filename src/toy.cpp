#include "toy.h"
#include <iostream>

Toy::Toy(std::string name) noexcept : m_name(name)
{
	
}

//-------------------------------------------------------------

std::string Toy::getName() const noexcept
{
	return m_name;
}

//-------------------------------------------------------------

Toy::~Toy()
{
	std::cout << "Toy " << m_name << " was dropped " << "\n";
}

//-------------------------------------------------------------

Toy::Toy(const Toy& other) noexcept : m_name(other.m_name)
{

}

//-------------------------------------------------------------

Toy& Toy::operator==(const Toy& other) noexcept
{
	if (this != &other)
	{
		m_name = other.m_name;
	}

	return *this;
}

//-------------------------------------------------------------

Toy::Toy(Toy&& other) noexcept
{
	m_name = std::move(other.m_name);
}

//-------------------------------------------------------------

Toy& Toy::operator=(Toy&& other) noexcept
{
	if (this != &other)
	{
		m_name = std::move(other.m_name);
	}

	return *this;
}

//-------------------------------------------------------------


