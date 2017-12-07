#include <iostream>

using std::cin;
using std::cout;

void qSort(int a[], int left, int right){
    int i = left;
    int j = right;
    int temp = a[left];
    if (left >= right)
        return;
    while (i != j) {
        while (i < j && a[j] >= temp)
            j--;
        if (j > i)
            a[i] = a[j];
        while (i < j && a[i] <= temp)
            i++;
        if (i < j)
            a[j] = a[i];
    }
    a[i] = temp;
    qSort(a, left, i - 1);
    qSort(a, i + 1, right);
}

void quickSort(int a[], int n) {
    qSort(a, 0, n-1);
}

int main() {
    int n;
    cin>>n;
    int *a = new int [n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    quickSort(a, n);
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
