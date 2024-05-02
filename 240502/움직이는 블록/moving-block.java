import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static ArrayList<Integer> blocks = new ArrayList<>();
    static int goal = 0, answer = 0;
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            blocks.add(Integer.parseInt(br.readLine()));
            goal += blocks.get(i);
        }
        goal /= N; // 평균값이 목표값
        while(Collections.max(blocks) != goal){
            int curMax = Collections.max(blocks);
            int maxIdx = blocks.indexOf(curMax);
            for(int i = 0; i < N; i++){
                if(blocks.get(i) < goal){
                    int diff = goal - blocks.get(i) <= blocks.get(maxIdx) - goal ?
                    goal - blocks.get(i) : blocks.get(maxIdx) - goal;
                    blocks.set(i, blocks.get(i) + diff);
                    blocks.set(maxIdx, blocks.get(maxIdx) - diff);
                    answer += diff;
                    break;

                }
            }
        }
        System.out.print(answer);
    }
}