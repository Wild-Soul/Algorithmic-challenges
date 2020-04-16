import java.io.*;
import java.util.*;

class Graph {
    final int N = 50005;
    final int INF = 100000007;
    List<List< Pair >> adj = new ArrayList<List< Pair >> (N);

    void init() {
        for(int i=0; i<N; i++) {
            adj.add(new ArrayList<Pair>());
        }
    }

    int bfs_0_1( int n ) {
        Deque< Pair > d = new LinkedList< Pair > ();
        d.addFirst( new Pair(1,0) );
        int[] dist = new int[n+1];
        for(int i=0; i<=n; i++) {
            dist[i] = INF;
        }
        dist[1] = 0;

        while(d.isEmpty() == false) {
            Pair j = d.poll();
            int u = j.getKey();
            int w = j.getValue();

            for(Pair p : adj.get(u)) {
                if( dist[p.getKey()] > ( dist[u] + p.getValue() ) ) {
                    dist[p.getKey()] = dist[u] + p.getValue();
                    if(p.getValue() == 1) {
                        d.addLast(new Pair (p.getKey(), 1));
                    } else {
                        d.addFirst(new Pair (p.getKey(), 0));
                    }
                }
            }
        }
        return dist[n];
    }

    public static void main(String args[]) {
        int t,n;
        Graph g = new Graph();
        g.init();
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        while(t-->0) {
            n = sc.nextInt();
            int[] a = new int[n+1];
            for(int i=1; i<=n; i++) {
                a[i] = sc.nextInt();
                if(i+1<=n) {
                    g.adj.get(i).add(new Pair(i+1,1));
                }
                if(i-1 > 0) {
                    g.adj.get(i).add(new Pair(i-1,1));
                }
                if(i!=a[i]) {
                    g.adj.get(i).add(new Pair(a[i],0));
                }
            }
            System.out.println( g.bfs_0_1(n) );
            for(int i=0; i<=n; i++) {
                g.adj.get(i).clear();
            }
        }

        return;
    }
}

class Pair {
    int a,b;
    Pair(int a,int b) {
        this.a = a;
        this.b = b;
    }
    int getKey() {
        return this.a;
    }
    int getValue() {
        return this.b;
    }
}