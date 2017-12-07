#include <iostream>

using std::cin;
using std::cout;

void merge(int a[], int l, int mid, int r) {
    int t = r - l + 1;
    int ll = l;
    int tmp = t;
    int *b = new int [tmp];
    int ltmp = mid + 1;
    while (tmp) {
        tmp--;
        if (l > mid) {
            b[tmp] = a[ltmp];
            ltmp++;
        }
        else if (ltmp > r) {
            b[tmp] = a[l];
            l++;
        }
        else if (a[l] <= a[ltmp] && l <= mid) {
            b[tmp] = a[l];
            l++;
        }
        else if (a[l] >= a[ltmp] && ltmp <= r) {
            b[tmp] = a[ltmp];
            ltmp++;
        }
    }
    for (int i = 0; i < t; i++) {
        a[ll + i] = b[t - i - 1];
    }
    delete []b;
    return;
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
    return;
}

int main() {
    int n;
    cin>>n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
