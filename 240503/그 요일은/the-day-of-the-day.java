import java.util.*;
import java.io.*;

public class Main {
    static int m1, d1, m2, d2;
    static int[] month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int day = 0;
    static HashMap<String, Integer> days = new HashMap<>();
    static int answer = 0;

    static void initDays(){
        days.put("Mon", 0);
        days.put("Tue", 1);
        days.put("Wed", 2);
        days.put("Thu", 3);
        days.put("Fri", 4);
        days.put("Sat", 5);
        days.put("Sun", 6);
    }

    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m1 = Integer.parseInt(st.nextToken());
        d1 = Integer.parseInt(st.nextToken());
        m2 = Integer.parseInt(st.nextToken());
        d2 = Integer.parseInt(st.nextToken());

        String tempday = br.readLine();
        initDays();
        day = days.get(tempday);
        int curDay = 0;
        int curMonth = month[m1];
        if(curDay == day) ++answer;

        while(true){
            if(m1 == m2 && d1 == d2){
                break;
            }
            if(d1 + 1 > curMonth){
                m1 = (m1 + 1) % 13;
                d1 = 1;
                curMonth = month[m1];
            }
            else ++d1;
            curDay = (curDay + 1) % 7;
            if(curDay == day) ++answer;
            //System.out.println(d1);
        }
        System.out.print(answer);

    }
}