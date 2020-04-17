int Solution::lengthOfLastWord(const string A) 
{
    if(A.size() == 0)
    {
        return 0;
    }
    vector<int > vec;
    vec.push_back(0);
    int count = 0;
    int ma = 0;
    for(int i =0; i<A.size(); i++)
    {
        if(A[i] != ' ')
        {
            count++;
            vec.push_back(count);

        }
        else 
        {
            count = 0;
        }

    }
    ma = vec[vec.size()-1];
    return ma;
}
