cd $SRCROOT
cd ..
testname="if_nested"
infoplist=${BUILT_PRODUCTS_DIR}/${CONTENTS_FOLDER_PATH}/Info.plist

if [ -f ${infoplist} ] ; then
	rm -f ${infoplist}
fi

./plcompile ../PLC_Extras/Tests/Test_${testname}.plc

if [ -f ${infoplist} ] ; then
	cp ${infoplist} ../PLC_Extras/Tests/Output/Info_${testname}.plist
fi
