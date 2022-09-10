################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
AP.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/AP.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="AP.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Clock.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Clock.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CortexM.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/CortexM.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="CortexM.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

GPIO.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/GPIO.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="GPIO.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

LaunchPad.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/LaunchPad.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="LaunchPad.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

UART1.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/UART1.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="UART1.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --advice:power=all --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


