#include "validators.h"

int leapYear(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }

    if (year % 400 == 0)
    {
        return 1; 
    }

    return 0;
}

int validateData(int day, int month, int year)
{
    if (day > 0 && day <= 31 && (month == 1 | month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    {
        return 1;
    }

    if (day > 0 && day <= 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    {
        return 1;
    }

    if (leapYear(year) == 1)
    {
        if (day > 0 && day <= 29 && month == 2)
        {
            return 1;
        }

        printf("\n--------------");
        printf("\nData invalida!");
        printf("\n--------------");
        return 0;
    }

    if (leapYear(year) == 0)
    {
        if (day > 0 && day <= 28 && month == 2)
        {
            return 1;
        }
        
        printf("\n--------------");
        printf("\nData invalida!");
        printf("\n--------------");
        return 0;
    }

    printf("\nData inválida\n");
    return 0;

}
