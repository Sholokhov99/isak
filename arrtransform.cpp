#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

// Вывод Списка на экран
void printList(list<int> arItems, string title) {
    cout << title << "\n";

    for (int number : arItems) {
        printf("%d\t", number);
    }

    printf("\n");
}

void printArray(int data[], string title) {
    int lengthArr = _msize(data) / sizeof(data[0]);
    cout << title << "\n";

    for (int index = 0; index < lengthArr; index++) {
        printf("%d\t", data[index]);
    }

    printf("\n");
}

// Заполнение массива случайными значениями
int* setRandValues(int maxItems) {
    // Список значений
    int *arValues = new int[maxItems];
    // Максимальное значение
    int maxRand = 32;
    // Минимальное значение
    int minRand = -32;

    for (int carriage = 0; carriage < maxItems; carriage++) {
        arValues[carriage] = rand() % (maxRand - minRand);
    }

    //printList(arValues, "Начальный массив");
    printArray(arValues, "Начальный массив");

    return arValues;
}

// Валидация значения
bool isValideValue(int number) {
    // Максимальное значение числа
    int maxValue = 2;
    // Минимальное значение числа
    int minValue = -14;

    // Сокрашенная форма записи if      (Условеие) ? ответ_если_TRUE : ответ_если_FALSE;
    // Если ответ не задали, то вернет true или false, все зависит от логического значения условия
    return (number >= minValue && number <= maxValue);
}

int* cutOfArray(int arItems[], int newLength) {
    int* shortArr = new int[newLength];

    for (int index = 0 ; index < newLength; index++) {
        shortArr[index] = arItems[index];
    }

    return shortArr;
}

// Трансформация массива
int* transformationArray(int arValues[], int maxItems) {
    // Массив с новыми значениями
    int* newArray = new int[maxItems];
    int transformValue = 6;
    int summNewArrItems = 0;
    int carriageNewArray = 0;

    for (int index = 0; index < maxItems; index++) {
        arValues[index] -= transformValue;
        if (isValideValue(arValues[index])) {
            summNewArrItems += arValues[index];
            newArray[carriageNewArray] = arValues[index];
            carriageNewArray++;
        }
    }

    printArray(arValues, "Преобразованный массив");

    newArray = cutOfArray(newArray, carriageNewArray);

    printArray(newArray, "Новый массив");

    cout << "\nСумма значений в новом массиве:\n" << summNewArrItems << "\n";

    return newArray;
}

int main() {
    setlocale(LC_ALL, "rus");
    // Максимальное количество элементов в списке
    int maxItems = 24;
    
    int* arItems = setRandValues(maxItems);

    int* newArray = transformationArray(arItems, maxItems);

    return 0;
}