#include "stdio.h"

int main(int argc, char* argv[])
{
	if ( argc <= 1) 
	{
		printf("CompileToCppVariable <Filename> [VariableName]\n");
		return 1;
	}

	if ( argc > 2)
	{
		printf ("const char %s[] = {\n", argv[2]);
	}
	

	FILE* fp = fopen(argv[1],"rb");
	if (fp == NULL)
	{
		printf ("Could not open file %s\n", argv[1]);
		return 2;
	}
	fseek(fp,0,SEEK_END);
	long size = ftell(fp);
	
	unsigned char* buffer = new unsigned char[size];

	fseek(fp,0,SEEK_SET);
	fread(buffer,sizeof(char),size,fp);

	for (long i = 0 ; i < size ; i++)
	{
		printf("0x%02hhx,",buffer[i]);
		if ((i % 20)==19)
		{
			printf("\n");
		}
	}

	printf ("0x%02hhx\n",(const unsigned char)(0));

	if ( argc > 2)
	{
		printf ("};\n");
	}

	fclose(fp);

	return 0;
}
