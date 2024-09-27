#include <bits/stdc++.h>

using namespace std;

void Print_all_substring(string str , string output , int i)
{
	if(i>=str.length())
	{
		cout<<output<<endl;
		return;
	}
	
	//execlude the current char 
	Print_all_substring(str , output , i+1);
	
	//include the current char 
	output.push_back(str[i]);
	Print_all_substring(str , output , i+1);
}

int main()
{
	string str = "xy";
	string output = " ";
	int i=0;
	Print_all_substring(str , output , i);
	return 0;
}