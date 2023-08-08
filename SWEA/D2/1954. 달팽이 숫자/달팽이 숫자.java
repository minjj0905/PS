import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    int tc = Integer.parseInt(br.readLine());
    for (int t = 1; t <= tc; t++) {
      int n = Integer.parseInt(br.readLine());

      int[][] ans = new int[n][n];
      int cur = 1;
      int d = 0;
      int x = 0, y = 0;

      while (true) {
        ans[y][x] = cur;
        
        if (cur++ == n * n) {
          break;
        }
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny >= 0 && ny < n && nx >= 0 && nx < n && ans[ny][nx] == 0) {
          y = ny;
          x = nx;
        } else {
          d = (d + 1) % 4;
          y = y + dy[d];
          x = x + dx[d];
        }

      }
      System.out.println("#" + t);
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          System.out.print(ans[i][j] + " ");
        }
        System.out.println();
      }
    }
  }
}