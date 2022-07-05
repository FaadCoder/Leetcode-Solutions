class Solution
{
    public:
        int countBattleships(vector<vector < char>> &board)
        {
            int rows = board.size();
            int cols = board[0].size();
            int battleships = 0;

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    if (row == 0 and col == 0 and board[row][col] == 'X')
                    {
                        battleships++;
                    }
                    else if (row == 0 and board[row][col] == 'X')
                    {
                        if (board[row][col - 1] == '.')
                            battleships++;
                    }
                    else if (col == 0 and board[row][col] == 'X')
                    {
                        if (board[row - 1][col] == '.')
                            battleships++;
                    }
                    else
                    {
                        if (board[row][col] == 'X'
                            and board[row - 1][col] == '.'
                            and board[row][col - 1] == '.')
                            battleships++;
                    }
                }
            }

            return battleships;
        }
};