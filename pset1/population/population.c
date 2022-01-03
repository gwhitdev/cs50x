#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize = 0;

    do
    {
        startSize = get_int("Enter population start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize = 0;

    do
    {
        endSize = get_int("Enter population end size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    while (startSize < endSize)
    {
        startSize = startSize + (startSize / 3) - (startSize / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i \n", years);
}
