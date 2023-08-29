import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < t; tc++) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());

            int[][] dp = new int[15][15];
            for (int i = 1; i <= 14; i++) dp[0][i] = i;

            for (int i = 1; i <= k; i++) {
                for (int j = 1; j <= n; j++) {
                    int sum = 0;
                    for (int m = 1; m <= j; m++) sum += dp[i - 1][m];
                    dp[i][j] = sum;
                }
            }
            System.out.println(dp[k][n]);

        }
    }
}