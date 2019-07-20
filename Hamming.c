//Generating the Hamming code which we'll send at receiving side.
//Hamming code Generaton


#include<stdio.h>


int main()
{

	int data[11],i;
	
	printf("Enter data bits:");
	scanf("%d%d%d%d%d%d%d",&data[0],&data[1],&data[2],&data[4],&data[5],&data[6],&data[8]);
	
	//calculating parity bits;
	
	data[10]=data[8]^data[6]^data[4]^data[2]^data[0];
	data[9]= data[8]^data[5]^data[4]^data[1]^data[0];
	data[7]= data[6]^data[5]^data[4];
	data[3]= data[2]^data[1]^data[0];
	
	printf("code word is:");
	for(i=0;i<11;i++)
	{
		printf("%d \t ",data[i]);
	}
	printf("\n");
	return 0;
}
