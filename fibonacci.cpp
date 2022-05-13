#include <iostream>
#include <string>
#include <vector>

using namespace std;

//使用模板，可以适应多种数据类型参数
//第8章：习题2.输出一个vector容器中的内容，每行5个
template<typename T>
void print(string tips, const vector<T>& vec)
{
	cout << tips << ": " << endl;
	for (size_t i = 0;i < vec.size();)
	{
		cout << vec[i] << " ";
		++i;
		if (i % 5 == 0) cout << endl;
	}
	cout << endl;
}

//第8章：习题3.4.计算指定个数的fibonacci数列，并保存到容器中，并判断最大有效值
void fibonacci(const int& n, int x, int y, vector<int>& fibo)
{
	fibo.push_back(x);
	fibo.push_back(y);
	for (int i = 2;i < n;++i)
	{
		int fi = x + y;		
		fibo.push_back(fi);
		x = y;
		y = fi;
		if ((x + y) < 0) {
			cout << "The max int fibonacci: " << fi <<", fibonacci counts:" << i << endl;
			return;
		}
	}
}

//第8章：习题5.反转一个传入的容器，并将其逆序复制到一个容器并传回
template<typename T>
T reverse(const T& vec)
{
	T temp{};
	size_t i = vec.size() - 1;
	while(true)
	{
		temp.push_back(vec[i]);
		if (i == 0) break;
		--i;
	}
	return temp;
}

//第8章：习题5.把一个容器中的内容进行逆序排列，还是保存在原容器中。
template<typename T>
void reverse2(T& vec)
{
	if (vec.size() < 2) return;
	size_t i = 0;
	size_t j = vec.size() - 1;
	while (true)
	{
		swap(vec[i], vec[j]);
		++i;
		--j;
		if (i >= j) return;
	}
}

//第8章：习题6.首先从键盘获得一个字符串。
void init_string(vector<string>& vec)
{
	string temp{};
	cout << "Please input a string(Press ctrl_z to end.):" << endl;
	while (cin >> temp)
		vec.push_back(temp);
}

int main(int argc, char* argv[], char* env[])
{
	//将命令行参数和系统环境变量进行保存
	vector<string> in_argv, in_env;
	for (int i = 0; i < argc; ++i)
		in_argv.push_back(argv[i]);
	for (int i = 0; env[i] != NULL; ++i)
		in_env.push_back(env[i]);

	cout << "Argument:" << endl;
	for (auto v : in_argv)
		cout << v << endl;

	cout << "Environment(first 5):" << endl;
	for (int i=0; i<5 && i<in_env.size(); ++i)
		cout << in_env[i] << endl;
	cout << "......" << endl;

	//第8章：习题4.计算fibonacci数列
	vector<int> fibo;
	int x = 1, y = 1;
	fibonacci(50, x, y, fibo);
	print("fibonacci", fibo);

	//第8章：习题5.逆序1，不改变参数容器顺序，生成新的逆序容器并返回
	vector<int> rev;
	rev = reverse(fibo);
	print("Reverse", rev);

	//第8章：习题5.逆序2，对参数容器直接进行逆序
	rev= fibo ;
	reverse2(rev);
	print("Reverse2", rev);

	//第8章：习题6.初始化string和逆序1，不改变原始容器的内容，在函数中保存到临时容器中并返回结果
	vector<string> rev_str, in_str;
	init_string(in_str);
	rev_str = reverse(in_str);
	print("Reverse", rev_str);

	//第8章：习题6.逆序2， 在原始容器上逆序
	rev_str= in_str ;
	reverse2(rev_str);
	print("Reverse2", rev_str);
}