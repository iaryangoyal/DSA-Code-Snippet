----------raw code------------------------------------


class Solution {
public:
    int majorityElement(vector<int>& a) {
        unordered_map<int, int> mp;
        int n = a.size();
        
        for(int i=0;i<n;i++) {
            mp[a[i]]++;
        }
        
        for(int i=0;i<n;i++) {
            if(mp[a[i]] > (n/2)) {
                n = a[i];
                break;
            }
        }
        
        return n;
    }
};