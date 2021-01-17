//#include"../Include/EmpathicEngine.h"
#include"../Include/ByteConverter.h"
#include<sstream>
class te {
public:
	int aa;
	te(){}
	te(int x):aa(x){}
	te(te& z) { aa = z.aa; }
	void showte() { cout << aa<<endl; }
};
class ts {
public:
	int a;
	double d;
	te ty;
	ts() {}
	ts(int x,double y,te ty1) :a(x),d(y),ty(ty1) {}
	void show() {
		cout << a << ", " << d << ", ";
		ty.showte();
	}
};
int main()
{
	int index = 0;
	/// <summary>
	/// test Vector2Byte
	/// </summary>
	/// <returns></returns>
	list<int> Ltest;
	for (int j = 0; j < 20; j++)
	{
		Ltest.push_back(j);
	}
	List2Byte<int>::mPacking(buffer, index, Ltest);

	int indeL = 0;
	list<int> Lte;
	for (int j = 0; j < 20; j++)
	{
		List2Byte<int>::mUnpacking(buffer, indeL, Lte);
	}


	list<int>::iterator itL = Lte.begin();
	while (itL != Lte.end())
	{
		cout << *itL << endl;
		itL++;
	}

	/// <summary>
	/// test Vector2Byte
	/// </summary>
	/// <returns></returns>
	vector<int> Vtest;
	for (int j = 0; j < 20;j++)
	{
		Vtest.push_back(j);
	}
	Vector2Byte<int>::mPacking(buffer, index, Vtest);
	
	int inde = 0;
	vector<int> Vte;
	for (int j = 0; j < 20; j++)
	{
		Vector2Byte<int>::mUnpacking(buffer, inde, Vte);
	}

	
	vector<int>::iterator itv = Vte.begin();
	while (itv != Vte.end())
	{
		cout << *itv << endl;
		itv++;
	}

	/// <summary>
	/// test Map2Byte
	/// </summary>
	/// <returns></returns>
	map<int, int> map1;
	int inx = 10;
	while (inx--)
	{
		map1[inx] = inx;
	}
	
	map<string, int>map2;
	map<string, int>map3;
	map2["chang"] = 1;
	map2["li"] = 0;

	Map2Byte<string, int>::mPacking(buffer, index, map2);

	int index1 = 0;
	Map2Byte<string, int>::mUnpacking(buffer, index1, map3);

	map<string, int>::iterator it1 = map3.begin();
	while (it1 != map3.end())
	{
		cout << it1->first << ", " << it1->second << endl;
		it1++;
	}
	

	/// <summary>
	/// test Byteconverter
	/// </summary>
	/// <returns></returns>
	int test = sizeof(ts);
	int tst = sizeof(te);
	
	
	double t = 10.1;
	double& t22 = t;
	for (int i = 0; i < 10; i++)
	{
		te t111(i);
		ts* att = new ts(i,t,t111);
		ByteConverter<ts>::mPacking(buffer, index, *att);
	}
	

	int in = 0;
	ts b;
	for (int i = 0; i < 10; i ++)
	{
		ByteConverter<ts>::mUnpacking(buffer, in, b);
		b.show();
		//cout << *b << endl;
	}

	

	//EmpathicEngine* Epeg = new EmpathicEngine();
	//Epeg->mServerSocket = new Server();

	//Epeg->mServerSocket->mStartListenThread();

	while (true)///<can avoid memory leak in created thread \
						caused by main thread termination
	{

	}
	return 0;

}


