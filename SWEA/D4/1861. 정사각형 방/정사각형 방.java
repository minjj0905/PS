import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int tc = Integer.parseInt(br.readLine());

    for (int t = 1; t <= tc; t++) {
      int ans = 0, cnt = 1;
      int n = Integer.parseInt(br.readLine());
      int[][] grid = new int[n][n];

      for (int i = 0; i < n; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < n; j++) {
          grid[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      Queue<int[]> q = new LinkedList<>();

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          q.offer(new int[]{i, j, 1, i, j});
        }
      }

      int[] dy = {-1, 1, 0, 0};
      int[] dx = {0, 0, -1, 1};

      while (!q.isEmpty()) {
        int[] cur = q.poll();
        int y = cur[0], x = cur[1];
        int move = cur[2];
        int sy = cur[3], sx = cur[4];

        if (move > cnt) {
          ans = grid[sy][sx];
          cnt = move;
        } else if (move == cnt && ans > grid[y][x]) {
          ans = grid[sy][sx];
        }

        for (int d = 0; d < 4; d++) {
          int ny = y + dy[d];
          int nx = x + dx[d];

          if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

          if (grid[y][x] + 1 == grid[ny][nx]) {
            q.offer(new int[]{ny, nx, cnt + 1, sy, sx});
          }
        }
      }

      System.out.println("#" + t + " " + ans + " " + cnt);
    }
  }
}