#include<bits/stdc++.h>
using namespace std;
#include<string>
 
int main(){
ios_base::sync_with_stdio(false);
 cin.tie(NULL);  
  cout.tie(NULL);
 freopen("input.txt", "r", stdin); 
 freopen("output.txt", "w", stdout);
 char y_name[100],year[5];
 cout<<"What is your name?"<<endl;
 cin.getline(y_name,100);
 cout<<"Hello, "<<y_name<<"!"<<endl;
 cout<<"What year were you born?"<<endl;
 cin.getline(year,5);
 int num=0;
 for(int i=0;i<4;i++){
 	num=num*10+year[i]-'0';
 }

 num=2021-num;
 if(num>0){
    cout<<"Congratulations, You are "<<num<<" years old!";
 }
 else if(num==0){
 	cout<<"You are just born bro";
 }
 else{
 	cout<<"invalid age bro";
 }

}