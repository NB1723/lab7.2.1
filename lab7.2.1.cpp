#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>

using namespace std;
void Create(int** a, const int size, const int low, const int high);
void Print(int** a, const int size);
//void Sort(int** a, const int size, int i, int j);
void Trans(int** a, const int size);
//void Change(int** a, const int row0, const int row1, const int col);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));

    int low = -17;
    int high = 14;
    int size;

    cout << "¬вед≥ть розм≥р квадратноњ матриц≥: ";
    cin >> size;
    cout << endl;

    int** a = new int* [size];
    for (int i = 0; i < size; i++)
        a[i] = new int[size];
    cout << setw(21) << "ѕочаткова матриц€" << endl;
    Create(a, size, low, high); cout << endl;
    Print(a, size); cout << endl;
    cout << setw(23) << "“ранспонована матриц€" << endl; cout << endl;
    Trans(a, size); cout << endl; cout << endl;
    Print(a, size); cout << endl;
    for (int i = 0; i < size; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
void Create(int** a, const int size, const int low, const int high)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            a[i][j] = low + rand() % (high - low + 1);
}
void Print(int** a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void Trans(int** a, const int size)
{
    int temp;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
}
