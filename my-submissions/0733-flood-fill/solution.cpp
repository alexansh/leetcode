class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        int n = image.size(), m = image[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != oldColor)
            return;

        image[i][j] = newColor;

        dfs(image, i+1, j, oldColor, newColor);
        dfs(image, i-1, j, oldColor, newColor);
        dfs(image, i, j+1, oldColor, newColor);
        dfs(image, i, j-1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;

        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
