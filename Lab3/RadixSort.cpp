#include <iostream>

using std::cin;
using std::cout;

#define Base 4

void radixSort(int a[], int n) {
    int *b = new int [n];
    int m = a[0];
    int exp = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > m) {
            m = a[i];
        }
    }

    while (m / exp > 0) {
        int bucket[Base] = {0};

        for (int i = 0; i < n; i++) {
            bucket[(a[i] / exp) % Base]++;
        }

        for (int i = 1; i < Base; i++) {
            bucket[i] += bucket[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            b[--bucket[(a[i] / exp) % Base]] = a[i];
        }

        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }

        exp *= Base;
    }
}

int main() {
    int n;
    cin>>n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    radixSort(a, n);
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
