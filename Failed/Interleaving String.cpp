 bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case. 
        string::iterator index1 = s1.begin();
        string::iterator index2 = s2.begin();
        string::iterator index3 = s3.begin();
        if(index1==s1.end()&&index2==s2.end()&&index3==s3.end())
        {
           return true; 
        }
        if(index3==s3.end()&&(index1!=s1.end()||index2!=s2.end()))
		{
			return false;
		}
        if(*index3==*index1&&*index3==*index2)
        {
            if(isInterleave(s1.substr(index1-s1.begin()+1,s1.size()-1),s2,s3.substr(index3-s3.begin()+1,s3.size()-1)))
            {
                return true;
            }
            else
            {
                return isInterleave(s1,s2.substr(index2-s2.begin()+1,s2.size()-1),s3.substr(index3-s3.begin()+1,s3.size()-1));
            }

        }
        else if(*index3==*index1)
        {
            return isInterleave(s1.substr(index1-s1.begin()+1,s1.size()-1),s2,s3.substr(index3-s3.begin()+1,s3.size()-1));
        }
        else if(*index3==*index2)
        {
            return isInterleave(s1,s2.substr(index2-s2.begin()+1,s2.size()-1),s3.substr(index3-s3.begin()+1,s3.size()-1));
        }
        else
        {
            return false;
        }
        
    }