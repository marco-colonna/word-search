#include <iostream>
#include <vector>

using namespace std;

void displayGrid(vector<vector<char>> & grid);

void horizontalString(vector<vector<char>> & grid);

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

    displayGrid(matrix);
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
