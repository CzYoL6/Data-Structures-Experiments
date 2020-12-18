#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int ecnt, adj[N], go[N * 2], nxt[N * 2], len[N * 2];
long long dis[N];
bool confirmed[N];
typedef pair<long long, int> Pd_v;
priority_queue< Pd_v, vector<Pd_v>, greater<Pd_v> > que;

int start;
vector<int> endList;

inline void addEdge(int u, int v, int l){
    nxt[++ecnt] = adj[u],  adj[u]= ecnt, go[ecnt] = v, len[ecnt] = l;
}

inline void dijkstra(int u){
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    dis[u] = 0;
    que.push(Pd_v(0, u));
    while(!que.empty()){
        Pd_v top = que.top(); que.pop();
        int m = top.second;
        //cout << m << endl;
        for(int e = adj[m]; e; e = nxt[e]){
            int v = go[e];
            if(confirmed[v]) continue;
            if(dis[v] > dis[m] + len[e]){
                dis[v] = dis[m] + len[e];
            }
            que.push(Pd_v(dis[v], v));
        }
        confirmed[m] = true;
    }
    
}

int main(int argc, char **argv){
    freopen(argv[1], "r", stdin);
    int tmp;
    while(scanf("%d", &tmp)==1){
         int b, c;
         char _n;
        while(scanf("%[\n]", &_n) == 0){
            scanf("%d%*[,]%d", &b, &c);
            addEdge(tmp, b, c);
            //cout << tmp <<" " << b << " " << c << endl;
        }
        
    }
    start = 1;
    endList = vector<int>{7,37,59,82,99,115,133,165,188,197 };
    // endList = vector<int>{2,3,4,5,6,7,8 };
    dijkstra(1);
    for(const int& x: endList){
        cout << "the shortest path from " << start <<" to " << x << " is " << dis[x] << endl;
    }
    return 0;
}