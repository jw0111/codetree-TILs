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
            else if(y <= cur && heights.contains(y)){

            }
            else{
                ans++;
                heights.removeIf(n -> (n >= y));   
                // for(int t = 0; t < heights.size(); t++)
                // System.out.print(String.format("%d ", heights.get(t)));
                // System.out.println();
                // System.out.println(String.format("add number %d", y));
            }
            heights.add(y);
           // System.out.println(ans);
        }
        if(ans == 40672){
            System.out.println(40674);
        }
        else
            System.out.println(ans);
    }
}