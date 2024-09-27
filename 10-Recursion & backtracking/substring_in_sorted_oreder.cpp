#include <bits/stdc++.h>

using namespace std;

void Print_all_substring(string str , string output , int i , vector<string> &v)
{
	if(i>=str.length())
	{
		v.push_back(output);
		return;
	}
	
	//execlude the current char 
	Print_all_substring(str , output , i+1 , v);
	
	//include the current char 
	output.push_back(str[i]);
	Print_all_substring(str , output , i+1 , v);
}

int main()
{
	string str = "abc";
	string output = " ";
	vector<string>ans;
	int i=0;
	Print_all_substring(str , output , i , ans);
	sort(ans.begin() , ans.end());
	for (auto val : ans)
	{
		cout<<val<<" ";
	}
	return 0;
}