#!/bin/bash

echo "script initialized!"

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

echo "next step is to push the content of this git repository"

echo "script finished"
