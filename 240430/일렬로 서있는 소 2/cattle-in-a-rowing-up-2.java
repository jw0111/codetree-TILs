import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int answer = 0;
    static ArrayList<Integer> cows = new ArrayList<>();

    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            cows.add(Integer.parseInt(st.nextToken()));
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(cows.get(i) <= cows.get(j) &&
                    cows.get(j) <= cows.get(k))
                        ++answer;
                }
            }
        }

        System.out.print(answer);

    }
}