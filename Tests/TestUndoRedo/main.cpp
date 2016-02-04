#include <iostream>
#include <string>
#include <vector>
#include "../../source/UndoRedo.h"

using namespace std;

int main()
{
	UndoRedo c(3);
	Command cSegment("detruit seg 1", "construit seg 1");
	Command cSegment2("construit seg 2", "detruit seg 2");
	Command cRectangle("detruit rec 2", "construit rec 2");
	Command cRectangle2("construit rec 1", "detruit rec 1");
	c.AddUndo(cSegment);
	c.AddUndo(cSegment2);
	c.AddUndo(cRectangle);
	c.AddUndo(cRectangle2);
	cout << c.Undo() << endl;
	cout << c.Undo() << endl;
	cout << c.Undo() << endl;
	cout << c.Undo() << endl;
	cout << c.Redo() << endl;
	cout << c.Redo() << endl;
	cout << c.Redo() << endl;
	return 0;
}