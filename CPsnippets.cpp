
//Fastest way to get a prime.

bool prime(lli n){
    if(n==1)
        return false;
    if(n==2||n==3)
        return true;
    if(n%2==0||n%3==0)
        return false;
    for(lli i = 5;i*i<=n;i+=6) {
        if(n%i==0||n%(i+2)==0)
            return false;
    }
    return true;
}}
///////////////////////////////////////////////////////////////

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_set<int, custom_hash> u;



//coordinate compression
vector<int> a(n);
// read the vector
vector<int> b = a;
sort(b.begin(), b.end());
map<int, int> m;
for (int i = 0; i < n; i++) {
    m[b[i]] = i;
}
for (int i = 0; i < n; i++) {
    a[i] = m[a[i]];
}
//Now every value of an array lies in [0, n). The most convineint it that if you need the original value for a[i], you can just write b[a[i]].
??--------------------------------------------------------------------------------------------------------------------------------------------

//Another approach
int n = a.size();
vector<pair<int, int>> pairs(n);
for(int i = 0; i < n; ++i) {
	pairs[i] = {a[i], i};
}
sort(pairs.begin(), pairs.end());
int nxt = 0;
for(int i = 0; i < n; ++i) {
	if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
	a[pairs[i].second] = nxt;
}








//create frequecy bit array
 vector<int> freq(32,0);
    for(int i=0;i<n;i++){
        int curr;curr=arr[i];
        deque<int> dq;
        while(curr){
            dq.push_front(curr%2);
            curr=curr/2;
        }
        int j=0;
        for(int itr=dq.size()-1;itr>=0;itr--){
            freq[j++]+=dq[itr];
        }
    }
--------------------------------------------------------


//Fermats little theorem 
//works only if mod is a prime 
//modular inverse of a number//
vector<int> fact(maxN);

void computeFact(int n){
    fact.reserve(n+1);
    fact[0]=1;
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

int power(int  x,int y)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2) % MOD;
    p = (p * p) % MOD;
    return (y % 2 == 0) ? p : (x * p) % MOD;
}
int inverse(int a){
    return power(a,MOD-2);
}

int nCr(int n,int r)
{
    if(n<r)return 0;
    if(r==0)return 1;

    return fact[n] * inverse(fact[r]) % MOD * inverse(fact[n-r])%MOD;
}
-----------------------------------------------
//Seive of Eratosthenes

const int template_array_size = 1e6 + 585;
bool is_prime[template_array_size];
void seive(){
    n=template_array_size;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

//Chinese Remainder Theorem(CRT)
int crt(vector<pair<int,int>> v){  //(first-> prime number(p1) ----- second-> k1
    int ans=0;
    int n=v.size();

    int m=1;

    for(int i=0;i<n;i++){
        m*=v[i].first;
    }


    for(int i=0;i<n;i++){
        int t=1;
        for(int j=0;j<i;j++){
            t*=v[j].first;
            t*= inverse(v[j].first,v[i].first);
            t%=m;
        }
        ans+=(t*(v[i].second + m - ans))%m;
        ans%=m;
    }

    return ans;
}
//O(N^2)

//template to solve interactive problems

struct Interactor{
    int limitQueries = 0;
    int queries = 0;
    Interactor(int n,int k){

    }
    int query(int l,int r){

    }
    void correctOutput(int ans,int n){

    }

};

