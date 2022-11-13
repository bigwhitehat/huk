#include <iostream>
using namespace std;

class Set
{
    public:
    	
    Set(int a[],int b)   //添加构造函数完成初始化
    {
        M = b;
        for(int i = 0; i<b+1; i++)
        {
            data[i] = a[i];
        }
        cout << "构造函数成功" << endl;
    }
    
    int Empty();
    bool Isempty();
    bool Ismemberof(int n);
    int Add(int x);
    int Sub(int y);
    int Intersection(int a[],int b);
    int Union_set(int a[],int b);
    int Differ_set(int a[],int b);
    void Print();
    
    private:
    	
    int data[100];
    int M;
};

int Set::Empty()                           //清空集合 
{
    M = -1;
    return 0;
}

bool Set::Isempty()                        //判断整数集合是否为空 
{
    if(M == -1)
    {
	    return 0;
    }
    else
	{ 
        return 1;
    }
}

bool Set::Ismemberof(int n)           //判断整数集合中是否存在该元素 
{
    for(int j = 0; j<=M; j++)
    {
        if(n == data[j])
	    return 1;
    }
    return 0;
}

int Set::Add(int x)                     //从整数集合中添加一个整数元素，元素不重复
{
    for(int i = 0; i<M+1; i++)
    {
        if(x == data[i])
        {
            cout << "集合中已经存在该元素！" << x << endl;
            return 0;
        }
    }
 
    M++;
    data[M] = x;
    return 0;
}

int Set::Sub(int y)                  //从整数集合中删除一个整数元素
{
    int temp;
    if(Ismemberof(y) == 1)
    {
        for(int j = 0; j<M+1; j++)
        {
            if(data[j] == y)
            {
                temp = j;//获取位置
            }
        }
        for(int j = temp; j<M; j++)
        {
           data[j] = data[j+1];
        }
        M--;
    }
    return 0;
}

int Set::Intersection(int a[],int b)     //求俩个整数集合的交集
{
    int temp[100];
    int t=0;
    for(int k1 = 0; k1<=M; k1++)
    {
        for(int k2 = 0; k2<b; k2++)
        {
            if(data[k1] == a[k2])
            {
                temp[t] = a[k2];
                t++;
            }
        }
    }
    cout << "交集是：";
    for(int q = 0; q<t; q++)
    {
        cout << temp[q] << " ";
    }
    cout << endl;
    return 0;
}

int Set::Union_set(int a[],int m)              //求俩个整数集合的并集
{
    int b[200];
    int t = M+1;
    int k1,k2,k3; 
    for(int i=0; i<M+1; i++)
    {
        b[i] = data[i];
    }

    for(k1 = 0; k1<m; k1++)
    {
        k3 = 0;
        for(k2 = 0; k2<M+1; k2++)
        {
            if(a[k1] != data[k2])
            {
                k3++;
            }
        }
        if(k3 == M+1)
        {
            b[t] = a[k1];
            t++;
        }
    }
    cout << "并集共" <<  t << " 个元素" << endl;
    cout << "并集是：";
    for(int q = 0; q<t; q++)
    {
        cout << b[q] << " ";
    }
    cout << endl;
    return 0;
}

int Set::Differ_set(int a[],int m)              //求俩个整数集合的差集
{
    int b[200];
    int t = 0;
    int k1,k2 = 0; 
    int Q = 0;

    for(k1 = 0; k1<M+1; k1++)
    {
    	for(k2 = 0; k2<m; k2++)
    	{
    	    if(data[k1] != a[k2])
    	    {
    		    Q++;
    	    }
        }
    	if(Q == m)
    	{
    		b[t] = data [k1];
    		t++;
		}
		Q = 0;
	}
    cout << "差集共" <<  t << " 个元素" << endl;
    cout << "差集是：";
    for(int q = 0; q<t; q++)
    {
        cout << b[q] << " ";
    }
    cout << endl;
    return 0;
}


void Set::Print()
{
    if(M == -1)
    {
        cout << "集合为空！" << endl;
    }
    else
    {
        cout<<"集合是:";
        for(int q = 0; q<M+1; q++)
        {
            cout << data[q] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[100] = {1,2,4,6,8,9};
    int n,m;
    int b=5;
    Set s(a,b);
    s.Print();
    int a2[7] = {1,13,5,6,7,10,11};
    cout<<endl;
    
    cout << "输入你想要添加的元素：";
    cin >> n;
    s.Add(n);
    s.Print();
    cout << endl;
    cout << "输入你想要删除的元素："; 
    cin >> m;
    s.Sub(m);
    s.Print();
    cout << endl;
    
    cout << "另一个集合是：";
    for(int q = 0; q<7; q++)
    {
        cout << a2[q] << " ";
    }
    cout << endl;
	 
    s.Union_set(a2,7);      //并集 
    cout << endl;
    s.Intersection(a2,b);   //交集 
    s.Differ_set(a2,7);     //差集
	cout << endl; 
    
    cout << "清空集合" << endl;
    s.Empty();
    int i = s.Isempty();
    if(i == 0)
	cout <<"经检测，集合为空" << endl;
    else 
	cout << "经检测，集合不为空" << endl;
    return 0;
}