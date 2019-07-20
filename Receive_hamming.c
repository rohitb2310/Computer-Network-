//program which receive bits at receiving side at checking the error is present or not
//Hammming code Detection and correction.


#include<stdio.h>


int main()
{

	int data[11],i,j;
	
	printf("Received data bits:");//receiving the data bits
	for(i=0;i<11;i++)
	{
		scanf("%d",&data[i]);
	}
		
	//checking the parity bits 
	int p1,p2,p4,p8,e_bit;
	
	p1 = data[10] ^ data[8] ^ data[6] ^ data[4] ^ data[2] ^ data[0];

	p2 = data[9] ^ data[8] ^ data[5] ^ data[4] ^ data[1] ^ data[0];

	p4 = data[7] ^ data[6] ^ data[5] ^ data[4];

	p8 = data[3] ^ data[2] ^ data[1] ^ data[0];
	
		printf("bits are is:");

		for(i=0;i<11;i++)
		{
			printf("%d  ",data[i]);
		}
		
		e_bit=p1 + p2*2 + p4*4 + p8*8;		//calculating numeric value for the binary numbers
		
		if(e_bit==0)//checking all the parity bits are zero or not
		{
			printf("\n The Code word is ERROR FREE");
		}
		else
		{
			printf("\n Code Word having ERROR");

			printf("\n Resolving error.....");	//if error resolving the error
			
			int E_position=abs(11 - e_bit);
			printf("\n Error is at position:%d",E_position);	//checking error position
			printf("\n correcting Error....");

			if(data[E_position]==0)		//making inverison of the bits
			{
				data[E_position]=1;
			}
			else
			{
				data[E_position]=0;
			}
 		}
		
		printf("\n Bits Checking after Error Condition: \n Corrected code Word is"); // after coorecting the error printing the bits
		for(i=0;i<11;i++)
		{
			printf("%d  ",data[i]);
		}
	
	printf("\n");
	return 0;
}
