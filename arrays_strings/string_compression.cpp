#include <iostream>
#include <string>
/*
 * Implement c method to perform basic string compression using the counts of repeated characters. For
 * example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become
 * smaller than the original string, your method should return the original string. You can assume the
 * string has only uppercase and lowercase letters (c-z)
 */

void set_char_and_number(char c, int counter, std::string &str)
{
    str += c;
    char temp[11];
    itoa(counter, temp, 10);
    str += temp;
}

std::string compress_string(std::string str)
{
    int i = 1;
    str += '\0';
    int counter = 1;
    char current_char = str[0];
    std::string buffer_string;

    while(i < str.length())
    {
        if (current_char != str[i])
        {
            set_char_and_number(current_char, counter,buffer_string);
            if (buffer_string.length() >= str.length())
                return str;
            current_char = str[i];
            counter = 0;
        }
        counter++;
        i++;
    }
    return buffer_string;
}

int main()
{
    std::cout <<  "New compressed string: " << compress_string("abbb") << std::endl;
    return 0;
}
