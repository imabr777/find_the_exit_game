/* Find the Exit
 * By Abraham Im
 */

#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void drawRoom(int x, int y, int exitX, int exitY, int highBoundX, int highBoundY) {
	string topBotWall = "";
	for (int a = 0; a <= highBoundX + 1; a++) {
		topBotWall += "# ";
	}
	cout << topBotWall << endl;
	for (int b = highBoundY; b >= 1; b--) {  // y loop
		string thisRow = "# ";
		for (int c = 1; c <= highBoundX; c++) {
			if (c == exitX && b == exitY) {
				thisRow += "O ";
			} else if (c == x && b == y) {
				thisRow += "@ ";
			} else {
				thisRow += "  ";
			}
		}
		cout << thisRow + "# " << endl;
	}
	cout << topBotWall << endl;
}

int main() {
	int lowBoundX = 1, lowBoundY = 1;
	int highBoundX = 10, highBoundY = 10;
	int x = 1, y = 1;
	int exitX, exitY;

	cout << "Where should we put the exit?" << endl;
	cout << "Enter a number between 1 and 10, inclusive: ";
	cin >> exitX;
	cout << "Enter a number between 1 and 10, inclusive: ";
	cin >> exitY;
	cout << "You chose: " << exitX << ", " << exitY << endl;

	drawRoom(x, y, exitX, exitY, highBoundX, highBoundY);

	int c = 0;
	while (!(x == exitX && y == exitY)) {
		if (kbhit()) {  // if a key is pressed
			_getch();
			switch((c=_getch())) {  // get the key stroke
			case KEY_UP:
				if (y < highBoundY) {
					y++;
				}
				drawRoom(x,y,exitX,exitY,highBoundX,highBoundY);
				break;
			case KEY_DOWN:
				if (y > lowBoundY) {
					y--;
				}
				drawRoom(x,y,exitX,exitY,highBoundX,highBoundY);
				break;
			case KEY_LEFT:
				if (x > lowBoundX) {
					x--;
				}
				drawRoom(x,y,exitX,exitY,highBoundX,highBoundY);
				break;
			case KEY_RIGHT:
				if (x < highBoundX) {
					x++;
				}
				drawRoom(x,y,exitX,exitY,highBoundX,highBoundY);
				break;
			default:
				cout << "" << endl;  // we basically ignore any non-arrow key hits here
			}
		}
	}

	return 0;
}