#pragma once
#include <iostream>

//a quick Vector3 implementation
//Vector3 is used in many ways, basically having three scalars means it
//could be a forward vector, WorldLocation or whereever you'd need 3 scalars
//in one place. Pretty useful!

struct Vector3 {
	float x = 0, y = 0, z = 0;

	Vector3() { }
	Vector3(float scalar) :
		x(scalar), y(scalar), z(scalar) { }

	Vector3(float x, float y, float z) :
		x(x), y(y), z(z) { }

	Vector3(const Vector3& other) :
		x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copy" << std::endl;
	}

	~Vector3() {
		std::cout << "Destroy\n";
	}

	Vector3& operator=(const Vector3& other) {
		std::cout << "Copy\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	Vector3& operator=(const Vector3&& other) noexcept {
		std::cout << "Copy\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

};