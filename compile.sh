#!/bin/bash

#================================================================
#   
#   
#   文件名称：compile.sh
#   创 建 者：肖飞
#   创建日期：2022年10月31日 星期一 16时50分42秒
#   修改日期：2024年01月13日 星期六 09时51分33秒
#   描    述：
#
#================================================================
function main() {
	# bash ./libs/build_deps_all.sh
	mkdir -p build;
	pushd build;
	cmake -GNinja -DCMAKE_BUILD_TYPE=Release ..
	ninja -j4 -d keepdepfile
	popd
	# bash ./libs/deploy_linux64.sh
}

main $@
