#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int aj)
{
    static int sum = 0;
    if(aj != 0)
    {
        sum = sum *10 + aj%10;
        isPalindrome(aj/10);   // recursive call same as while(n!=0) using loop
    }
    else if(sum == n)
        return 1;
    else
        return 0;
}

/**************************/

int isArmstrong(int number) 
{

  // declare variables
  int lastDigit = 0;
  int power = 0;
  int sum = 0;

  // temporary variable to store number
  int n = number;

  while(n!=0) {

     // find last digit
     lastDigit = n % 10;

     // find power of digit (order = 3)
     power = lastDigit*lastDigit*lastDigit;

     // add power value into sum
     sum += power;

     // remove last digit
     n /= 10;
  }

  if(sum == number)
    return 0;
  else
    return 1;
}