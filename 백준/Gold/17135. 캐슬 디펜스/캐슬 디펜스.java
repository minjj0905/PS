import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int n, m, d;
    static int[][] grid;
    static ArrayList<boolean[]> archerComb;

    static int getDist(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }

    static void getArcherComb(boolean[] isSelected, int m, int r, int cnt) {
        if (r == 0) {
            archerComb.add(isSelected.clone());
            return;
        }
        if (cnt == m) return;

        isSelected[cnt] = true;
        getArcherComb(isSelected, m, r - 1, cnt + 1);
        isSelected[cnt] = false;
        getArcherComb(isSelected, m, r, cnt + 1);
    }

    static int ARCHER_CNT = 3;

    public static void main(String[] args) throws IOException {
        int ans = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        d = Integer.parseInt(st.nextToken());
        grid = new int[n][m];

        int totalEnemy = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
                if (grid[i][j] == 1) totalEnemy++;
            }
        }

        archerComb = new ArrayList<boolean[]>();
        getArcherComb(new boolean[m], m, ARCHER_CNT, 0);
        for (boolean[] archer : archerComb) {
            int[][] curGrid = new int[n][m];
            for (int i = 0; i < n; i++) {
                curGrid[i] = grid[i].clone();
            }
            boolean[][] killed = new boolean[n][m];
            for (int line = n - 1; line >= 0; line--) {
                for (int a = 0; a < m; a++) {
                    if (!archer[a]) continue;
                    int dist = Integer.MAX_VALUE;
                    int row = 0, col = 0;
                    for (int i = 0; i <= line; i++) {
                        for (int j = 0; j < m; j++) {
                            if (curGrid[i][j] == 1) {
                                int curDist = getDist(new int[]{i, j}, new int[]{line, a});
                                if (dist > curDist && curDist < d) {
                                    row = i;
                                    col = j;
                                    dist = curDist;
                                } else if (dist == curDist && col > j) {
                                    row = i;
                                    col = j;
                                }
                            }
                        }
                    }
                    if (dist == Integer.MAX_VALUE) continue;
                    killed[row][col] = true;
                }
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (killed[i][j]) curGrid[i][j] = 0;
                    }
                }

            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (killed[i][j]) cnt++;
                }
            }
            ans = Math.max(ans, cnt);
            if (ans == totalEnemy) break;
        }
        System.out.println(ans);
    }
}