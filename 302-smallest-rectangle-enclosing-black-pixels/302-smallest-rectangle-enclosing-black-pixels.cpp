class Solution {
public:
  int minArea(const vector<vector<char>>& image, int xx, int yy) {
    x = xx;
    y = yy;
    img = image;
    int r = right(), l = left(), b = bottom(), t = top();
    return (r - l + 1) * (b - t + 1);
  }

private:
  vector<vector<char>> img;
  int x, y;
  
  int left() const {
    int l = 0, r = y - 1;
    while (l <= r) {
      int mid = l + (r - l)/2;
      if (goodCol(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r + 1;
  }
  
  int right() const {
    int l = y + 1, r = img[0].size() - 1;
    while (l <= r) {
      int mid = l + (r - l)/2;
      if (goodCol(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l - 1;
  }
  
  int bottom() const {
    int l = x + 1, r = img.size() - 1;
    while (l <= r) {
      int mid = l + (r - l)/2;
      if (goodRow(mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return l - 1;
  }
  
  int top() const {
    int l = 0, r = x - 1;
    while (l <= r) {
      int mid = l + (r - l)/2;
      if (goodRow(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r + 1;
  }  
  
  bool goodCol(int c) const {
    for (int i = 0; i < img.size(); ++i) {
      if (img[i][c] == '1') {
        return true;
      }
    }
    return false;
  }
  
  bool goodRow(int r) const {
    for (int i = 0; i < img[0].size(); ++i) {
      if (img[r][i] == '1') {
        return true;
      }
    }
    return false;
  }
};