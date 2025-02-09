/*
Calculate GCD of two nos
*/
#include<iostream>
using namespace std;
int gcd(int no1, int no2){
	if(no1 == 0)
		return no2;
	
	if(no2 == 0)
		return no1;	
		
	while(no1 != no2){
		if(no1>no2)
			no1 = no1-no2;
		else
			no2 = no2-no1;
	}
	return no1;
}

int main(){
	int a,b;
	cin>>a>>b;
	
	int ans = gcd(a, b);
	cout<<"GCD of "<<a<<" and "<<b<<" is "<<ans;
	return 0;
}
