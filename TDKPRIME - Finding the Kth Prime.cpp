#include <bits/stdc++.h>
using namespace std; 

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define N 90000001

vector < int > prime; 
bool a[N];

void sieve() {
        a[0] = a[1] = true; 

        for ( int i = 2; i * i <= N; i++ ) {
                if ( a[i] == false ) {
                        for ( int j = i * i; j <= N; j += i ) 
                                a[j] = true;
                }
        }

        for ( int i = 2; i <= N; i++ ) 
                if ( a[i] == false ) 
                        prime.push_back(i);
}

int main()
{
        IOS;

        // #ifndef prince77
        //         freopen("input.txt", "r", stdin);
        //         freopen("output.txt", "w", stdout);
        // #endif

        sieve();

        int tc; 
        cin >> tc; 
        while ( tc-- ) {
                int n; 
                cin >> n;
                cout << prime[n-1] << endl; 
        }

        return 0;
}
