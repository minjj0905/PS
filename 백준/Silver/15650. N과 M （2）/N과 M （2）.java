import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {

  static int n, m;
  static ArrayList<Integer> s;

  public static void fn() {
    if (s.size() == m) {
      System.out.println(s.stream().map(String::valueOf).collect(Collectors.joining(" ")));
      return;
    }

    for (int i = 1; i <= n; i++) {
      if (!s.contains(i) && (s.isEmpty() || s.get(s.size() - 1) < i)) {
        s.add(i);
        fn();
        s.remove(s.size() - 1);
      }
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    n = Integer.parseInt(st.nextToken());
    m = Integer.parseInt(st.nextToken());
    s = new ArrayList<>();

    fn();
  }
}
