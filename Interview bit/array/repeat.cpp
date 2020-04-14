#define ll long long
vector<int> Solution::repeatedNumber(const vector<int> &A) 
{
    long long max = A.size();
    long long sum = 0;
    long long square = 0;
    vector<int> fin;
    for(long long i=0; i<max; i++)
    {
        sum += (long long) A[i];
        square += ((long long) A[i])*((long long) A[i]);
    }
    long long sum_act = (max*(max+1))/2;
    long long square_act = (max*(max+1)*(2*max+1))/6;
    long long s_diff = sum_act - sum;
    long long sq_diff = square_act - square;
    long long no = ((abs(sq_diff)/abs(s_diff))-abs(s_diff))/2;
    if(s_diff>0)
    {
        fin.push_back((int)no);
        fin.push_back((int)(no+s_diff));
    }
    else
    {
        fin.push_back((int)(no+abs(s_diff)));
        fin.push_back((int)no);
    }
    return fin;
}
