vector<int> Solution::plusOne(vector<int> &A) 
{
    int flag = 1;
    int count = 0;
    for(int i=0; i<A.size()-1 ; i++)
    {
        if((A[i] == 0) && flag)
        {
            count++;
        }
        else
        flag = 0;
    }
    while(count)
    {
        A.erase(A.begin() + count - 1);
        count--;
    }
    int m = A.size();
    int stag = 1;
    while(stag && m)
    {
        if(A[m-1] != 9)
        {
            A[m-1] = A[m-1] + 1;
            stag = 0;
        }
        else
        {
            A[m-1] = 0;
            m--;
        }
    }
    if(stag)
    {
        for(int i = 0; i<A.size() ; i++)
        {
            A[i] = 0;
        }
        A.insert(A.begin() + 0, 1);
    }
    return A;
}    
