#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>

using namespace std;

// --- GRAF YAPISI ---
// Pair: {hedef_dugum, agirlik}
// Adj: vector<vector<pair<int, int>>>
const int INF = 1e9;

// 1. DFS (Recursive) - Kod Yazma Sorusu İçin
void DFS(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " "; // Ziyaret edilen düğümü yaz
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}

// 2. BFS - İzleme Sorusu İçin
void BFS(int start, vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Sirasi: ";
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Komşuları küçükten büyüğe gezmek için adj listesi sıralı olmalı
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// 3. Dijkstra (Detaylı Trace)
void dijkstraTrace(int startNode, int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    
    dist[startNode] = 0;
    
    cout << "\n--- Dijkstra Algoritmasi Trace ---" << endl;
    cout << "Dugum Haritasi: 0:A, 1:B, 2:C, 3:D, 4:E, 5:Z (Ornek)" << endl;

    for (int i = 0; i < n; i++) {
        // 1. Ziyaret edilmemiş en küçük mesafeli düğümü bul
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (dist[u] == INF) break; // Ulaşılamayan yerler kaldı

        visited[u] = true;
        cout << "Secilen Dugum: " << u << " (Mesafe: " << dist[u] << ")" << endl;

        // 2. Komşuları güncelle
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                cout << "  Guncelleme: Dugum " << v << " eski mesafe " << (dist[v]==INF ? "INF" : to_string(dist[v])) 
                     << " -> yeni " << dist[u] + weight << endl;
                dist[v] = dist[u] + weight;
            }
        }
        
        // Şu anki durum
        cout << "  Su anki Mesafeler: ";
        for(int d : dist) {
            if(d == INF) cout << "INF ";
            else cout << d << " ";
        }
        cout << endl << "------------------" << endl;
    }
}

int main() {
    // Dijkstra Örneği (Soru 3 - Graf)
    // 0:A, 1:B, 2:C, 3:D, 4:E, 5:Z
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    // Kenarları ekle (u, v, weight)
    // A -> B(4), A -> C(2)
    adj[0].push_back({1, 4}); adj[0].push_back({2, 2});
    // B -> C(1), B -> D(5)
    adj[1].push_back({2, 1}); adj[1].push_back({3, 5});
    // C -> B(1), C -> D(8), C -> E(10)
    adj[2].push_back({1, 1}); adj[2].push_back({3, 8}); adj[2].push_back({4, 10});
    // D -> E(2), D -> Z(6)
    adj[3].push_back({4, 2}); adj[3].push_back({5, 6});
    // E -> Z(3)
    adj[4].push_back({5, 3});

    dijkstraTrace(0, n, adj);

    return 0;
}