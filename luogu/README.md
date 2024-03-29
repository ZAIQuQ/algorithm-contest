##### P1000

题目简单，需要会利用C++11特性`cout << R"()";`

括号中的字符串可以换行

##### P1003

第一反应开`n^2`空间枚举，但是会`MLE`，因为空间`10^10`

于是只需要存矩形，空间`10^5`左右，再遍历矩形数组即可

##### P1005

区间dp + 高精度

int64 ~ 10^18 

int128 ~ 10^36

需要实现的高精度操作：

`高精+高精`

`高精*高精`

`max{高精，高精}`

```cpp
#define A 1000000000000000
struct bint{
	long long s[10];
	bint(long long num = 0){
		*this=num;
	}
	bint operator = (long long num){
		memset(s, 0, sizeof(s));
		s[0]=num;
		return *this;
	}
	bint operator + (const bint& b) const {
		bint c;
		unsigned long long g = 0;
		for (int i=0; i<9 ; i++){
			unsigned long long x = g;
			x += (unsigned long long)s[i]+b.s[i];
			c.s[i]=x%A;
			g=x/A;
		}
		return c;
	}
	bint operator* (const bint& b) const {
		bint c;
		unsigned long long g=0;
		for (int i=0; i<9; i++){
			unsigned long long x=g;
			for (int j=0; j<=i; j++){
				int k=i-j;
				x+=(unsigned long long)s[k]*b.s[j];
			}
			c.s[i]=x%A;
			g=x/A;
		}
		return c;
	}
	bool operator < (const bint& b) const {
		for (int i=9; i>=0; i--){
			if (s[i]<b.s[i]) return 1;
			if (s[i]>b.s[i]) return 0;
		}
		return 0;	
	}
```

`int128重载`（更容易）

```cpp
struct int128
{
    long long hig;
    long long low;
};//定义int128
long long p=1e18;//作mod用
int128 max(int128 a,int128 b)
{
	if(a.hig>b.hig) return a;
	if(a.hig<b.hig) return b;//高位比较
	if(a.low>b.low) return a;
	if(a.low<b.low) return b;//低位比较
	return a;//相等时还要返回一个值
}
int128 operator + (int128 a,int128 b)//重载运算符
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low+b.low;
    k.hig=k.low/p+a.hig+b.hig;//防止溢出
    k.low%=p;
    return k;
}
int128 operator * (int128 a,int b)
{
	int128 k;
	k.low=0,k.hig=0;
	k.low=a.low*b;
	k.hig+=k.low/p+b*a.hig;//与上同理
	k.low%=p;
	return k;
}
```

