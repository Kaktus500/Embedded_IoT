/**
 * @file      mainPage.h
 * @brief     Doxygen text for main page./*
 * @author    Daniel Valvano and Jonathan Valvano
 * @copyright Copyright 2020 by Jonathan W. Valvano, valvano@mail.utexas.edu,
 * @warning   AS-IS
 * @note      For more information see  http://users.ece.utexas.edu/~valvano/
 * @date      Sept 2, 2021
 * */

/*!
 * \mainpage EE382V Embedded IoT
 * Sept 2, 2021
 * \author Jonathan Valvano, PhD
 * \author Daniel Valvano, BS
 *
 * \section sec1 Overview
\par
Internet of Things (IoT) is ubiquitous in the computing world.  Connected devices allow remote data acquisition, distributed processing, and remote actuation. The focus of this class will be low-level technology to implement IoT devices. By exposing fundamental operational behavior, students, when facing a design problem, will be empowered to either select an appropriate existing technology, or to develop new technologies.
\par
Each category will begin with fundamental operational theory. The second step will be to present reference designs that utilize the technology.  The third step will be able to evaluate performance, such as electrical power, computational performance, communication bandwidth, system reliability, and network diameter.  The course will discuss similarities and differences in the technologies. The course will conclude with an open-ended and interactive discussion of future trends in IoT.

 * \section sec2 Hardware
\par
The hardware used in these projects include
 \li MSP432 LaunchPad (MSP-EXP432P401R)
 \li RSLK Max (TIRSLK-EVM)
 \li CC3100 BoosterPack (CC3100BOOST)
 \li CC2650 BoosterPack (BOOSTXL-CC2650MA)
 \li CC2650 LaunchPad (LAUNCHXL-CC2650)
 \li Educational BoosterPack MKII (BOOSTXL-EDUMKII)
 \li Building Automation Sensor (BP-BASSENSORSMKII)
 \li Adafruit FONA Cellular Module 2G (obsolete)
 \li Seeed HC12 (SKU 113990039)<br>

These project utilize the MSP432 LaunchPad.
For more information see<br> https://www.ti.com/tool/MSP-EXP432P401R
 * \image html MSP432.jpg width=500px
 * \image latex MSP432.jpg "TI MSP432 LaunchPad" width=10cm
 *
The CC2650 implements Bluetooth Low Energy.
For more information see<br>
 https://www.ti.com/tool/LAUNCHXL-CC2650<br>
  and https://www.ti.com/tool/BOOSTXL-CC2650MA
 * \image html CC2650.jpg width=500px
 * \image latex CC2650.jpg "TI CC2650 BoosterPack" width=10cm
 *
The CC3100 implements wifi.
For more information see<br> https://www.ti.com/tool/CC3100BOOST
 * \image html CC3100.png width=500px
 * \image latex CC3100.png "TI CC3100 BoosterPack" width=10cm
 *
The RSLK Max is a full-featured robot platform, shown here with CC2650.
For more information see<br>
https://www.ti.com/tool/TIRSLK-EVM<br>
https://training.ti.com/ti-robotics-system-learning-kit-max<br>
and
https://university.ti.com/en/faculty/ti-robotics-system-learning-kit/ti-rslk-max-edition-curriculum
 * \image html RSLK_CC2650.png width=500px
 * \image latex RSLK_CC2650.png "TI CC3100 BoosterPack" width=10cm
 *
 *
The Building Automation Sensor BP-BASSENSORSMKII includes a wide range of sensors. The booster includes
TMP117 Temperature, HDC2080 Temperature/Humidity, OPT3001 Light intensity, DRV5055A Hall Effect,
and BMI160/BMM150 9-axis IMU.
For more information see<br>
https://www.ti.com/tool/BP-BASSENSORSMKII
 * \image html BASSENSORSMKII.png width=500px
 * \image latex BASSENSORSMKII.png "BP-BASSENSORSMKII" width=10cm


The Educational BoosterPack MKII is simple platform with lots of I/O, shown here with the CC2650 BoosterPack.
For more information see<br>
https://www.ti.com/tool/BOOSTXL-EDUMKII
 * \image html Fitness.png width=500px
 * \image latex Fitness.png "TI Educational BoosterPack MKII" width=10cm
 *
The Seeed HC12 implements subGHz IEEE 15.4 communication, shown here connected to the MSP432 LaunchPad. For more information see
<br> https://www.seeedstudio.com/433Mhz-Wireless-Serial-Transceiver-Module-1-Kilometer-p-1733.html
 * \image html HC12.jpg width=500px
 * \image latex HC12.jpg "Seeed HC12" width=10cm
 *

Adafruit FONA Cellular Module 2G can send and receive SMS text messages. For more information see<br>
 https://www.adafruit.com/product/1946
 * \image html Fona.jpg width=500px
 * \image latex Fona.jpg "Adafruit FONA Cellular Module 2G" width=10cm
 *

 * \section sec3 Modules
 * \par
The documentation is divided into modules.
 \li MSP432 contains the MSP432 peripherals
 \li BLE contains Bluetooth Low Energy Application Processor with CC2650
 \li RSLK describes software for the TI-RSLK MAX robot
 \li BP-BASSENSORSMKII describes software for the Building Automation Sensors BoosterPack
 \li MKII describes software for the Educational BoosterPack MKII
 \li Math contains math functions, TExaS scope, and logic analyzer
 \li Fona describes software for the Adafruit FONA Cellular Module 2G <br>

*/


