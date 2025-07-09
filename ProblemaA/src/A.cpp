#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int v; // destino
    int cap; // capacidad residual
    int rev; // índice arista inversa
    int ocap; // capacidad original (para obtener el flujo de cada arista)
};

int maxFlow(const vector<vector<pair<int,int>>>& adj)
{
    int n = adj.size();
    /* ---------- construir grafo residual ---------- */
    vector<vector<Edge>> g(n);

    auto addEdge = [&](int u, int v, int c) {
        Edge a{v, c, (int)g[v].size(), c};
        Edge b{u, 0, (int)g[u].size(), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    };

    for (int u = 0; u < n; ++u)
        for (const auto& pr : adj[u])
            addEdge(u, pr.first, pr.second);

    const int SRC = 0, SNK = n - 1, INF = 1e9;
    vector<int> level(n), ptr(n);

    /* ---------- BFS para niveles ---------- */
    auto bfs = [&]() -> bool {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[SRC] = 0;  q.push(SRC);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const Edge& e : g[u])
                if (e.cap > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
        return level[SNK] != -1;
    };

    /* ---------- DFS bloqueante ---------- */
    function<int(int,int)> dfs = [&](int u, int pushed) -> int {
        if (u == SNK || pushed == 0) return pushed;
        for (int& cid = ptr[u]; cid < (int)g[u].size(); ++cid) {
            Edge& e = g[u][cid];
            if (e.cap > 0 && level[e.v] == level[u] + 1) {
                int tr = dfs(e.v, min(pushed, e.cap));
                if (tr) {
                    e.cap -= tr;
                    g[e.v][e.rev].cap += tr;
                    return tr;
                }
            }
        }
        return 0;
    };

    /* ---------- bucle principal Dinic ---------- */
    int flow = 0;
    while (bfs()) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(SRC, INF))
            flow += pushed;
    }
    return flow;
}

struct Mitin {
    int ciudad;
    int hora;
};

bool solve(){
    int P, C; cin >> P >> C;
    if (!cin) return false;

    int G1[P][P]; fill(&G1[0][0],&G1[0][0]+P*P,0);

    // Leer ciudades
    while (C--){
        int a, b, h; cin >> a >> b >> h;
        a--; b--;
        G1[a][b] = G1[b][a] = h;
    }

    // Floyd-Warshall en distancia de ciudades
    for (int i = 0; i < P; i++) for (int j = 0; j < P; j++){
        if (i == j) G1[i][j] = 0;
        else if (!G1[i][j]) G1[i][j] = INT_MAX;
    }
    for (int k = 0; k < P; k++)
        for (int i = 0; i < P; i++) for (int j = 0; j < P; j++)
            if (G1[i][k] != INT_MAX && G1[k][j] != INT_MAX)
                G1[i][j] = min(G1[i][j],G1[i][k]+G1[k][j]);

    // Leer mitines
    vector<Mitin> mitines;
    int N = 0;
    for (int i = 0; i < P; i++){
        int Ni; cin >> Ni;
        N += Ni;
        for (int j = 0; j < Ni; j++){
            int h; cin >> h;
            mitines.push_back({i,h+1});
        }
    }

    // Modelar grafo G2
    int G2[N][N]; fill(&G2[0][0],&G2[0][0]+N*N,0);

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
        if (i == j) continue;
        auto ci = mitines[i].ciudad;
        auto cj = mitines[j].ciudad;
        if (ci == cj) G2[i][j] = 0;
        else /*if (G1[ci][cj])*/ G2[i][j] = G1[ci][cj];
    }
        
    // Crear DAG G3 (como lista de adyacencia)
    vector<int> G3[N];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
        if (i == j) continue;
        auto hi = mitines[i].hora;
        auto hj = mitines[j].hora;
        int t = G2[i][j] == INT_MAX ? INT_MAX : hi+G2[i][j]+2;
        if (t <= hj) G3[i].push_back(j);
    }

    #ifdef DEBUG
    for (int i = 0; i < N; i++){
        cout << i << ": ";
        for (auto x : dag[i]) cout << x << ' ';
        putchar('\n');
    }
    #endif

    // Min path cover DAG
    // 1. Crear grafo bipartito
    vector<vector<pair<int,int>>> g(2*N+2);
    for (int i = 0; i < N; i++)
        for (auto x : G3[i]) g[i+1].push_back({N+x+1,1});

    // 1.5 Añadir Source and Sink (Max Flow)
    for (int i = 0; i < N; i++) g[0].push_back({i+1,1});
    for (int i = 0; i < N; i++) g[N+i+1].push_back({2*N+1,1});

    // 2. Calcular M (Max Bipartite Matching) (usando Dinic)
    int m = maxFlow(g);

    // 3. Solucion: |V| - |M|
    cout << N - m << '\n';

    return true;
}

int main(){
    while (solve());
    return 0;
}