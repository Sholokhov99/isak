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

// Заполнение массива случайными значениями
list<int> setRandValues() {
    // Максимальное количество элементов в списке
    int maxItems = 24;
    // Список значений
    list<int> arValues = {};
    // Максимальное значение
    int maxRand = 32;
    // Минимальное значение
    int minRand = -32;

    for (int index = 0; index < maxItems; index++) {
        arValues.push_back( rand() % (maxRand - minRand));
    }

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

// Трансформация массива
list<int> transformationArray(list<int> &arValues, int &summNewArrItems) {
    // Массив с новыми значениями
    list<int> newArray = {};
    int transformValue = 6;

    for (auto iter = arValues.begin(); iter != arValues.end(); iter++){
        *iter -= transformValue;
        if (isValideValue(*iter)) {
            summNewArrItems += *iter;
            newArray.push_back(*iter);
        }
    }

    return newArray;
}

int main() {
    setlocale(LC_ALL, "rus");
    int summNewArrItems = 0;
    
    list<int> arItems = setRandValues();

    printList(arItems, "Начальный массив");

    list<int> newArray = transformationArray(arItems, summNewArrItems);

    printList(arItems, "Преобразованный массив");

    printList(newArray, "Новый массив");

    cout << "\nСумма значений в новом массиве:\n" << summNewArrItems << "\n";
    return 0;
}
