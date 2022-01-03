#include <stdio.h>
#include <cs50.h>

int getHeight()
{
    int height;
    do
    {
        height = get_int("Enter a number: ");
    }
    while (height < 1 || height > 8);

    return height;
}

void drawPyramid(int height)
{
    for(int row = 0; row < height; row++)
    {
        for(int spaces = row + 1; spaces < height; spaces ++)
        {
            printf(" ");
        }

        for(int hashes = height + row + 1; hashes > height; hashes--)
        {
            printf("#");
        }

        printf("  ");
        for(int hashes = height + row + 1; hashes > height; hashes--)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    int height = getHeight();

    drawPyramid(height);

}
