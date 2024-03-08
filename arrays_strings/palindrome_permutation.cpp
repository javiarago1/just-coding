#include <iostream>


/*
 * Given a string, write a function to check if it is a permutation of a palindrome. A
 * palindrome is a word or phrase that is the same forwards and backwards. A permutation is
 * a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
 * You can ignore casing and not-letter characters
 *
 * Example: Tact Coa
 * Output: True (permutations : "taco cat", "atco cta", etc.)
 *
 */


int convert_to_alphabet_pos(char c)
{
    if (c >=  'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else
    {
        return -1;
    }
}


bool palindrome_permutation(char *str)
{
    int map_of_bits = 0;
    int on = 0;
    int i = 0;
    while(*str)
    {
        int pos = convert_to_alphabet_pos(*str);
        if (pos != -1)
        {
            // create mask of specific position in the bit map
            int mask = 1 << pos;
            // deactivate or activate bit in pos
            map_of_bits ^= mask;
            // update counter of BITS on/off
            on += map_of_bits & mask ? 1 : -1;
            i++;
        }
        str++;
    }
    // validates the 2 main cases: odd and even size and palindrome possibilities
    return ((i % 2 == 0) && on == 0) || (i % 2 != 0 && on == 1);
}

int main()
{

    char str[] = "xazzaabba";
    std::cout <<  palindrome_permutation(str);
    return 0;
}