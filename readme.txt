Git is a distrubuted version control system.
git is free software distributed under the GPL
git has a mutable index called stage
git tracks changes of files
版本回退的相关命令：
查询历史记录
git log
head 表示当前版本，也就是最新提交的版本
head ^-->往上一个版本
head ^^ -->往上两个版本
head~100  -->往上100个版本
.....

回到上一个版本：
git reset --hard HEAD^
hard是什么意思？
格式：
git reset --hard commit id

具体原理：
head只是一个指针，指针指向最近上传的文件
版本的回退其实就是指针的后移

那么有没有什么方法回退到任意版本呢？
git reflog 用来查询每一次的命令

