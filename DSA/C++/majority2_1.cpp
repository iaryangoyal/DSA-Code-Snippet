class Solution {
public:
    int majorityElement(vector<int>& nums) {    // function with vector of elements as argument

        // Hash Map to store the frequency of every element in the vector
        unordered_map <int, int> mp;    

        // loop to store the frequency of every element
        for(int i=0; i<nums.size(); i++) {
            
            mp[nums[i]]++;      // frequency of element encountered is increased by 1

        }

        // loop to check frequency of every element encountered
        for(auto it: mp) {

            // if the frequency of any element is found to be greater than n/2, we have found the majority element!!
            if(it.second > nums.size()/2)   
                return it.first;    // therefore we return it.
        }

        return -1;      // we return -1 if majority element doesn't exist
    }
};