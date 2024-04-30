import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static int n;
    static ArrayList<Integer> houses = new ArrayList<>();
    static int answer = 987654321;
    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            houses.add(Integer.parseInt(st.nextToken()));
        }

        for(int i = 0; i < n; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++){
                tmp += Math.abs(i - j) * houses.get(j);
            }
            answer = tmp < answer ? tmp : answer;
        }

        System.out.print(answer);
    }
}