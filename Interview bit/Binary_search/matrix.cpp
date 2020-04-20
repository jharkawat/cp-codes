int Solution::searchMatrix(vector<vector<int> > &A, int B) 
{
int n = A.size(), m = A[0].size(), l = 0, r = m * n - 1;
if(m*n==1)
    return A[0][0]==B;
while (l<=r){
    int mid=(l+r)/2;
    if (A[mid/m][mid%m]==B)
        return 1;
    else if(A[mid/m][mid%m] < B)
        l = mid + 1;
    else r = mid-1;
}
return 0;}

