#include "library.h"

int existsInArray(const int *array, size_t size, int value)
{
	while ( size-- )
	{
		if ( *array++ == value )
		{
			return 1;
		}
	}
	return 0;
}