import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Solution {
    static int v, e;
    static Edge[] edgelist;
    static int[] parents;

    static class Edge implements Comparable<Edge> {
        int from, to, weight;

        public Edge(int from, int to, int weight) {
            super();
            this.from = from;
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge o) {
            return Integer.compare(this.weight, o.weight);
        }
    }

    static void make() {
        parents = new int[v + 1];
        for (int i = 0; i <= v; i++) {
            parents[i] = i;
        }
    }

    static int find(int x) {
        if (parents[x] == x) return x;
        return parents[x] = find(parents[x]);
    }

    static boolean union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot) return false;
        parents[xRoot] = yRoot;
        return true;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tc; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());

            edgelist = new Edge[e];

            for (int i = 0; i < e; i++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                edgelist[i] = new Edge(a, b, c);
            }

            make();
            Arrays.sort(edgelist);

            long ans = 0;
            long count = 0;

            for (Edge edge : edgelist) {
                if (union(edge.from, edge.to)) {
                    ans += edge.weight;
                    if (++count == v - 1) break;
                }
            }

            System.out.println("#" + t + " " + ans);
        }
    }
}