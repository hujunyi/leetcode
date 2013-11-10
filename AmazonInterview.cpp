/*
题目3：
Question 2 / 3 (Q9. SI)
Given a list of test results (each with a test date, Student ID, and the student’s Score), return the Final Score for each student. A student’s Final Score is calculated as the average of his/her 5 highest test scores. You can assume each student has at least 5 test scores.
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct TestResult {
	int studentID;
	string testDate;
	int testScore;
};
void updatePriorityQueue(vector<int>& q,int candidate)
{
	sort(q.begin(),q.begin()+5);
	if(candidate>*q.begin())
	{
		*q.begin() = candidate;
	}
}
map<int,int> calculateFinalScore(vector<TestResult> results)
{
	map<int,vector<int> > rec;
	map<int,int> ret;
	for(vector<TestResult>::iterator i=results.begin();i!=results.end();i++)
	{
		if(rec.find((*i).studentID)==rec.end())
		{
			vector<int> scores(1,(*i).testScore);
			rec.insert(pair<int,vector<int> >((*i).studentID,scores));
		}
		else if((rec.find((*i).studentID)->second).size()<5)
		{
			(rec.find((*i).studentID)->second).push_back((*i).testScore);
		}
		else
		{
			updatePriorityQueue(rec.find((*i).studentID)->second,(*i).testScore);
		}
	}

	for(map<int,vector<int> >::iterator j=rec.begin();j!=rec.end();j++)
	{
		vector<int> scores = j->second;
		int sum=0;
		
		for(vector<int>::iterator k=scores.begin();k!=scores.end();k++)
		{
			sum += *k;
		}
		int mean = sum/5;
		ret.insert(pair<int,int>(j->first,mean));
	}
	return ret;
}

int main()
{
	TestResult a;
	a.studentID=1;
	a.testDate = "10/18";
	a.testScore = 90;
	TestResult b;
	b.studentID=1;
	b.testDate = "10/18";
	b.testScore = 80;
	vector<TestResult> results;
	results.push_back(a);
	results.push_back(b);
	map<int,int> ret = calculateFinalScore(results);
	for(map<int,int>::iterator i=ret.begin();i!=ret.end();i++)
	{
		cout<<i->first<<":"<<i->second<<endl;
	}
	
	return 0;
	
}