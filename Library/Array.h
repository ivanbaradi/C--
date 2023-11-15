#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Array{

    /**
     * @brief Prints all strings from an array
     * 
     * @param strs: list of strings
     */
    static void print(vector <string> strs){
        for(string str: strs){
            cout << str << " ";
        }
        cout << endl;
    }



    /**
     * @brief Prints all integers from an array
     * 
     * @param nums: list of numbers
     */
    static void print(vector <int> nums){
        for(int num: nums){
            cout << num << " "; 
        }
        cout << endl;
    }



    /**
     * @brief Creates an array of non-duplicated values
     * 
     * @param nums: list of numbers
     * @return list of duplicated numbers
     */
    static vector <int> removeDuplicates(vector <int> nums){

        vector <int> res;

        for(int num : nums){
            if(std::find(res.begin(), res.end(), num) == res.end()){
                res.push_back(num);
            }
        }

        return res;
    }



    /**
     * @brief Creates an array by multiply values from the current array
     * 
     * @param nums: list of numbers
     * @param factor: multiplies the 1st factor of all numbers from an array
     * @return list of numbers multiplied by the second factor
     */
    static vector <int> multiply(vector <int> nums, int a){
        for(int i = 0; i < nums.size(); i++) nums[i] *= a;
        return nums;
    }



    /**
     * @brief Creates an array of prime numbers
     * 
     * @param nums: list of numbers
     * @return list of primes from numbers array
     */
    static vector <int> getPrimes(vector <int> nums){

        vector <int> primes;

        for(int num : nums){
            if(num != 1){
                
                bool isPrime = true;

                for(int i = num-1; i > 1; i--){
                    if(num % i == 0){
                        isPrime = false;
                        break;
                    }
                }

                if(isPrime){
                    primes.push_back(num);
                }
            }
        }

        return primes;
    }

    
    
    /**
     * @brief Rotates array of integers clockwise
     * 
     * @param nums: array of integers 
     * @param rotations: amount of times to rotate the array clockwise
     */
    static void rotateRight(vector <int> &nums, int rotations){
        for(int i = 0; i < rotations; i++){
            nums.insert(nums.begin(), nums[nums.size()-1]);
            nums.pop_back();
        }
    }



    /**
     * @brief Rotates array of integers counter-clockwise
     * 
     * @param nums: array of integers 
     * @param rotations: amount of times to rotate the array counter-clockwise
     */
    static void rotateLeft(vector <int> &nums, int rotations){
        for(int i = 0; i < rotations; i++){
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }



    /**
     * @brief Sorts the array of strings in ascending or descending order (alphabetical characters ONLY)
     * 
     * @param strs: list of strings
     * @param boolean: sorts the array in ascending order by default unless "false" is passed (OPTIONAL)
     */
    static void sort(vector <string> &strs, bool ascending = true){

        //Swaps strings with specified indices
        auto swap = [&](int i, int j){
            string temp = strs[j];
            strs[j] = strs[i];
            strs[i] = temp;
        };

        int n = strs.size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                
                int strSize = strs[i].size(), strSize2 = strs[j].size();
                int shortStrSize = (strSize < strSize2) ? strSize : strSize2;
                bool success = true;
                
                int k = 0;
                while(k < shortStrSize){
                    if(strs[i][k] != strs[j][k]){
                        success = false;
                        break;
                    }
                    k++;
                }

                if(success){
                    if(ascending){
                        if(strSize > strSize2)
                            swap(i,j);
                    } else {
                        if(strSize < strSize2)
                            swap(i,j);
                    }
                } else {
                    if(ascending){
                        if(int(strs[i][k]) > int(strs[j][k]))
                            swap(i,j);
                    } else {
                        if(int(strs[i][k]) < int(strs[j][k]))
                            swap(i,j);
                    }
                }
            }
        }  
    }



    /**
     * 
     * @brief Finds the smallest value and returns it
     * 
     * @param nums: list of numbers
     * @return smallest number from an array
    */
    static int min(vector <int> nums){

        int smallest = INT_MAX;

        for(int num : nums){
            if(num < smallest)
                smallest = num;
        }

        return smallest;
    }



    /**
     * 
     * @brief Finds the largest value and returns it
     * 
     * @param nums: list of numbers
     * @return largest number from an array
    */
    static int max(vector <int> nums){

        int largest = INT_MIN;

        for(int num : nums){
            if(num > largest)
                largest = num;
        }

        return largest;
    }
};