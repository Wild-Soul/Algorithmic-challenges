package main
import "fmt"

func merge(a []int, l, mid, r int) {
	i,j := l, mid+1;
	idx:=0;
	c := make([]int, (r-l+1));
	for; i<=mid && j<=r; {
		if a[i] < a[j] {
			c[idx] = a[i];
			idx++; i++;
		} else {
			c[idx] = a[j];
			idx++; j++;
		}
	}
	
	for ; i<=mid; i++ {
		c[idx] = a[i];
		 idx++;
	}
	
	for ; j<=r ; j++ {
		c[idx] = a[j];
		idx++;
	}
	for i=0; l<=r; l++ {
		a[l] = c[i];
		i++;
	}
}

func merge_sort(a []int, l,r int) {
	if l>=r {
		return;
	}
	mid := l+(r-l)/2;
	merge_sort(a, l, mid);
	merge_sort(a, mid+1, r);
	merge(a,l,mid,r);
}

func main(){
	
	var t,n int;
	fmt.Scanf("%d\n",&t);
	
	for ;t>0; t-- {
		fmt.Scanf("%d\n", &n);
// 		fmt.Println(n);
		a := make([]int, n);
		for i:=0; i<n; i++ {
			fmt.Scanf("%d",&a[i]);
// 			fmt.Printf("%d ", a[i]);
		}
// 		fmt.Println();
		merge_sort(a,0,n-1);
		for i:=0; i<n; i++ {
			fmt.Printf("%d ",a[i]);
		}
		fmt.Println();
	}
	
}
