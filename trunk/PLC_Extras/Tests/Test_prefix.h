// ===========================================================================
// Test_prefix.h
//                       Created: 2006-11-04 18:16:25
//             Last modification: 2007-09-10 19:13:29
// Author: Bernard Desgraupes
// e-mail: <bdesgraupes@users.sourceforge.net>
// www: <http://sourceforge.net/projects/plistcompiler>
// (c) Copyright: Bernard Desgraupes 2006-2007
// All rights reserved.
// ===========================================================================
// This is a prefix file to test the -prefix command line option introduced
// in version 0.5 of PList Compiler.
// 
// This must be tested from the command line:
//     plcompile -prefix Test_prefix.h Test_prefix.plc
//     
// Prefix files can also be soft links. This can be tested with the
// Test_link_prefix.h file which is a soft link to the present file.
//     plcompile -prefix Test_link_prefix.h Test_prefix.plc
//     


#define PLC_Identifier "net.sourceforge.plistcompiler"

#define PREFIX_FILE_FOUND  1

#pragma output_filename "prefix.list"

#if __YEAR__ > 2000
#define TWENTY_FIRST_CENTURY "21st century"
#endif

#ifdef TWENTY_FIRST_CENTURY
#warning "Brave new world!"
#endif

#if "[file exists /Volumes/im2/Devel/Code/PListCompiler/PListCompiler_Devel/PLC_Extras/Tests/Test_pragmas.plc]"
#warning "File exists!"
#endif


/* Some instructions that PLC does not support */
#pragma once          uponthetime

#pragma optimize_for_size off

#pragma mark - 

#pragma section pintab end


/* Deliberately putting instructions that PLC does not understand */

// Note;
// PLC_DEBUG should be defined in the shell:
//     export PLC_DEBUG=0
// It is also possible to pass it via the -D option:
//     plcompile -DPLC_DEBUG=0 -prefix Test_prefix.h Test_prefix.plc
//
//     
// If it is set to 1, errors will follow
// If it is set to 0, processing should be ok

#if PLC_DEBUG == 1
	#ifdef __cplusplus
	extern "C" {
	#endif
		extern long gEnvironment;
		void *	ckcalloc(size_t nmemb, size_t size);
		extern Boolean gUnitTesting;
	#ifdef __cplusplus
	}
	#endif
#endif
	
// Unknown preprocessor macros are silently ignored
#bernardo is_undefined