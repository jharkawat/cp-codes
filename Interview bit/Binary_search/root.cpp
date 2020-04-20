int Solution::sqrt(int A) 
{
    int s;
    int ans = 0;
    int low = 1;
    int high = A;
    while(low <= high)
    {
        s = low + (high-low)/2;
        if( s*s == A)
        {
            return s;
        }
        else if(s > A/s)
        {
            high = s-1;            
        }
        else if(s*s <A)
        {
            int a = s;
            ans = max(ans, s);
            low = s+1;
        }
    }
    
    return ans;
}
