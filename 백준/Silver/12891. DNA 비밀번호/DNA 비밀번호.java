import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * 1. summary: 문제 해석
 *  문자열은 A, C, G, T 로만 이루어져야 한다.
 *  주어진 문자열을 토대로 부분 문자열 생성
 *  부분 문자열이 비밀번호로 사용되려면 문자 개수가 특정 개수 이상이어야 함.
 *  비밀번호가 가능한 부분 문자열의 개수 구하기
 *
 * 2. strategy: 풀이 전략
 *  부분문자열을 구할 때, 해당 개수에 맞도록 구하면 될듯.
 *
 * 3. note: 주의할 사항(특이사항)
 */


public class Main {

  static int ans = 0;
  static int s, p;
  static String[] dna;
  static int[] arr;
  static int[] check;
  static String[] letter = {"A", "C", "G", "T"};

  static void isValid() {
    for (int i = 0; i < 4; i++) {
      if (arr[i] > check[i]) {
        return;
      }
    }
    ans++;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    s = Integer.parseInt(st.nextToken());
    p = Integer.parseInt(st.nextToken());

    dna = br.readLine().split("");

    arr = new int[4];
    st = new StringTokenizer(br.readLine());
    for (int i = 0; i < 4; i++) {
      arr[i] = Integer.parseInt(st.nextToken());
    }

    check = new int[4];

    int l = 0;
    int r = p;

    for (int i = 0; i < 4; i++) {
      for (int j = l; j < r; j++) {
        if (dna[j].equals(letter[i])) {
          check[i]++;
        }
      }
    }
    isValid();

    for (int i = 0; i < s - p; i++) {
      for (int j = 0; j < 4; j++) {
        if (dna[i].equals(letter[j])) {
          check[j]--;
        }
        if (dna[i + p].equals(letter[j])) {
          check[j]++;
        }
      }
      isValid();
    }

    System.out.println(ans);
  }
}