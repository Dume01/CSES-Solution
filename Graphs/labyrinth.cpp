#include <bits/stdc++.h>
using namespace std;

// input
int n,m;
vector<string> a;

// index of A and B
int starti, startj,endi, endj;

// Validator for inside the grid and visited 
bool valid(int i, int j){
	return i>=0 && j>=0 && i<n && j<m && a[i][j]=='.';
}

void run_case(){
	// Taking input
	cin>>n>>m;
	a = vector<string>(n);
	for(int i =0;i<n;i++)cin>>a[i];
	
	// Storing position of A and B 
	for(int i =0;i<n;i++){
		for(int j =0;j<m;j++){
			if(a[i][j]=='A'){
				starti = i;
				startj = j;
			}
			if(a[i][j]=='B'){
				endi = i;
				endj = j;
			}
		}
	}
	
	a[endi][endj]= '.';
	
	queue<pair<int,int>> bfs;
	bfs.push({starti,startj});
	bool found = false;
	while(!found && !bfs.empty()){
		auto f = bfs.front();
		bfs.pop();
		int i = f.first;
		int j = f.second;
		if(valid(i+1,j)){
			bfs.push({i+1,j});
			a[i+1][j] = 'D';
			if(i+1==endi && j==endj)found = true;
		}
		if(valid(i-1,j)){
			bfs.push({i-1,j});
			a[i-1][j] = 'U';
			if(i-1==endi && j==endj)found = true;
		}
		if(valid(i,j+1)){
			bfs.push({i,j+1});
			a[i][j+1] = 'R';
			if(i==endi && j+1==endj)found = true;
		}
		if(valid(i,j-1)){
			bfs.push({i,j-1});
			a[i][j-1] = 'L';
			if(i==endi && j-1==endj)found = true;
		}
	}
	if(!found){
		cout<<"NO"<<endl;
		return;
	}
	string ans = "";
	int curri = endi, currj = endj;
	while(!(curri==starti && currj==startj)){
		ans += a[curri][currj];
		switch(a[curri][currj]){
			case 'D':
				curri--;
				break;
			case 'U':
				curri++;
				break;
			case 'R':
				currj--;
				break;
			case 'L':
				currj++;
				break;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);int tc=1;
while(tc--)run_case();
return 0;
}