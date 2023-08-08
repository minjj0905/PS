import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int tc = Integer.parseInt(br.readLine());

    for (int t = 1; t <= tc; t++) {
      int ans = 0;

      StringTokenizer st = new StringTokenizer(br.readLine());
      int n = Integer.parseInt(st.nextToken());
      int m = Integer.parseInt(st.nextToken());

      int[][] grid = new int[n][n];

      for (int i = 0; i < n; i++) {
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < n; j++) {
          grid[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j <= n - m; j++) {
          int res = 0;
          for (int y = i; y < i + m; y++) {
            for (int x = j; x < j + m; x++) {
              res += grid[y][x];
            }
          }
          ans = Math.max(ans, res);
        }
      }

      System.out.println("#" + t + " " + ans);
    }
  }
}