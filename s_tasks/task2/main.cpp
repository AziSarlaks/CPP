#include <iostream>

int main() {
	int* value = new int(10);

	int size = 10;
	int* array = new int[size];

	for (int i = 0; i < size; ++i) {
		array[i] = (i + 1) * 10;
	}
	
	std::cout << "Array:\n";

	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}

	std::cout << "\n";

	int* lost = new int(100);

	std::cout << "Before delete: " << *lost << " - " << lost << "\n";

	delete lost;
	lost = new int(300);

	std::cout << "After delete: " << *lost << " - " << lost << "\n";

	lost = nullptr;

	int position = size / 2;
	int newValue = 123;

	int* newArray = new int[size + 1];

	for (int i = 0; i < position; i++) {
		newArray[i] = array[i];
	}

	newArray[position] = newValue;

	for (int i = position; i < size; i++) {
		newArray[i + 1] = array[i];
	}

	delete[] array;

	array = newArray;
	size++;

	std::cout << "After insert:\n";

	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}

	delete value;
	delete[] newArray;

	newArray = nullptr;
	value = nullptr;
}