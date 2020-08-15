#pragma once
#include "Vector3.h"

template<typename T>
class Vector {
public:
	Vector() {
		//allocate 2 elements for start
		ReAlloc(2);
	}
	~Vector() {
		delete[] aData;
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
	void PushBack(T&& value) {

		//no moving if applicable, less cycles
		if (aSize >= aCapacity) {
			ReAlloc(aCapacity + aCapacity / 2);
		}

		aData[aSize++] = std::move(value); //moving an element as an rvalue, 
	}

	void PopBack() {
		//destroy object in the tail of the vector
		if (aSize > 0) {
			aSize--;
			aData[aSize].~T();
		}
	}
	void Clear() {
		for (size_t i = 0; i < aSize; i++) {
			aData[i].~T();
		}
		aSize = 0;
	}
	size_t GetSize() const { return aSize; }

	const T& operator[] (size_t index) const {
		return aData[index];
	}

	T& operator[] (size_t index) {
		//in case you want to actually modify your data
		return aData[index];
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args) {

		/*a useful function included in std::vector.
		this thing constructs a T type in place instead of us creating an object and pushing
		it back like we usually do!
		*/

		if (aSize >= aCapacity)
			ReAlloc(aCapacity + aCapacity / 2); //basic available space check

		new(&aData[aSize]) T(std::forward<Args>(args)...); // by using new() it actually constructs the element in the existing memory, not wasting another piece of it
		return aData[aSize++]; //increment size because we just added an element
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
			newBlock[i] = std::move(aData[i]); //try and cast to move; if successful, less cycles, more optimization!
		}
		delete[] aData;
		aData = newBlock;
		aCapacity = newCapacity;
	}

	T* aData = nullptr;

	size_t aSize; //current size
	size_t aCapacity; //current size + free allocated memory
};