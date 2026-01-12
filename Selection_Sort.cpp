#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void selectionSort(vector<int> arr) {
    int n = arr.size();
    cout << "Baslangic: "; printArray(arr);

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        // En küçüğü bul
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Bulunan en küçüğü mevcut konumla takas et
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
            cout << "Swap: " << arr[i] << " <-> " << arr[min_idx] << endl;
        }

        cout << "Adim " << i + 1 << " (Ilk " << i + 1 << " eleman sirali): ";
        printArray(arr);
    }
    cout << "Sonuc: "; printArray(arr);
}

int main() {
    vector<int> data = {64, 25, 12, 22, 11};
    selectionSort(data);
    return 0;
}