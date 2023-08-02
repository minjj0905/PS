import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

  static class Point {

    int x, y;

    public Point(int x, int y) {
      this.x = x;
      this.y = y;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] arr = new int[n];

    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int i = 0; i < n; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    int studentCnt = Integer.parseInt(br.readLine());
    ArrayList<Point> studentList = new ArrayList<>();
    for (int i = 0; i < studentCnt; i++) {
      st = new StringTokenizer(br.readLine());
      studentList.add(
          new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
    }

    for (Point p : studentList) {
      int sex = p.x;
      int num = p.y;

      if (sex == 1) {
        for (int i = num - 1; i < n; i += num) {
          arr[i] ^= 1;
        }
      } else {
        int l = num - 1;
        int r = num - 1;
        while (true) {
          if (l == 0 || r == n - 1) {
            break;
          }

          l--;
          r++;

          if (arr[l] != arr[r]) {
            l++;
            r--;
            break;
          }
        }
        for (int i = l; i <= r; i++) {
          arr[i] ^= 1;
        }
      }
    }

    int cnt = 0;
    for (int i : arr) {
      System.out.print(i + " ");
      cnt++;
      if (cnt == 20) {
        System.out.println();
        cnt = 0;
      }
    }
  }

}
