#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {

    Data myData;
    myData.value = 42;
	myData.double_v = 42.42;
    myData.name = "Test Data";
    myData.string = "this is a test";

    Data* originalPtr = &myData;
    
    std::cout << "Original Address: " << originalPtr << std::endl;
    std::cout << "Data content: " << originalPtr->name <<std::endl;
	std::cout << "Value: " << originalPtr->value << std::endl;
    uintptr_t raw = Serializer::serialize(originalPtr);
	std::cout << std::endl;
    std::cout << "Serialized (uintptr_t):   " << raw << std::endl;
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized Address:     " << deserializedPtr << std::endl;
	std::cout << std::endl;
    if (deserializedPtr == originalPtr) {
        std::cout << "The Addresses are equal!" << std::endl;
        std::cout << "Data: " << deserializedPtr->name << " value: " << deserializedPtr->value << std::endl;
    }
	else
        std::cout << "The Addresses are different!" << std::endl;

    return 0;
}