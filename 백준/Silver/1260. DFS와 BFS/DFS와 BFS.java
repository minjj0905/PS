import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m, v;
    static int[][] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        graph = new int[n + 1][n + 1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        visit = new boolean[n + 1];
        dfs(v);
        System.out.println();
        bfs();

    }

    static boolean[] visit;

    static void dfs(int cur) {
        if (!visit[cur]) {
            visit[cur] = true;
            System.out.print(cur + " ");
        }

        for (int i = 1; i <= n; i++) {
            if (graph[cur][i] == 1 && !visit[i]) dfs(i);
        }
    }

    static void bfs() {
        visit = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.offer(v);

        while (!q.isEmpty()) {
            int cur = q.poll();
            if (!visit[cur]) {
                visit[cur] = true;
                System.out.print(cur + " ");
            }

            for (int i = 1; i <= n; i++) {
                if (graph[cur][i] == 1 && !visit[i]) q.offer(i);
            }
        }
    }
}