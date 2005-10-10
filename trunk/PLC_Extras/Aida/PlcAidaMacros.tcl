# ===========================================================================
# File: "PlcAidaMacros.tcl"
#                        Created: 2005-10-05 15:39:47
#              Last modification: 2005-10-06 00:11:07
# Author: Bernard Desgraupes
# e-mail: <bdesgraupes@easyconnect.fr>
# www: <http://webperso.easyconnect.fr/bdesgraupes/>
# (c) Copyright: Bernard Desgraupes 2005
# All rights reserved.
# $Date$
# $Revision$
# ===========================================================================

namespace eval plc {}

proc plc::getVersion {} {
	global plc
	set aidafile [win::Current]
	catch {source [file normalize [file join [file dir $aidafile] ../../PLC_Sources/plcompile ]]}
	return $plc(version)
}