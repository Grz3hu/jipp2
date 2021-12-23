#include "templates.h"

int main()
{
	cout << maxT<int>(1,2) << endl;
	cout << minT<int>(1,2) << endl;

	Array<int,3> tmp = Array<int,3>();
	cout << tmp.getSize();
	
	

	return 0;
}
