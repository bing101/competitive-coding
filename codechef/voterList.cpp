#include<bits/stdc++.h>
#include<vector>
using namespace std;


bool binSearch(int item, int *arr, int n)
{
	int lo = 0, hi = n - 1;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if( arr[mid] == item )
			return true;
		else if( item < arr[mid] )
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return false;
}

bool checkItem(int item, int *lst1, int *lst2, int n1, int n2)
{
	int count = 0;
	if( binSearch(item, lst1, n1) )
		count++;
	if( binSearch(item, lst2, n2) )
		count++;
	if( count >= 1 )
		return true;
	return false;
}

int main()
{
	int n1, n2, n3;
	vector<int> finalList;
	scanf("%d %d %d", &n1, &n2, &n3);
	int l1[n1] = {0}, l2[n2] = {0}, l3[n3] = {0};
	for(int i = 0; i < n1; i++)
		scanf("%d", &l1[i]);
	for(int i = 0; i < n2; i++)
		scanf("%d", &l2[i]);
	for(int i = 0; i < n3; i++)
		scanf("%d", &l3[i]);
	
	for( int i = 0; i < n1; i++ ){
		if(checkItem(l1[i], l2, l3, n2, n3))
			finalList.push_back(l1[i]);
	}	
	
	for( int i = 0; i < n2; i++ ){	
		if(checkItem(l2[i], l1, l3, n1, n3))
			finalList.push_back(l2[i]);
	}
	sort(finalList.begin(), finalList.end() - 1);
	for(int i = 0; i < finalList.size() - 1 ; i++){
		if(finalList[i] == finalList[i+1])
			finalList.erase(finalList.begin() +i);
	}
	cout << finalList.size() << endl;
	for(int i = 0; i < finalList.size(); i++)
		printf("%d\n", finalList[i]);
	return 0;
}
