#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;

long long dis[N];
typedef pair<int, int> Pv_e;
typedef pair<bool, long long> Pans;

vector<Pv_e> vex[N];

int start;
vector<int> endList;

inline void addEdge(int u, int v, int l){
    vex[u].push_back(Pv_e(v, l));
}

inline Pans bellman_ford(){
    long long minL = 0x7fffffff;
    for(int u = 1; u <= n; u++){
       cout << u << endl;
        for(int i = 1; i <= n; i++) dis[i] = 0x7fffffff;
        dis[u] = 0;
        for(int i = 1; i <= n - 1; i++){
            for(int v = 1; v <= n; v++){
                for(const Pv_e& pve : vex[v]){
                    int to_vex = pve.first, len = pve.second;
                    dis[to_vex] = min(dis[to_vex], dis[v] + (long long)len);
                }
            }
        }

        for(int v = 1; v <= n; v++){
            for(const Pv_e& pve : vex[v]){
                int to_vex = pve.first, len = pve.second;
                if(dis[to_vex] >  dis[v] + (long long)len) return Pans(false, 0);
            }
        }

        
        for(int i = 1; i <= n; i++) minL = min(minL, dis[i]);
        //cout << minL;
    }
    return Pans(true, minL);
}

int main(int argc, char **argv){
    freopen(argv[1], "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c;
       scanf("%d%d%d", &a, &b,&c);
        addEdge(a, b, c);
    }
    start = 1;
    //  endList = vector<int>{7,37,59,82,99,115,133,165,188,197 };
    // endList = vector<int>{2,3,4,5,6,7,8 };
    Pans ans = bellman_ford();
    if(ans.first){
       cout<<ans.second;
    }
    else cout << "contains a negative cycle" << endl;
    return 0;
}