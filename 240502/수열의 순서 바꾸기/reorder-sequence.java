import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static ArrayList<Integer> numbers = new ArrayList<>();
    static ArrayList<Integer> sorted = new ArrayList<>();
    static int answer = 0;
    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            numbers.add(Integer.parseInt(st.nextToken()));
            sorted.add(numbers.get(i));
        }
        Collections.sort(sorted);
        while(!sorted.equals(numbers)){
            int insertIdx = 4;
            for(int i = N - 1; i >= 0; i--){
                if(numbers.get(0) < numbers.get(i)){
                    insertIdx = i;
                    break;
                }
            }
            numbers.add(insertIdx, numbers.get(0));
            numbers.remove(0);
            // for(int i = 0; i < N; i++){
            //     System.out.print(String.format("%d ", numbers.get(i)));
            // }
            // System.out.println();

            ++answer;
        }

        System.out.print(answer);
    }
}