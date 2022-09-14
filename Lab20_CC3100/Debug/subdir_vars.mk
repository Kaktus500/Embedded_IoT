################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../msp432p401r.cmd 

C_SRCS += \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Bump.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Clock.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/CortexM.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/LaunchPad.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Motor.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/PWM.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/SSD1306.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/TA3InputCapture.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Tachometer.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Timer32.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/TimerA1.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/UART0.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/blinker.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/board.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/cpu.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/device.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/driver.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/fixed.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/flowcont.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/fpu.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/fs.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/interrupt.c \
../main.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/netapp.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/netcfg.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/nonos.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/odometry.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/socket.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/spawn.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/spi.c \
../startup_msp432p401r_ccs.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/sysctl.c \
../system_msp432p401r.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/timer_tick.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/utils/ustdlib.c \
C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/wlan.c 

C_DEPS += \
./Bump.d \
./Clock.d \
./CortexM.d \
./LaunchPad.d \
./Motor.d \
./PWM.d \
./SSD1306.d \
./TA3InputCapture.d \
./Tachometer.d \
./Timer32.d \
./TimerA1.d \
./UART0.d \
./blinker.d \
./board.d \
./cpu.d \
./device.d \
./driver.d \
./fixed.d \
./flowcont.d \
./fpu.d \
./fs.d \
./interrupt.d \
./main.d \
./netapp.d \
./netcfg.d \
./nonos.d \
./odometry.d \
./socket.d \
./spawn.d \
./spi.d \
./startup_msp432p401r_ccs.d \
./sysctl.d \
./system_msp432p401r.d \
./timer_tick.d \
./ustdlib.d \
./wlan.d 

OBJS += \
./Bump.obj \
./Clock.obj \
./CortexM.obj \
./LaunchPad.obj \
./Motor.obj \
./PWM.obj \
./SSD1306.obj \
./TA3InputCapture.obj \
./Tachometer.obj \
./Timer32.obj \
./TimerA1.obj \
./UART0.obj \
./blinker.obj \
./board.obj \
./cpu.obj \
./device.obj \
./driver.obj \
./fixed.obj \
./flowcont.obj \
./fpu.obj \
./fs.obj \
./interrupt.obj \
./main.obj \
./netapp.obj \
./netcfg.obj \
./nonos.obj \
./odometry.obj \
./socket.obj \
./spawn.obj \
./spi.obj \
./startup_msp432p401r_ccs.obj \
./sysctl.obj \
./system_msp432p401r.obj \
./timer_tick.obj \
./ustdlib.obj \
./wlan.obj 

OBJS__QUOTED += \
"Bump.obj" \
"Clock.obj" \
"CortexM.obj" \
"LaunchPad.obj" \
"Motor.obj" \
"PWM.obj" \
"SSD1306.obj" \
"TA3InputCapture.obj" \
"Tachometer.obj" \
"Timer32.obj" \
"TimerA1.obj" \
"UART0.obj" \
"blinker.obj" \
"board.obj" \
"cpu.obj" \
"device.obj" \
"driver.obj" \
"fixed.obj" \
"flowcont.obj" \
"fpu.obj" \
"fs.obj" \
"interrupt.obj" \
"main.obj" \
"netapp.obj" \
"netcfg.obj" \
"nonos.obj" \
"odometry.obj" \
"socket.obj" \
"spawn.obj" \
"spi.obj" \
"startup_msp432p401r_ccs.obj" \
"sysctl.obj" \
"system_msp432p401r.obj" \
"timer_tick.obj" \
"ustdlib.obj" \
"wlan.obj" 

C_DEPS__QUOTED += \
"Bump.d" \
"Clock.d" \
"CortexM.d" \
"LaunchPad.d" \
"Motor.d" \
"PWM.d" \
"SSD1306.d" \
"TA3InputCapture.d" \
"Tachometer.d" \
"Timer32.d" \
"TimerA1.d" \
"UART0.d" \
"blinker.d" \
"board.d" \
"cpu.d" \
"device.d" \
"driver.d" \
"fixed.d" \
"flowcont.d" \
"fpu.d" \
"fs.d" \
"interrupt.d" \
"main.d" \
"netapp.d" \
"netcfg.d" \
"nonos.d" \
"odometry.d" \
"socket.d" \
"spawn.d" \
"spi.d" \
"startup_msp432p401r_ccs.d" \
"sysctl.d" \
"system_msp432p401r.d" \
"timer_tick.d" \
"ustdlib.d" \
"wlan.d" 

C_SRCS__QUOTED += \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Bump.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Clock.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/CortexM.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/LaunchPad.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Motor.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/PWM.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/SSD1306.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/TA3InputCapture.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Tachometer.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Timer32.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/TimerA1.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/UART0.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/blinker.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/board.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/cpu.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/device.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/driver.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/fixed.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/flowcont.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/fpu.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/fs.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/interrupt.c" \
"../main.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/netapp.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/netcfg.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/nonos.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/odometry.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/socket.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/spawn.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/spi.c" \
"../startup_msp432p401r_ccs.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/sysctl.c" \
"../system_msp432p401r.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/timer_tick.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/utils/ustdlib.c" \
"C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/wlan.c" 


