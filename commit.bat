@echo off
:: Commit and push ONLY the DSA folder to GitHub

cd /d %~dp0

set /p msg="Enter commit message: "

git add DSA
git commit -m "%msg%"
git push origin main

pause
