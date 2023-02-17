class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        // Will map, first characrter to strings.
        unordered_map <char, vector<string>> mp;
        // All the unique first chars. (26 max possible).
        unordered_set <char> uni;
        // To check fast if the string is present in initial ideas when we change first char
        // of any string.
        unordered_set <string> ss;
        for (auto s : ideas) {
          mp[s[0]].push_back(s);
          ss.insert(s);
          uni.insert(s[0]);
        }
        /*
          To check if any two strings after swapping there first char, makes a good company name or NOT.
          We can see while swapping chars, we swapped every unique char with this string's first char
          And then we just incremented the cnt[s[0]][ch] means s[0] when swapped with ch, ch + s.substr(1) is Not present in intial ideas
          We do this for all the strings.
          At last we have to multiply all pairs of (i, j) with (j, i) (Convince youself)
        */
        vector <vector<long long>> cnt(26, vector(26, 0LL));
        for (auto s : ideas) {
          for (auto ch : uni) {
            // Changing first char of s with ch.
            string ns = "";
            ns.push_back(ch);
            ns += s.substr(1);
            if (!ss.count(ns)) {
              cnt[s[0] - 'a'][ch - 'a']++;
            }
          }
        }
        for (int i = 0; i < 26; ++i) {
          for (int j = 0; j < 26; ++j) {
            ans += cnt[i][j] * cnt[j][i];
          }
        }
        return ans;
    }
};