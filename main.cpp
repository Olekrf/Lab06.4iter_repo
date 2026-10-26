#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
using namespace std;

void Input(double* a, const int size);
void Print(double* a, const int size);
int Countpositive(double* a, const int size);
int Lastzero (double* a, const int size);
double Sum (double* a, const int size, int lzero);
void Rearrenge (double* a, const int size);

int main() {
    srand((unsigned)time(NULL));

    int n;
    cout << "n = "; cin >> n;

    double* a = new double[n];

    cout << fixed<< setprecision(1);

    Input(a, n);
    cout << "a: ";
    Print(a, n);

    cout << "Count = " << Countpositive(a, n) << endl;
   int lzero = Lastzero(a, n);
    if (lzero == -1)
        cout << "немає елемнтів, рівних нулю" << endl;
    else
        cout << "Sum = " <<Sum(a, n, lzero) << endl;

    Rearrenge(a, n);
    cout << "a: ";
    Print(a, n);

    delete[] a;
    return 0;

}

void Input(double* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}
void Print(double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}
int Countpositive(double* a, const int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] > 0)
            k++;
    }
    return k;
}
int Lastzero (double* a, const int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (a[i] == 0)
            return i;
    }
    return -1;
}
double Sum (double* a, const int size, int lzero) {
    double s = 0;
    for (int i = lzero + 1; i < size; i++)
        s += a[i];
    return s;
}
void Rearrenge (double* a, const int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (floor(a[i]) <= 1) {
            double tmp = a[i];
            for (int j = i; j > k; j--)
                a[j] = a[j - 1];
            a[k] = tmp;
            k++;
        }

    }
}



