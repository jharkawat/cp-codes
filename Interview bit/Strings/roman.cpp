int Solution::romanToInt(string A) 
{
    
    int sum = 0;
    for(int i =0; i<A.size(); i++)
    {
        char a = A[i];
        char b = 'I';
        if(i<A.size()-1)
        {
            b = A[i+1];
        }
        
        if( a == 'M')
        {
            sum += 1000;
        }
        else if( a == 'D')
        {
            if(b != 'M')
            {
                sum += 500;
            }
            else 
            {
                sum -= 500;
                
            }
        }
        else if( a == 'C')
        {
            if((b != 'M') && (b != 'D')) 
            {
                sum += 100;
            }
            else 
            {
                sum -= 100;
                
            }
        }
        else if( a == 'L')
        {
            if((b != 'M') && (b != 'D')&& (b != 'C')) 
            {
                sum += 50;
            }
            else 
            {
                sum -= 50;
                
            }
        }
        else if( a == 'X')
        {
            if((b != 'M') && (b != 'D')&& (b != 'C')&& (b != 'L')) 
            {
                sum += 10;
            }
            else 
            {
                sum -= 10;
                
            }
        }
        else if( a == 'V')
        {
            if((b != 'M') && (b != 'D')&& (b != 'C')&& (b != 'L')&& (b != 'X')) 
            {
                sum += 5;
            }
            else 
            {
                sum -= 5;
                
            }
        }
        else if( a == 'I')
        {
            if((b != 'M') && (b != 'D')&& (b != 'C')&& (b != 'L')&& (b != 'X')&& (b != 'V')) 
            {
                sum += 1;
            }
            else 
            {
                sum -= 1;
                
            }
        }
    }
    return sum;
}
