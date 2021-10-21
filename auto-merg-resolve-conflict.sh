#!/bin/bash
# 通用脚本头
set -e #出错退出
# set -x #输出所有
set -u #确保所有变量都初始化
set -o errexit
# 通用脚本头结束
git merge dev --no-ff -m "Merge branch 'dev' into 'master'" && true
if [ $? -ne 0 ]; then
    echo "Auto Merging conflict, Ready to accept theirs"
    find ./ -name "gitTutor" -exec git checkout --theirs {} \;
    git add .
    git commit -m "Merge branch 'dev' into 'master' with accepting theirs"
    git push
fi
git status
exit 0
