class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {    // function with vector of elements as argument

        // vector to store all the majority elements
        vector <int> ans;

        // Hash Map to store the frequency of every element in the vector
        unordered_map <int, int> mp;

        // loop to store the frequency of every element
        for(int i=0; i<nums.size(); i++) {

            mp[nums[i]]++;      // frequency of element encountered is increased by 1

        }

        // loop to check frequency of every element encountered
        for(auto it: mp) {

            // if the frequency of any element is found to be greater than n/3, it is one of the majority elements
            if(it.second > nums.size()/3)
                ans.push_back(it.first);    // therefore we push the element in the ans vector
        }

        return ans;     // finally we return the ans vector
    }
};