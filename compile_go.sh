#!/bin/bash

#================================================================
#   
#   
#   文件名称：compile_go.sh
#   创 建 者：肖飞
#   创建日期：2023年11月05日 星期日 12时21分14秒
#   修改日期：2023年11月05日 星期日 13时11分45秒
#   描    述：
#
#================================================================
set -x
function main() {
	export GOOS=linux
	export GOARCH=amd64
	#proxychains bash libs/get_source.sh
	bash libs/build_go.sh
	#bash libs/build_public_res.sh
}

main $@
