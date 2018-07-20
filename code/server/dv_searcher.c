//
// Created by pedro on 29/06/18.
//

#include "server.h"

#define MAX_ARGPTR 20000 //Unknow real value. For now just 20000
int sizevalues = 0;
valuesData **values;
dataType type = sNone;

void cleanOffset()
{
	while(removeOffset(0) != -1) {}
	type = sNone;
}

int addOffset(int offset)
{
	//Space for save offset
	values = realloc(values, sizeof(valuesData *)*(sizevalues+1));
	values[sizevalues] = malloc(sizeof(valuesData));
	if(!values[sizevalues])
	{
		//can't allocate space
		return -1;
	}
	values[sizevalues]->offset = offset;
	values[sizevalues]->type = type;
	switch (type)
	{
		case sInt:
			values[sizevalues]->value = malloc(sizeof(int));
			*(int*)values[sizevalues]->value = *((int *)VM_ArgPtr(offset));
			break;
		case sDouble:
			values[sizevalues]->value = malloc(sizeof(double));
			*(double*)values[sizevalues]->value = *((double *)VM_ArgPtr(offset));
			break;
		case sFloat:
			values[sizevalues]->value = malloc(sizeof(float));
			*(float*)values[sizevalues]->value = *((float *)VM_ArgPtr(offset));
			break;
		case sString:
			values[sizevalues]->value = malloc(sizeof(char[64]));
			strncpy((char*)values[sizevalues]->value, ((char *)VM_ArgPtr(offset)), 64);
			break;
		case sLong:
			values[sizevalues]->value = malloc(sizeof(long));
			*(long*)values[sizevalues]->value = *((long *)VM_ArgPtr(offset));
			break;
		default:
			//????????????
			return 0;
	}
	return ++sizevalues;
}
int removeOffset(int index)
{
	if(index >= sizevalues || index < 0)
	{
		return -1;
	}
	//Free memory
	if(values[index] != 0)
	{
		free(values[index]->value);
		free(values[index]);
		values = realloc(values, sizeof(valuesData *)*(sizevalues+1));
	}
	sizevalues--;
	values[index] = values[sizevalues];
	values[sizevalues] = 0;
	return sizevalues;
}

void listData(void)
{
	int i;
	if(sizevalues == 0)
	{
		Com_Printf("Nothing to list!\n");
	}
	Com_Printf("Size %d\n", sizevalues);
	for (i = 0; i < sizevalues; i++)
	{
		Com_Printf("[%d] %p | ",i, values[i]->offset);

		if(type == sInt)
		{
			Com_Printf("%d - %d\n", *((int *)values[i]->value), *((int*)VM_ArgPtr(values[i]->offset)));
		}else if(type == sFloat)
		{
			Com_Printf("%f - %f\n", *((float *)values[i]->value), *((float*)VM_ArgPtr(values[i]->offset)));
		}else if(type == sDouble)
		{
			Com_Printf("%f - %f\n", *((double *)values[i]->value), *((double*)VM_ArgPtr(values[i]->offset)));
		}else if(type == sString)
		{
			Com_Printf("%s - %s\n",  (char *)values[i]->value, ((char*)VM_ArgPtr(values[i]->offset)));

		}else if(type == sLong)
		{
			Com_Printf("%ld - %ld\n", *((long *)values[i]->value), *((long*)VM_ArgPtr(values[i]->offset)));
		}
	}
}

int searchForI(int formatch) {
	if(type != sInt || type != sNone)
	{
		return -1;
	}
	type = sInt;
	if(sizevalues)
	{
		int i = 0;
		while(i < sizevalues)
		{
			if(formatch != *((int*)VM_ArgPtr(values[i]->offset)))
			{
				removeOffset(i);
			}else
			{
				*(int*)values[i]->value = formatch;
				i++; //Continue to next
			}
		}
	}else
	{
		int i;
		for (i=1;i < MAX_ARGPTR; i++)
		{
			if(formatch == *((int*)VM_ArgPtr(i)))
			{
				addOffset(i);
			}
		}
	}
	return sizevalues;
}

qboolean inline fqde(float a , float b)
{
	return fabs(a - b) < .3;
}

int searchForF(float formatch) {
	if(type != sFloat || type != sNone)
	{
		return -1;
	}
	type = sFloat;
	if(sizevalues)
	{
		int i = 0;
		while(i < sizevalues)
		{
			if(fqde(formatch,*((float*)VM_ArgPtr(values[i]->offset))))
			{
				removeOffset(i);
			}else
			{
				*(float*)values[i]->value = formatch;
				i++; //Continue to next
			}
		}
	}else
	{
		int i;
		for (i=1;i < MAX_ARGPTR; i++)
		{
			if(fqde(formatch,*((float*)VM_ArgPtr(i))))
			{
				addOffset(i);
			}
		}
	}
	return sizevalues;
}

int searchForD(double formatch) {
	if(type != sDouble || type != sNone)
	{
		return -1;
	}
	type = sDouble;
	if(sizevalues)
	{
		int i = 0;
		while(i < sizevalues)
		{
			if(fqde(formatch,*((double*)VM_ArgPtr(values[i]->offset))))
			{
				removeOffset(i);
			}else
			{
				*(double*)values[i]->value = formatch;
				i++; //Continue to next
			}
		}
	}else
	{
		int i;
		for (i=1;i < MAX_ARGPTR; i++)
		{
			if(fqde(formatch,*((double*)VM_ArgPtr(i))))
			{
				addOffset(i);
			}
		}
	}
	return sizevalues;
}

int searchForL(long formatch) {
	if(type != sLong || type != sNone)
	{
		return -1;
	}
	type = sLong;
	if(sizevalues)
	{
		int i = 0;
		while(i < sizevalues)
		{
			if(fqde(formatch,*((long*)VM_ArgPtr(values[i]->offset))))
			{
				removeOffset(i);
			}else
			{
				*(long*)values[i]->value = formatch;
				i++; //Continue to next
			}
		}
	}else
	{
		int i;
		for (i=1;i < MAX_ARGPTR; i++)
		{
			if(fqde(formatch,*((long*)VM_ArgPtr(i))))
			{
				addOffset(i);
			}
		}
	}
	return sizevalues;
};

/*
int searchForS(char *s) {
	if(type != sString)
	{
		Com_Printf("Is not the same type!");
		return -1;
	}
	if(sizevalues)
	{

	}else
	{

	}
}

 */