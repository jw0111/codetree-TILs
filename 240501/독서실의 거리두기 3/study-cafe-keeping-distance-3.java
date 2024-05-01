import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static String chairs;
    static int maxdist = 0, mindist = Integer.MAX_VALUE;
    static int maxcnt = 0;
    static int idx = 0;

    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        chairs = br.readLine();

        for(int i = 1; i < chairs.length(); i++){
            int tmpdist = 0;
            if(chairs.charAt(i) == '1'){
                tmpdist = i - idx; // 이게 현재 거리
                if(maxdist == tmpdist) ++maxcnt;
                if(maxdist < tmpdist){
                    maxcnt = 1;
                    maxdist = tmpdist;
                }
                if(mindist > tmpdist)
                    mindist = tmpdist;
                idx = i;
            }
        }

        int newMindist = maxdist / 2;
        mindist = mindist < newMindist ? mindist : newMindist;

        //System.out.println(String.format("%d %d %d", maxdist, maxcnt, mindist));
        System.out.print(mindist);
    }
}