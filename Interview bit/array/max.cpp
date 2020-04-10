int Solution::maxArr(vector<int> &A) 
{
    vector<int > A1, A2;
    for(int i = 0; i<A.size() ; i++)
    {
        int t = A[i]+i;
        int u = A[i]-i;
        A1.push_back(t);
        A2.push_back(u);
    }
    
    int max_ele1 = *max_element(A1.begin(),A1.end());
    int min_ele1 = *min_element(A1.begin(),A1.end());
    int max1 = abs(max_ele1-min_ele1);

    int max_ele2 = *max_element(A2.begin(),A2.end());
    int min_ele2 = *min_element(A2.begin(),A2.end());
    int max2 = abs(max_ele2-min_ele2);
    
    int max3 = max(max1,max2);

    return max3;
}
