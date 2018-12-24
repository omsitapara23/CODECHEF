    #include<stdio.h>
    long int GCD(long int a, long int b)
    {
        if (a == 0)
            return b;
        return GCD(b%a, a);
    }
    int main() {
        int cases;
        scanf("%d", &cases);
        while(cases--)
        {
            int n;
            long int x, gcd;
            scanf("%d", &n);
            scanf("%ld", &gcd);
            --n;
            while(n--) {
                scanf("%ld", &x);
                gcd = GCD(x, gcd);
            }
            if (gcd == 1)
                printf("0\n");
            else
                printf("-1\n");
        }
        return 0;
    } 