string Solution::intToRoman(int A) 
{
    int q;
    string ans;
    q = A/1000;
    if(q)
    {
        for(int i =0; i<q; i++)
        {
            ans.push_back('M');
        }
    }
    A = A%1000;
    if(A>=900)
    {
        ans.push_back('C');
        ans.push_back('M');
        A = A%100;
    }
    else if(A>=500)
    {
        ans.push_back('D');
        A = A-500;
        q = A/100;
        for(int i =0; i<q; i++)
        {
            ans.push_back('C');
        }
        A = A%100;
    }
    else if(A>=400)
    {
        ans.push_back('C');
        ans.push_back('D');
        A = A%100;
    }
    else
    {
        q = A/100;
        for(int i =0; i<q; i++)
        {
            ans.push_back('C');
        }
        A = A%100;
    }
    
    if(A>=90)
    {
        ans.push_back('X');
        ans.push_back('C');
        A = A%10;
    }
    else if(A>=50)
    {
        ans.push_back('L');
        A = A-50;
        q = A/10;
        for(int i =0; i<q; i++)
        {
            ans.push_back('X');
        }
        A = A%10;
    }
    else if(A>=40)
    {
        ans.push_back('X');
        ans.push_back('L');
        A = A%10;
    }
    else
    {
        q = A/10;
        for(int i =0; i<q; i++)
        {
            ans.push_back('X');
        }
        A = A%10;
    }
    
    if(A>=9)
    {
        ans.push_back('I');
        ans.push_back('X');
    }
    else if(A>=5)
    {
        ans.push_back('V');
        A = A-5;
        q = A;
        for(int i =0; i<q; i++)
        {
            ans.push_back('I');
        }
    }
    else if(A>=4)
    {
        ans.push_back('I');
        ans.push_back('V');
    }
    else
    {
        q = A;
        for(int i =0; i<q; i++)
        {
            ans.push_back('I');
        }
    }
    
    return ans;
}
