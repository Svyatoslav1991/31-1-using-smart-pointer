#pragma once
#include <string>
#include <memory>
#include "toy.h"

class Dog
{
public:
	Dog(std::string name = "Unnamed", std::shared_ptr<Toy> toy = std::make_shared<Toy>("ball"), int64_t age = 0);
	Dog(std::string name) noexcept;
	Dog(int64_t age);
	void copyLovelyToy(const Dog& other) noexcept;
	void setBestie(std::shared_ptr<Dog> bestie) noexcept;
	void getToy(std::shared_ptr<Toy>& toy) noexcept;
	void dropToy() noexcept;

private:
	std::string m_name;
	int64_t m_age;
	std::shared_ptr<Toy> m_lovelyToy;
	std::weak_ptr<Dog> m_bestie;
};