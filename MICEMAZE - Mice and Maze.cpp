#include <bits/stdc++.h>
using namespace std; 

#define sz  105
#define inf 100000005

typedef pair < int, int > ii; 
typedef vector < ii > vii; 
typedef vector < int > vi; 

vector < vii > a; 
vi dist(sz); 

void bfs(int s, int d) {
        queue < int > q; 
        q.push(s); 

        dist[s] = 0; 

        while ( !q.empty() ) {
                int u = q.front();
                q.pop();

                if ( u == d ) 
                        break;

                for ( auto v : a[u] ) {
                        if ( dist[v.first] > dist[u] + v.second ) {
                                dist[v.first] = dist[u] + v.second;
                                q.push(v.first);
                        }
                }
        }
}

int main()
{
        ios_base :: sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0); 

        // #ifndef Prince77
        //         freopen("Inputs/input.txt", "r", stdin); 
        //         freopen("Inputs/output2.txt", "w", stdout); 
        // #endif

        int n; 
        while ( cin >> n ) {
                int exitCell, minTime; 
                cin >> exitCell; 
                cin >> minTime; 

                a.assign(n+5, vii()); 

                int e; 
                cin >> e; 
                for ( int i = 0; i < e; i++ ) {
                        int u, v, w; 
                        cin >> u >> v >> w; 

                        a[u].push_back({v, w});  
                }

                int cnt = 0;
                for ( int i = 1; i <= n; i++ ) {
                        dist.assign(n+5, inf);

                        bfs(i, exitCell);

                        if ( minTime >= dist[exitCell] ) 
                                cnt++;
                }

                cout << cnt << "\n";
        }        

        return 0; 
}
