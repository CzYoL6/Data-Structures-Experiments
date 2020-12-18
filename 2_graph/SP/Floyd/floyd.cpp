#include<bits/stdc++.h>
using namespace std;

const int N = 105;
long long dis[N][N];
int n, m;
typedef pair<bool, long long> Pans;

inline void addEdge(int u, int v, int l){
    dis[u][v] = l;
}

Pans floyd(){
    long long minL = 0x7fffffff;
    for(int k = 1; k <= n; k++){
        // cout << k << ":" << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
            if(dis[i][i] < 0) return Pans(false, 0);
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            minL = min(minL, dis[i][j]);
    return Pans(true, minL);
}

int main(int argc, char **argv){
    freopen(argv[1], "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dis[i][j] = 0x7fffffff;
        dis[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b,&c);
        addEdge(a, b, c);
    }
    Pans ans = floyd();
    if(ans.first){
       cout<<ans.second;
    }
    else cout << "contains a negative cycle" << endl;
    return 0;
}