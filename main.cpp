#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayGrid(vector<vector<char>> & grid);

void displayStrings(vector<string> & strings);

void getStrings(vector<vector<char>> & grid, vector<string> & strings, int type);

bool findString(vector<vector<string>> & strings, string key);

bool findStringReverse(vector<vector<string>> & strings, string key);

void foundString(string key, int i, int j, size_t found);

int main()
{
    vector<vector<char>> matrix
    {
        { 'W', 'V', 'E', 'R', 'T', 'I', 'C', 'A', 'L', 'L'},
        { 'R', 'O', 'O', 'A', 'F', 'F', 'L', 'S', 'A', 'B' },
        { 'A', 'C', 'R', 'I', 'L', 'I', 'A', 'T', 'O', 'A' },
        { 'N', 'D', 'O', 'D', 'K', 'O', 'N', 'W', 'D', 'C' },
        { 'D', 'R', 'K', 'E', 'S', 'O', 'O', 'D', 'D', 'K' },
        { 'O', 'E', 'E', 'P', 'Z', 'E', 'G', 'L', 'I', 'W' },
        { 'M', 'S', 'I', 'I', 'H', 'O', 'A', 'E', 'R', 'A' },
        { 'A', 'L', 'R', 'K', 'R', 'R', 'I', 'R', 'E', 'R' },
        { 'K', 'O', 'D', 'I', 'D', 'E', 'D', 'R', 'C', 'D' },
        { 'H', 'E', 'L', 'W', 'S', 'L', 'E', 'U', 'T', 'H' }
    };

    vector<string> key { "SEEK", "FIND", "RANDOM", "SLEUTH", "BACKWARD", "VERTICAL", "DIAGONAL", "WIKIPEDIA", "HORIZONTAL", "WORDSEARCH" };

    vector<vector<string>> strings
    {
        { "", "", "", "", "", "", "", "", "", "" },
        { "", "", "", "", "", "", "", "", "", "" },
        { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
        { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" }
    };

    displayGrid(matrix);

    for (int i = 0; i < strings.size(); ++i)
    {
        getStrings(matrix, strings[i], i);

        displayStrings(strings[i]);
    }

    for (int i = 0; i < key.size(); ++i)
    {
        findString(strings, key[i]);

        findStringReverse(strings, key[i]);
    }
}

void displayGrid(vector<vector<char>> & grid)
{
    cout << endl;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            cout << " " << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void displayStrings(vector<string> & strings)
{
    for (int i = 0; i < strings.size(); ++i)
        cout << strings[i] << endl;
}

// 0 - horizontal, 1 - vertical, 2 - main diagonal, 3 - antidiagonal
void getStrings(vector<vector<char>> & grid, vector<string> & strings, int type)
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
        {
            int index = 0;
            switch (type)
            {
                case 0:
                    index = i;
                    break;
                case 1:
                    index = j;
                    break;
                case 2:
                    index = 9 + i - j;
                    break;
                case 3:
                    index = i + j;
                    break;
                default:
                    return;
            }
            strings[index] += grid[i][j];
        }
    }
}

bool findString(vector<vector<string>> & strings, string key)
{
    for (int i = 0; i < strings.size(); ++i)
    {
        for (int j = 0; j < strings[i].size(); ++j)
        {
            size_t found = strings[i][j].find(key);

            if (found != string::npos)
            {
                foundString(key, i, j, found);
                return true;
            }
        }
    }
    return false;
}

bool findStringReverse(vector<vector<string>> & strings, string key)
{
    for (int i = 0; i < strings.size(); ++i)
    {
        for (int j = 0; j < strings[i].size(); ++j)
        {
            string reversed(strings[i][j].rbegin(), strings[i][j].rend());

            size_t found = reversed.find(key);

            if (found != string::npos)
            {
                foundString(key, i, j, found);
                return true;
            }
        }
    }
    return false;
}

void foundString(string key, int i, int j, size_t found)
{
    cout << "Found " << key << " @" << " i = " << i
        << " j = " << j << " position = " << found << endl;
}
