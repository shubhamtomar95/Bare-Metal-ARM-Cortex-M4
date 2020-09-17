
#ifndef __REG_NAMES__
#define __REG_NAMES__

#define PORTF_DATA (*((volatile unsigned long *)0x400253FC))
#define PORTF_DIR  (*((volatile unsigned long *)0x40025400))
#define PORTF_PUR  (*((volatile unsigned long *)0x40025510))
#define PORTF_DEN  (*((volatile unsigned long *)0x4002551C))
#define RCGC2      (*((volatile unsigned long *)0x400FE108))

#endif



#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DATA_BITS_R  ((volatile unsigned long *)0x40025000)
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_MIS_R        (*((volatile unsigned long *)0x40025418))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DR2R_R       (*((volatile unsigned long *)0x40025500))
#define GPIO_PORTF_DR4R_R       (*((volatile unsigned long *)0x40025504))
#define GPIO_PORTF_DR8R_R       (*((volatile unsigned long *)0x40025508))
#define GPIO_PORTF_ODR_R        (*((volatile unsigned long *)0x4002550C))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_PDR_R        (*((volatile unsigned long *)0x40025514))
#define GPIO_PORTF_SLR_R        (*((volatile unsigned long *)0x40025518))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_PORTF_ADCCTL_R     (*((volatile unsigned long *)0x40025530))
#define GPIO_PORTF_DMACTL_R     (*((volatile unsigned long *)0x40025534))

#define SWITCH_TWO (*((volatile unsigned long *)0x40025004))
#define RED_LED    (*((volatile unsigned long *)0x40025008))
#define BLUE_LED   (*((volatile unsigned long *)0x40025010))
#define GREEN_LED  (*((volatile unsigned long *)0x40025020))
#define SWITCH_ONE (*((volatile unsigned long *)0x40025040))
//int PF2 = GPIO_PORTF_DATA_R & BIT2;



/*
void PortF_Init(void)
{
	// volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;
	//delay =  SYSCTL_RCGC2_R;
	GPIO_PORTF_LOCK_R  = 0x4C4F434B;
	GPIO_PORTF_CR_R = 0x1F;
	GPIO_PORTF_AMSEL_R = 0x00;
	GPIO_PORTF_PCTL_R = 0x0000000;
	GPIO_PORTF_DIR_R = 0x04;
	GPIO_PORTF_AFSEL_R = 0x00;
	GPIO_PORTF_PUR_R = 0x10;
	GPIO_PORTF_DEN_R = 0x14;
	return;
}
*/
/*
void PortF_Init2(void)
{
	// volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x00000020;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_DEN_R = 0x1F;

	return;
}
*/
// void delay()
// {
// 	int variable = 100000;
// 	while(variable--)
// 	{
// 		//__asm volatile("NOP");
// 	}
// }

int delay;


int main(void)
{	
	SYSCTL_RCGC2_R |= 0x00000020;
	GPIO_PORTF_DIR_R = 0x0E;
	GPIO_PORTF_DEN_R = 0x1E;
	GPIO_PORTF_PUR_R = 0x10;
	GPIO_PORTF_DATA_R = 0x02;
	__asm volatile("MOV R5,#99");
	
	while(1)
	{
		delay = 0;
		while(delay < 500000)
		{
			GPIO_PORTF_DATA_R = 0x04;
			delay = delay + 1;	
		}

		delay = 0;
		while(delay < 500000)
		{
			GPIO_PORTF_DATA_R = 0x00;
			delay = delay + 1;	
		}		

		delay = 0;
		while(delay < 500000)
		{
			GPIO_PORTF_DATA_R = 0x02;
			delay = delay + 1;	
		}

		delay = 0;
		while(delay < 500000)
		{
			GPIO_PORTF_DATA_R = 0x00;
			delay = delay + 1;	
		}	
		
		delay = 0;
		while(delay < 500000)
		{
			GPIO_PORTF_DATA_R = 0x08;
			delay = delay + 1;	
		}

		delay = 0;
		while(delay < 500000)
		{
			GPIO_PORTF_DATA_R = 0x00;
			delay = delay + 1;	
		}	
	}	
}

