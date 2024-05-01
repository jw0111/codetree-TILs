import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    static int A, B, x, y;
    static int answer = Integer.MAX_VALUE;
    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        // 1. 텔레포트 사용 X
        answer = Math.abs(B - A);

        // 2. x에서 y로 텔레포트
        answer = Math.min(answer, Math.abs(x - A) + Math.abs(y - B));

        // 3. y에서 x로 텔레퐅,
        answer = Math.min(answer, Math.abs(x - B) + Math.abs(y - A));

        System.out.print(answer);
    }
}