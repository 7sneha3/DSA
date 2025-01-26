#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
vector<bool> sieve(N+1, true);

void createSieve(){
    sieve[0] = sieve[1] = false;
    for(int i=0; i<N; i++){
    	if(sieve[i]){
    		for(int j=2*i; j<N; j=j+i){
    			sieve[j] = false;
			}
		}
	}
	
}

vector<int> generatedPrimes(int N){
	vector<int> ds;
	for(int i=2; i<=N; i++){
		if(sieve[i] == true){
			ds.push_back(i);
		}
	}
	return ds;
}

int main(){
	createSieve();
	int t;
	cout<<"Enter no of test cases: ";
	cin>>t;
	
	while(t--){
		int l, r;
		cout<<"\nEnter l and r values: ";
		cin>>l>>r;
		
		//step1: generate all primes till sqrt(r)
		vector<int> primes = generatedPrimes(sqrt(r));
		
		//step2: create a dummy array of size r-l+1 and make everyone to 1
		int dummy[r-l+1];
		for(int i=0; i<r-l+1; i++){
			dummy[i] = 1;
		}
		
		//step3: for all prime number mark ita multiples as false
		for(auto pr:primes){
			int firstMultiple = (l/pr) * pr;
			if(firstMultiple < l)
				firstMultiple += pr;
				
			for(int j=max(firstMultiple, pr*pr); j<=r; j+=pr){
				dummy[j-l] = 0;
			}
		}
		
		// Step *: Handle the case where l = 1 (1 is not a prime number)
        if (l == 1) dummy[0] = 0;
		
		//step4: get all the primes
		for(int i=l; i<=r; i++){
			if(dummy[i-l] == 1){
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
}
