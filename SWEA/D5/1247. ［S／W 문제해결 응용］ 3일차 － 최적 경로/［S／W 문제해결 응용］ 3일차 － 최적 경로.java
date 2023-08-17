import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution {

    static int getDistance(int[] first, int[] second) {
        return Math.abs(first[0] - second[0]) + Math.abs(first[1] - second[1]);
    }

    static void solution(boolean[] visit, int cnt, int dis, int[] cur) {
        if (dis >= ans) return;
        if (cnt == n && ans > dis + getDistance(cur, home)) {
            ans = dis + getDistance(cur, home);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visit[i]) continue;

            visit[i] = true;
            solution(visit, cnt + 1, dis + getDistance(cur, customer.get(i)), customer.get(i));
            visit[i] = false;
        }
    }

    static int n, ans;
    static int[][] grid;
    static int[] com, home;
    static ArrayList<int[]> customer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tc; t++) {
            grid = new int[101][101];
            ans = Integer.MAX_VALUE;

            n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());

            com = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            home = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
            customer = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                customer.add(new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
            }

            solution(new boolean[n], 0, 0, com);

            System.out.println("#" + t + " " + ans);
        }
    }
}