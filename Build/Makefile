##################################################################################################
#
#	FILENAME:       Makefile
#
#	DESCRIPTION:
#		This is makefile of Blinking-Led program for AVR ATmega168PB Xplained Mini development board.
#		Please use following make commands:
#		make build BUILD_TYPE=DEBUG          -> build DEBUG executable
#		make build BUILD_TYPE=RELEASE        -> build RELEASE executable
#		make clean BUILD_TYPE=DEBUG          -> clean DEBUG build
#		make clean BUILD_TYPE=RELEASE        -> clean RELEASE build
#		make empty_dir                       -> create empty Debug and Release directories
#
#		Before first build, set the following environment variables with paths to required
#		tools from AVR8 GNU Toolchain, or define these variables in this Makefile:
#
#		AVR_GCC       <avr8 gnu toolchain installation directory>/bin/avr-gcc.exe
#		AVR_SIZE      <avr8 gnu toolchain installation directory>/bin/avr-size.exe
#
#		Use make empty_dir command in order to create new Debug and Release directories on
#		your drive, where part of build artefacts will be stored.
#
#	AUTHOR:         Copyright (C) 2021 Kamil Deć github.com/deckamil
#	DATE:           9 MAY 2021
#
#	LICENSE:
#		This makefile is free software: you can redistribute it and/or modify
#		it under the terms of the GNU General Public License as published by
#		the Free Software Foundation, either version 3 of the License, or
#		(at your option) any later version.
#
#		This makefile is distributed in the hope that it will be useful,
#		but WITHOUT ANY WARRANTY; without even the implied warranty of
#		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
#		GNU General Public License for more details.
#
#		You should have received a copy of the GNU General Public License
#		along with this makefile. If not, see <https://www.gnu.org/licenses/>.
#
##################################################################################################


# Commands
MKDIR:= mkdir
RM:= rm -rf

# Default build type
BUILD_TYPE:= DEBUG


# DEBUG build configuration
ifeq ($(BUILD_TYPE),DEBUG)

OBJS +=  \
Debug/ioport.o \
Debug/timer.o \
Debug/main.o

DIR:= Debug

# RELEASE build configuration
else ifeq ($(BUILD_TYPE),RELEASE)

OBJS +=  \
Release/ioport.o \
Release/timer.o \
Release/main.o

DIR:= Release

endif


# Build outputs
OUTPUT_FILE_ELF +=  \
Blinking-Led.elf

OUTPUT_FILE_MAP +=  \
Blinking-Led.map


# Compile DEBUG sources
Debug/ioport.o: ../Src/ioport.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(AVR_GCC) -x c -funsigned-char -funsigned-bitfields -DF_CPU=16000000UL -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega168pb -c -std=gnu99 -MD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -o"$@" "$<"
	@echo Finished building: $<
	
Debug/timer.o: ../Src/timer.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(AVR_GCC) -x c -funsigned-char -funsigned-bitfields -DF_CPU=16000000UL -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega168pb -c -std=gnu99 -MD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -o"$@" "$<"
	@echo Finished building: $<
	
Debug/main.o: ../Src/main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(AVR_GCC) -x c -funsigned-char -funsigned-bitfields -DF_CPU=16000000UL -DDEBUG -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega168pb -c -std=gnu99 -MD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -o"$@" "$<"
	@echo Finished building: $<


# Compile RELEASE sources
Release/ioport.o: ../Src/ioport.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(AVR_GCC) -x c -funsigned-char -funsigned-bitfields -DF_CPU=16000000UL -DNDEBUG -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega168pb -c -std=gnu99 -MD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -o"$@" "$<"
	@echo Finished building: $<
	
Release/timer.o: ../Src/timer.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(AVR_GCC) -x c -funsigned-char -funsigned-bitfields -DF_CPU=16000000UL -DNDEBUG -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega168pb -c -std=gnu99 -MD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -o"$@" "$<"
	@echo Finished building: $<
	
Release/main.o: ../Src/main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler
	$(AVR_GCC) -x c -funsigned-char -funsigned-bitfields -DF_CPU=16000000UL -DNDEBUG -Os -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -mmcu=atmega168pb -c -std=gnu99 -MD -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -o"$@" "$<"
	@echo Finished building: $<


# Build executable
build: $(OBJS)
	@echo Building target: $(OUTPUT_FILE_ELF)
	@echo Invoking: AVR/GNU Linker
	$(AVR_GCC) -o$(OUTPUT_FILE_ELF) $(OBJS) -Wl,-Map=$(OUTPUT_FILE_MAP) -Wl,--start-group -Wl,-lm -Wl,-lc -Wl,--end-group -Wl,--gc-sections -mmcu=atmega168pb
	@echo Finished building target: $(OUTPUT_FILE_ELF)
	$(AVR_SIZE) $(OUTPUT_FILE_ELF)


# Remove all artefacts
clean:
	$(RM) $(DIR)
	$(MKDIR) $(DIR)
	$(RM) $(OUTPUT_FILE_ELF)
	$(RM) $(OUTPUT_FILE_MAP)


# Create empty directories 
empty_dir:
	$(RM) Debug
	$(RM) Release
	$(MKDIR) Debug
	$(MKDIR) Release
