import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    static int N;
    static String chairs;
    static int maxdist = Integer.MIN_VALUE, mindist = Integer.MAX_VALUE;
    static int maxcnt = 1;
    static int idx = 0;
    static int answer;

    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        chairs = br.readLine();

        boolean emptyFirst = chairs.charAt(0) == '0' ? true : false;
        boolean emptyEnd = chairs.charAt(N - 1) == '0' ? true : false;

        for(int i = 0; i < chairs.length(); i++){
            int tmpdist; // 의자를 놓고 나서 최대 거리
            if(chairs.charAt(i) == '1'){
                if(emptyFirst){
                    tmpdist = i - idx;
                    emptyFirst = false;
                }
                else{
                    tmpdist = (i - idx) / 2;
                    if(i - idx > 0)
                        mindist = mindist < i - idx ? mindist : i - idx;
                }
                idx = i;
                if(maxdist < tmpdist){
                    maxdist = tmpdist;
                    maxcnt = 1;
                }
                if(maxdist == tmpdist) ++maxcnt;
            }
            //System.out.println(String.format("%d %d", mindist, maxdist));
        }

        if(emptyEnd){
            int tmpdist = N - 1 - idx;
            if(maxdist < tmpdist){
                maxdist = tmpdist;
                maxcnt = 1;
            }
            if(maxdist == tmpdist) ++maxcnt;
        }


        answer = mindist < maxdist ? mindist : maxdist;

        System.out.print(answer);

        
    }
}