#!/bin/bash
#================================================================
#   
#   
#   文件名称：compile.sh
#   创 建 者：肖飞
#   创建日期：2022年06月25日 星期六 12时46分01秒
#   修改日期：2022年06月25日 星期六 12时46分01秒
#   描    述：
#
#================================================================
version_standalone="nekoray-"$(cat ../nekoray_version.txt)
pushd /home/xiaofei/media/android/v2ray-core
version_v2ray=$(git log --pretty=format:'%h' -n 1)
popd
function main() {
	pushd cmd/nekoray_core/
	go build -v -trimpath -ldflags "-w -s -X neko/pkg/neko_common.Version_v2ray=$version_v2ray -X neko/pkg/neko_common.Version_neko=$version_standalone"
	popd
	pushd cmd/nekobox_core/
	go build -v -trimpath -ldflags "-w -s -X neko/pkg/neko_common.Version_neko=$version_standalone" -tags "with_gvisor,with_quic,with_wireguard"
	popd
}

main $@
