import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 3];
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;

        for (int i = 4; i <= n; i++) {
            int min = dp[i - 1];
            if (i % 3 == 0) min = Math.min(min, dp[i / 3]);
            if (i % 2 == 0) min = Math.min(min, dp[i / 2]);
            dp[i] = min + 1;
        }
        System.out.println(dp[n]);
    }
}