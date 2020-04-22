long long find(long long x, long long n, long long d)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return (x%d);
    }
    else if(n%2 == 0)
    {
        return( find(x*x,(n/2),d)%d);
    }
    else
    {
        return( (find(x*x,(n/2),d)*x)%d);
    }
}
int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long t;
    long long a = x;
    long long b = n;
    long long c = d;
    
    if((x==0))
    {
        return 0;
    }
    if(d == 1)
    {
        return 0;
    }
    long long m = find(a,b,c);
    if(m<0)
    {
        t = (m%c);
        t = t + c;
        return (int)t;
    }
    t = (m%c);

    //cout << 
    return (int)t;
}
