# ===========================================================================
# File: "AllTests.tcl"
#                        Created: 2005-12-13 08:40:32
#              Last modification: 2005-12-13 08:55:19
# Author: Bernard Desgraupes
# e-mail: <bdesgraupes@easyconnect.fr>
# www: <http://webperso.easyconnect.fr/bdesgraupes/>
# (c) Copyright: Bernard Desgraupes 2005
# All rights reserved.
# ===========================================================================

set initime [clock clicks -milliseconds]

if {[info exists ALPHA]} {
	set testdir [file dir [win::Current]]
} else {
	set testdir [file dir [info script]]
}

set PLComp [file normalize [file join $testdir ../../PLC_Sources/plcompile ]]

uplevel #0 {source [file join $testdir Fake_env.tcl]}
catch {uplevel #0 {source $PLComp}}

set testlist [glob -nocomplain -tail -dir $testdir Test_*.plc]

set plc_def(OUTPUT_FILENAME) MyTestApp
set plc_def(OUTPUT_TYPE) APPL
set plc_def(OUTPUT_CREATOR) ABCD


foreach test $testlist {
	set plc(debugfile) [file join $testdir $test]
	set plc_def(FILE) $plc(debugfile)
	set plc(input_file) $plc(debugfile)
	
	regexp {Test_(.*)\.plc} $test -> kind
	set plc(output_folder) [file join $testdir Output [string totitle $kind]]
	
	if {[catch {plc::processFile $plc(debugfile)} res]} {
		puts "Test '$kind' returned: \"$res\""
	} 
} 

set millisecs [expr {([clock clicks -milliseconds] - $initime)}]
puts "Tests executed in [eval expr {$millisecs.0/1000}] seconds\n"

