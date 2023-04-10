#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;
ll year_dp[2][19], month_dp[4][19], day_dp[19], free_dp[10][19];

bool is_valid_year(string ys) {
  for (ll k = 0; k < 4; k++) {
    if (ys[k] != s[4 + k] && s[4 + k] != 'X') {
      return false;
    }
  }
  return true;
}

bool is_leap_year(ll year) {
  if((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0)) {
    return true;
  } else {
    return false;
  }
}

bool is_valid_month(string ms) {
  for(ll k = 0; k < 2; k++) {
    if(ms[k] != s[2 + k] && s[2 + k] != 'X') {
      return false;
    }
  }
  return true;
}

ll month_type(ll month, ll is_leap) {
  // 0: 28일, 1: 29일, 2: 30일, 3: 31일
  if(month != 2) {
    if((month <= 7 && month % 2) || (month >= 8 && month % 2 == 0)) {
      return 3;
    } else {
      return 2;
    }
  } else {
    if(is_leap) {
      return 1;
    } else {
      return 0;
    }
  }
}

bool is_valid_day(string ds) {
  for(ll k = 0; k < 2; k++) {
    if(ds[k] != s[k] && s[k] != 'X') {
      return false;
    }
  }
  return true;
}

bool is_valid_month_type(ll day, ll month_type) {
  return day <= 28 + month_type;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  for (ll year = 1; year <= 9999; year++) {
    string ys = to_string(year);
    while (ys.size() < 4) ys = "0" + ys;
    if(!is_valid_year(ys)) continue;
    ll sum = 0;
    for(ll k = 0; k < 4; k++) {
      sum += (6 - k) * (ys[k] - '0');
    }
    sum %= 19;
    if(is_leap_year(year)) {
      year_dp[1][sum] += 1;
    } else {
      year_dp[0][sum] += 1;
    }
  }

  #ifdef DEBUG
  ll cnt = 0;
  for(ll i = 0; i < 19; i++) cnt += year_dp[1][i];
  #endif

  for(ll month = 1; month <= 12; month++) {
    string ms = to_string(month);
    while (ms.size() < 2) ms = "0" + ms;
    if(!is_valid_month(ms)) continue;
    ll sum = 0;
    for(ll k = 0; k < 2; k++) {
      sum += (8 - k) * (ms[k] - '0');
    }
    sum %= 19;
    for(ll is_leap = 0; is_leap <= 1; is_leap++) {
      for(ll p_sum = 0; p_sum < 19; p_sum++) {
        month_dp[month_type(month, is_leap)][(p_sum + sum) % 19] += year_dp[is_leap][p_sum];
      }
    }
  }

  for(ll day = 1; day <= 31; day++) {
    string ds = to_string(day);
    while(ds.size() < 2) ds = "0" + ds;
    if(!is_valid_day(ds)) continue;
    ll sum = 0;
    for(ll k = 0; k < 2; k++) {
      sum += (10 - k) * (ds[k] - '0');
    }
    sum %= 19;
    for(ll month_type = 0; month_type < 4; month_type++) {
      for(ll p_sum = 0; p_sum < 19; p_sum++) {
        if(day <= 28 + month_type) {
          day_dp[(sum + p_sum) % 19] += month_dp[month_type][p_sum];
        }
      }
    }
  }

  for(ll i = 0; i < 10; i++) {
    if(s[8] != 'X' && s[8] != '0' + i) continue;
    ll sum = 2 * i;
    sum %= 19;
    for(ll p_sum = 0; p_sum < 19; p_sum++) {
      free_dp[0][(sum + p_sum) % 19] += day_dp[p_sum];
    }
  }

  for(ll n = 1; n < 10; n++) {
    for(ll i = 0; i < 10; i++) {
      if(s[8 + n] != 'X' && s[8 + n] != '0' + i) continue;
      ll sum = (11 - n) * i;
      sum %= 19;
      for(ll p_sum = 0; p_sum < 19; p_sum++) {
        free_dp[n][(sum + p_sum) % 19] += free_dp[n - 1][p_sum];
      }
    }
  }

  ll answer = 0;
  if(s[18] == 'X') {
    for(ll i = 0; i < 19; i++) answer += free_dp[9][i];
  } else {
    ll r = s[18] - '0';
    answer = free_dp[9][r] + free_dp[9][19 - r];
  }

  cout << answer << '\n';

  return 0;
}