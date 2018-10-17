#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

class _time {

	int *h, *m, *s;

public:

	_time(int a = 0, int b = 0, int c = 0) {

		h = new int(0);
		m = new int(0);
		s = new int(0);
		setH(a);
		setM(b);
		setS(c);

	}

	_time(const _time &object) {

		this->h = new int(*object.h);
		this->m = new int(*object.m);
		this->s = new int(*object.s);

	}

	void setTime(int H, int M, int S) {
		*h = H;
		*m = M;
		*s = S;
	}

	void btnH() {
		(*h == 23) ? *h = 0 : (*h)++;
	}

	void btnM() {
		if (*m == 59) {
			*m = 0;
			btnH();

		}
		else
			(*m)++;

	}

	void btnS() {
		if (*s == 59) {
			*s = 0;
			btnM();
		}
		else
			(*s)++;
	}

	void setH(int a)
	{
		int k = 0;
		k = (a + *h) / 24;
		*h += a - k * 24;
	}

	void setM(int b)
	{
		int k = 0;
		k = (*m + b) / 60;
		setH(k);
		*m += b - k * 60;
	}

	void setS(int c)
	{
		int k = 0;
		k = (*s + c) / 60;
		setM(k);
		*s += c - k * 60;
	}


	int getH() {
		return*h;
	}

	int getM() {
		return*m;
	}

	int getS() {
		return*s;
	}

	void print() {
		if (*h > 23 || *h < 0) *h = 0;
		if (*m > 59 || *m < 0) *m = 0;
		if (*s > 59 || *s < 0) *s = 0;

		if (*h < 10) cout << "0";
		cout << *h << ":";

		if (*m < 10) cout << "0";
		cout << *m << ":";

		if (*s < 10) cout << "0";
		cout << *s << endl;
	}

	~_time() {

		delete h;
		delete m;
		delete s;

	}
};

void main() {
	int n;

	_time T;

	

	T.setTime(0, 0, 0);
	T.print();

	T.setS(9000);
	T.print();

	cout << T.getM();

	cout << endl;

	_time T1(T);
	T1.print();


	/*while (true)
	{
	system("cls");
	T.print();
	T.btnS();
	Sleep(1000);
	}*/

	system("pause");
}
