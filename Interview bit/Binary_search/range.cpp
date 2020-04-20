vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    int left = -1; 
    int right = -1;
    int low = 0;
    int high = A.size()-1;
    int mid;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid] == B)
        {
            left = mid;
            high = mid-1;
        }
        else if(A[mid] > B)
        {
            high = mid -1;
        }
        else if(A[mid] < B)
        {
            low = mid+1;
        }
    }

    low = 0;
    high = A.size()-1;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid] == B)
        {
            right = mid;
            low = mid+1;
        }
        else if(A[mid] > B)
        {
            high = mid -1;
        }
        else if(A[mid] < B)
        {
            low = mid+1;
        }
    }
    
    vector<int >ans;
    ans.push_back(left);
    ans.push_back(right);
    return ans;
    
}
