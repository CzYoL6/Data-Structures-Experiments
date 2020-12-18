#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, ecnt;
int anc[N];

struct Edge{
    int u, v;
    long long len;
    Edge():u(0), v(0), len(0){}
    Edge(int _u, int _v, long long _l):u(_u), v(_v), len(_l){}
}edges[N * 2];
long long minLen;


inline int getAnc(int u){
    return u == anc[u] ? u : (anc[u] = getAnc(anc[u]));
}

inline void unite(int u, int v){
    anc[getAnc(u)] = getAnc(v);
}

const bool cmp(const Edge& e1, const Edge& e2){
    return e1.len < e2.len;
}

inline void addEdge(int u, int v, int l){
    edges[++ecnt] = Edge(u, v, l);
}

inline void Kruskal(){
    for(int i = 1; i <= n; i++) anc[i] = i;
    sort(edges + 1, edges + m + 1, cmp);
    int ec = 0;
    for(int i = 1; i <= m; i++){
        const Edge& e = edges[i];
        int u = e.u, v = e.v, l = e.len;
        //cout << u <<" " << v << endl;
        if(getAnc(u) == getAnc(v)) continue;
        cout << "edge " << ++ec << ": " << u << "-------" << v << "  (len: " << l <<")"<<endl;
        minLen += (long long) l;
        unite(u, v);
    }
    cout << "the sum of the length: " << minLen << endl;
}

int main(int argc, char **argv){
    freopen(argv[1], "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    Kruskal();
    return 0;
}