# NXP Middleware RTCESL - Real Time Control Embedded Software Libraries 
A complimentary group of algorithms, ranging from basic mathematics operations to advanced transformations and observers, which can be easily incorporated into complex real-time control applications. The complimentary
algorithms help to speed development and ease of use in applications that require intensive math computation and control such as advanced high efficiency motor control and power conversion. 
The libraries are highly optimized, are tested on NXP hardware, and are easy to use as they are implemented with a C-callable function interface. The libraries are currently available for the Kinetis ARM Cortex M0+, M4, M7 and M33.
More details can be founded on https://www.nxp.com/rtcesl

RTCESL consists from:

Math Library (MLIB)
Simple math functions (addition, subtraction, multiplication, division, shifts...) with and without saturation. This aim of this block is to have efficient and fast mathematics built on the MCU’s instructions. The User's Guides are available:
[MLIB CM0+ ](https://www.nxp.com/docs/en/user-guide/CM0MLIBUG.pdf)
[MLIB CM4F ](https://www.nxp.com/docs/en/user-guide/CM4FMLIBUG.pdf)
[MLIB CM7F ](https://www.nxp.com/docs/en/user-guide/CM7FMLIBUG.pdf)
[MLIB CM33F](https://www.nxp.com/docs/en/user-guide/CM33FMLIBUG.pdf)

General Function Library (GFLIB)
Contains the basic building blocks of a real-time control application. Functions for basic mathematical calculations, trigonometric functions, simple look-up table and control functions such as PI and PID controllers. The User's Guides are available:
[GFLIB CM0+ ](https://www.nxp.com/docs/en/user-guide/CM0GFLIBUG.pdf)
[GFLIB CM4F ](https://www.nxp.com/docs/en/user-guide/CM4FGFLIBUG.pdf)
[GFLIB CM7F ](https://www.nxp.com/docs/en/user-guide/CM7FGFLIBUG.pdf)
[GFLIB CM33F](https://www.nxp.com/docs/en/user-guide/CM33FGFLIBUG.pdf)

General Motor Control Library (GMCLIB)
The fundamental blocks of a motor control application. The libraries include vector modulation, Park and Clarke transformations and specific motor related functions to build digitally controlled motor drives. The User's Guides are available:
[GMCLIB CM0+ ](https://www.nxp.com/docs/en/user-guide/CM0GMCLIBUG.pdf)
[GMCLIB CM4F ](https://www.nxp.com/docs/en/user-guide/CM4FGMCLIBUG.pdf)
[GMCLIB CM7F ](https://www.nxp.com/docs/en/user-guide/CM7FGMCLIBUG.pdf)
[GMCLIB CM33F](https://www.nxp.com/docs/en/user-guide/CM33FGMCLIBUG.pdf)

General Digital Filter Library (GDFLIB)
Includes filter functions for signal conditioning. The User's Guides are available:
[GDFLIB CM0+ ](https://www.nxp.com/docs/en/user-guide/CM0GDFLIBUG.pdf)
[GDFLIB CM4F ](https://www.nxp.com/docs/en/user-guide/CM4FGDFLIBUG.pdf)
[GDFLIB CM7F ](https://www.nxp.com/docs/en/user-guide/CM7FGDFLIBUG.pdf)
[GDFLIB CM33F](https://www.nxp.com/docs/en/user-guide/CM33FGDFLIBUG.pdf)

Advanced Motor Control Library (AMCLIB)
Functions that enable the construction of a variable speed, AC motor drive system that implements field oriented control techniques without position or speed sensors to provide the lowest cost solution. The User's Guides are available:
[AMCLIB CM0+ ](https://www.nxp.com/docs/en/user-guide/CM0AMCLIBUG.pdf)
[AMCLIB CM4F ](https://www.nxp.com/docs/en/user-guide/CM4FAMCLIBUG.pdf)
[AMCLIB CM7F ](https://www.nxp.com/docs/en/user-guide/CM7FAMCLIBUG.pdf)
[AMCLIB CM33F](https://www.nxp.com/docs/en/user-guide/CM33FAMCLIBUG.pdf)

Power Control Library (PCLIB)
Contains control loop algorithms required in Power Control applications. The User's Guides are available:
[PCLIB CM0+](https://www.nxp.com/docs/en/user-guide/CM0PCLIBUG.pdf)
[PCLIB CM4 ](https://www.nxp.com/docs/en/user-guide/CM4PCLIBUG.pdf)
[PCLIB CM7 ](https://www.nxp.com/docs/en/user-guide/CM7PCLIBUG.pdf)
[PCLIB CM33](https://www.nxp.com/docs/en/user-guide/CM33PCLIBUG.pdf)

## Documentation
User guide is provided to explain more details of RTCESL function and their API.

## License
This repository is under **LA_OPT_Online Code Hosting NXP_Software_License**.

## Examples
The best examples of the RTCESL functions usage are the Motor Control examples, that are placed on the repository [mcux-sdk-examples](https://github.com/nxp-mcuxpresso/mcux-sdk-examples).

- **mc_acim**
  - Motor control example for ACIM based on RTCESL.

- **mc_bldc**
  - Motor control example for BLDC based on RTCESL.
  
- **mc_pmsm**
  - Motor control example for PMSM based on RTCESL.
  
- **mc_pmsm_frac**
  - Motor control example for PMSM based on RTCESL and fraction arithmetic.
  
