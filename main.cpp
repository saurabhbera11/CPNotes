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
   int n,t;
   cin>>n>>t;
   string s;
   cin>>s;
   vector<int> v;
    for(int i=0;i<n;i++){
        if(s[i]=='B')v.PB(i);
    }

    for(int i=0;i<t;i++){
        for(int itr=0;itr<v.size();itr++){
            int curr=v[itr];
            if(curr+1<s.size() && s[curr+1]=='G') {
                char temp = s[curr];
                s[curr] = s[curr + 1];
                s[curr + 1] = temp;
                v[itr]++;
            }
        }
    }
    cout<<s<<endl;
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
