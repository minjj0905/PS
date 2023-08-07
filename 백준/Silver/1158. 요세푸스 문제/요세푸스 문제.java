import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int n = Integer.parseInt(st.nextToken());
    int k = Integer.parseInt(st.nextToken());

    Stack<Integer> ans = new Stack<>();
    Stack<Integer> stack = new Stack<>();
    for (int i = 1; i <= n; i++) {
      stack.push(i);
    }

    int idx = 1;
    int cnt = 0;
    while (cnt != n) {
      if (idx % k == 0) {
        ans.push(stack.get(idx - 1));
        idx++;
        cnt++;
      } else {
        stack.push(stack.get(idx - 1));
        idx++;
      }
    }
    System.out.print("<");
    System.out.print(ans.stream().map(String::valueOf).collect(Collectors.joining(", ")));
    System.out.print(">");

  }
}