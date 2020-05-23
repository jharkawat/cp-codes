string Solution::convert(string A, int B) 
{
    vector<string> vec(B);
    int k = 0;
    int j = -1;
    for(int i = 0; i<A.size(); i++)
    {
        if(k<B)
        {
            string str;
            if(i>B-1)
            {
                str = vec[k];
            }
            char ch = A[i];
            str.push_back(ch);
            vec[k] = str;
            //cout << str << " i :" << i << " k :" << k << endl;
            k++;
            if(k == B)
            {
                j = B-2;
                
            }
            if(B <= 2 && k == B)
            {
                k = 0;
                j = -1;
            }
            
        }
        else if(j > -1)
        {

            string str;
            str = vec[j];
            char ch = A[i];
            str.push_back(ch);
            vec[j] = str;
            //cout << str << " i :" << i << " j :" << j << endl;
            if(j == 0)
            {
                k = 1;
            }
            j--;
        }
    }
    string ans;
    ans = vec[0];
    for(int l = 1; l<B; l++)
    {
        ans += vec[l];
    }
    return ans;
}
