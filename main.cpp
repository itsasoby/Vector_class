// AVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//this whole project is an exercise in data structures
//made for portfolio and nothing more.
//I wrote this to be tailored to my specific needs in terms
//of data flow control and memory control (as you'll see in the code comments)
//and this pretty much works with the test class!
// -- Asoby 2020
//github.com/itsasoby

#include <iostream>
#include "Vector.h"
#include "Vector3.h"



void Printvector(const Vector<Vector3>& vector) {
	for (size_t i = 0; i < vector.GetSize(); i++)
		std::cout << vector[i].x << " " << vector[i].y << " " << vector[i].z << std::endl;
	std::cout << "-------------------------\n";
}

int main()
{
    Vector<Vector3> vector;
    vector.EmplaceBack(1.0f);
    vector.EmplaceBack(2, 3, 4);
    vector.PopBack();
    vector.EmplaceBack(1.0f);
    vector.EmplaceBack(8, 5, 4);
    vector.EmplaceBack(8.0f);
    vector.PopBack();
    Printvector(vector);
    vector.EmplaceBack(1, 2, 6);
    vector.EmplaceBack(1.0f);
    vector.EmplaceBack(1, 9, 5);
    vector.EmplaceBack(1.7f);
    vector.PopBack();
    Printvector(vector);
    vector.Clear();
    vector.EmplaceBack(2, 7, 5);
    vector.EmplaceBack(1.0f);
    vector.EmplaceBack(1, 9, 5);
    vector.EmplaceBack();
    Printvector(vector);

    std::cin.get();
}


