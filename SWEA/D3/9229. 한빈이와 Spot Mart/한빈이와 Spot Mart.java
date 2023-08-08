import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

  static int[] arr, select;
  static int ans, n, m;

  static void sol(int cnt, int sum) {
    if (cnt == 2) {
      if (sum <= m) {
        ans = Math.max(ans, sum);
      }
      return;
    }

    for (int i = 0; i < n; i++) {
      if (select[i] == 1) {
        continue;
      }
      select[i] = 1;
      sol(cnt + 1, sum + arr[i]);
      select[i] = 0;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int tc = Integer.parseInt(br.readLine());

    for (int t = 1; t <= tc; t++) {
      ans = 0;

      StringTokenizer st = new StringTokenizer(br.readLine());

      n = Integer.parseInt(st.nextToken());
      m = Integer.parseInt(st.nextToken());

      arr = new int[n];
      st = new StringTokenizer(br.readLine());
      for (int i = 0; i < n; i++) {
        arr[i] = Integer.parseInt(st.nextToken());
      }

      select = new int[n];
      sol(0, 0);
      if (ans == 0) {
        System.out.println("#" + t + " " + -1);
        continue;
      }
      System.out.println("#" + t + " " + ans);
    }
  }
}