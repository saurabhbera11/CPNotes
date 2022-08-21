#include <bits/stdc++.h>
using namespace std;
 
typedef long long int lli;
typedef vector<int> vi;
typedef vector<long long int> vl;
typedef vector<vector<int>> vvin;
typedef vector<vector<long long int>> vvln;
typedef map<int, int> mii;
typedef map<char, int> mci;
#define endl '\n'
#define FOR(i, n) for (int i = 0; i < n; i++)
#define MP make_pair
#define PB push_back
#define FastIO                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
const lli mod = 1e9 + 7;
 
void testcase() {
    int n;
    cin>>n;
    lli sx=0,sy=0,sz=0;
    for(int i=0;i<n;i++){
       int x,y,z;
       cin>>x>>y>>z;
       sx+=x;
       sy+=y;
       sz+=z;
    }
    string res=(sx==0 && sy==0 && sz==0)?"YES":"NO";
    cout<<res;
    return;
}
 
int main() {
    FastIO;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
    int t=1;
//    cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}
