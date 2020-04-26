int Solution::singleNumber(const vector<int> &B) 
{
    vector<int> A;
    for(int i = 0; i<B.size(); i++)
    {
        A.push_back(B[i]);
    }
    sort(A.begin(), A.end());
    if(A.size() == 0)
    {
        return A[A.size()-1];
    }
    int x = 0;
    for(int i = 0; i<A.size()-3; i = i+3)
    {
        x = A[i]^A[i+1]^A[i+2];
        //cout << x << endl;
        if((x == A[i]) && (x == A[i+1]) && (x == A[i+2]))
        {
            x =0;
        }
        else
        {
            //cout << "in here" << endl;
            if(A[i]^A[i+1] != 0)
            {
                if(A[i]^A[i+2] != 0)
                {
                    return A[i];
                }
                else
                {
                    return A[i+1];
                }
            }
            else
            {
                return A[i+2];
            }
        }    
    }
    return A[A.size()-1];
}
