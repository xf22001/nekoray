#!/bin/bash

#================================================================
#   
#   
#   文件名称：compile.sh
#   创 建 者：肖飞
#   创建日期：2022年10月31日 星期一 16时50分42秒
#   修改日期：2022年10月31日 星期一 17时00分37秒
#   描    述：
#
#================================================================
function main() {
	mkdir -p build;
	cd build;
	cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
}

main $@
