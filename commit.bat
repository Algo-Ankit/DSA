@echo off
cd /d %~dp0

REM Stage all changes
git add .

REM Commit with timestamp
set datetime=%date% %time%
git commit -m "Auto-commit on %datetime%"

REM Detect branch (main or master)
for /f "delims=" %%b in ('git symbolic-ref --short HEAD') do set branch=%%b

REM Push to GitHub
git push origin %branch%

pause
