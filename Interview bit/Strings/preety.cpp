vector<string> Solution::prettyJSON(string A) 
{
    int count = 0;
    vector<string> vec;
    string str;
    str.erase();
    for(int i = 0; i< A.size(); i++)
    {
        if(A[i] == '{' || A[i] == '[')
        {
            if(str.size() != 0)
            {
                string spr;
                for(int j = 0; j<count; j++)
                {
                    spr += '\t';
                }
                spr += str;
                vec.push_back(spr);
                str.erase();
                spr.erase();      
            }
            
            for(int j = 0; j<count; j++)
            {
                str += '\t';
            }
            str.push_back(A[i]);
            vec.push_back(str);
            str.erase();
            count++;
            continue;
        }
        else if(A[i] == ']' || A[i] == '}')
        {
            if(str.size() != 0)
            {
                string spr;
                for(int j = 0; j<count; j++)
                {
                    spr += '\t';
                }
                spr += str;
                vec.push_back(spr);
                str.erase();
                spr.erase();            
                
            }
            count--;
            for(int j = 0; j<count; j++)
            {
                str += '\t';
            }
            str.push_back(A[i]);
            if(A[i+1] == ',')
            {
                str.push_back(A[i+1]);
                i++;
            }
            vec.push_back(str);
            str.erase();
            continue;
        }
        else if(A[i] == ',')
        {
            string spr;
            for(int j = 0; j<count; j++)
            {
                spr += '\t';
            }
            str.push_back(A[i]);
            spr += str;
            vec.push_back(spr);
            str.erase();
            spr.erase();
        }
        else
        {
            str.push_back(A[i]);
        }
    }
    return vec;
}
