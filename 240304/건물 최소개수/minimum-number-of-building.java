import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static List<Integer> heights = new ArrayList<>();
    static int ans;
    static int x, y;
    public static void main(String[] args) throws IOException {
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());
        heights.add(y);
        if(y != 0)
            ans++;

        for(int i = 1; i < n; i++){
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            int cur = heights.get(heights.size() - 1);

            if(y == 0){
                heights.clear();
            }
            else if(y < cur && heights.contains(y)){
                
            }
            else if (y == cur){

            }
            else
                ans++;
            heights.add(y);
            //System.out.println(ans);
        }
        System.out.println(ans);
    }
}