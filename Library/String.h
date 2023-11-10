#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct String {

    /**
     * @brief Determines if a character is a letter
     * 
     * @param ch: character
     * @return {true: character is a letter, false: character is not a letter}
     */
    static bool isLetter(char ch){
        return (int(ch) >= 65 && int(ch) <= 90) || (int(ch) >= 97 && int(ch) <= 122);
    }

    /**
     * @brief Counts the number of same characters from a string
     * 
     * @param str: string to evaluate
     * @param target: specified character to count from a string
     * @return number of occurrences of the same character from a string
     */
    static int countCharacter(string str, char target){

        int charCount = 0;

        for(char ch : str){
            if(ch == target){
                charCount++;
            }
        }

        return charCount;
    }



    /**
     * @brief Counts vowels from a string
     * 
     * @param str: string to evaluate
     * @return number of vowels from a string
     */
    static int countVowels(string str){

        vector <char> vowels{'a','e','i','o','u'};
        int result = 0;

        for(char letter : str){
            if(std::find(vowels.begin(), vowels.end(), tolower(letter)) != vowels.end()){
                result++;
            }
        }

        return result;
    }
    


    /**
     * @brief Reverses a string and stores it as a new string
     * 
     * @param str: string to evaluate
     * @return reversed string of "str"
     */
    static string reverse(string str){

        string reversed = "";
        for(int i = str.length()-1; i >= 0; i--){
            reversed += str[i];
        }

        return reversed;
    }



    /**
     * Determines whether a string is a palindrome
     * 
     * @param str: string to evaluate
     * @return {true: string is a palindrome, false: string is not a palindrome}
     */
    static bool isPalindrome(string str){

        for(int i = 0, j = str.length()-1; i <= j; i++, j--){
            if(str[i] != str[j]){
                return false;
            }
        }

        return true;
    }



    /**
     * @brief Gets all words from the text and makes a list outta them
     * 
     * @param str: string to evaluate
     * @return list of words from a string
     */ 
    static vector <string> breakIntoWords(string str){

        int n = str.length();
        vector <string> words;
        string word = "";

        

        for(int i = 0; i < n; i++){

            char ch = str[i];
            
            if(!isLetter(ch)){ //for non-letters
                if(word != ""){
                    words.push_back(word);
                    word = "";
                }
            } else if(i == n-1){ //last character of string
                word += ch;
                // word += tolower(ch);
                words.push_back(word);
            } else {
                word += ch;
                // word += tolower(ch);
            }
        }

        return words;
    }



    /**
     * @brief Counts all words from a string and puts them to a hashmap
     * 
     * @param str: string to evaluate
     * @return hashmap of words where {key = word, value = occurences of that word} 
     */
    static unordered_map <string, int> countWords(string str){

        unordered_map <string, int> res;
        vector <string> words = breakIntoWords(str);

        for(string word : words){
            // cout << "[" << word << "]\n";
            if(res.find(word) == res.end()){
                res[word] = 1;
            } else {
                res[word]++;
            }
        }

        return res;
    }
};