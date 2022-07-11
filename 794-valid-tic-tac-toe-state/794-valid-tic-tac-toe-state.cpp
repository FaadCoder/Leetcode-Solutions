class Solution
{
    public:
        bool validTicTacToe(vector<string> &board)
        {
            int turns = 0;
            int row[3] = { 0
            }, col[3] = { 0
            }, diag = 0, antiDiag = 0;

            int rows = board.size();

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == 'X')
                    {
                        row[i]++;
                        col[j]++;
                        turns++;
                        if (i == j)
                            diag++;
                        if (i + j == 2)
                            antiDiag++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        row[i]--;
                        col[j]--;
                        turns--;
                        if (i == j)
                            diag--;
                        if (i + j == 2)
                            antiDiag--;
                    }
                }
            }

            int xWin = (row[0] == 3 or row[1] == 3 or row[2] == 3 or col[0] == 3 or col[1] == 3 or col[2] == 3 or diag == 3 or antiDiag == 3);

            int oWin = (row[0] == -3 or row[1] == -3 or row[2] == -3 or col[0] == -3 or col[1] == -3 or col[2] == -3 or diag == -3 or antiDiag == -3);
            
            if((turns==0 and xWin) or (turns==1 and oWin))
                return false;
            
            if(oWin and xWin)
                return false;
            
            return (turns == 0 or turns==1);
        }
};