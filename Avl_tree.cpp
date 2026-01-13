/*
 * AVL Tree Implementation with Trace (Step-by-Step Rotation Logs)
 * Exam Topic: AVL Insertion, Rotations (LL, RR, LR, RL), Balance Factor
 */

#include <iostream>
#include <algorithm>

using namespace std;

// AVL Düğüm Yapısı
struct Node {
    int key;
    Node *left;
    Node *right;
    int height;
};

// Yükseklik alma (NULL güvenli)
int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Yeni düğüm oluşturma
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Yeni eklenen yaprak düğümün yüksekliği 1
    return(node);
}

// Sağa Döndürme (Right Rotate) - Sol-Sol (LL) Durumu için
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Döndürme işlemi
    x->right = y;
    y->left = T2;

    // Yükseklikleri güncelle
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    cout << "   -> Sag Rotasyon (Right Rotate) yapildi. Merkez: " << y->key << endl;
    return x;
}

// Sola Döndürme (Left Rotate) - Sağ-Sağ (RR) Durumu için
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Döndürme işlemi
    y->left = x;
    x->right = T2;

    // Yükseklikleri güncelle
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    cout << "   -> Sol Rotasyon (Left Rotate) yapildi. Merkez: " << x->key << endl;
    return y;
}

// Denge Faktörü (Balance Factor) Hesaplama
int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// AVL Ekleme İşlemi (Recursive)
Node* insert(Node* node, int key) {
    // 1. Standart BST Ekleme
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Aynı anahtara izin verilmez
        return node;

    // 2. Yüksekliği Güncelle
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Denge Faktörünü Kontrol Et
    int balance = getBalance(node);

    // 4. Dengesizlik Varsa 4 Durumdan Birini Uygula

    // Durum 1: Sol Sol (Left Left Case) -> Sağa Döndür
    if (balance > 1 && key < node->left->key) {
        cout << "[Dengesizlik] Node " << node->key << " (Balance: " << balance << ") -> LL Durumu" << endl;
        return rightRotate(node);
    }

    // Durum 2: Sağ Sağ (Right Right Case) -> Sola Döndür
    if (balance < -1 && key > node->right->key) {
        cout << "[Dengesizlik] Node " << node->key << " (Balance: " << balance << ") -> RR Durumu" << endl;
        return leftRotate(node);
    }

    // Durum 3: Sol Sağ (Left Right Case) -> Önce Sola, Sonra Sağa
    if (balance > 1 && key > node->left->key) {
        cout << "[Dengesizlik] Node " << node->key << " (Balance: " << balance << ") -> LR Durumu" << endl;
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Durum 4: Sağ Sol (Right Left Case) -> Önce Sağa, Sonra Sola
    if (balance < -1 && key < node->right->key) {
        cout << "[Dengesizlik] Node " << node->key << " (Balance: " << balance << ") -> RL Durumu" << endl;
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Ağacı yazdırmak için (Preorder)
void preOrder(Node *root) {
    if(root != NULL) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node *root = NULL;
    
    // Örnek Senaryo: Sırayla ekleyelim
    int keys[] = {10, 20, 30, 40, 50, 25};
    
    cout << "--- AVL Agaci Olusturuluyor ---" << endl;
    for(int k : keys) {
        cout << "\nEkleniyor: " << k << endl;
        root = insert(root, k);
        cout << "Guncel Agac (PreOrder): ";
        preOrder(root);
        cout << endl;
    }

    return 0;
}