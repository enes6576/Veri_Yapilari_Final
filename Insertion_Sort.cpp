#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    cout << "Baslangic: "; printArray(arr);

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Key'den büyük olanları sağa kaydır
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        cout << "Adim " << i << " (" << key << " yerlestirildi): ";
        printArray(arr);
    }
    cout << "Sonuc: "; printArray(arr);
}

int main() {
    vector<int> data = {12, 11, 13, 5, 6};
    insertionSort(data);
    return 0;
}