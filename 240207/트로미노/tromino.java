import java.util.*;
import java.io.*;

public class Main {
    static int N, M;
    static int[][] board = new int[201][201];

    static boolean notValid(int x, int y) {
        return x < 0 || x >= N || y < 0 || y >= M;
    }

    static int getSum(int x, int y) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        List<Integer> numbers = new ArrayList<>();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            numbers.add(board[nx][ny]);
        }
        Collections.sort(numbers, Collections.reverseOrder());

        return board[x][y] + numbers.get(0) + numbers.get(1);
    }

    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                int tmp = Integer.parseInt(st.nextToken());
                board[i][j] = tmp;
            }
        }

        int ans = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                ans = getSum(i, j) > ans ? getSum(i, j) : ans;
            }
        }

        System.out.println(ans);

    }
}