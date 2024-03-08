#include <iostream>
#include <queue>

#define SPACE_CHARACTER 32
#define SEPARATOR "%20"
#define SEPARATOR_SIZE 3

/*
 * Write a method to replace all spaces in a string with '%20'. You may assume that the string
 * has sufficient space at the end to hold the additional characters, and that you are given the "true"
 * length of the string. (Note: if implementing in Java, please use a character array so that you can
 * perform this operation in place)
 */



void urlify(char *str, int string_size)
{
    int i = 0;
    std::queue<char> queue;

    while (i < string_size or !queue.empty())
    {
        if (str[i] == SPACE_CHARACTER and i < string_size){
            int j = 0;
            while (j < SEPARATOR_SIZE)
                queue.push(SEPARATOR[j++]);
        }
        if (not queue.empty())
        {
            if (str[i] != SPACE_CHARACTER) queue.push(str[i]);
            str[i] = queue.front();
            queue.pop();
        }
        i++;
    }


}

int main()
{
    // giving space for 2 20s
    char str[18] = "Mr John Smith    ";
    urlify(str, 13);
    std::cout << str << std::endl;
    return 0;
}