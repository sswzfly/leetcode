//greedy
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<pair<int, int> > ans;
        if(people.size() == 0) {
            return people;
        }
        ans.push_back(people[0]);
        for(int i = 1; i < people.size(); i++) {
            int cnt = 0;
            for(auto iter = ans.begin(); iter != ans.end(); iter++) {
                if((*iter).first >= people[i].first) {
                    cnt++;
                }
                if(cnt == people[i].second) {
                    iter++;
                    while(iter != ans.end() && (*iter).first < people[i].first) {
                        iter++;
                    }
                    ans.insert(iter, people[i]);
                    break;
                }
            }
        }
        people.clear();
        for(auto iter = ans.begin(); iter != ans.end(); iter++) {
            people.push_back(*iter);
        }
        return people;
    }

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};
