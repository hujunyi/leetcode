#include<string>
#include<iostream>
#include<iterator>
using namespace std;
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
string longestPalindrome(string s)
{
	/*
	Add '#' to s.
	*/
	string s1;
	for(int j=0;j<s.size();j++)
	{
		s1.push_back('#');
		s1.push_back(s[j]);
	}
	s1.push_back('#');
	s1 = "^"+s1;
	s1 = s1+"$";
	int *p = new int[s1.size()];
	int id = 0;
	int max = 0;
	memset(p,0,sizeof(p));
	for(int i = 1; i<s1.size()-1;i++)
	{
		if(i<max)
		{
			p[i] = min(max-i,p[2*id-i]);
		}
		else
		{
			p[i]=0;
		}
		while(s1[i+p[i]]==s1[i-p[i]])
		{
			p[i]++;
		}
		if(i+p[i]>max)
		{
			max = i+p[i];
			id = i;
		}
	}

	int maxLen = 0;
	int centerIndex = 0;
	for (int i = 1; i < s1.size()-1; i++) {
		if (p[i] > maxLen) {
		maxLen = p[i];
		centerIndex = i;
		}
	}

	return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
int main()
{
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	//string s = "abba";
	cout<<longestPalindrome(s);
	return 0;
}
