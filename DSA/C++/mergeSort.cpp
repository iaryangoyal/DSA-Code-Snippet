#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int mid, int r){
    int i = l, j = mid + 1, k = l;
    int temp[r + 1];
    while (i <= mid && j <= r){
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int x = l; x <= r; x++)
        arr[x] = temp[x];
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    return 0;
}