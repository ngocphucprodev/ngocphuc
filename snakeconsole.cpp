#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include"Mylib.h"
#define MAX 100
using namespace std;
int nub = 6;
class View {
private:
	static const int height = 20;
	static const int width = 80;
public:
	void menu();
	void menuchon(int chon, int choncu);
	void create_lineabove();	void create_lineunder();
	void create_lineleft();
	void create_lineright();
	void create_snack(int toadox[], int toadoy[]);
	void draw_snack(int toadox[], int toadoy[]);
	void Delete_snack(int toadox[], int toadoy[]);
	void process_snack(int toadox[], int toadoy[], int x, int y);
	void Add(int a[], int x);
	void Delete(int a[], int vt);
	bool ktran(int x0, int y0);
	bool gancanduoi(int toadox[], int toadoy[]);
	bool checknake(int toadox[], int toadoy[]);
	void taoqua(int &xqua, int &yqua);
};
void View::create_lineabove()
{
	int i = 1;
	int x = 5, y = 1;
	// int check = 0;
	while (x < 75)
	{
		gotoXY(x, y);
		cout << "-";
		x++;
		Sleep(10);
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
		cout << "-";
		x++;
		Sleep(10);
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
		cout << "-";
		y++;
		Sleep(10);
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
		cout << "-";
		y++;
		Sleep(10);
		TextColor(i);
		i++;
		if (i > 15)
		{
			i = 1;
		}
	}
}
void View::create_snack(int toadox[], int toadoy[])
{
	int x = 50, y = 13;
	for (int i = 0; i < nub; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void View::draw_snack(int toadox[], int toadoy[])
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
void View::Delete_snack(int toadox[], int toadoy[])
{
	for (int i = 0; i < nub; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void View::process_snack(int toadox[], int toadoy[], int x, int y)
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
void View::Add(int a[], int x)
{
	for (int i = nub; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	nub++;
}
void View::Delete(int a[], int vt)
{
	for (int i = vt; i < nub; i++)
	{
		a[i] = a[i + 1];
	}
	nub--;
}
bool ktran(int x0, int y0)
{
	if (y0 == 2 && (x0 >= 10 && x0 <= 75))
	{
		return true; 
	}
	else if (y0 == 23 && (x0 >= 5 && x0 <= 75))
	{
		return true;
	}
	else if (x0 == 5 && (y0 >= 1 && x0 <= 23))
	{
		return true;
	}
	else if (x0 == 75 && (y0 >= 1 && x0 <= 23))
	{
		return true; 
	}
	return false;
}
bool gancanduoi(int toadox[], int toadoy[])
{
	for (int i = 1; i < nub; i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}
bool checknake(int toadox[], int toadoy[])
{
	bool check_snake1 = ktran(toadox[0], toadoy[0]);
	bool check_snake2 = gancanduoi(toadox, toadoy);
	if (check_snake1 == true || check_snake1 == true)
	{ 
		gotoXY(35, 13);
		cout << "GAME OVER";
		return true;
	} 
	return false; 
}
void taoqua(int &xqua, int &yqua)
{
	xqua = rand() % (74 - 11 + 1) + 11;
	xqua = rand() % (22 - 2 + 1) + 2;
	gotoXY(xqua, yqua);
	cout << "0";
}
void View::menu() {
	char  enter1 = 13, esc1 = 27, as2 = 80, as3 = 72, as4 = 49, as5 = 50, as6 = 51;
	int i = 9;
 	system("cls");
	TextColor(i);
	int chon = 1, choncu = 0;
	gotoXY(33, 9);
	cout << "Choi Luon";
	gotoXY(30, 10);
	cout << "Chon Muc Do Choi";
	gotoXY(33, 11);
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
		cout << "De" << endl;
		cout << "Binh Thuong" << endl;
		cout << "Kho" << endl;
		cout << "Thoat";

		do
		{
			chondokho = _getch();
			if (chondokho = as4 && chondokho == as5 && chondokho == as6 && chondokho == esc1)
				cout << "Chon lai di!!!" << endl;
		} while (chondokho == as4 && chondokho == as5 && chondokho == as6 && chondokho == esc1);
		system("cls");
		if (chondokho == as4)
		{
			return;
		}
		if (chondokho == as5)
		{
			return;
		}
		if (chondokho == as6)
		{
			return;
		}
		if (chondokho == esc1)
		{
			menu();
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
			gotoXY(25, 10);
			cout << " ";
			gotoXY(50, 10);
			cout << " ";
		}
		gotoXY(25, 9);
		cout << mnc1;
		gotoXY(50, 9);
		cout << mnc2;
	}
	if (chon == 2)
	{
		if (choncu == 1)
		{
			gotoXY(25, 9);
			cout << " ";
			gotoXY(50, 9);
			cout << " ";
		}
		if (choncu == 3)
		{
			gotoXY(25, 11);
			cout << " ";
			gotoXY(50, 11);
			cout << " ";
		}
		gotoXY(25, 10);
		cout << mnc1;
		gotoXY(50, 10);
		cout << mnc2;
	}
	if (chon == 3)
	{
		if (choncu == 2)
		{
			gotoXY(25, 10);
			cout << " ";
			gotoXY(50, 10);
			cout << " ";
		}
		gotoXY(25, 11);
		cout << mnc1;
		gotoXY(50, 11);
		cout << mnc2;
	}
}
int main()    
{

	View v;
	v.menu();
	system("cls");
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	v.taoqua(xqua, yqua);
	v.create_lineabove();
	v.create_lineunder();
	v.create_lineleft();
	v.create_lineright();
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	//create();
	v.create_snack(toadox, toadoy);
	v.draw_snack(toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	int i = 1;
	while (gameover == false)
	{
		v.Delete_snack(toadox, toadoy);
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
		/*// kiem tra bien
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
		}  */
		v.process_snack(toadox, toadoy, x, y);
		//gameover = checknake(toadox, toadoy);
		if ( gameover = ktran(toadox[0], toadoy[0]))
		{
			gotoXY(35, 13);
			cout << "GAME OVER";
		}
		/*if (gameover = gancanduoi(toadox[0], toadoy[0]))
		{
			gotoXY(37, 17);
			cout << "GAME OVER";
		}*/
		Sleep(100);
	} 
	_getch();
	return 0;
}
