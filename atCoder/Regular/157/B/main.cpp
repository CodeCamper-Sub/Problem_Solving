#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, x_cnt, answer;
string s, result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;

    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == 'X') x_cnt++;
    }

    if(x_cnt < k) {
        result = s;
        for(ll i = 0; i < result.size(); i++) {
            result[i] = 'Y';
        }

        k -= x_cnt;
        // 양 끝에 있는 Y먼저 커팅
        for(ll i = 0; i < s.size() && s[i] == 'Y' && k > 0; i++) {
            result[i] = 'X';
            k--;
        }
        for(ll i = s.size() - 1; i >= 0 && s[i] == 'Y' && k > 0; i--) {
            result[i] = 'X';
            k--;
        }

        // 길게 연속된 Y부터 X로 먼저 바꾼다.
        ll left_bound = -INF;
        vector<pair<ll, ll>> intervals;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == 'Y') {
                if(left_bound == -INF) {
                    left_bound = i;
                }
            } else {
                if(left_bound != -INF) {
                    intervals.push_back({left_bound, i});
                }
                left_bound = -INF;
            }
        }
        if(!intervals.empty() && intervals[0].first == 0) {
            intervals.erase(intervals.begin());
        }
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return (a.second - a.first) > (b.second - b.first);
        });
        for(ll i = 0; i < intervals.size() && k > 0; i++) {
            auto [l, r] = intervals[i];
            for(ll j = l; j < r && k > 0; j++) {
                result[j] = 'X';
                k--;
            }
        }
        for(ll i = 0; i < result.size() - 1; i++) {
            if(result[i] == 'Y' && result[i+1] == 'Y') answer++;
        }
        cout << answer << '\n';
    } else {
        result = s;
        // 연속한 짧은 X들을 Y로 바꾼다
        ll left_bound = -INF;
        vector<pair<ll, ll>> intervals;
        for(ll i = 0; i < s.size(); i++) {
            if(s[i] == 'X') {
                if(left_bound == -INF) {
                    left_bound = i;
                }
            } else {
                if(left_bound != -INF) {
                    intervals.push_back({left_bound, i});
                }
                left_bound = -INF;
            }
        }
        if(!intervals.empty() && intervals[0].first == 0) {
            intervals.erase(intervals.begin());
        }
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            return (a.second - a.first) < (b.second - b.first);
        });
        for(ll i = 0; i < intervals.size() && k > 0; i++) {
            auto [l, r] = intervals[i];
            for(ll j = l; j < r && k > 0; j++) {
                result[j] = 'Y';
                k--;
            }
        }
        ll i = 0;
        for(i = 0; i < s.size() && s[i] == 'X'; i++);
        for(ll j = i - 1; j >= 0 && k > 0; j--) {
            result[j] = 'Y';
            k--;
        }

        for(i = s.size()-1; i >= 0 && s[i] == 'X'; i--);
        for(ll j = i + 1; j < s.size() && k > 0; j++) {
            result[j] = 'Y';
            k--;
        }

        for(ll i = 0; i < result.size() - 1; i++) {
            if(result[i] == 'Y' && result[i+1] == 'Y') answer++;
        }
        cout << answer << '\n';
    }

    return 0;
}