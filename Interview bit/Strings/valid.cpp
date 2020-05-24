int Solution::isNumber(const string A) 
{
    int m = A.size();
    int flag = 0;
    int stag = 0;
    int tag = 0;
    for(int i = 0; i<m; i++)
    {
        if(A[m-1] == '.')
        {
            return 0;
        }
        if((A[i] >=48 && A[i]<58) || A[i] == 'e' || A[i] == '.' || A[i] == '-' || A[i] == '+' || A[i] == ' ') 
        {
            if(A[i] == 'e')
            {
                flag = 1;
            }
            if(A[i] == '.' && flag == 1)
            {
                return 0;
            }
            if(A[i] == '.' && A[i+1] == 'e')
            {
                return 0;
            }
            
            if(A[i] >=48 && A[i]<58)
            {
                stag = 1;
            }
            
        }
        else
        {
            return 0;
        }
    }
    if(stag == 0)
    {
        return 0;
    }
    return 1;
}
