//
// An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).
//
// Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.
//
// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on.  Replace the color of all of the aforementioned pixels with the newColor.
//
// At the end, return the modified image.
//
// Example 1:
//
// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
//
//
//
// Note:
// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
//


class Solution {
public:
    void dfs(vector<vector<int> > & image, vector<vector<int> > & vis, int sr, int sc, int oldColor, int newColor){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int m = image.size(), n = image[0].size();
        image[sr][sc] = newColor; vis[sr][sc] = 1;
        for(int k = 0;k < 4;k++){
            int nr = sr + dx[k], nc = sc + dy[k];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && image[nr][nc] == oldColor){
                dfs(image, vis, nr, nc, oldColor, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        vector<vector<int> > vis(m, vector<int>(n, 0));
        dfs(image, vis, sr, sc, image[sr][sc], newColor);
        return image;
    }
};
