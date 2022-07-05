class Solution {
public:
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumEffortPath(vector<vector<int>> &heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> differenceMatrix(row, vector<int>(col, INT_MAX));
        differenceMatrix[0][0] = 0;
        priority_queue<Cell, vector<Cell>, Comparator> queue;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue.push(Cell(0, 0, differenceMatrix[0][0]));
        while (!queue.empty()) {
            Cell curr = queue.top();
            queue.pop();
            visited[curr.x][curr.y] = true;
            if (curr.x == row - 1 && curr.y == col - 1) return curr.difference;
            for (auto direction : directions) {
                int adjacentX = curr.x + direction[0];
                int adjacentY = curr.y + direction[1];
                if (isValidCell(adjacentX, adjacentY, row, col) &&
                    !visited[adjacentX][adjacentY]) {
                    int currentDifference = abs(heights[adjacentX][adjacentY] -
                                                heights[curr.x][curr.y]);
                    int maxDifference = max(currentDifference,
                                            differenceMatrix[curr.x][curr.y]);
                    if (differenceMatrix[adjacentX][adjacentY] >
                        maxDifference) {
                        differenceMatrix[adjacentX][adjacentY] = maxDifference;
                        queue.push(Cell(adjacentX, adjacentY, maxDifference));
                    }
                }
            }
        }
        return differenceMatrix[row - 1][col - 1];
    }

    bool isValidCell(int x, int y, int row, int col) {
        return x >= 0 && x <= row - 1 && y >= 0 && y <= col - 1;
    }

    class Cell {
    public:
        int x, y;
        int difference;
        Cell(int x, int y, int difference) {
            this->x = x;
            this->y = y;
            this->difference = difference;
        }
    };

    struct Comparator {
        bool operator()(Cell const &p1, Cell const &p2) {
            return p2.difference < p1.difference;
        }
    };
};