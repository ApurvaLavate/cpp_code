/*#include <iostream>
#include <vector>

using namespace std;

void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (magicSquare[newRow][newCol] != 0) {
            row = (row + 1) % n;
        } else {
            row = newRow;
            col = newCol;
        }
    }

    cout << "Magic Square of size " << n << ":\n";
    for (const auto& r : magicSquare) {
        for (int val : r) {
            cout << val << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Please enter an odd number." << endl;
        return 1;
    }

    generateMagicSquare(n);
    return 0;
}*/

/*#include <iostream>

using namespace std;

void generateMagicSquare(int n) {
    int magicSquare[100][100] = {0};

    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num;
        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;
        if (magicSquare[newRow][newCol] != 0) {
            row = (row + 1) % n;
        } else {
            row = newRow;
            col = newCol;
        }
    }

    cout << "Magic Square of size " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;

    cout << "Enter the size of the magic square (odd number): ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Please enter an odd number." << endl;
        return 1;
    }

    generateMagicSquare(n);

    return 0;
}*/

#include <iostream>
using namespace std;

#define N 100

void Magicsquare1(int n, int magicsquare[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            magicsquare[i][j] = 0;
        }
    }

    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        magicsquare[row][col] = num;
        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (magicsquare[newRow][newCol] != 0)
        {
            row = (row + 1) % n;
        }
        else
        {
            row = newRow;
            col = newCol;
        }
    }
}

void printMatrix(int matrix[N][N], int n)
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotateMatrix(int matrix[N][N], int n)
{
    int temp[N][N];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[j][n - 1 - i] = matrix[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = temp[i][j];
}

void reflectionMatrix(int matrix[N][N], int n)
{
    int temp[N][N] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
        {
            temp[i][j] = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp[i][j];
        }
}

int main()
{
    float n;

    cout << "Enter an odd number for the magic square: ";
    cin >> n;
    if ((int)n != n || (int)n % 2 == 0 || n < 0)
    {
        cout<<"enter odd interger";
        return 1;
    }
    else
    {

        int magicsquare[N][N];

        Magicsquare1(n, magicsquare);
        cout << "Original Magic Square:\n";
        printMatrix(magicsquare, n);

        for (int i = 1; i <= 3; i++)
        {
            rotateMatrix(magicsquare, n);
            cout << "Rotation " << i * 90 << " degrees:\n";
            printMatrix(magicsquare, n);
        }

        reflectionMatrix(magicsquare, n);
        cout << "Reflected Magic Square:\n";
        printMatrix(magicsquare, n);

        for (int i = 1; i <= 3; i++)
        {
            rotateMatrix(magicsquare, n);
            cout << "Rotation of Reflected Magic Square " << i * 90 << " degrees:\n";
            printMatrix(magicsquare, n);
        }
    }
    return 0;
}
