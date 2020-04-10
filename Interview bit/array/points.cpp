int Solution::coverPoints(vector<int> &A, vector<int> &B) 
{
    int count = 0;
    for(int i = 0; i<(A.size()-1) ; i++ )
    {
        int hori;
        int vert;
        hori = abs(A[i+1] - A[i]);
        vert = abs(B[i+1] - B[i]);
        int maxi = max(hori,vert);
        count += maxi;
    }
    return count;
    
    
}