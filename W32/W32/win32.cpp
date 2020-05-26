#include "stdafx.h"
#include "win32.h"
int factorial(int n)
{
	int s=1;
	for (int i = n; i > 1; i--)
	{
		s = s * i;
	}
	return s;
}