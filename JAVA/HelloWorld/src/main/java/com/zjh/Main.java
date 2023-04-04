package com.zjh;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Queue<Integer> q = new LinkedList<>();
        int n = sc.nextInt();
        while (n -- > 0){
            String op = sc.next();
            if ("push".equals(op)) {
                int x = sc.nextInt();
                q.add(x);
            }
            else if ("pop".equals(op)){
                q.remove();
            }
            else if ("empty".equals(op)){
                if (q.isEmpty()) {
                    System.out.println("YES");
                }
                else {
                    System.out.println("NO");
                }
            }
            else {
                System.out.println(q.peek());
            }
        }
    }
}