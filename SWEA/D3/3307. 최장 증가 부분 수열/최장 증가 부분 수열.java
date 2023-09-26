import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// SWEA 3307 최장 증가 부분 수열
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tc; t++) {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n]; // 입력 수열
            int[] lis = new int[n]; // i번째 값까지 고려 했을 때의 최장 수열의 길이

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }

            int maxLen = 0;
            for (int i = 0; i < n; i++) { // 모든 원소에 대해 조사
                lis[i] = 1; // 자기 자신 으로만 이뤄진 문자열

                for (int j = 0; j < i; j++) { // 비교 대상. 0부터 자신 바로 앞의 값까지 비교
                    if (arr[j] < arr[i]) // 뒤쪽 숫자가 더 클 때
                        lis[i] = Math.max(lis[i], lis[j] + 1);
                }

                if (maxLen < lis[i])
                    maxLen = lis[i];
            }

            System.out.println("#" + t + " " + maxLen);
        }
    }
}