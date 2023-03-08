int n, m;
vector<pair<int, int>> dir{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int f[400][400]{0};
bool valid(int i, int j){
    if(i < 0 || i >= n || j >= m || j < 0)return 0;
    return 1;
}
int dfs(int i, int j, vector<vector<int>>& matrix){
    if(f[i][j] != 0){
        return f[i][j];
    }
    for(auto d : dir){
        int dx = d.first, dy = d.second;
        if(!valid(i + dx, j + dy))continue;
        if(matrix[i][j] >= matrix[i + dx][j + dy])continue;
        f[i][j] = max(f[i][j], dfs(i + dx, j + dy, matrix) + 1);
    }
    return f[i][j];
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size();
    m = matrix.back().size();
    int res = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res = max(res,  dfs(i, j, matrix));
        }
    }
    return res + 1;
}