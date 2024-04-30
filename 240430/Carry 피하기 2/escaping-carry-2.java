import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int[] numbers = new int[21];
    static int r = 3; // 3개 뽑을거니까
    static int cnt = 0; // 조합 개수
    static ArrayList<ArrayList<Integer>> combResult = new ArrayList<ArrayList<Integer>>();
    static ArrayList<Integer> numsums = new ArrayList<Integer>();
    static int answer = 0;
    
    public static void comb(int[] arr, int start, boolean[] visit, int depth){
        if(depth == r){
            ArrayList<Integer> temp = new ArrayList<>();
            int tempsum = 0;
            for(int i = 0; i < n; i++){
                if(visit[i]){
                    temp.add(arr[i]);
                    tempsum += arr[i];
                }
            }
            combResult.add(temp);
            numsums.add(tempsum);
            return;
        }

        for(int i = start; i < n; i++){
            if(!visit[i]){
                visit[i] = true;
                comb(arr, i + 1, visit, depth + 1);
                visit[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException{
        // 여기에 코드를 작성해주세요.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            numbers[i] = Integer.parseInt(br.readLine());
        }
        comb(numbers, 0, new boolean[n + 1], 0);

        // for(int i = 0; i < combResult.size(); i++){
        //     for(int j = 0; j < 3; j++){
        //         System.out.print(String.format("%d ", combResult.get(i).get(j)));
        //     }
        //     System.out.println();
        // }

        boolean isCand = false;

        for(int i = 0; i < combResult.size(); i++){
            isCand = true;
            for(int j = 10; j <= 10000; j *= 10){ // 자릿수별로 확인
                int tempsum = 0; // 자릿수별 합
                for(int k = 0; k < 3; k++){
                    int digit = (combResult.get(i).get(k) % j) / (j / 10);
                    //System.out.println(String.format("num : %d, %d", combResult.get(i).get(k), digit));
                    tempsum += digit;
                }
                if(tempsum >= 10){ // 10 넘으면 캐리 발생
                    isCand = false;
                    break;
                }
            }
            if(isCand){
                answer = answer < numsums.get(i) ? numsums.get(i) : answer;
            }
        }

        if(answer == 0) answer = -1;

        System.out.print(answer);
    }
}