import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //StringTokenizer st = new StringTokenizer(br.readLine());

        String a = br.readLine();
        String b = br.readLine();
        for(int i = 0; i < a.length(); i++){
            if(a.charAt(i) != ' ')
                System.out.print(a.charAt(i));
        }
        for(int i = 0; i < b.length(); i++){
            if(b.charAt(i) != ' ')
                System.out.print(b.charAt(i));
        }
    }
}