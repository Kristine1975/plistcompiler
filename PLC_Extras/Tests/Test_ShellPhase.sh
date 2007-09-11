cd $SRCROOT
cd ..
testname="if_nested"
infoplist=${TARGET_BUILD_DIR}/${CONTENTS_FOLDER_PATH}/Info.plist

if [ -f ${infoplist} ] ; then
	rm -f ${infoplist}
fi

./plcompile -pkginfo -DPLC_DEBUG=1 ../PLC_Extras/Tests/Test_${testname}.plc

result=$?
if ! [ $result == 0 ] ; then
	exit 1 
fi
 
if [ -f ${infoplist} ] ; then
	cp ${infoplist} ../PLC_Extras/Tests/Output/Info_${testname}.plist
fi
