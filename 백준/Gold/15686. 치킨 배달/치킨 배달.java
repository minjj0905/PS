import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  static int ans = Integer.MAX_VALUE;
  static ArrayList<int[]> chicks;
  static ArrayList<int[]> homes;
  static boolean[] selected;

  static int getDistance(int[] first, int[] second) {
    return Math.abs(first[0] - second[0]) + Math.abs(first[1] - second[1]);
  }

  static int getChickenDistance() {
    int sum = 0;
    for (int[] home : homes) {
      int res = Integer.MAX_VALUE;
      for (int j = 0; j < chicks.size(); j++) {
        if (!selected[j]) continue;
        res = Math.min(res, getDistance(home, chicks.get(j)));
      }
      sum += res;
    }
    return sum;
  }

  static void getChickenCombs(int s, int n, int r) {
    if (r == 0) {
      ans = Math.min(ans, getChickenDistance());
      return;
    }

    for (int i = s; i < n; i++) {
      selected[i] = true;
      getChickenCombs(i + 1, n, r - 1);
      selected[i] = false;
    }
  }


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    int[][] grid = new int[n][n];
    chicks = new ArrayList<>();
    homes = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      st = new StringTokenizer(br.readLine());
      for (int j = 0; j < n; j++) {
        grid[i][j] = Integer.parseInt(st.nextToken());
        if (grid[i][j] == 1) homes.add(new int[]{i, j});
        else if (grid[i][j] == 2) chicks.add(new int[]{i, j});
      }
    }

    selected = new boolean[chicks.size()];
    getChickenCombs(0, chicks.size(), m);

    System.out.println(ans);
  }
}