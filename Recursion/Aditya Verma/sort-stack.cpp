// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 

void insert(stack<int>&s, int ele)
{
	if(s.size()==0 or s.top()<=ele)     
	{
		s.push(ele);
		return;
	}
	
	int last=s.top();
	s.pop();
	insert(s,ele);
	s.push(last);
}

void sortStack(stack<int> &s)
{
	//complete the function here
	if(s.size()<=1) return;
	
	int last=s.top();
	s.pop();
	sortStack(s);
	insert(s,last);
}
