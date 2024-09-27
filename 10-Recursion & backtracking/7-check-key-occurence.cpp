#include <bits/stdc++.h>

using namespace std ;

void find_the_ouccr_index(string str  , int n , vector<int>&nums , int i , int key , bool& check)
{
	if(i>=n)
		return ;
	
	if(str[i]==key)
	{
		check = true ;
		nums.push_back(i);
	}
	find_the_ouccr_index(str , n , nums  , i+1 , key , check );
}

int main()
{
	
	string str = "AnishKashyap";
	int n = str.length();
	vector<int > nums;
	int i=0;
	char key = 'e';
	bool check = false;
	find_the_ouccr_index(str , n , nums , i , key , check);
	
	if (check)
	{
		cout<<"key is present at index " <<endl;
		for(auto val:nums)
		{
			cout<<val<<" ";
		}
	}
	else
	{
		cout<<"provided key is not present "<<endl;
	}
	return 0;
}