#include <iostream>

using std::cin;
using std::cout;

int getParent(int k) {
    return (k-1)/2;
}

int getLeftChild(int k) {
    return k*2+1;
}

int getRightChild(int k) {
    return k*2+2;
}

bool isLeaf(int k, int n) {
    return (k >= n / 2) && (k < n);
}

void siftDown(int a[], int k, int n) {
        while (!isLeaf(k, n)) {
        int lc = getLeftChild(k);
        int rc = getRightChild(k);
        if ((rc < n) && (a[rc] < a[lc])) {
            lc = rc;
        }
        if (a[k] < a[lc]) {
            return;
        }
        int flag = a[k];
        a[k] = a[lc];
        a[lc] = flag;
        k = lc;
    }
}

void BuildHeap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(a, i, n);
    }
}

int HeapPop(int a[], int n) {
    int key = a[0];
    a[0] = a[n];
    a[n] = key;
    siftDown(a, 0, n);
    return key;
}

void HeapSort(int a[], int n) {
    BuildHeap(a, n);
    for (int i = 1; i <= n; i++) {
        cout<<HeapPop(a, n - i)<<" ";
    }
    cout<<"\n";
}

int main() {
    int n;
    cin>>n;
    int *a = new int [n];
    HeapSort(a, n);
    return 0;
}
