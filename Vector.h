#pragma once
#include "Vector3.h"

template<typename T>
class Vector {
public:
	Vector() {
		//allocate 2 elements for start
		ReAlloc(2);
	}

	void PushBack(const T& value) {

		//if there's no room for the new element, makes room for half the current storage
		//capacity. In fact, you could double it or whatever, but I like to show pity
		//for the memory, even though it's heap and there's a LOT of it

		if (aSize >= aCapacity) {
			ReAlloc(aCapacity + aCapacity / 2);
		}

		aData[aSize++] = value; //puts data at size index (current free index) and increments size
	}

	size_t GetSize() const { return aSize; }

	const T& operator[] (size_t index) const {
		return aData[index];
	}

	T& operator[] (size_t index) {
		//in case you want to actually modify your data
		return aData[index];
	}
private:
	void ReAlloc(size_t newCapacity) {
		// allocates a new block of memory
		// - moves data there
		// - deletes old block of memory!

		T* newBlock = new T[newCapacity];

		if (newCapacity < aSize)
			aSize = newCapacity;

		for (size_t i = 0; i < aSize; i++) {
			newBlock[i] = aData[i];
		}
		delete[] aData;
		aData = newBlock;
		aCapacity = newCapacity;
	}

	T* aData = nullptr;

	size_t aSize; //current size
	size_t aCapacity; //current size + free allocated memory
};