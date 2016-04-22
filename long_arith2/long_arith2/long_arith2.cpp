// long_arith2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "long_arith.h"
#include <stdio.h>
#include <stdlib.h>

// int_arithmetic.cpp: определяет точку входа для консольного приложения.
//


int main(int argc, char* argv[])
{
	if(argc<5)
		return 0;
	char *fname_in1 = argv[1];
	char *act = argv[2];
	char *fname_in2 =argv[3];
	char *fname_in3;
	char *fname_out = argv[4];
	char *bin = argv[5];
	if(argc>6)
		fname_in3 = argv[6];
	BigInt a,b,result,mod;
	if(a.get(fname_in1,bin)==0)
	{
		printf("%s bad format",fname_in1);
		return 0;
	}

	if(b.get(fname_in2,bin)==0)
	{
		printf("%s bad format",fname_in2);
		return 0;
	}
	switch(act[0])
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		case '%':
			result = a % b;
			break;
		case '^':
			if(argc<7)
			{
				printf("Error: Param 7 not found");
				return 0;
			}
			if(mod.get(fname_in3,bin)==0)
			{
				printf("%s bad format",fname_in3);
				return 0;
			}
			result = power(a,b,mod);
			break;
	}
	result.save(fname_out,bin);
	return 0;
}

