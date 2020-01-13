#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"Mylib.h"
#define MAX 100
using namespace std;
int nub = 4;

class View {
private:
	static const int height = 20;
	static const int width = 80;
public:
	void menu();
	void menuchon(int chon, int choncu);
	void create_lineabove();
	void create_lineunder();
	void create_lineleft();
	void create_lineright();
	void create_snack(int toadox[], int toadoy[]);
	void draw_snack(int toadox[], int toadoy[]);
	void Delete_snack(int toadox[], int toadoy[]);
	void process_snack(int toadox[], int toadoy[], int x, int y);
	void Add(int a[], int x);
	void Delete(int a[], int vt);
};
class Snake {
private :
	int toadox[], toadoy[];
public :
	void create_snack(int toadox[], int toadoy[]);
	void draw_snack(int toadox[], int toadoy[]);
	void Delete_snack(int toadox[], int toadoy[]);
	void process_snack(int toadox[], int toadoy[], int x, int y);
	void Add(int a[], int x);
	void Delete(int a[], int vt);
};
void View::create_lineabove()
{
	int i = 1;
	int x = 5, y = 1;
	// int check = 0;
	while (x < 75)
	{
		gotoXY(x, y);
		cout << ".";
		x++;
		Sleep(30);
		TextColor(i);
		i++;
		if (i > 15)
		{
			i = 1;
		}
		/*   //kt huong
		   if (check == 2)
		   {
			   x--;
		   }
		   else if (check == 3)
		   {
			   x++;
		   }
		   //kt bien
		   if (x == 0)
		   {
			   check = 3;
		   }
		   else if (x == 66)
		   {
			   check = 2;
		   }*/
	}
}
void View::create_lineunder()
{
	int i = 1;
	int x = 5, y = 23;
	//  int check = 0;
	while (x < 75)
	{
		gotoXY(x, y);
		cout << ".";
		x++;
		Sleep(30);
		TextColor(i);
		i++;
		if (i > 15)
		{
			i = 1;
		}
		/*  //kt huong
		  if (check == 2)
		  {
			  x--;
		  }
		  else if (check == 3)
		  {
			  x++;
		  }
		  //kt bien
		  if (x == 0)
		  {
			  check = 3;
		  }
		  else if (x == 66)
		  {
			  check = 2;
		  }*/
	}
}

void View::create_lineleft()
{
	int i = 1;
	int x = 5, y = 1;
	while (y < 24)
	{
		gotoXY(x, y);
		cout << ".";
		y++;
		Sleep(30);
		TextColor(i);
		i++;
		if (i > 15)
		{
			i = 1;
		}
	}
}
void View::create_lineright()
{
	int i = 1;
	int x = 75, y = 1;
	while (y < 24)
	{
		gotoXY(x, y);
		cout << ".";
		y++;
		Sleep(30);
		TextColor(i);
		i++;
		if (i > 15)
		{
			i = 1;
		}
	}
}
void Snake::create_snack(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < nub; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void Snake::draw_snack(int toadox[], int toadoy[])
{
	for (int i = 0; i < nub; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "o";
		}
	}
}
void Snake::Delete_snack(int toadox[], int toadoy[])
{
	for (int i = 0; i < nub; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void Snake::process_snack(int toadox[], int toadoy[], int x, int y)
{
	// b1: them toa do moi vao dau mang 
	Add(toadox, x);
	Add(toadoy, y);
	// b2: xoa toa do cuoi mang
	Delete(toadox, nub - 1);
	Delete(toadoy, nub - 1);
	// b3: ve ran
	draw_snack(toadox, toadoy);
}
void Snake::Add(int a[], int x)
{
	for (int i = nub; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	nub++;
}
void Snake::Delete(int a[], int vt)
{
	for (int i = vt; i < nub; i++)
	{
		a[i] = a[i + 1];
	}
	nub--;
}


void View::menu() {//tao menu game
	char  enter1 = 13, esc1 = 27, as2 = 80, as3 = 72, as4 = 49, as5 = 50, as6 = 51;
	system("cls");
	int chon = 1, choncu = 0;
	gotoXY(33, 3);
	cout << "Choi Luon";
	gotoXY(30, 4);
	cout << "Chon Muc Do Choi";
	gotoXY(33, 5);
	cout << "Huong Dan";

	while (1)
	{
		char phim;
		if (_kbhit())
		{
			phim = _getch();
			if (phim == enter1)
				break;
			if (phim == as2)
			{
				if (chon < 4)
				{
					chon++;
					choncu = chon - 1;
					menuchon(chon, choncu);
				}
			}
			if (phim == as3)
			{
				if (chon > 1)
				{
					chon--;
					choncu = chon + 1;
					menuchon(chon, choncu);
				}
			}
		}
	}
	if (chon == 1)
		return;
	if (chon == 2)
	{
		system("cls");
		char chondokho;
		cout << "Bam 1 2 3 chon muc do: ( dai qua nhat lam )" << endl;
		cout << "1.De" << endl;
		cout << "2.Binh Thuong" << endl;
		cout << "3.Kho";

		do
		{
			chondokho = _getch();
			if (chondokho < as4 || chondokho > as6)
				cout << "Chon lai di!!!" << endl;
		} while (chondokho < as4 || chondokho > as6);
		system("cls");
		if (chondokho == as4)
		{
			//doKho = 150;
			cout << "Da chon muc do DE" << endl;
		}
		if (chondokho == as5)
		{
			//doKho = 90;
			cout << "Da chon muc do BINH THUONG" << endl;
		}
		if (chondokho == 51)
		{
			//doKho = 40;
			cout << "Da chon muc do KHO\n" << endl;
		}
		cout << "Bam enter de choi game" << endl << "Bam ESC de quay lai menu" << endl;
		char lchon;
		while (1)
		{
			lchon = _getch();
			if (lchon == esc1)
				break;
			if (lchon == enter1)
				return;
		}
		menu();
	}
	if (chon == 3)
	{
		system("cls");
		cout << "\tDung 4 phim a w d s de dieu khien con ran, dam dau zo tuong la chet" << endl;
		cout << "\tKhi an duoc 5 con moi thi se xuat hien con moi dac biet" << endl;
		cout << "\tKhi an con moi dac biet se duoc diem rat la cao" << endl;
		cout << "\tcung kha don gian" << endl;
		cout << "\tBam enter de qua lai luc nay" << endl;
		char lchon;
		while (1)
		{
			lchon = _getch();
			if (lchon == enter1)
				break;
		}
		menu();
	}
}
void View::menuchon(int chon, int choncu)
{
	char mnc1 = 16, mnc2 = 17;
	if (chon == 1)
	{
		if (choncu == 2)
		{
			gotoXY(25, 4);
			cout << " ";
			gotoXY(48, 4);
			cout << " ";
		}
		gotoXY(25, 3);
		cout << mnc1;
		gotoXY(48, 3);
		cout << mnc2;
	}
	if (chon == 2)
	{
		if (choncu == 1)
		{
			gotoXY(25, 3);
			cout << " ";
			gotoXY(48, 3);
			cout << " ";
		}
		if (choncu == 3)
		{
			gotoXY(25, 5);
			cout << " ";
			gotoXY(48, 5);
			cout << " ";
		}
		gotoXY(25, 4);
		cout << mnc1;
		gotoXY(48, 4);
		cout << mnc2;
	}
	if (chon == 3)
	{
		if (choncu == 2)
		{
			gotoXY(25, 4);
			cout << " ";
			gotoXY(48, 4);
			cout << " ";
		}
		gotoXY(25, 5);
		cout << mnc1;
		gotoXY(48, 5);
		cout << mnc2;
	}
}
int main()    
{
	View v;
	Snake S;
	v.menu();
	system("cls");
	srand(time(NULL));
	v.create_lineabove();
	v.create_lineunder();
	v.create_lineleft();
	v.create_lineright();
	int toadox[MAX], toadoy[MAX];
	//create();
	S.create_snack(toadox, toadoy);
	S.draw_snack(toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	int i = 1;
	while (true)
	{
		S.Delete_snack(toadox, toadoy);
		TextColor(i);
		i++;
		if (i > 15)
		{
			i = 1;
		}
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72)
				{
					check = 1;
				}
				else if (kitu == 80)
				{
					check = 0;
				}
				else if (kitu == 75)
				{
					check = 2;
				}
				else if (kitu == 77)
				{
					check = 3;
				}
			}
			if (kitu == 'w')
			{
				check = 1;
			}
			else if (kitu == 's')
			{
				check = 0;
			}
		}
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x--;
		}
		else if (check == 3)
		{
			x++;
		}
		// kiem tra bien
		if (y == 22)
		{
			check = 1;
		}
		else if (y == 2)
		{
			check = 0;
		}
		else if (x == 6)
		{
			check = 3;
		}
		else if (x == 74)
		{
			check = 2;
		}
		S.process_snack(toadox, toadoy, x, y);
		Sleep(100);
	}
	_getch();
	return 0;
}