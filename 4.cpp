#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[100], size, val, i, j;
    srand(time(0));

    cout << "Размер массива (до 100): ";
    cin >> size;
    for(i = 0; i < size; i++) arr[i] = rand() % 100;
    
    cout << "Исходный массив: ";
    for(i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Удалить значение: ";
    cin >> val;
    for(i = j = 0; i < size; i++)
        if(arr[i] != val) arr[j++] = arr[i];
    size = j;

    cout << "После удаления: ";
    for(i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;

    
    int even_count = 0;
    for(i = 0; i < size; i++)
        if(arr[i]%2 == 0) even_count++;
    
    if(size + even_count > 100) return cout << "Переполнение!", 1;
    
    j = size + even_count - 1;
    for(i = size - 1; i >= 0; i--) {
        if(arr[i]%2 == 0) {
            arr[j--] = arr[i];
            arr[j--] = 0;
        } else {
            arr[j--] = arr[i];
        }
    }
    size += even_count;

    cout << "С нулями: ";
    for(i = 0; i < size; i++) cout << arr[i] << " ";
}
