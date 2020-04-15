#define pb push_back
vector<string> Solution::fizzBuzz(int A) 
{
    vector<string > str;
    for(int i = 1; i<=A; i++)
    {
        if((i%3 == 0) && (i%5==0))
        {
            string s = "FizzBuzz";
            str.pb(s);
        }
        else if(i%3 == 0)
        {
            string s = "Fizz";
            str.pb(s);
        }
        else if(i%5==0)
        {
            string s = "Buzz";
            str.pb(s);
        }
        else
        {
            string s = to_string(i);
            str.pb(s);
        }

    }
    return str;
}
