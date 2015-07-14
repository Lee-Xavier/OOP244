// Workshop 6 - Flying Points Calculator
// w6bonus.cpp

#include <iostream>
#include "FlyingPoints.h"

using namespace std;

void read(const char* msg, FlyingPoints& f)
{
    int inPoints, outPoints;
    cout << "Enter " << msg << endl;
    cout << "Enter number of incoming flying points: ";
    cin >> inPoints;
    cout << "Enter number of spent flying points: ";
    cin >> outPoints;
    f = FlyingPoints(inPoints, outPoints);
    cin.ignore();
}

int main()
{
	char op[3];
	bool quit = false;
	FlyingPoints left, right, result, ref;

    cout << "Flying Points Calculator\n";
    cout << "========================\n";

	read("Left Operand...", left);

	do
    {
		cout << "+= -= *= /= (## to quit): ";
		cin.get(op, 3);
		char c = cin.get();
		if(c != '\n' || op[1] != '=' && op[1] != '#')
        {
			cerr << "Try Again!" << endl;
			cin.ignore(2000, '\n');
		}
		else if(strcmp(op, "##") == 0)
        {
			read("Reference...", ref);
			quit = true;
		}
		else
        {
			read("Right Operand...", right);

			cout << "Result: " << endl;
			left.display();

			switch(op[0])
            {
			case '+':
				cout << " += ";
				left += right;
				break;
			case '-':
				cout << " -= ";
				left -= right;
				break;
			case '*':
				cout << " *= ";
				left *= right;
				break;
			case '/':
				cout << " /= ";
				left /= right;
				break;
			}
			right.display();
			cout << " => ";
			left.display();
			cout << endl;
		}
	} while (!quit);

    if(left == ref)
    {
        cout << "Result == Reference" << endl;
    }
    else
    {
        cout << "Result != Reference" << endl;
    }
    
    return 0;
}
