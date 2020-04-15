#define pb push_back
bool isprime(int n)
{
    int sq = sqrt(n);
    for(int i =2; i<=sq; i++)
    {
        if(n%i == 0)
        {
            //cout << i << endl;
            return false;
        }
    }
    return true;
}
vector<int> Solution::primesum(int A) 
{
    vector<int > ans;
    if(A == 4)
    {
        ans.pb(2);
        ans.pb(2);
        return ans;
    }
    else
    {
        for(int i = 3; i<=A/2; i=i+2)
        {
            if(isprime(i) == true)
            {
                int m = A-i;
                //cout <<"m : " << m << endl;
                if(isprime(m) == true)
                {
                    //cout << "in here i :" << i << " m : " << m << endl;
                    ans.erase(ans.begin(), ans.end());
                    ans.pb(i);
                    ans.pb(A-i);
                    break;
                }
            }
        }
    }
    return ans;
}
