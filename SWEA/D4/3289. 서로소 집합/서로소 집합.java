import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
    static int[] parents;
    static int n;
    static int m;

    static void make() {
        for (int i = 0; i < n + 1; i++) {
            parents[i] = i;
        }
    }

    static int find(int x) {
        if (x == parents[x]) return x;
        return parents[x] = find(parents[x]);
    }

    static boolean union(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b) return false;

        parents[b] = a;
        return true;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tc; t++) {
            StringBuilder sb = new StringBuilder();
            sb.append("#").append(t).append(" ");
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            parents = new int[n + 1];
            make();

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int type = Integer.parseInt(st.nextToken());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                if (type == 0) union(a, b);
                else {
                    if (find(a) == find(b)) sb.append(1);
                    else sb.append(0);
                }


            }
            System.out.println(sb);
        }
    }
}