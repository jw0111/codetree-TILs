import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[][] board = new int[21][21];

    public static int getSum(int x, int y){
        int sum = 0;
        for(int i = x; i < 3; i++){
            for(int j = y; j < 3; j++){
                if(i >= N || j >= N)
                    continue;
                sum += board[i][j];
            }
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int ans = 0;

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
                int tmp = Integer.parseInt(st.nextToken());
                board[i][j] = tmp;
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans = getSum(i, j) > ans ? getSum(i, j) : ans;
            }
        }

        System.out.print(ans);
    }
}