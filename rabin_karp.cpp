#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    string s, p;
    cin >> s >> p;

    vector<long long> ans;

    long long hashVal = 0;
    long long pr = 31;
    long long pow = 1;
    long long mod = 1000000007;

    for (int i = 0; i < p.length(); i++) {
        char c = p[i];
        hashVal = (hashVal + (c - 'a' + 1) * pow) % mod;
        pow = (pow * pr) % mod;
    }

    vector<long long> dp(s.length());
    vector<long long> pa(s.length());
    dp[0] = (s[0] - 'a' + 1);
    pa[0] = 1;
    pow = pr;
    for (int i = 1; i < s.length(); i++) {
        dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * pow) % mod;
        pa[i] = pow;
        pow = (pow * pr) % mod;
    }

    for (int ep = p.length() - 1, sp = 0; ep < s.length(); ep++, sp++) {
        long long chash = dp[ep];
        if (sp > 0) chash = (chash - dp[sp - 1] + mod) % mod;
        if ((hashVal * pa[sp]) % mod == chash) ans.push_back(sp);
    }
    if (ans.size() == 0) {
        cout << "Not Found\n";
    } else {
        cout << ans.size() << "\n";
        for (long long x : ans) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
    return 0;
}


