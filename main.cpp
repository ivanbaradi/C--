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

   cout << Fraction::simplifyFraction("15/50") << endl; //expected output: 1/3

   return 0;
}