REM запуск программы без параметров
findtext.exe
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с одним параметром
findtext.exe file_name
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с пустой строкой в качестве одного из параметров
findtext.exe ""
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с пустой строкой в качестве одного из параметров
findtext.exe "test1.txt" ""
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы с несуществующим именем файла
findtext.exe -123
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы корректным параметром
findtext.exe "test1.txt" "строка" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result1.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы корректным параметром
findtext.exe "test1.txt" "строки" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result2.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы корректным параметром
findtext.exe "test1.txt" "длинная строка" > output.txt
IF NOT ERRORLEVEL 1 GOTO err

REM запуск программы корректным параметром
findtext.exe "test2.txt" "Все ушли" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result3.txt
IF ERRORLEVEL 1 GOTO err

REM запуск программы корректным параметром
findtext.exe "Onegin.txt" "скука" > output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt result4.txt
IF ERRORLEVEL 1 GOTO err

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
