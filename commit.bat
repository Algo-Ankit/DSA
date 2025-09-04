@echo off
cd /d %~dp0

REM Stage all changes
git add .

REM Ask for commit message
set /p msg=Enter commit message: 
if "%msg%"=="" set msg=Auto-commit on %date% %time%

REM Commit with your message (or auto if left blank)
git commit -m "%msg%"

REM Detect branch (main or master)
for /f "delims=" %%b in ('git symbolic-ref --short HEAD') do set branch=%%b

REM Push to GitHub
git push origin %branch%

pause
