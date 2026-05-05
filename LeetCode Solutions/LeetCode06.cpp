//My first solution
/**class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) { return s;};
        int nCol {0};
        int index {1};
        int cycle {(numRows - 1) * 2};
        int distance {numRows - 2};
        map<int, vector<char>> cmap;
        string result{};
        result.resize(s.length());
        result[0] = s[0];
        for(int i{1}; i<s.length(); ++i)
        {
            if(cycle != 0 && i % cycle == 0)
            {
                cmap[0].push_back(s[i]);
                ++nCol;
            }
            else if(numRows > 1 && i%((numRows-1) + (numRows-1)*2*nCol)==0)
            {
                cmap[numRows - 1].push_back(s[i]);
                i = i + distance;
            }
            else
            {
                cmap[i - ((numRows - 1)*2*nCol)].push_back(s[i]);
                if((i+((((numRows - 1) + (numRows - 1)*2*nCol)-i)*2)) < s.length())
                {
                    cmap[i - ((numRows - 1)*2*nCol)].push_back(s[i+((((numRows - 1) + (numRows - 1)*2*nCol)-i)*2)]);
                }
            }
        }

        for(auto& [key, vec] : cmap)
        {
            for(auto& val : vec)
            {
                if(index < result.length())
                {
                    result[index++] = val;
                }
            }
        }
        return result;
    }
};*/

//My new, more efficient solution
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) { return s; };
        string result;
        int cycle{ (numRows - 1) * 2 };
        result.reserve(s.length());
        for (int i{ 0 }; i < numRows; ++i)
        {
            for (int j{ i }; j < s.size(); j += cycle)
            {
                result += s[j];

                if (i != 0 && i != numRows - 1)
                {
                    int diagonale{ j + cycle - i * 2 };
                    if (diagonale < s.size())
                    {
                        result += s[diagonale];
                    }
                }
            }
        }
        return result;
    }
};
