#!/bin/bash

echo "script initialized!"

timestamp=$(date "+%Y-%m-%d %H:%M:%S")
user=$(hostname)
gstat=$(git status)

read -p "enter the commit message and use '' apostophes: " msg

if [ -z "$msg" ]; then
	echo "Commit message cannot be empty!"
	exit 1
else
	echo "All good!"
fi

rm -f gmon.out

git add .
git commit -m "$msg"

echo "$timestamp | $user - status before: $gstat | commit message: $msg" >> git_automation.log
echo "next step is to push the content of this git repository"

echo "script finished"
