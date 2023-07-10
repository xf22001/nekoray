#!/bin/bash

#================================================================
#   
#   
#   文件名称：cscope.sh
#   创 建 者：肖飞
#   创建日期：2019年11月14日 星期四 14时26分48秒
#   修改日期：2022年06月09日 星期四 13时47分53秒
#   描    述：
#
#================================================================
function main() {
	rm cscope e_cs -rf
	mkdir -p cscope
	tags.sh prepare;
	touch dep_files;

	touch raw_dep_files;
	for f in $(find . -type f -a \( -name "*.d" \) 2>/dev/null); do
		cat "$f" >> raw_dep_files;
	done;
	for i in $(cat "raw_dep_files" | sed 's/^.*://g' | sed 's/[\\ ]/\n/g' | sort -h | uniq); do
		if test "${i:0:1}" = "/";then
			echo "$i" >> dep_files;
		else
			readlink -f "$i" >> dep_files;
		fi;
	done;
	rm raw_dep_files

	cat dep_files | sort | uniq >> dep_files.tmp;

	mv dep_files.tmp dep_files

	cat dep_files | sort | uniq | sed 's/^\(.*\)$/\"\1\"/g' >> cscope/cscope.files;
	cat dep_files | sort | uniq >> cscope/ctags.files;
	rm dep_files
	tags.sh cscope;
	tags.sh tags;
	tags.sh env;
}

main $@
