#include <stdio.h>
#include <math.h>
#include "NumClass.h"

/* will return if a number is Armstrong number 
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
For Example: 407 = 43 + 03 + 73 = 64 + 0 + 343 = 407
*/
int isArmstrong(int num) 


{
   int num, originalNum, remainder, n = 0;
   float result = 0.0;

   originalNum = num;

   // store the number of digits of num in n
   for (originalNum = num; originalNum != 0; ++n) {
       originalNum /= 10;
   }

   for (originalNum = num; originalNum != 0; originalNum /= 10) {
       remainder = originalNum % 10;

      // store the sum of the power of individual digits in result
      result += pow(remainder, n);
   }

   // if num is equal to result, the number is an Armstrong number
   if ((int)result == num)
         return 1;
   else
         return 0;
}









/* will return if a number is a palindrome */ 
int isPalindrome(int n)
{
int n, reversed = 0, remainder, original;
    original = n;

    // reversed integer is stored in reversed variable
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    // palindrome if orignal and reversed are equal
    if (original == reversed)
        return 1;
    else
        return 0;

    





}
