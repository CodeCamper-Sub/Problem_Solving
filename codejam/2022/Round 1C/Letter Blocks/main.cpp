#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n;
string s_i;
int used_alphabats[30];

string compress_str(string source) {
    string result = "";
    result += source.front();
    char now = source.front();
    for(int k = 1; k < source.size(); k++) {
        if(now != source[k]) {
            result += source[k];
            now = source[k];
        }
    }
    return result;
}
bool is_valid_for_initial(string new_string) {
    string compressed_string = compress_str(new_string);
    for(int k = 0; k < compressed_string.size(); k++) {
        char now = compressed_string[k];
        if(used_alphabats[now - 'A'] == 1) {
            return false;
        } else {
            used_alphabats[now - 'A'] = 1;
        }
    }
    return true;
}

bool is_valid_for_prefix(string new_string, char prefix) {
    string compressed_string = compress_str(new_string);
    for(int k = 0; k < compressed_string.size()-1; k++) {
        char now = compressed_string[k];
        if(used_alphabats[now - 'A'] == 1) {
            return false;
        } else {
            used_alphabats[now - 'A'] = 1;
        }
    }
    return true;
}

bool is_valid_for_suffix(string new_string, char suffix) {
    string compressed_string = compress_str(new_string);
    for(int k = 1; k < compressed_string.size(); k++) {
        char now = compressed_string[k];
        if(used_alphabats[now - 'A'] == 1) {
            return false;
        } else {
            used_alphabats[now-'A'] = 1;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(int T = 1; T <= t; T++) {
        cin >> n;
        for(int i = 0; i <= 26; i++) {
            used_alphabats[i] = 0;
        }

        vector<string> continuous_set[30];
        vector<string> normal_set;
        string answer;
        bool is_impossible = false;

        for(int i = 1; i <= n; i++) {
            cin >> s_i;
            if(s_i.size() == 1) {
                continuous_set[s_i[0] - 'A'].push_back(s_i);
            } else {
                char inital_char = s_i[0];
                char continous_flag = true;
                for(int k = 1; k < s_i.size(); k++) {
                    if(s_i[k] != inital_char) {
                        continous_flag = false;
                        break;
                    }
                }
                if(continous_flag) {
                    continuous_set[inital_char - 'A'].push_back(s_i);
                } else {
                    normal_set.push_back(s_i);
                }
            }
        }
        char prefix, suffix;
        if(normal_set.size() > 0) {
            string temp = normal_set.back();
            normal_set.pop_back();
            prefix = temp[0];
            suffix = temp.back();
            is_impossible = !is_valid_for_initial(temp);
            answer = temp;
            while (!continuous_set[prefix - 'A'].empty()) {
                string prefix_str = continuous_set[prefix - 'A'].back();
                answer = prefix_str + answer;
                continuous_set[prefix - 'A'].pop_back();
            }
            while (!continuous_set[suffix - 'A'].empty()) {
                string suffix_str = continuous_set[suffix - 'A'].back();
                answer = answer + suffix_str;
                continuous_set[suffix - 'A'].pop_back();
            }

            while (!normal_set.empty()) {
                while (!continuous_set[prefix - 'A'].empty()) {
                    string prefix_str = continuous_set[prefix - 'A'].back();
                    answer = prefix_str + answer;
                    continuous_set[prefix - 'A'].pop_back();
                }
                while (!continuous_set[suffix - 'A'].empty()) {
                    string suffix_str = continuous_set[suffix - 'A'].back();
                    answer = answer + suffix_str;
                    continuous_set[suffix - 'A'].pop_back();
                }

                string prefix_str = "";
                string suffix_str = "";
                for (auto iter = normal_set.begin(); iter != normal_set.end(); iter++) {
                    string now = *iter;
                    if (now.back() == prefix) {
                        prefix_str = now;
                        normal_set.erase(iter);
                        is_impossible = !is_valid_for_prefix(prefix_str, prefix);
                        break;
                    }
                }
                if (is_impossible) {
                    break;
                }
                for (auto iter = normal_set.begin(); iter != normal_set.end(); iter++) {
                    string now = *iter;
                    if (now.front() == suffix) {
                        suffix_str = now;
                        normal_set.erase(iter);
                        is_impossible = !is_valid_for_suffix(prefix_str, prefix);
                        break;
                    }
                }
                if (is_impossible || (prefix_str == "" && suffix_str == "")) {
                    is_impossible = true;
                    break;
                }
                answer = prefix_str + answer;
                answer = answer + suffix_str;
                prefix = answer.front();
                suffix = answer.back();
            }
        }
        for(int i = 0; i <= 26; i++) {
            if(!continuous_set[i].empty() && used_alphabats[i] == 1) {
                is_impossible = true;
                break;
            }
            while(!continuous_set[i].empty()) {
                string prefix_str = continuous_set[i].back();
                answer = prefix_str + answer;
                continuous_set[i].pop_back();
            }
        }
        if(is_impossible) {
            cout << "Case #" << T << ": IMPOSSIBLE\n";
        } else {
            cout << "Case #" << T << ": " << answer << "\n";
        }
    }
    return 0;
}