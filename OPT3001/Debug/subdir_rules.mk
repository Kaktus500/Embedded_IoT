################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Clock.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/Clock.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Clock.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CortexM.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/CortexM.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="CortexM.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Nokia5110.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/Nokia5110.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Nokia5110.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

OPT3001.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/OPT3001.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="OPT3001.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

SSD1306.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/SSD1306.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="SSD1306.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

UART0.obj: /Users/pauldelseith/Documents/TUM/Master/UT\ Austin/Courses/Embedded\ IoT/HW/Embedded_IoT/inc/UART0.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include" --include_path="/Applications/ti/ccs1200/ccs/ccs_base/arm/include/CMSIS" --include_path="/Users/pauldelseith/Documents/TUM/Master/UT Austin/Courses/Embedded IoT/HW/Embedded_IoT/OPT3001" --include_path="/Applications/ti/ccs1200/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --c99 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="UART0.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


