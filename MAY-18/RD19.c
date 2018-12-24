    #include <stdio.h>
     
    int comp(const void *a, const void *b) {
    	return (*(int*)a - *(int*)b);
    }
     
    int main(void) {
    	int t;
    	scanf("%d", &t);
    	while(t--) {
    		int n;
    		scanf("%d", &n);
    		int arr[n],i;
    		for(i=0;i<n;i++)	scanf("%d", &arr[i]);
    		qsort(arr, n, sizeof(int), comp);
    		if (arr[0]==1)  {
    		    printf("0\n");
    		    continue;
    		}
    		int j, res = 0;
    		for(i=1;i<n;i++) {
    			if (arr[i]%arr[0]!=0) {
    			    break;
    			}
    		}
    		if (i<n)   printf("0\n");
    		else  printf("-1\n");
    	}
    	return 0;
    } 