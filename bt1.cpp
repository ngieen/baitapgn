#include <stdio.h>
#include <stdint.h>

/***************************************************
			Do not touch "ADMIN CODE" 
****************************************************/
/* ADMIN CODE BEGIN 0 */
typedef struct {
	uint32_t MODER;		/* GPIO port mode register, offset 0x00 */
	uint32_t OTYPER;	/* GPIO port mode register, offset 0x04 */
	uint32_t OSPEEDR;	/* GPIO port mode register, offset 0x08 */
	uint32_t Res[2];	/* Reserved, offset 0x0C */
	uint32_t ODR;		/* GPIO port mode register, offset 0x14 */
} GPIOA_Typedef;

/* Reset value */
GPIOA_Typedef GPIOA = {
	GPIOA.MODER 		= 0xA8000000, 
	GPIOA.OTYPER 	    = 0x00000000, 
	GPIOA.OSPEEDR 	    = 0x0C000000,
	GPIOA.ODR 		    = 0x00000000
};
/* ADMIN CODE END 0 */
//ham delay  
void delay_ms(unsigned int x){
unsigned int TGIAN_TRE1;     
      while(x!=0)
        {    
         TGIAN_TRE1=121;
         while(TGIAN_TRE1!=0)
         {          
                  TGIAN_TRE1=TGIAN_TRE1-1;
         }
         x=x-1;
      }
}

int main() {
	//uint32_t *addr = NULL;
	uint32_t *addr_moder    = &(GPIOA.MODER);
	uint32_t *addr_otyper   = &(GPIOA.OTYPER);
	uint32_t *addr_ospeedr  = &(GPIOA.OSPEEDR);
	uint32_t *addr_odr      = &(GPIOA.ODR);
	
	*addr_moder   |(1<<14);
	*addr_otyper  &~(1<<7);
	*addr_ospeedr |(1<<14);
	
	int i=0;
	
	for(i=0;i<10;i++)
	{
		*addr_odr |(1<<7);  
		printf("Bit 7 - Pin 7: %d  - led on\n", (*addr_odr & (1<<7)) >> 7);
		delay_ms(500);
		
		*addr_odr &~(1<<7); 
		printf("Bit 7 - Pin 7: %d  - led off\n", (*addr_odr & (1<<7)) >> 7);
		delay_ms(500);
	}
	 
	/***********************************
		Arg1: Number of character for arg2
		Arg2: Value of a register
		Arg3: Address of a register 
	************************************/
	printf("BASE ADDRESS: %X\n", &GPIOA);
	printf("MODER  : %-10.*X %X\n", 8, GPIOA.MODER, &GPIOA.MODER);
	printf("OTYPER : %-10.*X %X\n", 8, GPIOA.OTYPER, &GPIOA.OTYPER);
	printf("OSPEEDR: %-10.*X %X\n", 8, GPIOA.OSPEEDR, &GPIOA.OSPEEDR);
	printf("ODR    : %-10.*X %X\n", 8, GPIOA.ODR, &GPIOA.ODR);
	
	return 0;
}
