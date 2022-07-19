class Solution
{
    public:
        string findShortestWay(vector<vector < int>> &maze, vector< int > &ball, vector< int > &hole)
        {
            const int N = maze.size(),
                M = maze[0].size();
            using Quad = tuple<int, string, int, int> ;

            priority_queue<Quad, vector < Quad>, greater < Quad>> vertices;
            vertices.push({ 0,
                "",
                ball[0],
                ball[1] });

            vector<vector < int>> distances(N, vector<int> (M, INT_MAX));
            distances[ball[0]][ball[1]] = 0;

            unordered_map<char, pair<int, int>> dirs
            {
                {
                    'd',
                    { 1,
                        0 }
                },
                {
                    'u',
                    { -1,
                        0 }
                },
                {
                    'r',
                    { 0,
                        1 }
                },
                {
                    'l',
                    { 0,
                        -1 }
                }
            };

            while (!vertices.empty())
            {
                auto[_, path, i, j] = vertices.top();
                vertices.pop();

                if (i == hole[0] && j == hole[1])
                {
                    return path;
                }

                for (auto[move, dir]: dirs)
                {
                    auto ni = i, nj = j;
                    auto[di, dj] = dir;
                    auto cost = 0;

                    while (ni + di >= 0 && ni + di < N && nj + dj >= 0 && nj + dj < M && maze[ni + di][nj + dj] != 1)
                    {
                        ni += di;
                        nj += dj;
                        ++cost;

                        if (ni == hole[0] && nj == hole[1])
                        {
                            break;
                        }
                    }

                    if ((ni != i || nj != j) && distances[i][j] + cost <= distances[ni][nj])
                    {
                        distances[ni][nj] = distances[i][j] + cost;
                        vertices.push({ distances[ni][nj],
                            path + move,
                            ni,
                            nj });
                    }
                }
            }

            return "impossible";
        }
};