#include <iostream>

using std::cin;
using std::cout;

void insertSort(int *a, int n, int t) {
    for (int i = t; i < n; i += t) {
        for (int j = i; (j >= t) && (a[j] < a[j - t]); j -= t) {
            int flag = a[j];
            a[j] = a[j - t];
            a[j - t] = flag;
        }
    }
}
void shellSort(int a[], int n) {
    for (int i = n / 2; i > 2; i /= 2) {
        for (int j = 0; j < i; j++) {
            insertSort(a, n - j, i);
        }
    }
    insertSort(a, n, 1);
}
int main() {
    int n;
    cin>>n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    shellSort(a, n);
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
