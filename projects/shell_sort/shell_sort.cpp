#include <iostream>
#include <random>
#include <algorithm>

//Сортировка Шелла
void shell_sort(int* arr, int* hammingNumbers, int amountHamming, int lengthArr) {

    for (int k = amountHamming; k >= 0; k--) {
        int gap = hammingNumbers[k];
        for (int i = gap; i < lengthArr; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}


int main() {
    const int lengthArr = 30;
    int arr[lengthArr];
    const int amountHamming = int(lengthArr / 3);

    

    //3-гладкие числа
    int hammingNumbers[amountHamming];

    hammingNumbers[0] = 1;

    int index2 = 0, index3 = 0;

    for (int i = 1; i < amountHamming; ++i) {
        int nextNumber = std::min(2 * hammingNumbers[index2], 3 * hammingNumbers[index3]);
        hammingNumbers[i] = nextNumber;

        if (nextNumber == 2 * hammingNumbers[index2]) {
            ++index2;
        }
        if (nextNumber == 3 * hammingNumbers[index3]) {
            ++index3;
        }
    }


    //заполнение основного массива рандомом
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < lengthArr; ++i) {
        arr[i] = mt() % 100 + 100;
    }


    shell_sort(arr, hammingNumbers, amountHamming, lengthArr);
    
    for (int i = 0; i < lengthArr; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

