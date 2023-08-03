import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  static int ans;
  static int n;
  static ArrayList<int[]> arr;
  static boolean[] visit;

  static void cook(int cur) {
    if (cur == n) {
      int sour = 1, bitter = 0, cnt = 0;
      for (int i = 0; i < n; i++) {
        if (visit[i]) {
          cnt++;
          sour *= arr.get(i)[0];
          bitter += arr.get(i)[1];
        }
      }
      if (cnt == 0) {
        return;
      }
      if (ans > Math.abs(sour - bitter)) {
        ans = Math.abs(sour - bitter);
      }

      return;
    }
    visit[cur] = true;
    cook(cur + 1);
    visit[cur] = false;
    cook(cur + 1);

  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    n = Integer.parseInt(br.readLine());
    ans = Integer.MAX_VALUE;
    arr = new ArrayList<>();
    visit = new boolean[n];

    for (int i = 0; i < n; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int sour = Integer.parseInt(st.nextToken());
      int bitter = Integer.parseInt(st.nextToken());
      arr.add(new int[]{sour, bitter});
    }

    cook(0);
    System.out.println(ans);

  }
}