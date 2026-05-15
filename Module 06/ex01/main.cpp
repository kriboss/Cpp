#include <iostream>
#include "Serialization.hpp"

int main()
{
	Data d;
	d.value = 42;
	d.c = 'A';

	uintptr_t raw = Serializer::serialize(&d);
	Data* p = Serializer::deserialize(raw);

	if (p == &d)
		std::cout << "Serialization OK: pointers match" << std::endl;
	else
		std::cout << "Serialization ERROR" << std::endl;

	std::cout << "Original value: " << d.value << ", char: " << d.c << std::endl;
	std::cout << "Deserialized value: " << p->value << ", char: " << p->c << std::endl;

	return 0;
}