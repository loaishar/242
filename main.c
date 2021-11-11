#include <stdio.h>
#include <math.h>
#include "NumClass.h"

/* Function declarations */


void print_isArmstrong(int lowerLimit, int upperLimit);
void print_isPalindrome(int lowerLimit, int upperLimit);
void print_isPrime(int lowerLimit, int upperLimit);
void print_isStrong(int lowerLimit, int upperLimit);


int main()
{
    int lowerLimit, upperLimit;
    
    printf("Enter the lower and upper limit to list primes: ");
    scanf("%d%d", &lowerLimit, &upperLimit);
    
    // Call function to print all primes between the given range.
    print_isArmstrong(lowerLimit, upperLimit);
    print_isPalindrome(lowerLimit, upperLimit);
    print_isPrime(lowerLimit, upperLimit);
    print_isStrong(lowerLimit, upperLimit);
    return 0;
}







void print_isArmstrong(int lowerLimit, int upperLimit)
{
    printf("The Armstrong numbers are:");
    
    while(lowerLimit <= upperLimit)
    {
        // Print if current number is prime.
        if(isArmstrong(lowerLimit))
        {
            printf("%d, ", lowerLimit);
        }
        
        lowerLimit++;
    }
}
/*****************************************/

void print_isPalindrome(int lowerLimit, int upperLimit)
{
    printf("The Palindromes are:");
    
    while(lowerLimit <= upperLimit)
    {
        // Print if current number is prime.
        if(isPalindrome(lowerLimit))
        {
            printf("%d, ", lowerLimit);
        }
        
        lowerLimit++;
    }
}
/************************************************/

/**
 * Print all prime numbers between lower limit and upper limit. 
 */
void print_isPrime(int lowerLimit, int upperLimit)
{
    printf("The Prime numbers are:");
    
    while(lowerLimit <= upperLimit)
    {
        // Print if current number is prime.
        if(isPrime(lowerLimit))
        {
            printf("%d, ", lowerLimit);
        }
        
        lowerLimit++;
    }
}

/***************************************************/
void print_isStrong(int lowerLimit, int upperLimit)
{
    printf("The Strong numbers are:");
    
    while(lowerLimit <= upperLimit)
    {
        // Print if current number is prime.
        if(isStrong(lowerLimit))
        {
            printf("%d, ", lowerLimit);
        }
        
        lowerLimit++;
    }
}