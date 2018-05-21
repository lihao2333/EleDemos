################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./hwTCA6416A/TCA6416A.obj" \
"./hwTCA6416A/USCI_I2C.obj" \
"../lnk_msp430g2533.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include hwTCA6416A/subdir_vars.mk
-include subdir_rules.mk
-include hwTCA6416A/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
12_I2C_LED_KEY.out \

EXE_OUTPUTS__QUOTED += \
"12_I2C_LED_KEY.out" \

BIN_OUTPUTS += \
12_I2C_LED_KEY.hex \

BIN_OUTPUTS__QUOTED += \
"12_I2C_LED_KEY.hex" \


# All Target
all: 12_I2C_LED_KEY.out

# Tool invocations
12_I2C_LED_KEY.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmsp --use_hw_mpy=none -g --define=__MSP430G2553__ --diag_warning=225 --display_error_number --abi=eabi --printf_support=minimal -z -m"12_I2C_LED_KEY.map" --heap_size=80 --stack_size=80 -i"C:/software/ti/ccsv6/ccs_base/msp430/include" -i"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/lib" -i"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --reread_libs --warn_sections --xml_link_info="12_I2C_LED_KEY_linkInfo.xml" --use_hw_mpy=none --rom_model -o "12_I2C_LED_KEY.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

12_I2C_LED_KEY.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/software/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/hex430" --memwidth=8 --romwidth=8 -o "12_I2C_LED_KEY.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "main.d" "hwTCA6416A\TCA6416A.d" "hwTCA6416A\USCI_I2C.d" 
	-$(RM) "main.obj" "hwTCA6416A\TCA6416A.obj" "hwTCA6416A\USCI_I2C.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

