void swap(vector<vector<int> > &B, int i)
{
    int lim = B.size()-i-2;
    int swap; 
    for(int j= i;j<=lim; j++)
    {
        swap = B[i][j];
        B[i][j] = B[B.size()-1-j][i];
        B[B.size()-1-j][i] = B[lim+1][B.size()-1-j];
        B[lim+1][B.size()-1-j]= B[j][lim+1];
        B[j][lim+1] = swap;
    }
}
void Solution::rotate(vector<vector<int> > &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = A.size();
    int j = 0;
    while(j != (i/2))
    {
        swap(A,j);
        j++;
    }
}
