// N QUEENS

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display(const vector<vector<T>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}
bool checkSafe(const vector<vector<char>> &board, int row, int col)
{
    // Check Forward Diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    for (int i = row, j = col; i < board.size() && j < board.size(); i++, j++)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
void SolveNQueens(vector<vector<char>> &board, int row, vector<bool> &checkCol)
{
    for (int col = 0; col < board.size(); col++)
    {
        if (checkSafe(board, row, col) && !checkCol[col])
        {
            board[row][col] = 'Q';
            checkCol[col] = true;
            if (row == (board.size() - 1))
            {
                cout << "\n\n ::Combination of Borad :: \n";
                display(board);
            }
            else
                SolveNQueens(board, row + 1, checkCol);
            board[row][col] = '-';
            checkCol[col] = false;
        }
    }
}
int main()
{
    int boardSize = 0;
    cout << "Enter the board size : ";
    cin >> boardSize;
    vector<vector<char>> board(boardSize, vector<char>(boardSize, '-'));
    vector<bool> checkCol(boardSize, false);
    SolveNQueens(board, 0, checkCol);
    return 0;
}
