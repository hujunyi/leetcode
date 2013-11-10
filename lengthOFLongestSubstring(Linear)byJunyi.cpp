#include<string>
#include<iostream>
#include<iterator>
using namespace std;
string longestPalindrome(string s)
{
	string s1;
	for(int j=0;j<s.size();j++)
	{
		s1.push_back('#');
		s1.push_back(s[j]);
	}
	s1.push_back('#');
	int *p = new int[s1.size()];
	int id = 0;
	int max = 0;
	memset(p,0,sizeof(p));
	for(int i = 1; i<s1.size();i++)
	{
		if(i<max)
		{
			p[i] = min(max-i,p[2*id-i]);
		}
		else
		{
			p[i]=1;
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
	for( int i =1;i<s1.size()-1;i++)
	{
		if(p[i]>maxLen)
		{
			maxLen = p[i];
			centerIndex = i;
		}
	}
	string result = s1.substr(centerIndex - maxLen +1,maxLen*2-1);
	string result1;
	for( int i =0;i<result.size();i++)
	{
		if(result[i]!='#')
			result1.push_back(result[i]);
	}
	return result1;
 }
 int main()
{
	string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
	//string s = "abb";
	cout<<longestPalindrome(s);
	return 0;
}