#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int ecnt, adj[N], go[N * 2], nxt[N * 2], len[N * 2];
long long minLen;
bool inTree[N];
int n, m;
typedef pair<int, int> Puv;
typedef pair<int, Puv> Pd_puv;
priority_queue< Pd_puv, vector<Pd_puv>, greater<Pd_puv> > dis;

inline void addEdge(int u, int v, int l){
    nxt[++ecnt] = adj[u],  adj[u]= ecnt, go[ecnt] = v, len[ecnt] = l;
    nxt[++ecnt] = adj[v],  adj[v]= ecnt, go[ecnt] = u, len[ecnt] = l;
}

inline void Prim(int u){
    inTree[u] = true;
    for(int e = adj[u]; e; e = nxt[e])
        dis.push(Pd_puv(len[e], Puv(u, go[e])));
    for(int i = 1; i <= n - 1; i++){
        Pd_puv top;
        do{
            top = dis.top(); dis.pop();
        }while(inTree[top.second.second]);
        int l = top.first, u = top.second.first,v = top.second.second;
        inTree[v] = true;
        minLen += (long long)l;
        for(int e = adj[v]; e; e = nxt[e])
            if(!inTree[go[e]])
                dis.push(Pd_puv(len[e], Puv(v, go[e])));
        cout << "edge " << i << ": " << u << "-------" << v << "  (len: " << l <<")"<<endl;
    }
    cout << "the sum of the length: " << minLen << endl;
}

int main(int argc, char **argv){
    freopen(argv[1], "r", stdin);
    cin >> n >> m;
    memset(len, -1, sizeof(len));
    for(int i = 1; i <= m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    Prim(1);
    return 0;
}