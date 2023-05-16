#include<bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
	if(a.size()!=b.size()){
		return a.size()<b.size();
	}
	return a<b;
}
int main(){
	string s;
	cin>>s;
	vector<string>vs;
	s=s+"%";
	string c="";
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			c=c+s[i];
		} else {
			if(c!=""){
				vs.push_back(c);
			}
			c="";
		}
	}
	for(int i=0;i<vs.size();i++){
		int pos=-1e9;
		for(int j=0;j<vs[i].size();j++){
			if(vs[i][j]!='0'){
				pos=j;
				break;
			}
		}
		if(pos!=-1e9){
			vs[i].erase(0,pos);
		}
		if(pos==vs[i].size()-1){
			vs[i]="0";
		}
	}
	sort(vs.begin(),vs.end(), cmp); 
	cout<<vs[vs.size()-1];
}