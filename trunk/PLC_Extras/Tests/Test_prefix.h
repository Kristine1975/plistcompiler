// ===========================================================================
// Test_prefix.h
//                       Created: 2006-11-04 18:16:25
//             Last modification: 2006-11-05 09:12:10
// Author: Bernard Desgraupes
// e-mail: <bdesgraupes@users.sourceforge.net>
// www: <http://sourceforge.net/projects/plistcompiler>
// (c) Copyright: Bernard Desgraupes 2006
// All rights reserved.
// ===========================================================================
// This is a prefix file to test the -prefix command line option introduced
// in version 0.5 of PList Compiler.
// 
// This must be tested from the command line:
//     ./plcompile -prefix $prefixFile $srcfile


#define PLC_Identifier "net.sourceforge.plistcompiler"

#define PREFIX_FILE_FOUND  1

#pragma output_filename "property.list"

#if __YEAR__ > 2000
#define TWENTY_FIRST_CENTURY
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


/* Some instructions that PLC does not understand */

// Note;
// the double underscores are needed here because we execute from the
// command line and PLC_DEBUG should be defined therefrom:
//     export PLC_DEBUG=1
#if __PLC_DEBUG__ == 1
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