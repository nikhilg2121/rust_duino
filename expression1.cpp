#include<bits/stdc++.h>
using namespace std;

 
int main(){
ios_base::sync_with_stdio(false);
 cin.tie(NULL);  
  cout.tie(NULL);
 freopen("input.txt", "r", stdin); 
 freopen("output.txt", "w", stdout);
float num=0,prev=-1,prev2;
int i=0,flag=0,flag1=0,flag2=0,flag3=0;

char op,prevop; 
for(;i<5;i++){	
	if(i%2==0){
    
     cin>>num;
     if(cin.fail()){

     	flag2=1;

     }
     if(num>1000){
     	cout<<"invalid number";
     	flag3=1;
     	break;
     }
	}
	else{
		cin>>op;
		if(op==' '){
			i--;
			continue;
		}
		if(!(op==' ' || op=='*' || op=='/'||op=='+'||op=='-')){
			flag2=1;
			break;
		}
	
	}
	if(prev==-1){
		prev=num;
		continue;
	}
	if((op=='*'|| op=='/')&& flag==0 && i%2==0){
		flag1=1;
		if(op=='*'){
			prev=prev*num;

		}
		else{
			prev=prev/num;
		}
	}
	if((op=='+' || op=='-')&& flag==0 && i%2==0){
		
		if(flag1==1){
          if(op=='+'){
             prev=prev+num;
          }
          else{
          	prev=prev-num;
        }
		}
		else{
			prevop=op;
		flag=1;
		prev2=prev;
		prev=num;
		continue;
		}
	}
	if((op=='*'|| op=='/')&& flag==1 && i%2==0){
          if(op=='*'&& prevop=='+'){
          	prev=prev2+prev*num;
          }
          else if(op=='*'&& prevop=='-'){
          	prev=prev2-prev*num;
          }
          else if(op=='/'&& prevop=='+'){
          	prev=prev2+prev/num;
          }
          else if(op=='/'&& prevop=='-'){
          	prev=prev2-prev/num;
          }
	}
	if((op=='+'|| op=='-')&& flag==1 && i%2==0){
          if(op=='+'&& prevop=='+'){
          	prev=prev2+prev+num;
          }
          else if(op=='+'&& prevop=='-'){
          	prev=prev2+prev+num;
          }
          else if(op=='-'&& prevop=='+'){
          	prev=prev2+prev-num;
          }
          else if(op=='-'&& prevop=='-'){
          	prev=prev2+prev-num;
          }
	}



}
if(flag2==0 && flag==0){
cout<<prev;
}
else if(flag2==1){
cout<<"input is inappropriate";
}
}