#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE  ,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE  ,GPIO_PIN_1);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE  ,GPIO_PIN_2);
	GPIOPinTypeGPIOInput(GPIO_PORTA_BASE ,GPIO_PIN_3);
	GPIOPadConfigSet(GPIO_PORTA_BASE ,GPIO_PIN_3,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_0,0);
	GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_1,0);
	GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_2,0);
	while(1)
	{
		if (GPIOPinRead(GPIO_PORTA_BASE ,GPIO_PIN_3)==0)
		{
			GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_1,0);
			SysCtlDelay(1333333);
			GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_1,2);
			SysCtlDelay(1333333);
		}
		else
		{
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_0,1);
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_1,0);
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_2,0);
			 SysCtlDelay(1333333);
			 GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_0,0);
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_1,0);
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_2,4);
			 SysCtlDelay(1333333);
			 GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_0,0);
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_1,2);
	     GPIOPinWrite(GPIO_PORTD_BASE  ,GPIO_PIN_2,0);
			 SysCtlDelay(1333333);
		}
	}
}