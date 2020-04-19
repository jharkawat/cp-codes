int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int start = 0;
    int end = A.size()-1;
    int flag = 0;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(A[mid] == B)
        {
            return mid;
        }
        else if(A[mid] < B)
        {
            start = mid+1;
            flag = 0;
        }
        else if(A[mid] > B)
        {
            end = mid-1;
            flag =1;
        }
    }
    if(flag)
    {
        return mid;
    }
    else
    {
        return (mid+1);
    }
}
