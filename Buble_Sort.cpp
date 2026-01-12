#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    cout << "Baslangic: "; printArray(arr);

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // Her dış döngü sonunda (her pass) durumu yaz
        cout << "Adim " << i + 1 << " (En buyuk " << n - 1 - i << ". indise gitti): ";
        printArray(arr);

        // Eğer hiç takas olmadıysa dizi zaten sıralıdır
        if (!swapped) break;
    }
    cout << "Sonuc: "; printArray(arr);
}

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(data);
    return 0;
}