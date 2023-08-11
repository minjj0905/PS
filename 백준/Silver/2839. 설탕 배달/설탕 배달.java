import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int t = 0, f = 0;

    while (n % 5 != 0 && n >= 0) {
      n -= 3;
      t += 1;
    }

    if (n % 5 == 0 && n >= 0) {
      f = n / 5;
      System.out.println(t + f);
      return;
    }
    System.out.println(-1);
  }
}