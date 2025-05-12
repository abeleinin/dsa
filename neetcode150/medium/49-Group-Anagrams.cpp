#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * \c SortingSolution
 * 
 * 1. Create a map of sorted strings to buckets of their unsorted values
 * 2. Process the input strings, using the sorted version as the map key
 * 3. Create the result by appending all the grouped anagram buckets from the map
 * 
 * Time  : O(n k log k)
 * Space : O(n*k)
 * where n = |strs| and k = |strs[i]|
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str_to_anagrams;
    
        for (auto& s : strs) {
            string s_cpy(s);
            sort(s_cpy.begin(), s_cpy.end());
            str_to_anagrams[s_cpy].push_back(s);
        }
    
        vector<vector<string>> res;
        for (auto [_, val] : str_to_anagrams) {
            res.push_back(val);
        }
    
        return res;
    }
};

/**
 * \c ArrayHash
 * 
 * Defines a class that overrides operator() to hash an array<int, 26> object
 * 
 * Uses the Boost hash combine function:
 *    - hash<int>{}(i) produces a unique hash value of i
 *    - 1234 is simply a magic constant to add variance
 *    - (res << 6) + (res >> 2) mixes the existing bits 
 *      in res to spread out the entropy more
 * 
 */
struct ArrayHash {
    size_t operator()(const array<int, 26>& arr) const {
        size_t res = 0;
        for (int i : arr) {
            res ^= hash<int>{}(i) + 1234 + (res << 6) + (res >> 2);
        }
        return res;
    }
};

/**
 * \c ArraySolution
 * 
 * 1. Define a unqiue hash function for array<int, 26> and create a map
 * 2. Count the frequency of each letter in a input str and use that as
 *    the map key
 * 3. Create the result by appending all the grouped anagram buckets from the map
 * 
 * Time  : O(n * k)
 * Space : O(26 * n)
 * where n = |strs| and k = |strs[i]|
 */
class ArraySolution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrayHash> str_to_anagrams;

        for (auto& s : strs) {
            array<int, 26> freq = {0};
            for (char c : s) freq[c-'a']++;
            str_to_anagrams[freq].push_back(s);
        }

        vector<vector<string>> res;
        for (auto [_, val] : str_to_anagrams) {
            res.push_back(val);
        }

        return res;
    }
};