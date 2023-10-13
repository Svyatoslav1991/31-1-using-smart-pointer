#include <iostream>
#include "dog.h"


int main()
{
	std::cout << "\tTASK 31.1 USING SMART POINTER\n\n";

	std::shared_ptr<Toy> toy = std::make_shared<Toy>("bone");

	std::shared_ptr<Dog> dog1 = std::make_shared<Dog>("Fluffy", nullptr, 5);
	std::shared_ptr<Dog> dog2 = std::make_shared<Dog>("Snowball", nullptr, 3);

	dog1->getToy(toy);
	dog2->getToy(toy);

	dog1->dropToy();
	dog2->dropToy();

	return 0;
}
