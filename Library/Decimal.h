#include <iostream>
#include <vector>
using namespace std;

struct Decimal{

    /**
     * @brief Computes exponential expressions
     * 
     * @param base: integer
     * @param ex: exponent 
     * @return result of the base taking the power of the exponent
     */
    static double power(int base, int ex){

        if(ex == 0) return 1;

        double res = 1;

        for(int i = 0; i < abs(ex); i++){
            res *= base;
        }

        if(ex < 0) return 1/res;

        return res;
    }



    

};