#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Формування масиву випадковими числами у діапазоні [Low, High]
void F(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Форматне виведення масиву у вигляді рядка
void out(const int* a, const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << a[i];
    }
    cout << endl;
}

// Пошук максимального елемента масиву
int FindMax(const int* a, const int size) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Пошук мінімального елемента масиву
int FindMin(const int* a, const int size) {
    int min = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Обчислення суми максимального та мінімального елементів
int Sum(const int* a, const int size) {
    return FindMax(a, size) + FindMin(a, size);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "count elements n: ";
    cin >> n;

    if (n <= 0) {
        cout << "massive size can be > 0." << endl;
        return 1;
    }

    int* a = new int[n];
    int Low = -50, High = 50;

    F(a, n, Low, High);

    cout << "massive:" << endl;
    out(a, n);

    int maximal = FindMax(a, n);
    cout << "max= " << maximal << endl;
    int minimal = FindMin(a, n);
    cout << "min= " << minimal << endl;
    int sum = Sum(a, n);
    cout << "sum (max+min) = " << sum << endl;

    delete[] a;
    return 0;
}