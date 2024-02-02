import java.util.*;
import java.io.*;

class Node {
	private int x;
	private int y;

	public Node(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return this.x;
	}

	public int getY() {
		return this.y;
	}
}

public class Main {
    static int n, k;
    static int[][] board = new int[101][101];
    static boolean[][] visit = new boolean[101][101];
    static Queue<Node> q = new LinkedList<>();
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    public static void bfs(){
        while(!q.isEmpty()){
            Node cur = q.poll();
            int x = cur.getX();
            int y = cur.getY();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if(!visit[nx][ny] && board[nx][ny] == 0){
                    visit[nx][ny] = true;
                    q.offer(new Node(nx, ny));
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                int tmp = Integer.parseInt(st.nextToken());
                board[i][j] = tmp;
            }
        }

        int ans = 0;

        for(int i = 0; i <k; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            q.offer(new Node(x - 1, y - 1));
            visit[x - 1][y - 1] = true;
            bfs();
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visit[i][j])
                    ans++;
            }
        }
        System.out.println(ans);
    }
}