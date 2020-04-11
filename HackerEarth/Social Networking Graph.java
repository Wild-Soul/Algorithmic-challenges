import java.util.*;
import java.io.*;

class Graph {
    final int N = 100005;
    ArrayList< List<Integer> > adj = new ArrayList<List<Integer>> (N);

    void init() {
        for(int i=0; i<N; i++) {
            adj.add(new ArrayList<Integer>());
        }
    }

    int bfs(int s, int d, int n) {
        boolean[] vis = new boolean[n];
        for(int i=0; i<n; i++) {
            vis[i] = false;
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        vis[s] = true;
        int ans = 0;
        int lvl = 0;
        while(!q.isEmpty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int u = q.remove();
                List<Integer> a = adj.get(u);
                for(int v: a) {
                    if(vis[v])continue;
                    vis[v] = true;
                    q.add(v);
                }
            }
            lvl++;
            if(lvl == d) { ans = q.size(); break;}
        }
        return ans;
    }
    public static void main(String args[]) {
        Graph g = new Graph();
        g.init();
        int n,m,q,u,v,t;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for(int i=0; i<m; i++) {
            u = sc.nextInt(); v = sc.nextInt();
            g.adj.get(u).add(v);
            g.adj.get(v).add(u);
        }
        q = sc.nextInt();
        
        while(q-->0) {
            u = sc.nextInt();
            t = sc.nextInt();
            
            System.out.println(g.bfs(u,t,n));
        }
    }
}