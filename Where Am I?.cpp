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


bool isValid(int mid,string s){
    unordered_set<string> hs;
    int i=0;int j=mid;
    while (i+j<=s.size()){
    string curr=s.substr(i,j);
    if(hs.find(curr)!=hs.end())return false;
    hs.insert(curr);
    i++;
    }
    return true;
}

void testcase() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int low=1;
    int high=n;
    int ans=1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(isValid(mid,s)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}



int main() {
    FastIO;
#ifndef ONLINE_JUDGE
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int t=1;
//    cin >> t;
    while (t--) {
        testcase();
    }
}
