#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int val : arr) cout << val << " ";
    cout << endl;
}

void shellSort(vector<int> arr) {
    int n = arr.size();
    cout << "Baslangic: "; printArray(arr);

    // Gap (Aralık) yarıya inerek gider: n/2, n/4, ..., 1
    for (int gap = n / 2; gap > 0; gap /= 2) {
        cout << "\n--- Gap: " << gap << " ---" << endl;
        
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        printArray(arr);
    }
    cout << "\nSonuc: "; printArray(arr);
}

int main() {
    vector<int> data = {12, 34, 54, 2, 3};
    shellSort(data);
    return 0;
}