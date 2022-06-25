class Pair {
  int time;
  int row;
  int col;
  public:
    Pair(int _time, int _row, int _col) {
      time = _time;
      row = _row;
      col = _col;
    }

  int getTime() {
    return time;
  }

  int getRow() {
    return row;
  }

  int getCol() {
    return col;
  }

  void setTime(int _time) {
    time = _time;
  }

  void setRow(int _row) {
    row = _row;
  }

  void setCol(int _col) {
    col = _col;
  }

};

struct compare {
  bool operator()(Pair & a, Pair & b) {
    return a.getTime() > b.getTime();
  }
};

class Solution {
  int rows, cols;

  int directions[4][2] = {
    {
      1,
      0
    },
    {
      0,
      1
    },
    {
      -1,
      0
    },
    {
      0,
      -1
    }
  };

  int swimInWaterHelper(vector < vector < int >> & grid) {
    priority_queue < Pair, vector < Pair > , compare > pq;
    set < pair < int, int >> vis;

    auto isValid = [ & ](int row, int col) {
      return (row >= 0 and row < rows and col >= 0 and col < cols and!vis.count({
        row,
        col
      }));
    };

    vis.insert({
      0,
      0
    });
    pq.push(Pair(grid[0][0], 0, 0));

    while (!pq.empty()) {
      Pair queueTop = pq.top();
      pq.pop();

      int currentTime = queueTop.getTime();
      int currentRow = queueTop.getRow();
      int currentCol = queueTop.getCol();

      if (currentRow == rows - 1 and currentCol == cols - 1)
        return currentTime;

      for (int dir = 0; dir < 4; dir++) {
        int newRow = currentRow + directions[dir][0];
        int newCol = currentCol + directions[dir][1];

        if (isValid(newRow, newCol)) {
          vis.insert({
            newRow,
            newCol
          });
          pq.push(Pair(max(grid[newRow][newCol], currentTime), newRow, newCol));
        }
      }
    }

    return -1;
  }

  public:
    int swimInWater(vector < vector < int >> & grid) {
      rows = grid.size();
      cols = grid[0].size();

      return swimInWaterHelper(grid);
    }
};