#include <iostream>

/*
 * There are three types of edits that can be performed on strings: insert a character, remove a
 * character, or replace a character. Given two strings, write a function to check if they are
 * one edit (or zero edits) away.
 */

bool is_one_edit(std::string str1, std::string str2)
{
    if (abs((int)(str1.length() - str2.length())) >= 2) return false;
    int i = 0;
    int j = 0;
    bool has_edit_before = false;
    while (i < str1.length() && j < str2.length())
    {
        if (str1[i] != str2[j])
        {
            if (has_edit_before)
            {
                return false;
            }
            if (str2[j + 1] == str1[i + 1])
            {
                j += 2;
                i += 2;
            }
            else if (str1[i] == str2[j + 1])
            {
                j += 2;
                i++;
            }
            else if (str2[j] == str1[i + 1])
            {
                i += 2;
                j++;
            }
            else
            {
                return false;
            }
            has_edit_before = true;
        }
        else
        {
            i++;
            j++;
        }

    }
    return !((((str1.length() - i == 1)  || (str2.length() - j == 1)) && has_edit_before));
}

int main()
{
    std::cout << "Is it 1 (or 0) edits away? " << (is_one_edit("a", "bd") ? "Yes" : "No") << std::endl;
    return 0;
}