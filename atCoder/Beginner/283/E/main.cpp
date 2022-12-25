#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll H, W;
ll grid[1010][1010], dp[1010][2], conversions[8][3];

bool is_isolated(ll i, ll j, ll conversion[]) {
    ll dy[4] = {0, 0, -1, 1};
    ll dx[4] = {-1 ,1, 0, 0};
    ll flipped[4] = {conversion[1], conversion[1], conversion[0], conversion[2]};
    ll now = grid[i][j];
    if(conversion[1]) now = 1 - now;
    for(ll k = 0; k < 4; k++) {
        ll nexty = i + dy[k];
        ll nextx = j + dx[k];
        if(nexty < 0 || nexty >= H || nextx < 0 || nextx >= W) continue;
        ll next = grid[nexty][nextx];
        if(flipped[k]) {
            next = 1 - next;
        }
        if(now == next) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;
    for(ll i = 0; i < H; i++) {
        for(ll j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }
    for(ll i = 0; i < H; i++) {
        dp[i][0] = INF;
        dp[i][1] = INF;
    }
    ll cnt = 0;
    for(ll i = 0; i < 2; i++) {
        for(ll j = 0; j < 2; j++) {
            for(ll k = 0; k < 2; k++) {
                conversions[cnt][0] = i;
                conversions[cnt][1] = j;
                conversions[cnt][2] = k;
                cnt++;
            }
        }
    }

    dp[0][0] = 0;
    dp[0][1] = 1;
    for(ll k = 0; k < 8; k++) {
        bool is_possible = true;
        ll under_conversion[3] = {conversions[k][1], conversions[k][2], 0};
        for(ll i = 0; i < W; i++) {
            if(is_isolated(0, i, conversions[k]) || is_isolated(1, i, under_conversion)) {
                is_possible = false;
                break;
            }
        }
        if(is_possible) {
            dp[1][conversions[k][2]] = min(dp[1][conversions[k][2]], conversions[k][1] + conversions[k][2]);
        }
    }

    for(ll i = 2; i < H; i++) {
        for(ll k = 0; k < 8; k++) {
            bool is_possible = true;
            ll under_conversion[3] = {conversions[k][1], conversions[k][2], 0};
            for(ll j = 0; j < W; j++) {
                if(is_isolated(i-1, j, conversions[k]) || is_isolated(i, j, under_conversion)) {
                    is_possible = false;
                    break;
                }
            }
            if(is_possible) {
                dp[i][conversions[k][2]] = min(dp[i][conversions[k][2]], dp[i-2][conversions[k][0]]+ conversions[k][1] + conversions[k][2]);
            }
        }
    }

    if(dp[H-1][0] == INF && dp[H-1][1] == INF) {
        cout << -1 << '\n';
    } else {
        cout << min(dp[H-1][0], dp[H-1][1]);
    }

    return 0;
}