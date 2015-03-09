# TCL File Generated by Component Editor 14.1
# Mon Mar 02 11:45:41 CET 2015
# DO NOT MODIFY


# 
# Timer "Timer" v1.3
#  2015.03.02.11:45:41
# 
# 

# 
# request TCL package from ACDS 14.1
# 
package require -exact qsys 14.1


# 
# module Timer
# 
set_module_property DESCRIPTION ""
set_module_property NAME Timer
set_module_property VERSION 1.3
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME Timer
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL Timer
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file Timer.vhd VHDL PATH vhdl/Timer.vhd TOP_LEVEL_FILE


# 
# parameters
# 


# 
# display items
# 


# 
# connection point clock
# 
add_interface clock clock end
set_interface_property clock clockRate 50000000
set_interface_property clock ENABLED true
set_interface_property clock EXPORT_OF ""
set_interface_property clock PORT_NAME_MAP ""
set_interface_property clock CMSIS_SVD_VARIABLES ""
set_interface_property clock SVD_ADDRESS_GROUP ""

add_interface_port clock Clk clk Input 1


# 
# connection point reset
# 
add_interface reset reset end
set_interface_property reset associatedClock clock
set_interface_property reset synchronousEdges DEASSERT
set_interface_property reset ENABLED true
set_interface_property reset EXPORT_OF ""
set_interface_property reset PORT_NAME_MAP ""
set_interface_property reset CMSIS_SVD_VARIABLES ""
set_interface_property reset SVD_ADDRESS_GROUP ""

add_interface_port reset Reset_n reset_n Input 1


# 
# connection point timer_slave_0
# 
add_interface timer_slave_0 avalon end
set_interface_property timer_slave_0 addressUnits WORDS
set_interface_property timer_slave_0 associatedClock clock
set_interface_property timer_slave_0 associatedReset reset
set_interface_property timer_slave_0 bitsPerSymbol 8
set_interface_property timer_slave_0 burstOnBurstBoundariesOnly false
set_interface_property timer_slave_0 burstcountUnits WORDS
set_interface_property timer_slave_0 explicitAddressSpan 0
set_interface_property timer_slave_0 holdTime 0
set_interface_property timer_slave_0 linewrapBursts false
set_interface_property timer_slave_0 maximumPendingReadTransactions 0
set_interface_property timer_slave_0 maximumPendingWriteTransactions 0
set_interface_property timer_slave_0 readLatency 0
set_interface_property timer_slave_0 readWaitTime 1
set_interface_property timer_slave_0 setupTime 0
set_interface_property timer_slave_0 timingUnits Cycles
set_interface_property timer_slave_0 writeWaitTime 0
set_interface_property timer_slave_0 ENABLED true
set_interface_property timer_slave_0 EXPORT_OF ""
set_interface_property timer_slave_0 PORT_NAME_MAP ""
set_interface_property timer_slave_0 CMSIS_SVD_VARIABLES ""
set_interface_property timer_slave_0 SVD_ADDRESS_GROUP ""

add_interface_port timer_slave_0 Address address Input 3
add_interface_port timer_slave_0 ChipSelect chipselect Input 1
add_interface_port timer_slave_0 Read read Input 1
add_interface_port timer_slave_0 Write write Input 1
add_interface_port timer_slave_0 ReadData readdata Output 32
add_interface_port timer_slave_0 WriteData writedata Input 32
set_interface_assignment timer_slave_0 embeddedsw.configuration.isFlash 0
set_interface_assignment timer_slave_0 embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment timer_slave_0 embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment timer_slave_0 embeddedsw.configuration.isPrintableDevice 0


# 
# connection point timer_irq
# 
add_interface timer_irq interrupt end
set_interface_property timer_irq associatedAddressablePoint ""
set_interface_property timer_irq associatedClock clock
set_interface_property timer_irq associatedReset reset
set_interface_property timer_irq bridgedReceiverOffset ""
set_interface_property timer_irq bridgesToReceiver ""
set_interface_property timer_irq ENABLED true
set_interface_property timer_irq EXPORT_OF ""
set_interface_property timer_irq PORT_NAME_MAP ""
set_interface_property timer_irq CMSIS_SVD_VARIABLES ""
set_interface_property timer_irq SVD_ADDRESS_GROUP ""

add_interface_port timer_irq IRQ irq Output 1

