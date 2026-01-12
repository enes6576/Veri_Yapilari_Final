#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MinHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    MinHeap(vector<int> init) : heap(init) {} // Hazır dizi ile başlatma

    void printHeap() {
        for (int i : heap) cout << i << " ";
        cout << endl;
    }

    // Ekleme İşlemi (Trace ile)
    void insert(int k) {
        cout << "\n[Insert " << k << "] Basliyor..." << endl;
        heap.push_back(k);
        int i = heap.size() - 1;
        cout << "Diziye eklendi: "; printHeap();

        // Heapify Up
        while (i != 0 && heap[parent(i)] > heap[i]) {
            cout << "Swap: " << heap[i] << " ile Parent " << heap[parent(i)] << " yer degistiriyor." << endl;
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
            printHeap();
        }
        cout << "Insert Tamamlandi." << endl;
    }

    // Min Silme İşlemi (Trace ile)
    void extractMin() {
        if (heap.size() <= 0) return;
        if (heap.size() == 1) {
            heap.pop_back();
            return;
        }

        cout << "\n[Extract Min] Basliyor... Silinen: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        cout << "Son eleman basa tasindi: "; printHeap();

        // Heapify Down
        int i = 0;
        int n = heap.size();
        while (true) {
            int smallest = i;
            int l = left(i);
            int r = right(i);

            if (l < n && heap[l] < heap[smallest])
                smallest = l;
            if (r < n && heap[r] < heap[smallest])
                smallest = r;

            if (smallest != i) {
                cout << "Swap: " << heap[i] << " (index " << i << ") ile " << heap[smallest] << " (index " << smallest << ") yer degistiriyor." << endl;
                swap(heap[i], heap[smallest]);
                i = smallest;
                printHeap();
            } else {
                break;
            }
        }
        cout << "Extract Min Tamamlandi." << endl;
    }
};

int main() {
    // Sınav sorusundaki mevcut heap dizisi
    vector<int> startData = {2, 8, 12, 15, 20, 45, 30}; 
    MinHeap h(startData);
    
    h.insert(5); // Soru 3'teki işlem
    
    // Soru 2 (Deneme 2) için:
    // MinHeap h2({5, 12, 20, 30, 15, 45, 25});
    // h2.extractMin();
    
    return 0;
}