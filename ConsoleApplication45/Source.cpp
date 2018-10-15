#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;


class _time {

private:

	int h = 0, m = 0, s = 0;

public:

	void setTime(int H, int M, int S) {
		h = H;
		m = M;
		s = S;
	}

	void btnH() {
		(h == 23) ? h = 0 : h++;
	}

	void btnM() {
		if (m == 59) {
			m = 0;
			btnH();

		}
		else
			m++;

	}

	void btnS() {
		if (s == 59) {
			s = 0;
			btnM();
		}
		else
			s++;
	}

	void setH(int a)
	{
		int k = 0;
		k = (a + h) / 24;
		h += a - k * 24;
	}

	void setM(int b)
	{
		int k = 0;
		k = (m + b) / 60;
		setH(k);
		m += b - k * 60;
	}

	void setS(int c)
	{
		int k = 0;
		k = (s + c) / 60;
		setM(k);
		s += c - k * 60;
	}

	void print() {
		if (h > 23 || h < 0) h = 0;
		if (m > 59 || m < 0) m = 0;
		if (s > 59 || s < 0) s = 0;

		if (h < 10) cout << "0";
		cout << h << ":";

		if (m < 10) cout << "0";
		cout << m << ":";

		if (s < 10) cout << "0";
		cout << s << endl;
	}

};


void main() {
	int n;

	_time T;

	T.setTime(0, 0, 0);
	T.print();

	T.setS(9000);
	T.print();


	/*while (true)
	{
		system("cls");
		T.print();
		T.btnS();
		Sleep(1000);
	}*/

	system("pause");
}
