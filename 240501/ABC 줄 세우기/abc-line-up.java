import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static ArrayList<Integer> alphabets = new ArrayList<>();
    static int answer = 0;
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            char temp = st.nextToken().charAt(0);
            alphabets.add((int)temp - 65);
        }

        for(int i = 0; i < N; i++){
            int temp = alphabets.get(i);
            for(int j = alphabets.indexOf(i); j > i; j--){
                alphabets.set(j, alphabets.get(j - 1));
                ++answer;
            }
            alphabets.set(i, i);
        }

        System.out.print(answer);
    }
}