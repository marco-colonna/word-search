#include <iostream>

using namespace std;

int main()
{
    const int size1 = 10;
    const int size2 = 10;

    int array[size1][size2] = {};

    // filling array with sum of indices
    for (int i = 0; i < size1; ++i)
        for (int j = 0; j < size2; ++j)
            array[i][j] = (i + j);

    // printing filled array
    for (int i = 0; i < size1; ++i)
        for (int j = 0; j < size2; ++j)
            cout << array[i][j] << " ";
    cout << endl;

    // printing filled array, formatted as a grid
    cout << endl;
    for (int i = 0; i < size1; ++i)
    {
        cout << " ";
        for (int j = 0; j < size2; ++j)
            cout << array[i][j] << "\t";
        cout << endl;
    }
}
