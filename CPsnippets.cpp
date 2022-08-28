
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

