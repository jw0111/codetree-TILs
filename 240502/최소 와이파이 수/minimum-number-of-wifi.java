import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static int[] people = new int[101];
    static int answer = 0;
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            people[i] = Integer.parseInt(st.nextToken());
        }
        boolean isRange = false; 
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(people[i] == 1){
                if(!isRange) isRange = true;
            }
            if(isRange){
                if(cnt == m * 2){
                    ++answer;
                    isRange = false;
                    cnt = 0;
                }
                else ++cnt;
            }
        }
        if(isRange) ++answer;
        System.out.print(answer);
    }
}