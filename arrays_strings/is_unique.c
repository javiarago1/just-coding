#include <stdio.h>
#include <stdbool.h>


/*
 *  Implement an algorithm to determine if a string has all unique characters. What if you cannot use
 *  additional data structures?
 */
bool is_unique(char *str)
{
    int character_flags = 0;

    while(*str)
    {
        int alphabet_pos = *str - 97;
        int mask = 1 << alphabet_pos; // ex: 00000100

        // checks if the character has already been seen
        if (character_flags & mask)
            return false;
        
        // overlap the maps of bits (TURN ON LED)
        character_flags |= mask;
        str++;
    }
    return true;
}

/*
int main(void)
{
    char str[] = "helowrd!";
    printf("%s", is_unique(str) ? "Yes" : "No");
    return 0;
}


void printNumberInBits(int number)
{
    int i = 0;
    int mask = 1;
    int total_bits = 32;

    int array[total_bits];

    while (i < total_bits)
    {
        array[i] = number&mask ? 1 : 0;
        number = number >> 1;
        i++;
    }

    while(total_bits > 0)
    {
        printf("%d",array[total_bits - 1]);
        total_bits--;
    }
}
*/