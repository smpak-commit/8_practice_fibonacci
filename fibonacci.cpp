#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ʹ��ģ�壬������Ӧ�����������Ͳ���
//��8�£�ϰ��2.���һ��vector�����е����ݣ�ÿ��5��
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

//��8�£�ϰ��3.4.����ָ��������fibonacci���У������浽�����У����ж������Чֵ
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

//��8�£�ϰ��5.��תһ������������������������Ƶ�һ������������
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

//��8�£�ϰ��5.��һ�������е����ݽ����������У����Ǳ�����ԭ�����С�
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

//��8�£�ϰ��6.���ȴӼ��̻��һ���ַ�����
void init_string(vector<string>& vec)
{
	string temp{};
	cout << "Please input a string(Press ctrl_z to end.):" << endl;
	while (cin >> temp)
		vec.push_back(temp);
}

int main(int argc, char* argv[], char* env[])
{
	//�������в�����ϵͳ�����������б���
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

	//��8�£�ϰ��4.����fibonacci����
	vector<int> fibo;
	int x = 1, y = 1;
	fibonacci(50, x, y, fibo);
	print("fibonacci", fibo);

	//��8�£�ϰ��5.����1�����ı��������˳�������µ���������������
	vector<int> rev;
	rev = reverse(fibo);
	print("Reverse", rev);

	//��8�£�ϰ��5.����2���Բ�������ֱ�ӽ�������
	rev= fibo ;
	reverse2(rev);
	print("Reverse2", rev);

	//��8�£�ϰ��6.��ʼ��string������1�����ı�ԭʼ���������ݣ��ں����б��浽��ʱ�����в����ؽ��
	vector<string> rev_str, in_str;
	init_string(in_str);
	rev_str = reverse(in_str);
	print("Reverse", rev_str);

	//��8�£�ϰ��6.����2�� ��ԭʼ����������
	rev_str= in_str ;
	reverse2(rev_str);
	print("Reverse2", rev_str);
}