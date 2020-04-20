int Solution::cpFact(int A, int B) 
{
    int result = 1;
    int sq = sqrt(A);
    if( __gcd(A,B) == 1)
    {
        return A;
    }
    else
    {
        for(int i = 2; i<=sq; i++)
        {
            if(A%i == 0)
            {
                if(__gcd((A/i),B) == 1 )
                {
                    return A/i;
                }
                else if(__gcd(i,B) == 1)
                {
                    result = i;
                }
            }

        }
    }
    return result;
}
