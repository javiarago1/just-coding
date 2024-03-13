#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/*
 * Assume you have a method isSubstring which checks if one word is substring of another. Given two strings,
 * s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (e.g., "waterbottle" is
 * a rotation of "erbottlewat")
 */
bool is_substring(const char *string, size_t str_size, const char *substr, size_t substr_size)
{
    size_t i = 0;
    size_t j;
    while (i + substr_size <= str_size)
    {
        j = 0;
        while(string[i] == substr[j] && j < substr_size)
        {
            j++;
            i++;
        }
        if (j == substr_size) return true;
        i += j == 0 ? 1 : 0;
    }
    return false;
}
bool is_rotation(char *str, size_t str_size, char *rotated_str, size_t rot_str_size)
{
    if (str_size != rot_str_size) return false;
    size_t dest_size = str_size * 2 + 1;
    char temp_str[dest_size];
    strcpy(temp_str, rotated_str);
    strcat(temp_str, rotated_str);
    return is_substring(temp_str, dest_size, str ,str_size);
}

int main()
{
    char * ex_str = "erbottlewat";
    size_t str_size = strlen(ex_str);
    char * rot_str = "waterbottle";
    size_t rot_size = strlen(rot_str);
    printf("Is a rotation: %s\n", is_rotation(ex_str, str_size, rot_str, rot_size) ? "Yes" : "No");
    return 0;
}