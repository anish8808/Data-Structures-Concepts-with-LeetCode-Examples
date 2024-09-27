#include <bits/stdc++.h>

using namespace std;

void checkKey(string str , char key , int n ,  int i , int& index , bool& check)
{
	if(i>=n)
		return ;
	if(str[i]==key)
	{
		check = true;
		index = i;
	}
	
	checkKey(str , key , n , i+1 , index , check);
}

int main()
{
	string str = "Anish";
	char ch = 'k';
	bool  check = false;
	int n = str.length();
	int i =0; 
	int index=0;
	checkKey(str , ch  ,n , i , index , check );
	if(check)
		cout<<"the given key is present in the string at index" << index <<endl;
	return 0;
}