import java.util.*;
import java.io.*;

public class Main {
    static int a, b, c;
    static int answer = -1;
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Integer.parseInt(st.nextToken());
        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        if(a + 1 == b && b + 1 == c)
            answer = 0;
        else {
            answer = c - b - 1;
            answer = answer > b - a - 1 ? answer : b - a - 1;
        }

        System.out.print(answer);
    }
}