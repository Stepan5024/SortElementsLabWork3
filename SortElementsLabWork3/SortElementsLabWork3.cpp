// Сортировка массивов ЛР 3
// Выполнили студенты группы м3о-219Бк-20 Бокарев С.М. Кавалян А.А.

#include <iostream>

using namespace std;

void mergeSort(int* arr, int l, int r); // Функция, формирующая рандомную последовательность
void FillRand(int* arr, int n, double min, double max); // Функция, формирующая рандомную последовательность
void Writer(int* A, int length); // Функция, печатающая последовательность
void merge(int* buf, int l, int r, int m); // Функция, объединяющая отсортированные части массива

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int* array, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
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
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int* array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void FillRand(int* arr, int length, double min, double max) {
    for (int i = 0; i < length; i++) {
        arr[i] = 10 + ((double)rand() / RAND_MAX) * (max - min);
    }
    //arr[length - 1] = INT_MAX;
    Writer(arr, length);
}
void Writer(int* A, int length) {
    for (int i = 0; i < length; i++) {
        cout << "arr[" << i << "] = " << A[i] << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    system("color F0");
    srand(time(NULL));
    int n = 0;
    cout << "Введите размер последовательности: "; cin >> n;

    int* arrRand = new int[n]; // рандомная последовательность
    cout << "Given array is \n";
    FillRand(arrRand, n, 0, 30);

    mergeSort(arrRand, 0, n - 1);
    cout << "" << endl;
    cout << "" << endl;
    cout << "\nSorted array is \n";
    Writer(arrRand, n);


}
