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
#define A 1000000000000000 （1e15）
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
int128 operator * (int128 a,int b) // 这里控制b为2，不会炸，如果b是任意整数会炸
{
	int128 k;
	k.low=0,k.hig=0;
	k.low=a.low*b;
	k.hig+=k.low/p+b*a.hig;//与上同理
	k.low%=p;
	return k;
}
```

##### P1007

>   两人碰头，相当于交换灵魂
>
>   所以一个人走到任意端点的时间，就是直线距离x除速度v

*   最小值：离中点最近的人的时间
*   最大值：离端点最近的人的时间

##### P1008

>   纯模拟，更新vis[]数组统计每位的数字就行
>
>   第一次写，逻辑很复杂，其实就直接对vis[]数组求和，看看有没有9就行

##### P1009

>   完全掌握高精度重载板子！

##### P1011

>   熟悉斐波那契数列，秒过。

##### P1012

>   对于字典序的理解
>
>   ==a + b > b + a== 表示字符串ab的字典序更大，相应的十进制整数更大
>
>   难点在于这些都是变长字符串，所以直接比较a和b的字典序并不能确定它们的顺序

##### P1014

>   和P1013一样是找规律题
>
>   **送分类题型，应该快速AC**

##### P1015

>   高精度
>
>   需要重载N进制数的反转、加法、回文判断等操作
>
>   *   数据结构就用整数数组（可能需要有个记录数据长度的属性）
>   *   J为进制，输入多少就是多少
>   *   反转，如果有数据长度属性，更容易
>   *   加法，串行加法
>   *   回文，双指针判断

##### P1016

>   贪心 + 模拟
>
>   *   选择下一个==比当前油价小的第一个加油站==
>   *   如果没有比当前油价小的加油站，直接去终点
>   *   如果去往目标发现油箱油不够了，==先加满油==，选==可达范围内最小的加油站==
>       *   **一定要先加满油！！！**

写完的感受：

​	模拟过程并不复杂，但是我写了1小时30分钟，感觉主要的冗余代码出现在对当前最远续航范围的判断上，我在题目中可能出现了3次有关while循环的这方面的判断，这是很浪费时间的代码。
