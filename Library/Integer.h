#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Integer{

    /**
     * @brief Gets all factors from an integer
     * 
     * @param a: integer for getting its factors
     * @return list of all factors from an integer
     */
    static vector <int> getFactors(int a){

        vector <int> factors;

        for(int i = 1; i <= a; i++){
            if(a % i == 0){
                factors.push_back(i);
            }
        }

        return factors;
    }
    
    /**
     * @brief Finds the least common denominator from two integers
     * 
     * @param a: first integer
     * @param b: second integer
     * @return least common denominator from first and second integer
     */
    static int LCD(int a, int b){

        int c = 1, d = 1;

        while(true){

            int res = a * c, res2 = b * d;

            if(res == res2)
                return res;
            
            if(res < res2){
                c++;
            } else {
                d++;
            }
        }
    }



    /**
     * @brief Finds the greatest common denominator from two integers
     * 
     * @param a: first integer
     * @param b: second integer
     * @return greatest common denominator from first and second integer
     */
    static int GCD(int a, int b){

        vector <int> a_factors = getFactors(a), b_factors = getFactors(b);

        vector <int> least_factors, most_factors;
        if(a_factors.size() == b_factors.size()){
            least_factors = a_factors;
            most_factors = b_factors;
        } else {
            least_factors = (a_factors.size() < b_factors.size()) ? a_factors : b_factors; 
            most_factors = (a_factors.size() > b_factors.size()) ? a_factors : b_factors;     
        }

        int i = least_factors.size()-1, j = most_factors.size()-1;
        while(i >= 1 && j >= 1){
           
            if(least_factors[i] == most_factors[j])
                return least_factors[i];
            
            if(least_factors[i] > most_factors[j]){
                i--;
            } else {
                j--;
            }
        }

        return 1;
    }
};
