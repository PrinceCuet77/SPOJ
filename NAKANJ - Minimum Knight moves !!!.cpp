#include <bits/stdc++.h>
using namespace std;

#define pii pair < int, int >

bool visited[8][8];
int dist[8][8];

int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

int bfs(int sx, int sy, int dex, int dey) {
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));

        queue < pii > q;
        q.push(pii(sx, sy));

        visited[sx][sy] = true;

        while ( !q.empty() ) {
                pii u = q.front();
                q.pop();

                if ( u.first == dex && u.second == dey )
                        return dist[dex][dey];

                for ( int i = 0; i < 8; i++ ) {
                        int x = u.first + dx[i];
                        int y = u.second + dy[i];

                        if ( visited[x][y] == false && x >= 0 && x < 8 && y >= 0 && y < 8 ) {
                                visited[x][y] = true;
                                dist[x][y] = dist[u.first][u.second] + 1;
                                q.push(pii(x, y));
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
                string ch1, ch2;
                cin >> ch1 >> ch2;

                int s1 = ch1[0] - 'a';
                int s2 = ch1[1] - '0' - 1;

                int d1 = ch2[0] - 'a';
                int d2 = ch2[1] - '0' - 1;

                cout << bfs(s1, s2, d1, d2) << endl;
        }

        return 0;
}
