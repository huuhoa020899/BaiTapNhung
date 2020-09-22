#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
long x;
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_7);
	GPIOPinTypeGPIOInput(GPIO_PORTB_BASE,GPIO_PIN_2 );
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_2,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	while(1)
	{
		if (GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_2)==0)
		{
			while(GPIOPinRead(GPIO_PORTB_BASE,GPIO_PIN_2)==0);
			x=GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_7);
			x^=GPIO_PIN_7;
			GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_7,x);
		}
	}
}