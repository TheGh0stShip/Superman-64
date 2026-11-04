TARGET = superman

ASM_DIRS = asm asm/asm asm/os
SRC_DIRS = src src/os
BIN_DIRS = bin
BUILD_DIR = build

GLOBAL_ASM_C_FILES != grep -rl 'GLOBAL_ASM(' $(wildcard src/*/*.c)
GLOBAL_ASM_O_FILES = $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))

ASM_FILES = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))
SRC_FILES = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
BIN_FILES = $(foreach dir,$(BIN_DIRS),$(wildcard $(dir)/*.bin))
O_FILES = $(foreach file,$(ASM_FILES),$(BUILD_DIR)/$(file:.s=.o)) \
		  $(foreach file,$(SRC_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
		  $(foreach file,$(BIN_FILES),$(BUILD_DIR)/$(file:.bin=.o))

YAY0_FILES = $(foreach dir,$(YAY0_DIR),$(wildcard $(dir)/*.bin))
SZP_FILES = $(foreach file,$(YAY0_FILES),$(BUILD_DIR)/$(file:.bin=.szp))

ALL_DIRS = $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(ASM_DIRS) $(BIN_DIRS) $(SRC_DIRS) $(YAY0_DIR))
DUMMY != mkdir -p $(ALL_DIRS)

AS = mips-linux-gnu-as
ASFLAGS := -march=vr4300 -mtune=vr4300 -mabi=32 -mips3 -Iinclude -I. -I$(BUILD_DIR)

CC = tools/ido/cc
OPT_FLAGS := -O2
SIGNED_FLAG := -signed
TARGET_CFLAGS := -nostdinc -DTARGET_N64 -DF3DEX_GBI_2
CFLAGS = -c $(TARGET_CFLAGS) -Wab,-r4300_mul -non_shared -G0 -Xcpluscomm -Xfullwarn $(SIGNED_FLAG) -mips2 $(OPT_FLAGS) -Iinclude -I. -Isrc/

LD = mips-linux-gnu-ld
LD_SCRIPT = superman.ld
LDFLAGS := --no-check-sections -m elf32btsmip -mips3 --accept-unknown-input-arch -T $(BUILD_DIR)/$(LD_SCRIPT) -T undefined_syms_auto.txt -T undefined_funcs_auto.txt

CPP := cpp -P -Wno-trigraphs
CPPFLAGS := -Iinclude/ -Iinclude/libc -I. -DTARGET_N64 -ffreestanding -D _LANGUAGE_C -D_FINALROM -DF3DEX_GBI_2 -D_MIPS_SZLONG=32

CC_CHECK := gcc -fsyntax-only -fsigned-char -m32 $(CPPFLAGS) -std=gnu90 -Wall -Wextra -Wno-unknown-pragmas -Wno-format-security -Wno-main -DNON_MATCHING -DAVOID_UB

N64CRC := tools/n64crc

OBJCOPY := mips-linux-gnu-objcopy
OBJCOPY_FLAGS = --pad-to=0x800000 --gap-fill=0xFF
STRIP := mips-linux-gnu-strip

DUMMY != make -C tools

PYTHON := python3
POSTPROCESS = $(PYTHON) tools/postprocess_asm.py


default: all

$(GLOBAL_ASM_O_FILES): CC = $(PYTHON) asm-processor/build.py tools/ido/cc -- $(AS) $(ASFLAGS) --

$(BUILD_DIR)/%.o: %.s $(SZP_FILES)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.bin
	$(LD) -r -b binary -o $@ $<

$(BUILD_DIR)/%.o : %.c
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) $(CFLAGS) -o $@ $<
	$(STRIP) $@ -N $(<:.i=.c)

$(BUILD_DIR)/src/main_BFC30.o $(BUILD_DIR)/src/main_C51B0.o $(BUILD_DIR)/src/main_CCE70.o $(BUILD_DIR)/src/main_CDE10.o $(BUILD_DIR)/src/main_CE030.o $(BUILD_DIR)/src/main_D3BE0.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_BEF70.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_CA710.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_CE110.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CE6D0.o $(BUILD_DIR)/src/main_CE700.o $(BUILD_DIR)/src/main_D3B60.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D0830.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CCD30.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D3A60.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C4070.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_12A20.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_5070.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C4800.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C4910.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CEE20.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C8520.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D0390.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D04D0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D09D0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CEBF0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D3AB0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CF570.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D2370.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D0B90.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C76C0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D4900.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C75F0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CD0D0.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_CE070.o: OPT_FLAGS := -O2 -Wo,-loopunroll,0
$(BUILD_DIR)/src/main_D0860.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_D20B0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D24B0.o: OPT_FLAGS := -O2
$(BUILD_DIR)/src/main_D2170.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CEEF0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CE880.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CE980.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CEB80.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_CF5C0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CF720.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CFCD0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D2070.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D3630.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_D3730.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_D4800.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_D4850.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_D3FA0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_4CA0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_4950.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_3680.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_35A0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_4D60.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_5AE70.o: OPT_FLAGS := -O2 -g3
$(BUILD_DIR)/src/main_5B650.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_848E0.o: OPT_FLAGS := -O2 -g3
$(BUILD_DIR)/src/main_90710.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_94770.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B7610.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_B7970.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B7F00.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B5C0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B630.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B1E0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B41D0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_A3D70.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_19080.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_12300.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_2BA10.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_17F10.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_18390.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_350B0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_48CB0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_C04F0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C0660.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C0730.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C6490.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C6630.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C6700.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CDE90.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_B9940.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B9E00.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_B9EC0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_BA000.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_BD1D0.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_BFAE0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C36B0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C0830.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C48B0.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_CDFD0.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_D0C00.o: OPT_FLAGS := -O3
$(BUILD_DIR)/src/main_C3CE0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_C7300.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CE730.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_BED70.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_BEAA0.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_BEA10.o: OPT_FLAGS := -O1 -g3
$(BUILD_DIR)/src/main_CDF90.o: OPT_FLAGS := -O1
$(BUILD_DIR)/src/main_CE070.o: SIGNED_FLAG :=
$(BUILD_DIR)/src/main_D3BE0.o $(BUILD_DIR)/src/main_CF940.o: SIGNED_FLAG :=
$(BUILD_DIR)/src/main_C4710.o: OPT_FLAGS := -O3

$(BUILD_DIR)/%.szp: %.bin
	tools/slienc $< $@

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT)
	$(CPP) $(VERSION_CFLAGS) -Umips -MMD -MP -MT $@ -MF $@.d -o $@ $< \
	-DBUILD_DIR=$(BUILD_DIR)

$(BUILD_DIR)/$(TARGET).elf: $(BUILD_DIR)/$(LD_SCRIPT) $(O_FILES) $(I_FILES)
	$(LD) $(LDFLAGS) -o $@ -Map $(BUILD_DIR)/$(TARGET).map

# final z64 updates checksum
$(BUILD_DIR)/$(TARGET).z64: $(BUILD_DIR)/$(TARGET).elf $(SZP_FILES)
	$(OBJCOPY) $< $@ -O binary $(OBJCOPY_FLAGS)
	$(N64CRC) $@

all: $(BUILD_DIR)/$(TARGET).z64
	@sha1sum -c superman.sha1

clean:
	rm -rf $(BUILD_DIR)

test:
	~/Downloads/mupen64plus/mupen64plus-gui $(BUILD_DIR)/$(TARGET).z64

inventory:
	$(PYTHON) tools/verify_inventory.py

report:
	$(PYTHON) tools/generate_decomp_report.py

verify-history:
	$(PYTHON) tools/verify_history.py

hexedit:
	wine ~/.wine/drive_c/Program\ Files/HxD/HxD.exe baserom.z64

.PHONY: all clean default diff test inventory report verify-history distclean

# Remove built-in rules, to improve performance
MAKEFLAGS += --no-builtin-rules

print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true

