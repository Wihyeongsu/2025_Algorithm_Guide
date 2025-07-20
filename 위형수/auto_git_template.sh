#!/bin/bash
yn="n"

while [ $yn == "n" -o $yn == "N" ]
do
    echo "(1/7) Enter your platform.(BOJ/PROGRAMMERS/LEETCODE)"
    read PLATFORM

    echo "(2/7) Enter problem name."
    read PROBLEM_NAME

    echo "(3/7) Enter problem number."
    read PROBLEM_NUMBER

    echo "(4/7) Enter difficulty."
    read DIFFICULTY

    echo "(5/7) Enter title."
    read TITLE

    echo "(6/7) Enter used language."
    read LANGUAGE

    COMMIT_MESSAGE="[$PLATFORM] $PROBLEM_NAME / $PROBLEM_NUMBER / $DIFFICULTY / $TITLE / $LANGUAGE"
    echo "(7/7) Is your commit message correct?(y/n):"
    echo $COMMIT_MESSAGE
    read yn
    while [ $yn != "Y" -a $yn != "y" -a $yn != "N" -a $yn != "n" ]
    do
        echo "Try again."
        read yn
    done
done

git commit -m "$COMMIT_MESSAGE"