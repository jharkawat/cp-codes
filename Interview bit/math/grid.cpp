int value(int a, int b)
{
    if((a==1)||(b==1))
    {
        return 1;
    }
    return(value(a,b-1) + value(a-1,b));
    
}
int Solution::uniquePaths(int A, int B) 
{
    int sum = value(A,B);
    return sum;
}
