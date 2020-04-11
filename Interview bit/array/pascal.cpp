vector<int> pascal(vector<int>& b)
{
    vector<int> pass;
    pass.push_back(1);
    for(int i = 1; i<b.size(); i++)
    {
        pass.push_back(b[i-1]+b[i]);
    }
    pass.push_back(1);
    return pass;
}

vector<vector<int> > Solution::solve(int A) 
{
    vector<vector<int> > vec;
    vector<int> b;
    b.push_back(1);

    for(int i = 0; i<A; i++)
    {
        vec.push_back(b);
        b = pascal(b);
    }
    
    return vec;
    
}



