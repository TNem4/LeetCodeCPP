#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map <char, int> cmap;
        int length{ 0 };
        int index{ 0 };
        if (s.length() == 0)
        {
            return 0;
        }
        for (int i{ 0 }; i < s.length(); ++i)
        {
            cmap[s[i]]++;

            while (cmap[s[i]] > 1)
            {
                cmap[s[index]]--;
                index++;
            }
            length = max(length, i - index + 1);
        }
        return length;
    }
};