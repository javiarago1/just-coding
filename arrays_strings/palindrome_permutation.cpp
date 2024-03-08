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


int convert_to_alphabet_pos(char c){
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


bool palindrome_permutation(char *str) {
    int map_of_bits = 0;
    int on = 0;
    int i = 0;
    while(*str)
    {
        int temp = convert_to_alphabet_pos(*str);
        if (temp != -1)
        {
            int mask = 1 << temp;
            map_of_bits ^= mask;
            on += map_of_bits & mask ? 1 : -1;
            i++;
        }
        str++;
    }
    return ((i % 2 == 0) && on == 0) || (i % 2 != 0 && on == 1);
}

int main()
{

    char str[] = "xazzaabba";
    std::cout <<  palindrome_permutation(str);
    return 0;
}