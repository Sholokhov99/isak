#include <stdio.h>

using namespace std;

// Вывод массива на экран
void printArray(int array[], int lengthArray, string title){
    cout<<title<<"\n";
    for (int i = 0; i < lengthArray; i++) {
       printf("%d\t", array[i]);
    }
    printf("\n");
}

// Заполнение массива случайными значениями
int* setRandValues(int arValues[], int maxItems){
    int maxRand = 32;
    int minRand =-32;

    for(int index = 0; index < maxItems; index++){
        arValues[index] = minRand + rand() % (maxRand - minRand);
    }

   return arValues;
}

// Валидация значения
bool isValideValue(int number){
    int maxValue = 2;
    int minValue = -14;
    if (number >= minValue && minValue <= maxValue){
        return true;
    } else{
        return false;
    }
}

//
int* transformationArray(int array[], int lengthArray, int* sumNewItems){
    int newArray[lengthArray];
    int transformValue = 6;
    int indexPushItem = 0;
    int maxValue = 2;
    int minValue = -14;

    for(int index = 0; index < lengthArray; index++){
        array[index] -= transformValue;
       if(array[index] >= minValue && array[index] <= maxValue){
       //if(isValideValue(array[index])){
            newArray[indexPushItem] = array[index];
            //cout<<newArray[indexPushItem]<<"\n";
            sumNewItems += array[index];
            indexPushItem++;
        }
    }

    cout<<"\nСумма нового значения:\n"<<sumNewItems<<"\n";

    return newArray;
}

int main() {
    setlocale(LC_ALL, "rus");

    int maxItems = 24;
    int sumNewItems = 0;
    int lengthNewArray = 0;
    int values[maxItems];
    setRandValues(values, maxItems);

    printArray(values, maxItems, "Начальный массив");

	int* newArray = transformationArray(values, maxItems, &sumNewItems);

	printArray(values, maxItems, "Преобразованный массив");

	printArray(newArray, maxItems, "Новый массив");


    return 0;
}