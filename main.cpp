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

   cout << Fraction::convertDecimalToFraction(1.) << endl; //expected output: 1
   cout << Fraction::convertDecimalToFraction(.1) << endl; //expected output: 1/10
   cout << Fraction::convertDecimalToFraction(.5) << endl; //expected output: 1/2
   cout << Fraction::convertDecimalToFraction(1.5) << endl; //expected output: 3/2

   return 0;
}