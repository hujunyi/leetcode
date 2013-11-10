/*
Problem:
Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)
*/
#include<iostream>
using namespace std;
void swap(char &a,char &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
void reverse2(char *s){
    int n = strlen(s);
    for(int i=0; i<n/2; ++i)
        swap(s[i], s[n-i-1]);
}
void reverse(char* s)
{
	int j = strlen(s);
	int i = 0;
	j--;
	while(i<j)
	{
		swap(s[i],s[j]);
		i++;
		j--;
	}
}
int main(){
    char s[] = "1234567890";
    reverse(s);
    cout<<s<<endl;
    return 0;
}
