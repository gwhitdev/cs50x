#include <stdio.h>
#include <cs50.h>

long getCreditCardNumberFromInput()
{
    long cc;

    do
    {
        cc = get_long("Enter a card number: ");
    }
    while (cc < 0);

    return cc;
}


bool checkIsValid(long number)
{
    int digit = 0;
    int sumOne = 0;
    int sumTwo = 0;
    int count = 0;

    while(number > 0)
    {
        digit = number % 10; // access a digit at a time

        if (count % 2 == 0)
        {
            sumOne += digit; // if the count is an even number, add the current digit to the first sum
        }
        else
        {
            int sumThree = 2 * digit; // else, double the digit and add to sumThree
            sumTwo += (sumThree / 10) + (sumThree % 10); // also, sum the current sumThree's first digit with the current sumThree's last digit
        }

        number /= 10; // reduce the operating number for the next loop
        count++; // increase the loop count
    }
    if (count != 13 && count != 15 && count != 16) return 0; // check if the number length (loop count) is valid, else return 0 (false)
    return (sumOne + sumTwo) % 10 == 0; // return whether the total of sumOne and sumTwo is divisible by 10 (result of the checksum)
}

int getFirstDigits(long number)
{
    long digits = number;
    while (digits > 100)
    {
        digits /= 10;
    }
    return digits;
}

string findCardType(int firstDigits)
{
    if (firstDigits / 10 == 4) return "VISA";

    if (firstDigits == 34 || firstDigits == 37) return "AMEX";

    if (firstDigits == 51 || firstDigits == 52 || firstDigits == 53 || firstDigits == 54 || firstDigits == 55)
        return "MASTERCARD";

    return "INVALID";
}

int main()
{
    long number = getCreditCardNumberFromInput();

    bool isValid = checkIsValid(number);

    if (isValid)
    {
        int firstDigits = getFirstDigits(number);
        printf("%s\n", findCardType(firstDigits));
    }
    else
    {
        printf("%s", "INVALID\n");
    }
    return 0;
}
