    #include<cstdio>
    #include<cstring>
    #include<cmath>
    #include<algorithm>
    using namespace std;
    #define MAXN 277777
    const double PI=acos(-1.0);
     
    struct Complex{
    	double real,imag;
    	Complex(double _real,double _imag):real(_real),imag(_imag){}
    	Complex(){}
    	Complex operator+(const Complex &cp) const{
    		return Complex(real+cp.real,imag+cp.imag);
    	}
    	Complex operator-(const Complex &cp) const{
    		return Complex(real-cp.real,imag-cp.imag);
    	}
    	Complex operator*(const Complex &cp) const{
    		return Complex(real*cp.real-imag*cp.imag,real*cp.imag+cp.real*imag);
    	}
    	void setValue(double _real=0,double _imag=0){
    		real=_real; imag=_imag;
    	}
    };
     
    int len;
    Complex wn[MAXN],wn_anti[MAXN];
     
    void FFT(Complex y[],int op){
    	for(int i=1,j=len>>1,k; i<len-1; ++i){
    		if(i<j) swap(y[i],y[j]);
    		k=len>>1;
    		while(j>=k){
    			j-=k;
    			k>>=1;
    		}
    		if(j<k) j+=k;
    	}
    	for(int h=2; h<=len; h<<=1){
    		Complex Wn=(op==1?wn[h]:wn_anti[h]);
    		for(int i=0; i<len; i+=h){
    			Complex W(1,0);
    			for(int j=i; j<i+(h>>1); ++j){
    				Complex u=y[j],t=W*y[j+(h>>1)];
    				y[j]=u+t;
    				y[j+(h>>1)]=u-t;
    				W=W*Wn;
    			}
    		}
    	}
    	if(op==-1){
    		for(int i=0; i<len; ++i) y[i].real/=len;
    	}
    }
    void Convolution(Complex A[],Complex B[],int n){
    	for(len=1; len<(n<<1); len<<=1);
    	for(int i=n; i<len; ++i){
    		A[i].setValue();
    		B[i].setValue();
    	}
    	for(int i=0; i<=len; ++i){
    		wn[i].setValue(cos(2.0*PI/i),sin(2.0*PI/i));
    		wn_anti[i].setValue(wn[i].real,-wn[i].imag);
    	}
    	FFT(A,1); FFT(B,1);
    	for(int i=0; i<len; ++i){
    		A[i]=A[i]*B[i];
    	}
    	FFT(A,-1);
    }
     
    Complex A[MAXN],B[MAXN];
    int a[111111],cnt[111111];
    long long tot[MAXN];
    int main(){
    	int t,n;
    	scanf("%d",&t);
    	while(t--){
    		scanf("%d",&n);
    		memset(cnt,0,sizeof(cnt));
    		int maxa=0;
    		for(int i=0; i<n; ++i){
    			scanf("%d",a+i);
    			++cnt[a[i]];
    			maxa=max(maxa,a[i]);
    		}
    		for(int i=0; i<=maxa; ++i){
    			A[i].setValue(cnt[i]);
    			B[i].setValue(cnt[i]);
    		}
    		Convolution(A,B,maxa+1);
    		for(int i=0; i<len; ++i){
    			tot[i]=(long long)(A[i].real+0.5);
    		}
    		for(int i=0; i<n; ++i){
    			--tot[a[i]+a[i]];
    		}
    		for(int i=0; i<len; ++i){
    			tot[i]>>=1;
    		}
    		for(int i=1; i<len; ++i){
    			tot[i]+=tot[i-1];
    		}
    		sort(a,a+n);

//			for(int i = 1; i < len; ++i)
//				printf("%d : %lld\n", i, tot[i]);

    		long long res=0;
    		for(int i=0; i<n; ++i){
    			long long tmp=tot[len-1]-tot[a[i]];
    			tmp-=n-1; // 本身与其它的组合 
    			tmp-=(long long)i*(n-i-1); // 小于与大于等于的组合
    			if(n-i-1>1) tmp-=(long long)(n-i-1)*(n-i-2)/2; // 大于等于之间的组合 
				printf("%d: %lld\n", i, tmp);
    			res+=tmp;
    		}
    		printf("%.7f\n",res*1.0/((long long)n*(n-1)*(n-2)/6));
    	}
    	return 0;
    }
