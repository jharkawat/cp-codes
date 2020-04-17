int Solution::strStr(const string A, const string B) 
{
    if((B.size() == 0) || (A.size() == 0))
    {
        return -1;
    }
    int count = 0;
    for(int i = 0; i<A.size(); i++)
    {
        if(A[i] == B[0])
        {
            for(int j = 0; j<B.size(); j++)
            {
                if(A[i+j] == B[j])
                {
                    count++;
                }
            }
            if(count == B.size())
            {
                return i;
            }
            else
            {
                count = 0;
            }

        }
    }
    return -1;
}
