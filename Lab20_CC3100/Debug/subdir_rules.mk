################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Bump.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Bump.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Clock.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CortexM.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/CortexM.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LaunchPad.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/LaunchPad.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Motor.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Motor.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

PWM.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/PWM.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

SSD1306.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/SSD1306.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TA3InputCapture.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/TA3InputCapture.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Tachometer.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Tachometer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Timer32.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/Timer32.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TimerA1.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/TimerA1.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

UART0.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/UART0.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

blinker.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/blinker.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

board.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/board.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

cpu.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/cpu.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

device.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/device.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

driver.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/driver.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

fixed.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/fixed.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

flowcont.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/flowcont.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

fpu.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/fpu.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

fs.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/fs.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

interrupt.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/interrupt.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

netapp.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/netapp.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

netcfg.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/netcfg.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

nonos.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/nonos.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

odometry.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc/odometry.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

socket.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/socket.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

spawn.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/spawn.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

spi.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/spi.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

sysctl.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib/sysctl.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

timer_tick.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p/timer_tick.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

ustdlib.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/utils/ustdlib.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

wlan.obj: C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source/wlan.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/Lab20_CC3100" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/platform/msp432p" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/source" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/driverlib" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/simplelink/include" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/cc3100-sdk/examples/common" --include_path="C:/Users/Jerry/Documents/GitHub/Embedded_IoT/inc" --include_path="C:/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="C:/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


