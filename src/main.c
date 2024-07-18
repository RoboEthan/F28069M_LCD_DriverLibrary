// Included Files
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
#include "f28069M_LCD.h"

void InitLcdGpio(void);
// Main function
void main(void)
{
    InitSysCtrl();
    InitLcdGpio();

    Initialize();

    cursor_on();
    DELAY_US(999999);
    Display_LCD(1, "THIS WORKS");
    DELAY_US(999999);
    Display_LCD(2, "huh");
    while (1)
    {

    }

}

void InitLcdGpio()
{
    EALLOW;
    //  D0
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO21 = 1;   // Forces output to low
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 0; // 0=GPIO, 1=EPWM3B, 2=SPISIMOA, 3=ECAP1
    GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;      // 1=OUTput,  0=INput

    //  D1
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO14 = 1;   // Forces output to low
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 0; // 0=GPIO, 1=EPWM4A, 2=EPWMSYNCI, 3=EPWMSYNCO
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;      // 1=OUTput,  0=INput

    //  D2
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO20 = 1;   // Forces output to low
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0; // 0=GPIO, 1=EPWM4B, 2=SCIRXDA, 3=ECAP2
    GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;      // 1=OUTput,  0=INput

    //  D3
    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;   // Forces output to low
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0; // 0=GPIO, 1=TZ1n, 2=SCITXDA, 3=SPISIMOB
    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1;     // 1=OUTput,  0=INput

    //  D4
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;   // Forces output to low
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0; // 0=GPIO, 1=SPISIMOA, 2=Resv CAN-B, 3=TZ2n
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;     // 1=OUTput,  0=INput

    //  D5
    GpioCtrlRegs.GPAPUD.bit.GPIO22 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO22 = 1;   // Forces output to low
    GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 0; // 0=GPIO, 1=SPISOMIA, 2=Resv CAN-B, 3=TZ3n
    GpioCtrlRegs.GPADIR.bit.GPIO22 = 1;     // 1=OUTput,  0=INput

    //  D6
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO18 = 1;   // Forces output to low
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0; // 0=GPIO, 1=SPICLKA, 2=SCITXDB, 3=XCLKOUT
    GpioCtrlRegs.GPADIR.bit.GPIO18 = 1;     // 1=OUTput,  0=INput

    //  D7
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;   // Load output latch
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 0; // 0=GPIO, 1=SPISTEA, 2=SCIRXDB, 3=ECAP1
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;     // 1=OUTput,  0=INput

    //  RS
    GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPBCLEAR.bit.GPIO54 = 1;   // Forces output to low
    GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 0; // 0=GPIO,  1=I2C-SDA,  2=SYNCI,  3=ADCSOCA
    GpioCtrlRegs.GPBDIR.bit.GPIO54 = 1;     // 1=OUTput,  0=INput

    //  E
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;   // Enable pullup on GPIO8
    GpioDataRegs.GPACLEAR.bit.GPIO23 = 1;   // Forces output to low
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0; // 0=GPIO,  1=I2C-SCL,  2=SYNCO,  3=ADCSOCB
    GpioCtrlRegs.GPADIR.bit.GPIO23 = 1;     // 1=OUTput,  0=INput

    EDIS;

}
