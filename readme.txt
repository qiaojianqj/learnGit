#Learn Git
#Git is a distributed version control system
#Git is free software distributed under the GPL Lisence
#Git tracks changes

#change the current dir to a repository that can be managed by git
git init  

#look up the status of the current repository
git status 

#look up the difference between the changed file and the previous committed file
git diff file

#add file to the repository stage
git add file

#commit the change of the current dir files to the repository's current branch
git commit -m "comments messages"

#display the committing log from nearest to farest
git log / git log --pretty=oneline

#display the git command you have executed on the repository
git reflog

#perform the repository back and forth
git reset --hard HEAD@{2}
git reset --hard 236f48e

#remove file from git repository
git rm file

#to discard changes in working directory
git checkout -- file

