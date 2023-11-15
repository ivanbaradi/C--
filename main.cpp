#include <iostream>
#include <unordered_map>
#include <vector>
#include "Library/String.h"
#include "Library/Array.h"
#include "Library/Integer.h"
#include "Library/Decimal.h"
#include "Library/Fraction.h"
using namespace std;


/**
 * @brief Run program here
 * 
 */
int main(){

   Array::print(Fraction::getNumeratorAndDenominator("--32/6"));
   Array::print(Fraction::getNumeratorAndDenominator("-32/6"));
   Array::print(Fraction::getNumeratorAndDenominator("32/6"));

   return 0;
}