import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  static int n, r, c;

  static double sol(double n, double r, double c) {
    if (n == 1) {
      if (r == 0) {
        if (c == 0) return 0;
        else return 1;
      } else {
        if (c == 0) return 2;
        else return 3;
      }
    }

    if (r >= Math.pow(2, n - 1)) {
      int half = (int) Math.pow(2, 2 * n - 1);

      if (c >= Math.pow(2, n - 1))
        return half + Math.pow(2, 2 * n - 2) + sol(n - 1, r - (Math.pow(2, n - 1)), c - Math.pow(2, n - 1));
      else return half + sol(n - 1, r - Math.pow(2, n - 1), c);
    } else {
      if (c >= Math.pow(2, n - 1))
        return Math.pow(2, 2 * n - 2) + sol(n - 1, r, c - Math.pow(2, n - 1));
      else return sol(n - 1, r, c);
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    r = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());

    System.out.println((int) sol(n, r, c));
  }
}