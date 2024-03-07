#include <unordered_map>
#include <iostream>
#include <string>


/*
 * Given two strings, write a method to decide if one is permutation of the other
 */

bool check_permutation(const std::string &str1, const std::string &str2)
{
    if (str1.size() != str2.size()) return false;
    std::unordered_map<char, int> map;
    for (char i : str1)
    {
        map[i]++;
    }
    for (char j : str2)
    {
        map[j]--;
        if (map[j] < 0) return false;
    }

    return true;
}

int main()
{

    bool result = check_permutation("holaa", "aloha");
    std::cout << "Is it a permutation? " << (result ? "Yes" : "No");
    return 0;
}
