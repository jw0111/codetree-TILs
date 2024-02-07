import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int ans = 0;
    static int[][] board = new int[101][101];
    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++){
               int tmp = Integer.parseInt(st.nextToken()); 
               board[i][j] = tmp;
            }
        }

        for(int i = 0; i < N; i++){
            int cnt = 1;
            for(int j = 1; j < N; j++){
                if(board[i][j - 1] == board[i][j]){
                    cnt++;
                }
                else
                    cnt = 1;
                if(cnt == M){
                    ans++;
                    break;
                }
            }
        }

        for(int i = 0; i < N; i++){
            int cnt = 1;
            for(int j = 1; j < N; j++){
                if(board[j - 1][i] == board[j][i]) {
                    cnt++;
                }
                else
                    cnt = 1;
                if(cnt == M){
                    ans++;
                    break;
                }
            }
        }

        System.out.println(ans);
    }
}