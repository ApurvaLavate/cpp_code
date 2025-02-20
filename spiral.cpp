#include <iostream>
using namespace std;
void spiral(float A[10][10], int c, int r)
{
    int i;
    int t = 0;     // top
    int b = r - 1; // bottom
    int left = 0;
    int right = c - 1;
    while (t <= b && left <= right)
    {
        for (i = left; i <= right; i++)
            cout << A[t][i] << " ";
        t++;

        for (i = t; i <= b; i++)
            cout << A[i][right] << " ";
        right--;

        if (t <= b)
        {
            for (i = right; i >= left; i--)
                cout << A[b][i] << " ";
            b--;
        }
        if (left <= right)
        {
            for (i = b; i >= t; i--)
                cout << A[i][left] << " ";
            left++;
        }
    }
}
int main()
{
    float r, c;
    int i, j;
    float A[10][10];

    cout << "Enter number of rows and columns ";
    cin >> r >> c;
    while ((int)r != r || (int)c != c || r <= 0 || c <= 0)
    {
        cout << "Invalid input. Please enter positive integers and non decimal for rows and columns: ";
        cin >> r >> c;
    }

    cout << "Enter the elements row-wise: ";
    for (i = 0; i < (int)r; i++)
    {
        for (j = 0; j < (int)c; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "The matrix is:\n";
    for (i = 0; i < (int)r; i++)
    {
        for (j = 0; j < (int)c; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\nArray in spiral order: ";
    spiral(A, (int)c, (int)r);

    return 0;
}
