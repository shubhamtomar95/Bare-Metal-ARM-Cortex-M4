#include <gpio.h>

#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#define LED_OFF 0x00

void wait(unsigned long value)
{
  unsigned long volatile time;
  time = value;
  while(time){
	time--;
  }

}


int main(void)
{	
    PortF_Init();
    while (1)
    {
		GPIO_PORTF_DATA_R = RED;
		wait(500000);
		GPIO_PORTF_DATA_R = LED_OFF;
		wait(200000);
		GPIO_PORTF_DATA_R = GREEN;
		wait(500000);
		GPIO_PORTF_DATA_R = LED_OFF;
		wait(200000);
		GPIO_PORTF_DATA_R = BLUE;
		wait(500000);
		GPIO_PORTF_DATA_R = LED_OFF;
		wait(200000);
    }
}
