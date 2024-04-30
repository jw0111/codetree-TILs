import java.util.*;
import java.io.*;

public class Main {
    static int answer = 0;
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        for(int i = 0; i < A.length(); i++){
            if(A.charAt(i) == '('){
                for(int j = i; j < A.length(); j++){
                    if(A.charAt(j) == ')') ++answer;
                }
            }
        }

        System.out.print(answer);
    }
}