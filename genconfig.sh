mmp=$(cat ver/mmp.txt)
mls=$(cat ver/mls.txt)

echo "#pragma once" > include/config.h
echo >> include/config.h
echo "#define MMP \"$mmp\"" >> include/config.h
echo "#define MLS \"$mls\"" >> include/config.h

mls=$((mls + 1))

echo "$mls" > ver/mls.txt
