/*
 * Graph Algorithms Collection
 * Topics: Representation (Adj List), BFS, DFS, Dijkstra (Shortest Path), Prim (MST)
 */

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

// Sonsuzluk değeri
const int INF = 1e9;

class Graph {
    int V; // Düğüm Sayısı
    // Komşuluk Listesi: pair<hedef, ağırlık>
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Kenar Ekleme (Yönsüz varsayıldı, yönlü için ikinci satırı sil)
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    // 1. BFS (Genişlik Öncelikli Arama) - Trace
    void BFS(int start) {
        cout << "\n--- BFS Trace (Baslangic: " << start << ") ---" << endl;
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Ziyaret Sirasi: ";
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for(auto edge : adj[u]) {
                int v = edge.first;
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // 2. DFS (Derinlik Öncelikli Arama) - Recursive Trace
    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        
        for(auto edge : adj[u]) {
            int v = edge.first;
            if(!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int start) {
        cout << "\n--- DFS Trace (Baslangic: " << start << ") ---" << endl;
        vector<bool> visited(V, false);
        cout << "Ziyaret Sirasi: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // 3. Dijkstra (En Kısa Yol) - Trace
    void Dijkstra(int src) {
        cout << "\n--- Dijkstra Trace (Kaynak: " << src << ") ---" << endl;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INF);

        dist[src] = 0;
        pq.push({0, src}); // {mesafe, düğüm}

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            cout << "Secilen Dugum: " << u << " (Mesafe: " << dist[u] << ")" << endl;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                    cout << "   -> Guncelleme: " << v << " artik " << dist[v] << " mesafede." << endl;
                }
            }
        }
        
        cout << "Sonuc Mesafeler: ";
        for(int i=0; i<V; i++) cout << i << ":" << (dist[i]==INF ? -1 : dist[i]) << " ";
        cout << endl;
    }

    // 4. Prim Algoritması (Minimum Spanning Tree - MST)
    // Ağacın tüm düğümlerini en düşük maliyetle birbirine bağlar.
    void PrimMST() {
        cout << "\n--- Prim MST Trace ---" << endl;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int src = 0; // 0'dan başla
        
        vector<int> key(V, INF); // Minimum ağırlıklar
        vector<int> parent(V, -1); // MST yapısı
        vector<bool> inMST(V, false);

        key[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if(inMST[u]) continue;
            inMST[u] = true; // MST kümesine dahil et

            if(u != src)
                cout << "MST'ye Eklendi: " << parent[u] << " - " << u << " (Agirlik: " << key[u] << ")" << endl;

            for (auto edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                // Eğer v MST'de değilse ve ağırlığı daha küçükse güncelle
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }
    }
};

int main() {
    // 5 düğümlü örnek graf (0, 1, 2, 3, 4)
    Graph g(5);

    // Kenarlar: u, v, ağırlık
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    /*
       Graf Yapisi:
         (0) --2--(1)--3--(2)
          |        | \     |
          6        8  5    7
          |        |   \   |
         (3)-------+----9-(4)
    */

    g.BFS(0);
    g.DFS(0);
    g.Dijkstra(0);
    g.PrimMST();

    return 0;
}