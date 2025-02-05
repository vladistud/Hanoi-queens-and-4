#include <iostream>
using namespace std;

void hanoi(int n, int start, int temp, int finish) {
    if (n == 1) {
        cout << "Переместить диск 1 с башни " << start << " на башню " << finish << endl;
        return;
    }
    
    hanoi(n - 1, start, finish, temp);
    
    cout << "Переместить диск " << n << " с башни " << start << " на башню " << finish << endl;

    hanoi(n - 1, temp, start, finish);
}

int main() {
    int num_disks;
    cout << "Введите количество дисков: ";
    cin >> num_disks;

    cout << "Пошаговое решение задачи Ханойской башни:\n";
    hanoi(num_disks, 1, 2, 3);

    return 0;
}
