REM запуск программы без параметров
solve.exe
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним параметром
solve.exe 2.2
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с двумя параметрами
solve.exe 2.3 -3.04
IF NOT ERRORLEVEL 1 GOTO err

REM коэффициент А = 0
findtext.exe 0 3 -4 
IF NOT ERRORLEVEL 1 GOTO err

REM действительных корней нет
findtext.exe 2 1 2
IF NOT ERRORLEVEL 1 GOTO err

REM корни равны
solve.exe 1 2 1 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM 2 корня
solve.exe 1 1 -2 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM 2 действительных корня
solve.exe 4.234 32.1983 -25.32 > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
               