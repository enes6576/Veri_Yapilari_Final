#include <iostream>
#include <vector>

using namespace std;

void linearProbing(int size, vector<int> keys) {
    vector<int> table(size, -1); // -1 boş demek
    cout << "\n--- Linear Probing (Size: " << size << ") ---" << endl;

    for (int key : keys) {
        int index = key % size;
        int originalIndex = index;
        cout << "Key: " << key << " -> Hash: " << index;

        while (table[index] != -1) {
            cout << " [DOLU -> Next]";
            index = (index + 1) % size;
            // Sonsuz döngü koruması
            if (index == originalIndex) break; 
        }
        
        table[index] = key;
        cout << " -> Yerlesti: [" << index << "]" << endl;
    }
    
    // Son Tabloyu Yaz
    cout << "TABLO: ";
    for(int x : table) cout << (x==-1 ? "_" : to_string(x)) << " ";
    cout << endl;
}

void quadraticProbing(int size, vector<int> keys) {
    vector<int> table(size, -1);
    cout << "\n--- Quadratic Probing (Size: " << size << ") ---" << endl;

    for (int key : keys) {
        int h = key % size;
        cout << "Key: " << key << " -> Hash: " << h;
        
        int i = 0;
        int index = h;
        
        // h + i^2 mantığı
        while (table[index] != -1) {
            i++;
            cout << " [DOLU -> i=" << i << "]";
            index = (h + i * i) % size;
        }

        table[index] = key;
        cout << " -> Yerlesti: [" << index << "]" << endl;
    }
    
    cout << "TABLO: ";
    for(int x : table) cout << (x==-1 ? "_" : to_string(x)) << " ";
    cout << endl;
}

int main() {
    // Sınavdaki veriler
    vector<int> data1 = {12, 25, 33, 45, 8};
    linearProbing(11, data1);

    vector<int> data2 = {12, 22, 32};
    quadraticProbing(10, data2); // h(x) + i^2
    
    return 0;
}