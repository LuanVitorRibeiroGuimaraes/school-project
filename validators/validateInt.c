#include "validators.h"

int validateInt()
{
    int value;
    int scanfResult;
	int c;

    scanfResult = scanf("%d", &value);
    if (scanfResult != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF) { } 
        return -1; 
    }

    return value;
}