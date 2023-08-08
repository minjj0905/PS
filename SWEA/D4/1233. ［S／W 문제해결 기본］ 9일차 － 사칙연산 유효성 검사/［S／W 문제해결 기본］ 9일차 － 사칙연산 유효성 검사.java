import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {

  public static boolean isNumeric(String strNum) {
    if (strNum == null) {
      return false;
    }
    try {
      double d = Integer.parseInt(strNum);
    } catch (NumberFormatException nfe) {
      return false;
    }
    return true;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] operators = {"+", "-", "*", "/"};

    for (int t = 1; t <= 10; t++) {
      int n = Integer.parseInt(br.readLine());
      int ans = 1;
      for (int i = 0; i < n; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine());
        if (ans == 1) {
          st.nextToken();
          String root = st.nextToken();
          if (st.hasMoreTokens()) {
            if (!Arrays.asList(operators).contains(root)) {
              ans = 0;
            }
            String left = st.nextToken();
            String right = st.nextToken();
            if (!isNumeric(left) || !isNumeric(right)) {
              ans = 0;
            }
          } else {
            if (!isNumeric(root)) {
              ans = 0;
            }
          }
        }
      }

      System.out.println("#" + t + " " + ans);
    }
  }
}