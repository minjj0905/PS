import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()); // 이번 분기 분 수 N
		
		int score = 0; // 업무 평가 점수
		
		Stack<int[]> s = new Stack<int[]>(); //중단된 업무를 저장할 스택
		int[] job = new int[2]; // 업무 배열
		
		for(int i = 0; i<n; i++) { // 각 분 순회
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			if(st.nextToken().equals("1")) { // 업무가 주어질 경우
				if(job[0] != 0) s.add(job); // 하고 있던 업무가 있을 경우 스택에 삽입
				job = new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()) - 1}; // 새 업무 정보
				
				if(job[1] == 0) { //업무를 받자마자 끝난경우 계신
					score += job[0];
					job = new int[2];
				}
				continue;
			}
		
		
			// 업무가 주어지지 않을 경우
			if(job[0] == 0 && !s.isEmpty()) { // 현재 업무가 없고 중단된 업무가 있다면
				job = s.pop();
			}
			
			job[1]--; // 업무 진행
			
			if(job[1] == 0) { // 업무가 끝났다면
				score += job[0]; // 평가 점수 합산
				if(!s.isEmpty()) job = s.pop(); // 중단된 업무 이어서
			}
		}
		
		// 점수 출력
		System.out.println(score);
		
	}
}
