
struct Record {
    int x;
    int y;

    Record(int x, int y)
      : x(x),
        y(y)
    { }
};


class Solution {
public:
    Solution()
      : directs({
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    })
    { }

    /**
     * @param matrix: the given matrix
     * @return: The list of grid coordinates
     */
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        // write your code here

        int num_r = matrix.size();
        if (num_r == 0) {
            return {};
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return {};
        }

        std::vector<std::vector<bool>>
            pacific(num_r, std::vector<bool>(num_c, false));
        {
            std::vector<std::vector<bool>>
                visit(num_r, std::vector<bool>(num_c, false));
            std::queue<Record> queue;

            for (int i = 0 ; i < num_c ; ++i) {
                visit[0][i] = true;
                pacific[0][i] = true;
                queue.push(Record(0, i));
            }
            for (int i = 0 ; i < num_r ; ++i) {
                visit[i][0] = true;
                pacific[i][0] = true;
                queue.push(Record(i, 0));
            }
            floodAndFill(num_r, num_c, matrix, pacific, visit, queue);
        }

        std::vector<std::vector<bool>>
            atlantic(num_r, std::vector<bool>(num_c, false));
        {
            std::vector<std::vector<bool>>
                visit(num_r, std::vector<bool>(num_c, false));
            std::queue<Record> queue;

            for (int i = 0 ; i < num_c ; ++i) {
                visit[num_r - 1][i] = true;
                atlantic[num_r - 1][i] = true;
                queue.push(Record(num_r - 1, i));
            }
            for (int i = 0 ; i < num_r ; ++i) {
                visit[i][num_c - 1] = true;
                atlantic[i][num_c - 1] = true;
                queue.push(Record(i, num_c - 1));
            }
            floodAndFill(num_r, num_c, matrix, atlantic, visit, queue);
        }

        std::vector<std::vector<int>> ans;
        for (int i = 0 ; i < num_r ; ++i) {
            for (int j = 0 ; j < num_c ; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

private:
    void floodAndFill(
            int num_r,
            int num_c,
            const std::vector<std::vector<int>>& grid,
            std::vector<std::vector<bool>>& kind,
            std::vector<std::vector<bool>>& visit,
            std::queue<Record>& queue) {

        while (!queue.empty()) {
            auto point = queue.front();
            queue.pop();

            int x = point.x;
            int y = point.y;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >= 0 && nx < num_r && ny >= 0 && ny < num_c) ||
                    grid[nx][ny] < grid[x][y] ||
                    visit[nx][ny]) {
                    continue;
                }

                visit[nx][ny] = true;
                kind[nx][ny] = true;
                queue.push(Record(nx, ny));
            }
        }
    }

    std::vector<std::vector<int>> directs;
};