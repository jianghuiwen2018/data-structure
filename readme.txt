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

git 跟踪并管理的是修改而不是文件

这里用到了一个验证：
(1)修改reademe文件
（2)添加到缓存区
（3）修改reademe‘文件
（4）提交
结果：Git管理的是修改，当你用git add命令后，在工作区的第一次修改被放入暂存区，准备提交，但是，在工作区的第二次修改并没有放入暂存区，所以，git commit只负责把暂存区的修改提交了，也就是第一次的修改被提交了，第二次的修改不会被提交。

如何理解git跟踪修改：
每次修改，没有添加到缓存区的修改都不会被提交。

撤销修改


文件已修改，未add到暂存区:
git checkout -- file可还原

文件已修改，并add到暂存区未commit：
git read HEAD file
git checkout -- file可还原
git checkout --file的意思就是将工作区的版本设置成本地版本库最新的版本，然后清空
缓冲区。

场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令git checkout -- file。

场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令git reset HEAD file，就回到了场景1，第二步按场景1操作。

场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库。

如何删除文件？
git rm filename
rm file

删除文件之后如何恢复？
没有删除本地版本库文件之前：
git checkout --filename
不但删除了本地文件，而且删除了版本库文件：
只能恢复为当前版本，即HEAD所代表的最近提交的版本
这时就只能用：
git reset --hard HEAD

注意：
git checkout 代表的是将工作区的版本设置成本地最新版本，并清空缓存区。

有关git分支的概念艺理解：
git分支的作用是什么？
git分支产生的原因是什么？
可以说是git分支就是为了修改文件而产生的，
将主要文件保存在master分支上，
在修改文件的时候，不是直接到master分支上面进行修改，而是在新建的分支上进行修改，修改完成之后，合并到master分支上。

作用：
既保证了文件的修改进度，又可以保证文件的安全。

因为git分支的创建和删除是非常容易的，git鼓励用户使用分支完成任务，合并后在删除分支，这和在master分支上工作的效果是一样的，但是更安全。

分支的状态？
新的分支的状态是继承master分支当前的所有状态。

git 分支冲突的管理：
从其他分支转换到master分支的时候，master分支在没有进行合并的情况下继续进行提交，然后合并，这时就会产生冲突。

Dev提交了修改
master提交了修改
master和Dev合并-->把各自的修改合并起来。

一种情况就是：分支上产生多提交会如何？


git stash(存储当前文件)

git stash list 
git stash apply (恢复）
git stash drop(删除)
git stash pop(恢复并删除)
git stash apply stash@{0}
恢复制定的stash

    查看远程库信息，使用git remote -v；

    本地新建的分支如果不推送到远程，对其他人就是不可见的；

    从本地推送分支，使用git push origin branch-name，如果推送失败，先用git pull抓取远程的新提交；

    在本地创建和远程分支对应的分支，使用git checkout -b branch-name origin/branch-name，本地和远程分支的名称最好一致；

    建立本地分支和远程分支的关联，使用git branch --set-upstream branch-name origin/branch-name；

    从远程抓取分支，使用git pull，如果有冲突，要先处理冲突。
