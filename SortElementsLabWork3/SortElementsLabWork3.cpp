// Сортировка массивов ЛР 3 вариант 2
// Выполнили студенты группы м3о-219Бк-20 Бокарев С.М. Кавалян А.А.

#include <iostream>

using namespace std;

void mergeSort(int* arr, int l, int r); // Функция, сортировки слиянием
void selectionSort(int* arr, int lenght); // Функция, сортировки выбором
void fillRand(int* arr, int n, double min, double max); // Функция, формирующая рандомную последовательность
void writer(int* A, int length); // Функция, печатающая последовательность
void merge(int* buf, int l, int r, int m); // Функция, объединяющая отсортированные части массива

/* 
 Объединяет две отсортированные части массива array[].
 Первый подмассив с индексами arr[begin..mid]
 Второй подмассив с индексами arr[mid+1..end]
 */
void merge(int* array, int const left, int const mid, int const right) // реализован по блоксхеме ✔️
{
    int const subArrayOne = mid - left + 1; // Длина первого подмассива
    int const subArrayTwo = right - mid; // Длина второго подмассива

    // Создание дополнительных массивов для копирования элементов
    int* leftArray = new int[subArrayOne];
    int* rightArray = new int[subArrayTwo];

    // Копирование данныех во временные массивы leftArray[] и rightArray[] из общего array[]
    for (auto i = 0; i < subArrayOne; i++) leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++) rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0; // Индекс первого подмассива
    int indexOfSubArrayTwo = 0; // Индекс второго подмассива
    int indexOfMergedArray = left; // Индекс объединенного подмассива

    // Объединение временных массивов обратно в массив array[]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Копируем оставшиеся элементы из rightArray[]
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    // Копируем оставшиеся элементы из leftArray[]
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    
}

/* Сортировка слиянием */
void mergeSort(int* array, int const begin, int const end) // реализован по блоксхеме ✔️
{
    if (begin >= end)
        return; // Выход из рекурсии

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// сортировка выбором
void selectionSort(int* arr, int lenght) { // реализован по блоксхеме ✔️
    for (int i = 0; i < lenght - 1; ++i)
    {
        int biggest = i; 
        for (int j = i + 1; j < lenght; ++j)
        {
            if (arr[j] > arr[biggest])
                biggest = j; // наибольший элемент среди текущих
        }
        swap(arr[i], arr[biggest]); // меняем местами наибольший и i-ый элемент
    }
}

// заполнение массива arr рандомными числами
void fillRand(int* arr, int length, double min, double max) {
    for (int i = 0; i < length; i++) {
        arr[i] = 10 + ((double)rand() / RAND_MAX) * (max - min);
    }

    writer(arr, length);
}

// вывод переданного массива
void writer(int* A, int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "] = " << A[i] << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");
    srand(time(NULL));
    int lenght = 0; // размер последовательности
    cout << "Введите размер последовательности: "; cin >> lenght;

    int* arrRand = new int[lenght]; // рандомная последовательность
    cout << "Значения массива до сортировки:" << endl;
    fillRand(arrRand, lenght, 0, 30); // заполнение массива случайными числами
    mergeSort(arrRand, 0, lenght); // сортировка слиянием
    cout <<"Отсортированный массив:" << endl;
    writer(arrRand, lenght); // печать массива

    cout << "Значения массива до сортировки:" << endl;
    fillRand(arrRand, lenght, 0, 30); // заполнение массива случайными числами
    selectionSort(arrRand, lenght); // сортировка выбором
    cout << "Отсортированный массив:" << endl;
    writer(arrRand, lenght); // печать массива
}
