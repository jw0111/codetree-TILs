import java.util.*;
import java.io.*;

class Node {
    private int x;
    private int y;
    private int cnt;

    public Node (int x, int y, int cnt) {
        this.x = x;
        this.y = y;
        this.cnt = cnt;
    }

    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getCnt(){
        return cnt;
    }
}

public class Main {
    static int n, m;
    static int[][] board = new int[101][101];
    static boolean[][] visit = new boolean[101][101];
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static Queue<Node> q = new LinkedList<>();

    public static int bfs(int std){
        int sum = 0;
        while(!q.isEmpty()){
            Node cur = q.poll();
            int x = cur.getX();
            int y = cur.getY();
            int cnt = cur.getCnt();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if(cnt < std && !visit[nx][ny]){
                    sum += board[nx][ny];
                    visit[nx][ny] = true;
                    q.offer(new Node(nx, ny, cnt+1));
                }
            }
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        int ans = 0;

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                int tmp = Integer.parseInt(st.nextToken());
                if(tmp == 1)
                    ans = 1;
                board[i][j] = tmp;
            }
        }

        for(int cnt = 1; cnt <= n; cnt++){
            int cost = cnt * cnt + (cnt + 1) * (cnt + 1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    q.offer(new Node(i, j, 0));
                    visit = new boolean[21][21];
                    visit[i][j] = true;
                    int golds = bfs(cnt);
                    if(board[i][j] == 1)
                        golds++;
                  
                    if(golds * m >= cost && golds > ans){
                        ans = golds;
                        //System.out.println(String.format("%d %d %d %d %d", i, j, cnt, golds, cost));
                    }
                }
            }
        }
        System.out.print(ans);
    }
}