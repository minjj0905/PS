import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());
    int r = Integer.parseInt(st.nextToken());

    int[][] arr = new int[n][m];
    int[][] ans = new int[n][m];

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < m; j++) {
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    for (int i = 0; i < Math.min(n, m) / 2; i++) {
      int y = i;
      int x = i;
      int d = 0;

      Queue<Integer> layer = new LinkedList<>();

      while (true) {
        layer.add(arr[y][x]);
        arr[y][x] = 0;

        if (y == i + 1 && x == i) {
          break;
        }

        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || arr[ny][nx] == 0) {
          d += 1;
          ny = y + dy[d];
          nx = x + dx[d];
        }

        y = ny;
        x = nx;
      }

      for (int ro = 0; ro < r % layer.size(); ro++) {
        layer.add(layer.poll());
      }

      y = i;
      x = i;
      d = 0;

      while (true) {
        ans[y][x] = layer.poll();

        if (y == i + 1 && x == i) {
          break;
        }

        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m || ans[ny][nx] != 0) {
          d += 1;
          ny = y + dy[d];
          nx = x + dx[d];
        }

        y = ny;
        x = nx;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        System.out.print(ans[i][j] + " ");
      }
      System.out.println();
    }
  }
}