#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct HashMap {

    /**
     * @brief Converts array of numbers to hashmap
     * 
     * @param nums: list of numbers
     * @return hashmap of numbers where {key: identifier, value: number}
     */
    static unordered_map <int, int> convertArrayToHashMap(vector <int> nums){

        unordered_map <int, int> numsMap;

        for(int i = 0; i < nums.size(); i++){
            numsMap[i+1] = nums[i];
        }

        return numsMap;
    }



    /**
     * @brief Converts array of strings to hashmap
     * 
     * @param strs: list of strings
     * @return hashmap of strings where {key: identifier, value: string}
     */
    static unordered_map <int, string> convertArrayToHashMap(vector <string> strings){

        unordered_map <int, string> stringsMap;

        for(int i = 0; i < strings.size(); i++){
            stringsMap[i+1] = strings[i];
        }

        return stringsMap;
    }
};
