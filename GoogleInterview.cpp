[1, 3, 2, 7, 10, 2]
[3, 1, 6, 9]
Return the minimum non-repeated (unique) element
6 is the answer, b/c 1 and 2 is repeated

[1, 2]
[1]

int FindMinUnique(int[] arrA, int[] arrB) {
 set<int> setA;
 set<int> setB;
 sort(arrA,arrA+sizeof(arrA)/4);
 sort(arrB,arrB+sizeof(arrB)/4);
 for(int i=0;i<sizeof(arrA)/4;i++)
{
	setA.insert(arrA[i]);
}
for(int i=0;i<sizeof(arrB)/4;i++)
{
	setB.insert(arrB[i]);
}
for(set<int>::iterator j=setA.begin(),k=setB.begin();j!=setA.end()||k!=setB.end();j++,k++)
{
	if(j!=setA.end()&&k!=setB.end())
{
	if(*j==*k)
		continue;
	else
		return(min(*j,*k));
}
else
{
	if(j==setA.end())
		return *k;
	else
		return *j;
}
}
return -1;

}

C
A _ T
T    R
      E
      E

A _ T → ACT, ART, ACE
T_ _ _ → tree, etc.

char[] constraints = { ‘t’, ‘_’, ‘_’, ‘_’}
Dictionary.IsWord(string word) // “tree” returns true, “trzz” returns false

void GetValidWords(Set<string> &ans,char[] constraints) {
	char letters[26];
	string solution;
	for(int i=0;i<26;i++)
	{
		letters[i] = ‘a’+i;
}
for(int j=0;j<sizeof(constraints);j++)
{
	if(constraints[j]!=’_’)
		continue;
	else
	{
		for(int k=0;k<26;k++)
		{
			constraints[j] = letters[k];
			GetValidWords(ans,constraints);
		}
		return;
	}
}
for(int m=0;m<sizeof(constraints);m++)
{
	solution.push_back(constraints[m]);
}

if(Dictionary.IsWord(solution))
ans.push_back(solution);
return;

}
 