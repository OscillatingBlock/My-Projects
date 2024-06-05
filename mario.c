#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    // Print a pyramid of that height
    for (int k = n; k > 0; k--)
    {
        int no_of_spaces = k - 1;
        int no_of_bricks = n - k + 1;
        // Print row of bricks
        print_row(no_of_spaces, no_of_bricks);
    }
}
void print_row(int spaces, int bricks)
{
    // Print spaces
    for (int i = spaces; i > 0; i--)
    {
        printf(" ");
    }

    // Print bricks
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }

    // Print newline
    printf("\n");
}
