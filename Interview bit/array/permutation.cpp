#define pb push_back
vector<int> Solution::findPerm(const string A, int B) 
{
    int count = 0;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == 'D')
        {
            count++;
        }
    }
    vector<int > ans;
    int d = count +1;
    int i = count +1;
    ans.push_back(d);
    for(int j =0; j<A.size(); j++)
    {
        if(A[j] == 'I') 
        {
            i++;
            ans.push_back(i);
        }
        else
        {
            d--;
            ans.push_back(d);
        }
    }
    return ans;
}
