#include <iostream>
#include "Dijkstra.h"

using namespace std;

int main()
{
	while (true)
	{
		char startLetter, endLetter;

		cout << "Enter the start position letter: ";
		cin >> startLetter;

		while (startLetter < 'A' || startLetter > 'G')
		{
			cout << "Letter must be A B C D E F G" << endl;
			cout << "Enter the start position letter: ";
			cin >> startLetter;
		}


		cout << "Enter the end position letter: ";
		cin >> endLetter;

		while (endLetter < 'A' || endLetter > 'G')
		{
			cout << "Letter must be A B C D E F G" << endl;
			cout << "Enter the end position letter: ";
			cin >> endLetter;
		}

		int startPos = startLetter - 65;
		int endPos = endLetter - 65;

		Dijkstra* find = new Dijkstra();

		find->findPath(find->graph, startPos, endPos);
		cout << endl << endl;

	}

	return 0;

	

}