int Solution::findCount(const vector<int> &A, int B) 
{
    int low = 0;
    int high = A.size()-1;
    int left = -1;
    int right = -1;
    int mid;
    while( low <= high)
    {
        mid = low + (high-low)/2;
        if(A[mid] == B)
        {
            left = mid;
            high = mid -1;
        }
        else if(A[mid] > B)
        {
            high = mid-1;
        }
        else if(A[mid] < B)
        {
            low = mid+1;
        }

    }

    low = 0;
    high = A.size()-1;

    while( low <= high)
    {
        mid = low + (high-low)/2;
        if(A[mid] == B)
        {
            right = mid;
            low = mid +1;
        }
        else if(A[mid] > B)
        {
            high = mid-1;
        }
        else if(A[mid] < B)
        {
            low = mid+1;
        }

    }
    if(left == -1)
    {
        return 0;
    }
    else
    {
        return (right-left +1);
    }
    
}
