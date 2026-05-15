#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>

struct Data {
    int value;
    char c;
};

class Serializer {
private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
