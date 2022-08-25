//solved as blackbox




#include <bits/stdc++.h>

using namespace std;

typedef long long int ln;

typedef long double ld;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ln t = 0;
    cin >> t;

    while (t--)
    {
        ln n = 0, ans = 0, val = 0, dup = 0, prev = 0;
        cin >> n;

        unordered_map <ln, ln> u;

        for (ln i = 0; i < n; i++)
        {
            cin >> val;

            if (u.count (val) > 0)
            {
                u[val] += 1;

                dup = 1;
            }
            else
            {
                u[val] = 1;
            }
        }

        for (auto &x : u)
        {
            ans += (x.second * (n - x.second - prev));  //impppp
 
            prev += x.second; //imppp
        }

        if (dup)
        {
            ans += 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
