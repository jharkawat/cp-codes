vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) 
{
    int n = A.size();
    vector<vector<int>> vec(2*n-1);
    for(int i = 0; i<n; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            vec[i+j].push_back(A[i][j]);
        }
    }
    return vec;
}
