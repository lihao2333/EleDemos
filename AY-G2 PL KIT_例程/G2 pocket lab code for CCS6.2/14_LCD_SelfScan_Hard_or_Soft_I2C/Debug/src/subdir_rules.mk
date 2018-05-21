################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/HT1621.obj: ../src/HT1621.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="C:/software/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS6.2/14_LCD_SelfScan_Hard_or_Soft_I2C/src" --include_path="C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --abi=eabi --printf_support=minimal --preproc_with_compile --preproc_dependency="src/HT1621.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/I2C.obj: ../src/I2C.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="C:/software/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS6.2/14_LCD_SelfScan_Hard_or_Soft_I2C/src" --include_path="C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --abi=eabi --printf_support=minimal --preproc_with_compile --preproc_dependency="src/I2C.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LCD_128.obj: ../src/LCD_128.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="C:/software/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS6.2/14_LCD_SelfScan_Hard_or_Soft_I2C/src" --include_path="C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --abi=eabi --printf_support=minimal --preproc_with_compile --preproc_dependency="src/LCD_128.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TCA6416A.obj: ../src/TCA6416A.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmsp --use_hw_mpy=none --include_path="C:/software/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/Users/SAPL108/Desktop/G2 pocket lab code for CCS6.2/14_LCD_SelfScan_Hard_or_Soft_I2C/src" --include_path="C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --abi=eabi --printf_support=minimal --preproc_with_compile --preproc_dependency="src/TCA6416A.d" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


