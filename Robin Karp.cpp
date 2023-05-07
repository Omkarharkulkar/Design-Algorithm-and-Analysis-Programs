//Robin Karp

#include <bits/stdc++.h>

using namespace std;

void rabinKarpSearch(string S, string P)
{
    int Ns = S.length();
    int Np = P.length();
 
    int prime = 31;
    int mod = 1e9 + 9;
 
    vector<long long> p_pow(Ns);
    p_pow[0] = 1; 
    for (int i=1; i<Ns; i++) 
    {
        p_pow[i] = (p_pow[i-1] * prime) % mod;
    }
 
    vector<long long> h(Ns + 1, 0); 
    for (int i=0; i<Ns; i++)
    {
        h[i+1] = (h[i] + (S[i] - 'a' + 1) * p_pow[i]) % mod;
    }
 
    long long hash_P = 0; 
    for (int i=0; i<Np; i++) 
    {
        hash_P = (hash_P + (P[i] - 'a' + 1) * p_pow[i]) % mod; 
    }
 
    for (int i=0; i+Np-1 < Ns; i++) 
    { 
        long long curr_hash = (h[i+Np] + mod - h[i]) % mod; 
        if (curr_hash == hash_P * p_pow[i] % mod)
            cout<<"Pattern found at position: "<<i<<endl;
    }
}

int main()
{
    string S;
    cout<<"Enter the string: ";
    cin>>S;
 
    string P;
    cout<<"Enter the pattern want to search: ";
    cin>>P;
 
    rabinKarpSearch(S,P);
 
 return 0;
}

