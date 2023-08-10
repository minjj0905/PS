import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

  static int ans;
  static int n;
  static int[][] grid;
  static boolean[] visit;

  static void updateDiff() {
    int a = 0, b = 0;
    int[] arr1 = new int[n / 2];
    int[] arr2 = new int[n / 2];

    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < n; i++) {
      if (visit[i]) {
        arr1[idx1++] = i;
      } else {
        arr2[idx2++] = i;
      }
    }

    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        a += grid[arr1[i]][arr1[j]];
        b += grid[arr2[i]][arr2[j]];
      }
    }
    ans = Math.min(ans, Math.abs(a - b));
  }

  static void comb(int cnt, int r) {
    if (r == 0) {
      updateDiff();
      return;
    }
    if (cnt == n) {
      return;
    }

    visit[cnt] = true;
    comb(cnt + 1, r - 1);
    visit[cnt] = false;
    comb(cnt + 1, r);

  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int tc = Integer.parseInt(br.readLine());

    for (int t = 1; t <= tc; t++) {
      ans = Integer.MAX_VALUE;

      n = Integer.parseInt(br.readLine());
      grid = new int[n][n];
      visit = new boolean[n];

      for (int i = 0; i < n; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int j = 0; j < n; j++) {
          grid[i][j] = Integer.parseInt(st.nextToken());
        }
      }

      comb(0, n / 2);

      System.out.println("#" + t + " " + ans);
    }
  }
}