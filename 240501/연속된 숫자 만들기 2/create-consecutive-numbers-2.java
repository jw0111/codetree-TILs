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

        if(a + 1 == b && b + 1 == c){ // 이미 연속됨
            answer = 0;
        }
        else if(a + 1 == b && b + 2 == c ||
        a + 2 == b && b + 1 == c){
            answer = 1;
        }
        else answer = 2;

        System.out.print(answer);
    }
}