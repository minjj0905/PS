import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int ans = 0;
    static int space = 0;
    static int n, m;
    static int[][] arr;
    static ArrayList<int[]> cam = new ArrayList<>();

    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    static void cctv(int cnt, int[][] watched) {
        // cctv 탐색 종료시 업데이트
        if (cnt >= cam.size()) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (watched[i][j] > 0 && arr[i][j] == 0) res++;
                }
            }
            ans = Math.max(ans, res);
            return;
        }

        // 현재 cctv
        int[] cur = cam.get(cnt);
        int y = cur[0], x = cur[1];

        // 1번
        if (arr[y][x] == 1) {
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]++;
                    ny += dy[i];
                    nx += dx[i];
                }

                cctv(cnt + 1, watched);

                ny -= dy[i];
                nx -= dx[i];
                while (arr[ny][nx] != arr[y][x]) {
                    watched[ny][nx]--;
                    ny -= dy[i];
                    nx -= dx[i];
                }
            }
        }

        // 2번
        else if (arr[y][x] == 2) {
            // 좌우
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[2 + i];
                while (nx >= 0 && nx < m && arr[y][nx] != 6) {
                    watched[y][nx]++;
                    nx += dx[2 + i];
                }
            }
            cctv(cnt + 1, watched);
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[2 + i];
                while (nx >= 0 && nx < m && arr[y][nx] != 6) {
                    watched[y][nx]--;
                    nx += dx[2 + i];
                }
            }

            // 상하
            for (int i = 0; i < 2; i++) {
                int ny = y + dy[i];
                while (ny >= 0 && ny < n && arr[ny][x] != 6) {
                    watched[ny][x]++;
                    ny += dy[i];
                }
            }
            cctv(cnt + 1, watched);
            for (int i = 0; i < 2; i++) {
                int ny = y + dy[i];
                while (ny >= 0 && ny < n && arr[ny][x] != 6) {
                    watched[ny][x]--;
                    ny += dy[i];
                }
            }
        }

        // 3번
        else if (arr[y][x] == 3) {

            int[] ay = {-1, 0, 1, 0};
            int[] ax = {0, 1, 0, -1};

            int[] by = {0, 1, 0, -1};
            int[] bx = {1, 0, -1, 0};

            for (int i = 0; i < 4; i++) {
                // 'ㄴ' 기준 위
                int ny = y + ay[i];
                int nx = x + ax[i];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]++;
                    ny += ay[i];
                    nx += ax[i];
                }
                // 'ㄴ' 기준 오른쪽
                ny = y + by[i];
                nx = x + bx[i];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]++;
                    ny += by[i];
                    nx += bx[i];
                }
                cctv(cnt + 1, watched);


                // 롤백
                ny = y + ay[i];
                nx = x + ax[i];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]--;
                    ny += ay[i];
                    nx += ax[i];
                }
                ny = y + by[i];
                nx = x + bx[i];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]--;
                    ny += by[i];
                    nx += bx[i];
                }
            }
        }

        // 4번
        else if (arr[y][x] == 4) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i == j) continue;

                    int ny = y + dy[j];
                    int nx = x + dx[j];
                    while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                        watched[ny][nx]++;
                        ny += dy[j];
                        nx += dx[j];
                    }
                }
                cctv(cnt + 1, watched);
                for (int j = 0; j < 4; j++) {
                    if (i == j) continue;

                    int ny = y + dy[j];
                    int nx = x + dx[j];
                    while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                        watched[ny][nx]--;
                        ny += dy[j];
                        nx += dx[j];
                    }
                }
            }
        }

        // 5번
        else if (arr[y][x] == 5) {
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]++;
                    ny += dy[i];
                    nx += dx[i];
                }
            }

            cctv(cnt + 1, watched);

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                while (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6) {
                    watched[ny][nx]--;
                    ny += dy[i];
                    nx += dx[i];
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] != 0) {
                    if (arr[i][j] != 6) cam.add(new int[]{i, j});
                } else space++;
            }
        }

        cctv(0, new int[n][m]);

        System.out.println(space - ans);
    }
}