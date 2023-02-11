#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
    ll x, y;
};

Point s, t;
ll a, b, c, d;
vector<ll> xpath, ypath;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s.x >> s.y;
    cin >> t.x >> t.y;

    cin >> a >> b >> c >> d;

    if((s.x - t.x) % 2 || (s.y - t.y) % 2) {
        cout << "No\n";
        return 0;
    }

    if(a == b && c == d) {
        if(s.x == t.x && s.y == t.y) {
            cout << "Yes\n";
        } else if(2 * a - s.x == t.x && 2 * c - s.y == t.y) {
            cout << "Yes\n";
            cout << a << ' ' << c << '\n';
        } else {
            cout << "No\n";
        }
        return 0;
    } else if(a == b) {
        if(s.x == t.x) {
            ll differ = t.y - s.y;
            while(differ != 0) {
                if(differ > 0) {
                    ypath.push_back(c);
                    ypath.push_back(c+1);
                    differ -= 2;
                } else {
                    ypath.push_back(c+1);
                    ypath.push_back(c);
                    differ += 2;
                }
            }
            for(ll i = 0; i < ypath.size(); i++) {
                xpath.push_back(a);
            }
        } else if(2 * a - s.x == t.x) {
            ypath.push_back(c);
            s.y = 2 * c - s.y;
            ll differ = t.y - s.y;
            while(differ != 0) {
                if(differ > 0) {
                    ypath.push_back(c);
                    ypath.push_back(c+1);
                    differ -= 2;
                } else {
                    ypath.push_back(c+1);
                    ypath.push_back(c);
                    differ += 2;
                }
            }
            for(ll i = 0; i < ypath.size(); i++) {
                xpath.push_back(a);
            }
        } else {
            cout << "No\n";
            return 0;
        }
    } else if(c == d) {
        if(s.y == t.y) {
            ll differ = t.x - s.x;
            while(differ != 0) {
                if(differ > 0) {
                    xpath.push_back(a);
                    xpath.push_back(a+1);
                    differ -= 2;
                } else {
                    xpath.push_back(a+1);
                    xpath.push_back(a);
                    differ += 2;
                }
            }
            for(ll i = 0; i < xpath.size(); i++) {
                ypath.push_back(c);
            }
        } else if(2 * c - s.y == t.y) {
            xpath.push_back(a);
            s.x = 2 * a - s.x;
            ll differ = t.x - s.x;
            while(differ != 0) {
                if(differ > 0) {
                    xpath.push_back(a);
                    xpath.push_back(a+1);
                    differ -= 2;
                } else {
                    xpath.push_back(a+1);
                    xpath.push_back(a);
                    differ += 2;
                }
            }
            for(ll i = 0; i < xpath.size(); i++) {
                ypath.push_back(c);
            }
        } else {
            cout << "No\n";
            return 0;
        }
    } else {
        ll differ = t.x - s.x;
        while(differ != 0) {
            if(differ > 0) {
                xpath.push_back(a);
                xpath.push_back(a+1);
                differ -= 2;
            } else {
                xpath.push_back(a+1);
                xpath.push_back(a);
                differ += 2;
            }
        }
        differ = t.y - s.y;
        while(differ != 0) {
            if(differ > 0) {
                ypath.push_back(c);
                ypath.push_back(c+1);
                differ -= 2;
            } else {
                ypath.push_back(c+1);
                ypath.push_back(c);
                differ += 2;
            }
        }
        
        while(xpath.size() != ypath.size()) {
            if(xpath.size() < ypath.size()) {
                xpath.push_back(a);
            } else {
                ypath.push_back(c);
            }
        }
    }

    assert(xpath.size() == ypath.size());
    cout << "Yes\n";
    for(ll i = 0; i < xpath.size(); i++) {
        cout << xpath[i] << ' ' << ypath[i] << '\n';
    }

    return 0;
}