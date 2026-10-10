#include <iostream>
#include <memory>

void printArray(const std::unique_ptr<int[]>& array, int size)
{
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    // Умный указатель на одно значение
    auto value = std::make_shared<int>(10);
    std::cout << "Одно значение: " << *value << '\n';

    // Умный указатель на динамический массив
    int size = 10;
    auto array = std::make_unique<int[]>(size);

    for (int i = 0; i < size; ++i) {
        array[i] = (i + 1) * 10;
    }

    std::cout << "Массив:\n";
    printArray(array, size);

    // Сырой наблюдающий указатель стал бы висячим после освобождения объекта
    int* danglingPointer = value.get();
    std::weak_ptr<int> safeObserver = value;
    std::cout << "До освобождения памяти: " << *danglingPointer << '\n';

    value.reset();

    std::cout << "После освобождения памяти сырой указатель " << danglingPointer
              << " стал висячим, его разыменование или удаление опасно и "
                 "приводит к неопределённому поведению\n";

    // weak_ptr позволяет проверить, существует ли объект, не обращаясь
    // к уже освобождённой памяти
    if (auto observedValue = safeObserver.lock()) {
        std::cout << "Наблюдаемое значение: " << *observedValue << '\n';
    } else {
        std::cout << "Объект уже удалён, weak_ptr недействителен\n";
    }
    danglingPointer = nullptr;

    const int position = size / 2;
    const int newValue = 123;
    auto newArray = std::make_unique<int[]>(size + 1);

    for (int i = 0; i < position; ++i) {
        newArray[i] = array[i];
    }
    newArray[position] = newValue;
    for (int i = position; i < size; ++i) {
        newArray[i + 1] = array[i];
    }

    array = std::move(newArray);
    ++size;

    std::cout << "После вставки:\n";
    printArray(array, size);

    array.reset();

    return 0;
}
