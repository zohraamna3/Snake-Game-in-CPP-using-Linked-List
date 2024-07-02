#include<iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>


using namespace std;

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

class node
{
public:
	int data;
	node* next;
	node(int data)
	{
		this->data = data;
		next = NULL;
	}
};
class SLL
{
	node* head;
	int size;
public:
	SLL()
	{
		size = 3;
		head = NULL;
	}	
	int getSize()
	{
		return size;
	}
	void insertnode(node* temp)
	{
		if (head == NULL)
		{
			head = temp;
			size++;
		}
		else
		{
			node* rptr;
			rptr = head;
			while (rptr->next != NULL)
			{
				rptr = rptr->next;
			}
			rptr->next = temp;
			size++;
		}
	}
	void deletetail()
	{
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			size--;
		}
		else
		{
			node* rptr;
			rptr = head;
			while (rptr->next->next != NULL)
			{
				rptr = rptr->next;
			}
			node* del;
			del = rptr->next;
			delete del;
			rptr->next = NULL;
			size--;
		}
	}
	void insertathead(node* temp)
	{
		if (head == NULL)
		{
			head = temp;
			size++;
		}
		else
		{
			temp->next = head;
			head = temp;
			size++;
		}
	}
	void Delete()
	{
		while (size != 3)
		{
			node* temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
			size--;
		}		
	}
	/////////////////////////////////////////////////////////////

	void textcolor(int fc, int bc = -1) {
		if (fc < 0 || fc > 15)
			return;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		if (bc >= 0 && bc < 16)
			SetConsoleTextAttribute(h, fc | bc * 16);
		else
			SetConsoleTextAttribute(h, fc);
	}

	void textcolor(string fc, string bc = "") {
		int x, y = 16;
		string colors[] = { "Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White", "Gray",
						   "LightBlue", "LightGreen", "LightAqua", "LightRed", "LightPurple", "LightYellow", "BrightWhite" };
		for (x = 0; x < 16; x++)
			if (colors[x] == fc)
				break;
		if (bc.length() > 0)
			for (y = 0; y < 16; y++)
				if (colors[y] == bc)
					break;
		textcolor(x, y);
	}

	void textcolor(string fc, int bc) {
		int x;
		string colors[] = { "Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White", "Gray",
						   "LightBlue", "LightGreen", "LightAqua", "LightRed", "LightPurple", "LightYellow", "BrightWhite" };
		for (x = 0; x < 16; x++)
			if (colors[x] == fc)
				break;
		textcolor(x, bc);
	}

	void textcolor(int fc, string bc) {
		int y;
		string colors[] = { "Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White", "Gray",
						   "LightBlue", "LightGreen", "LightAqua", "LightRed", "LightPurple", "LightYellow", "BrightWhite" };
		if (bc.length() > 0)
			for (y = 0; y < 16; y++)
				if (colors[y] == bc)
					break;
		textcolor(fc, y);
	}
	void interface_of_game() {
		HANDLE hout;
		CONSOLE_CURSOR_INFO cursor;
		hout = GetStdHandle(STD_OUTPUT_HANDLE);
		cursor.dwSize = 1;
		cursor.bVisible = false;
		SetConsoleCursorInfo(hout, &cursor);
		system("cls");
		textcolor("LightPurple");
		cout << "\n  " << char(218);
		int x;
		for (x = 0; x < 75; x++)
			cout << char(196);
		cout << char(191) << "  ";
		for (x = 0; x < 17; x++)
		{
			gotoxy(2, x + 2);
			cout << char(179);
			gotoxy(78, x + 2);
			cout << char(179) << " ";
		}
		cout << endl << "  " << char(192);
		for (x = 0; x < 75; x++)
			cout << char(196);
		cout << char(217) << "  ";
		cout << endl << "  " << char(218);
		for (x = 0; x < 21; x++)
			cout << char(196);
		cout << char(191) << endl;
		cout << "  " << char(179);
		textcolor(9);
		cout << " S N A K E   G A M E ";
		textcolor("LightPurple");
		cout<< char(179) << endl;
		cout << "  " << char(192);
		for (x = 0; x < 21; x++)
			cout << char(196);
		cout << char(217);

		gotoxy(59, 20);

		cout << char(218);
		for (x = 0; x < 18; x++)
			cout << char(196);
		cout << char(191);
		gotoxy(59, 21);
		cout << char(179) << " SCORE :          " << char(179);
		gotoxy(59, 22);
		cout << char(179) << " STATUS: Playing  " << char(179);
		gotoxy(59, 23);
		cout << char(192);
		for (x = 0; x < 18; x++)
			cout << char(196);
		cout << char(217);
		gotoxy(28, 20);
		cout << "Press 'x' to Exit";
		gotoxy(28, 21);
		cout << "Press Space to Pause and Play";
		gotoxy(3, 23);
		textcolor("White", "Blue");
		cout << " Project by Mam Drakhshan ";
		textcolor(7);
	}


	void status(string s, int c = 7) {
		gotoxy(69, 22);
		textcolor(c);
		cout << s.substr(0, 8);
		for (int x = s.length(); x < 8; x++)
			cout << " ";
		textcolor(7);
	}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void score(int sc) {
	gotoxy(69, 21);
	cout << setw(6) << sc * 10;
}

void display()
{
		node* rptr;
		rptr = head;
		while (rptr != NULL)
		{
			cout << rptr->data << "->";
			rptr = rptr->next;
		}
		cout << endl;
}
};


int main()
{
	SLL Snake;
	int snakeSize = 3;
	for (int i = 0; i < snakeSize; i++)
		Snake.insertnode(new node(1));
	Snake.interface_of_game();
	int flow, i, xb, yb;
	int speed, restart = 1, tmp, xpos[100], ypos[100], scr;
	// srand(time(NULL));
	while (true) {
		if (restart) {
			Snake.status("Playing", 10);
			for (int k = 1; k < 75; k += 2)
				for (int j = 0; j < 17; j++) {
					Snake.gotoxy(k + 3, j + 2);
					cout << " ";
				}
			Snake.Delete();
			speed = 200;
			scr = 0;
			Snake.score(scr);
			flow = RIGHT;
			xpos[0] = 20;
			for (i = 0; i < Snake.getSize(); i++)
			{
				xpos[i] = xpos[0] - i * 2;
				ypos[i] = 10;
			}
			for (i = 0; i < Snake.getSize(); i++) {
				Snake.gotoxy(xpos[i], ypos[i]);
				cout << "o";
			}
			for (tmp = 1; true;) {
				do {
					xb = rand() % 75 + 3;
				} while (xb % 2 != 0);
				yb = rand() % 17 + 2;
				for (i = 0; i < Snake.getSize(); i++)
					if (xb == xpos[i] && yb == ypos[i]) {
						tmp = 0;
						break;
					}
				if (tmp)
					break;
			}
			Snake.gotoxy(xb, yb);
			Snake.textcolor("LightGreen");
			cout << "@";
			Snake.textcolor(7);
			restart = 0;
		}
		while (!_kbhit() && !restart) {
			if (xpos[0] == xb && ypos[0] == yb) {
				for (tmp = 1; true;)
				{
					do {
						xb = rand() % 75 + 3;
					} while (xb % 2 != 0);
					yb = rand() % 17 + 2;
					for (i = 0; i < Snake.getSize(); i++)
						if (xb == xpos[i] && yb == ypos[i]) {
							tmp = 0;
							break;
						}
					if (tmp)
						break;
				}
				Snake.gotoxy(xb, yb);
				Snake.textcolor("LightGreen");
				cout << "@";
				Snake.textcolor(7);
				Snake.insertnode(new node(1));
				scr++;
				speed -= 3;
				Snake.score(scr);
			}
			Snake.gotoxy(xpos[Snake.getSize() - 1], ypos[Snake.getSize() - 1]);
			for (i = Snake.getSize() - 1; i > 0; i--) {
				xpos[i] = xpos[i - 1];
				ypos[i] = ypos[i - 1];
			}
			switch (flow) {
			case RIGHT:
				xpos[i] += 2;
				break;
			case LEFT:
				xpos[i] -= 2;
				break;
			case UP:
				ypos[i] -= 1;
				break;
			case DOWN:
				ypos[i] += 1;
			}
			tmp = 1;
			for (i = 1; i < Snake.getSize(); i++)
				if (xpos[i] == xpos[0] && ypos[i] == ypos[0]) {
					tmp = 0;
					break;
				}
			if (xpos[0] > 76 || xpos[0] < 4 || ypos[0] < 2 || ypos[0] > 18)
				tmp = 0;
			if (tmp) {
				cout << " ";
				Snake.gotoxy(xpos[0], ypos[0]);
				Snake.textcolor("LightBlue");
				cout << "O";
				Snake.gotoxy(xpos[1], ypos[1]);
				Snake.textcolor("Aqua");
				cout << "o";
				Snake.textcolor("white");
			}
			else {
					Snake.textcolor("LightRed");
				cout << "o";
				Snake.textcolor("Red");
				Snake.gotoxy(xpos[1], ypos[1]);
				cout << "O";
				for (i = 2; i < Snake.getSize(); i++) 
				{
					Snake.gotoxy(xpos[i], ypos[i]);
					Snake.textcolor("LightRed");
					cout << "o";
				}
				Snake.textcolor(7);
				Snake.status("GameOver", 12);
				restart = 1;
				_getch();
			}
			Sleep(speed);
		}
		char ch = _getch();
		switch (tolower(ch)) {
		case 'x':
			system("cls");
			return 0;
		case ' ':
			Snake.status("Paused");
			while (true) {
				char z = _getch();
				if (z == 'x')
					return 0;
				if (z == ' ')
					break;
			}
			Snake.status("Playing", 10);
			break;
		case -32: {
			char chh = _getch();
			if (chh == 72 && flow != DOWN)
				flow = UP;
			else if (chh == 80 && flow != UP)
				flow = DOWN;
			else if (chh == 75 && flow != RIGHT)
				flow = LEFT;
			else if (chh == 77 && flow != LEFT)
				flow = RIGHT;
			break;
		}
		}
	}



	

	return 0;
}