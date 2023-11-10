#include <iostream>
#include <unordered_map>
#include <vector>
#include "Library/String.h"
#include "Library/Array.h"
#include "Library/Integer.h"
using namespace std;

/**
 * @brief Run program here
 * 
 */
int main(){

   int a = 2, b = 31;

   cout << "a = " << a << ", b = " << b << endl;
   cout << "LCD of 'a' and 'b': " << Integer::LCD(a,b) << endl;
   cout << "GCD of 'a' and 'b': " << Integer::GCD(a,b) << endl;

   return 0;
}