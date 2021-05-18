#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
 cin.tie(NULL);  
  cout.tie(NULL);
 freopen("input.txt", "r", stdin); 
 freopen("output.txt", "w", stdout);

 string line,s;
 cin>>s;
ifstream fin;
fin.open("courses.txt");
while(fin){
getline(fin,line);
size_t found=line.find(s);
if(found<100 && found>=0){
cout<<line<<endl;
}
}

}