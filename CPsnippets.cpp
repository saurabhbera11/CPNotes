
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

//Another approach







