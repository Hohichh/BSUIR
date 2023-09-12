@echo off

set "dir=%1"
set "user=%2"
set "date=%3"

If exist %dir% (

>NUL copy /y NUL result.txt 

echo "Look for result in result.txt" 
for /f "tokens=1-6* delims= " %%a in ('dir /a-d %dir% /q /tc /-c ^| findstr /rc:"[0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9]"') do (
     if /i "%%a"=="%date%" (
          if /i "%%e"=="%user%" (
               echo %%f >> result.txt
               
          )   
      ) 
)  


) ELSE (
echo "Folder does not exist"
)




	