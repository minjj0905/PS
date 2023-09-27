import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());

		for (int t = 1; t <= tc; t++) {
			int ans = Integer.MAX_VALUE;

			StringTokenizer st = new StringTokenizer(br.readLine());

			int n = Integer.parseInt(st.nextToken());
			int[][] arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (i == j)
							continue;
						if (arr[i][k] != 0 && arr[k][j] != 0) {
							if (arr[i][j] == 0)
								arr[i][j] = arr[i][k] + arr[k][j];
							else
								arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
						}
					}
				}
			}

			for (int i = 0; i < n; i++) {
				int sum = 0;
				for (int j = 0; j < n; j++) {
					sum += arr[i][j];
				}
				ans = Math.min(sum, ans);
			}

			System.out.println("#" + t + " " + ans);
		}

	}

}