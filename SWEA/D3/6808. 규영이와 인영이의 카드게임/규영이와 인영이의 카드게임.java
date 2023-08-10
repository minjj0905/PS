import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {

  static int n = 9;

  static void swap(int[] numbers, int a, int b) {
    int tmp = numbers[a];
    numbers[a] = numbers[b];
    numbers[b] = tmp;
  }

  static boolean nextPerm(int[] numbers) {
    int i = n - 1;
    int j = n - 1;

    while (i > 0 && numbers[i - 1] >= numbers[i]) {
      --i;
    }
    if (i == 0) {
      return false;
    }

    while (numbers[i - 1] >= numbers[j]) {
      --j;
    }
    swap(numbers, i - 1, j);
    j = n - 1;
    while (i < j) {
      swap(numbers, i++, j--);
    }
    return true;
  }


  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int tc = Integer.parseInt(br.readLine());

    for (int t = 1; t <= tc; t++) {
      int[] G = new int[9];
      int[] Y = new int[9];
      int win = 0, lose = 0;
      boolean[] select = new boolean[18];

      StringTokenizer st = new StringTokenizer(br.readLine());
      for (int i = 0; i < 9; i++) {
        G[i] = Integer.parseInt(st.nextToken());
        select[G[i] - 1] = true;
      }

      int idx = 0;
      for (int i = 0; i < 18; i++) {
        if (!select[i]) {
          Y[idx++] = i + 1;
        }
      }

      do {
        int a = 0, b = 0;
        for (int i = 0; i < 9; i++) {
          if (G[i] > Y[i]) {
            a += G[i] + Y[i];
          } else {
            b += G[i] + Y[i];
          }
        }
        if (a > b) {
          win++;
        } else {
          lose++;
        }
      } while (nextPerm(Y));

      System.out.println("#" + t + " " + win + " " + lose);
    }
  }
}
