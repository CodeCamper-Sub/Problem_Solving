#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll k, n, hidden_row;
vector<char> start, result, answer, last_result;
vector<vector<char>> ladder;

void go(char who, ll row, ll now) {
  if(row == hidden_row) {
    start[now] = who;
    return;
  }
  if(now < k && ladder[row][now] == '-') {
    go(who, row + 1, now + 1);
  } else if(now > 0 && ladder[row][now - 1] == '-') {
    go(who, row + 1, now - 1);
  } else {
    go(who, row + 1, now);
  }
}

void go2(char who, ll row, ll now) {
  if(row == hidden_row) {
    result[now] = who;
    return;
  }
  if(now < k && ladder[row][now] == '-') {
    go2(who, row - 1, now + 1);
  } else if(now > 0 && ladder[row][now - 1] == '-') {
    go2(who, row - 1, now - 1);
  } else {
    go2(who, row - 1, now);
  }
}

bool go3(char who, ll now) {
  if(now < k && ladder[hidden_row][now] == '-') {
    now += 1;
  } else if(now > 0 && ladder[hidden_row][now - 1] == '-') {
    now -= 1;
  }
  return result[now] == who;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> k >> n;
  start.resize(k);
  result.resize(k);
  last_result.resize(k);
  ladder.assign(n, vector<char>(k));
  for(ll i = 0; i < k; i++) {
    cin >> last_result[i];
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < k - 1; j++) {
      cin >> ladder[i][j];
      if(ladder[i][j] == '?') {
        hidden_row = i;
      }
    }
  }

  for(ll i = 0; i < k; i++) {
    go('A' + i, 0, i);
  }

  for(ll i = 0; i < k; i++) {
    go2(last_result[i], n - 1, i);
  }

  for(ll i = 0; i < k - 1; i++) {
    if(start[i] == result[i]) {
      answer.push_back('*');
    } else if(start[i] == result[i + 1] && start[i + 1] == result[i]) {
      swap(start[i], start[i + 1]);
      answer.push_back('-');
      if(i < k - 2) {
        answer.push_back('*');
      }
      i++;
    } else {
      for(ll i = 0; i < k - 1; i++) {
        cout << 'x';
      }
      return 0;
    }
  }
  
  for(ll i = 0; i < k; i++) {
    if(start[i] != result[i]) {
      for(ll i = 0; i < k - 1; i++) {
        cout << 'x';
      }
      return 0;
    }
  }

  for(ll i = 0; i < answer.size(); i++) {
    cout << answer[i];
  }
  
  return 0;
}