class Solution {
public:
    struct S {
        char ch;
        int cnt;
    };
    
    static bool cmp(const S& a, const S& b) {
        return a.cnt > b.cnt;
    }
public:
    string frequencySort(string s) {
        map<char, int> char_map;
        for(int i = 0; i < s.length(); i++) {
            char_map[s[i]]++;
        }
        vector<S> vec;
        for(auto it = char_map.begin(); it != char_map.end(); it++) {
            vec.push_back(S{it->first, it->second});
        }
        sort(vec.begin(), vec.end(), cmp);
        string ans;
        for(int i = 0; i < vec.size(); i++) {
            ans += string(vec[i].cnt, vec[i].ch);
        }
        return ans;
    }
};
