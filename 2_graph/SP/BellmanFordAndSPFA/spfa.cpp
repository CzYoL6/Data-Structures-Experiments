#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m;

long long dis[N];
typedef pair<int, int> Pv_e;
typedef pair<bool, long long> Pans;

vector<Pv_e> vex[N];

queue<int> que;
bool inQueue[N];
int enQueueTimes[N];

inline void addEdge(int u, int v, int l){
    vex[u].push_back(Pv_e(v, l));
}

inline Pans spfa(){
    long long minL = 0x7fffffff;
    for(int u = 1; u <= n; u++){
       // cout<<u<<endl;
        while(!que.empty()) que.pop();
       //cout << u << endl;
        for(int i = 1; i <= n; i++) dis[i] = 0x7fffffff, enQueueTimes[i] = 0, inQueue[i] = false;
        dis[u] = 0;
        que.push(u);
        enQueueTimes[u]++;
        inQueue[u] = true;
        while(!que.empty()){
            int v = que.front(); que.pop();
            inQueue[v] = false;
            for(const Pv_e& pve : vex[v]){
                int to_vex = pve.first, len = pve.second;
                if(dis[to_vex] > dis[v] + (long long) len){
                    dis[to_vex] = dis[v] + (long long)len;
                    if(!inQueue[to_vex]){
                        inQueue[to_vex] = true;
                        que.push(to_vex);
                        enQueueTimes[to_vex]++;
                        if(enQueueTimes[to_vex] > n) return Pans(false, 0);
                    }
                }
            }
        }
        
        for(int i = 1; i <= n; i++) minL = min(minL, dis[i]);
        cout << u << " as the source:" << minL << endl;
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
    //  endList = vector<int>{7,37,59,82,99,115,133,165,188,197 };
    // endList = vector<int>{2,3,4,5,6,7,8 };
    Pans ans = spfa();
    if(ans.first){
       cout<<ans.second;
    }
    else cout << "contains a negative cycle" << endl;
    return 0;
}