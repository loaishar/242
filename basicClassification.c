#include <stdio.h>
#include <math.h>
#include "NumClass.h"

/* will return if a number is prime*/ 
int isPrime(int n)
{

int i, flag = 0;

  for (i = 2; i <= n / 2; ++i) {
    // condition for non-prime
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  if (n == 1) {
   return 1;// printf("1 is neither prime nor composite.");
  } 
  else {
    if (flag == 0)
      return 1;
    else
      return 0;
  }


}



/*Strong number is a special number whose sum of the factorial of digits is equal to the original 
number. For Example: 145 is strong number
1! + 4! + 5! = 145
*/

int factorial(int r) {
   int fact = 1;
   while(r>1) {
      fact = fact * r;
      r--;
   }
   return fact;
}
int isStrong(int n) {
   int temp, rem, result = 0;
   temp = n;
   while(temp) {
      rem = temp % 10;
      result = result + factorial(rem);
      temp = temp/10;
   }
   if (result == n)
      return 1;
   else
      return 0;
}