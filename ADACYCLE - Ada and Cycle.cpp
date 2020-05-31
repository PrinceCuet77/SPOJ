#include <bits/stdc++.h>
using namespace std; 

#define inf 10000005
#define sz 2005

vector < int > a[sz], dist(sz);
vector < bool > visited(sz);

int bfs(int s) {
        queue < int > q;
        q.push(s); 

        dist[s] = 0;
        visited[s] = true;

        while ( !q.empty() ) {
                int u = q.front(); 
                q.pop(); 

                for ( auto v : a[u] ) {
                        if ( v == s ) 
                                return dist[u]+1;

                        if ( visited[v] == false ) {
                                visited[v] = true;
                                dist[v] = dist[u] + 1; 
                                q.push(v);
                        }
                }
        } 

        return inf;
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
                for ( int i = 0; i <= n; i++ ) 
                        a[i].clear();

                for ( int i = 1; i <= n; i++ ) { 
                        for ( int j = 1; j <= n; j++ ) { 
                                int t; 
                                cin >> t; 
                                if ( t == 1 ) 
                                        a[i].push_back(j);
                        }
                }

                for ( int i = 1; i <= n; i++ ) {
                        for ( int k = 0; k <= n; k++ ) {
                                dist[k] = inf; 
                                visited[k] = false;
                        }

                        int val = bfs(i); 

                        if ( val == inf ) cout << "NO WAY\n";
                        else cout << val << "\n";
                }        
        }        

        return 0; 
}
