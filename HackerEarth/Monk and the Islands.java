import java.io.*;
import java.util.*;

class Graph {
    private final int N = 100002;
    List< List<Integer> > adj = new ArrayList< List<Integer> > (N);
    void init() {
        for(int i=0; i<N; i++) {
            adj.add(new ArrayList<Integer>());
        }
    }
    int bfs(int n) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[n+1];
        int [] lvl = new int[n+1];
        for(int i=0; i<=n; i++) {
            vis[i] = false;
            lvl[i] = 0;
        }
        
        vis[1] = true;
        q.add(1);
        lvl[1] = 0;

        while(!q.isEmpty()) {
            int u = q.remove();
            List<Integer> a = adj.get(u);
            for(int v: a) {
                if(vis[v])continue;
                q.add(v);
                vis[v] = true;
                lvl[v] = lvl[u] + 1;
            }
        }
        return lvl[n];
    }
    public static void main(String args[]) {
        Graph g = new Graph();
        g.init();
        int n,m,t,u,v;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t-- > 0) {
            n = sc.nextInt();
            m = sc.nextInt();
            for(int i=0; i<m; i++) {
                u = sc.nextInt();
                v = sc.nextInt();
                g.adj.get(u).add(v);
                g.adj.get(v).add(u);
            }
            // for(int i=1; i<=n; i++) {
            //     System.out.println(i + " is connected with " + g.adj.get(i));
            // }
            int lvl = g.bfs(n);
            System.out.println(lvl);
            for(int i=0; i<=n; i++) {
                g.adj.get(i).clear();
            }
        }
    }
}