/*位图数据结构：该数据结构描述了一个有限定义域内的稠密集合，其中每个元素最多出现一次并且没有其他任何数据结构与该元素相关联*/
#include<iostream>
#define BITSPERWORD 32
#define N 10000000
#define SHIFT 5
#define MASK 0x1F
using namespace std;
int a[1 + N / BITSPERWORD];
/*N表示的是需要用位向量存储数据的最大值，因为C++中int类型由4个字节表示，
因此有32位，那么我们可以用（N/32+1）个int来表示这些数据，比如a[0]表示的范围是0-31，a[1]表示的范围是32-63，以此类推。
那么站在位的角度来看，数组a就是一个（N/32+1） × 32的位矩阵，那么就下来的任务就是确定每一个数在这个矩阵中的位置，行号和列号，找到后将该位置置1*/
void set(int i){
	/*i >> SHIFT表示的是i在数组中的位置（也就是位矩阵的行数），可以改写成i/SHIFT;
	i & MASK则表示的是i在这一行中的列数，MASK的值是0x1F，也就31，i & MASK形成了一个i与0-31（列编号）之间的一一映射，
	则表示形成一个所在列为1其他位置为0的32位2进制串（1右移列编号的位数），与a[i >> SHIFT]进行或操作后相当于将i在位矩阵中的位置值置1*/
	a[i >> SHIFT] |= 1 << (i & MASK);
}
void clear(int i){
	/*原理和set函数相近，首先找到i在位矩阵中的位置，其次将该位置的值置0，i >> SHIFT表示行号，
	i & MASK表示列号，a[i >> SHIFT] &= ~(1 << (i & MASK))是置0操作*/
	a[i >> SHIFT] &= ~(1 << (i & MASK));
}
int test(int i){
	/*找到i所在的位置，进行与操作，如果该数存在那么结果非0，否则结果为0*/
	return a[i >> SHIFT] & (1 << (i & MASK));
}
int main(){
	set(100);
	cout << test(100) << endl;	
	set(0);
	cout << test(0) << endl;

	set(31);
	cout << test(31) << endl;

	set(32);
	cout << test(32) << endl;

	clear(100);
	cout << test(100) << endl;
	return 0;
}