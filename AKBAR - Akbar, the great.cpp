#include <bits/stdc++.h>
using namespace std;

#define node 1000005

vector < int > dist(node), a[node];
vector < bool > visited(node);

void bfs(int source, int strength) {
        queue < int > q;
        q.push(source);

        visited[source] = true;
        dist[source] = 0;

        while ( !q.empty() ) {
                int u = q.front();
                q.pop();

                for ( auto v : a[u] ) {
                        if ( visited[v] == false ) {
                                if ( dist[u] < strength ) {
                                        visited[v] = true;
                                        dist[v] = dist[u] + 1;
                                        q.push(v);
                                }
                        }
                }
        }
}

int main()
{
        //freopen("file.txt", "r", stdin);
        int tc;
        cin >> tc;
        while ( tc-- ) {
                int n, r, m;
                cin >> n >> r >> m;

                for ( int i = 0; i <= n; i++ ) {
                        a[i].clear();
                        visited[i] = false;
                        dist[i] = 0;
                }

                for ( int i = 0; i < r; i++ ) {
                        int u, v;
                        cin >> u >> v;
                        a[u].push_back(v);
                        a[v].push_back(u);
                }

                bool flag = false;
                for ( int i = 0; i < m; i++ ) {
                        int s, sth;
                        cin >> s >> sth;

                        if ( sth == 0 ) {
                                if ( visited[s] == true )
                                        flag = true;
                                else
                                        visited[s] = true;
                        }
                        else {
                                if ( visited[s] == true )
                                        flag = true;
                                else
                                        bfs(s, sth);
                        }
                }

                if ( flag )
                        cout << "No" << endl;
                else {
                        for ( int i = 1; i <= n; i++ ) {
                                if ( visited[i] == false ) {
                                        flag = true;
                                        break;
                                }
                        }

                        if ( flag )
                                cout << "No" << endl;
                        else
                                cout << "Yes" << endl;
                }
        }

        return 0;
}
