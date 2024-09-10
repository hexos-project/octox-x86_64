mmp=$(cat ver/mmp.txt)
mls=$(cat ver/mls.txt)

echo "#pragma once" > include/config.hh
echo >> include/config.h
echo "#define MMP \"$mmp\"" >> include/config.hh
echo "#define MLS \"$mls\"" >> include/config.hh

mls=$((mls + 1))

echo "$mls" > ver/mls.txt
