#!/bin/bash
# oj dl "https://atcoder.jp/contests/${1:0:6}/tasks/${1:0:8}"
# oj dl "https://${1:0:6}.contest.atcoder.jp/tasks/${1:0:8}"
oj dl "https://atcoder.jp/contests/dp/tasks/${1:0:4}"
g++ -Wall -std=c++14 ./$1
oj test
rm -f a.out
rm -rf test
