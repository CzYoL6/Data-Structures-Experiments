# 任务：
比较各种排序算法的绝对执行时间
内容：
用自己喜欢的编程语言实现折半插入排序、希尔排序（shell）、快速排序(quicksort)、二路归并排序（mergesort）、基数排序(Radixsort)，求出每种排序方法所需的绝对时间。

# 运行

在此目录下打开`Powershell`

```
./build/bin/main.exe 输入文件名 [true|false]
```

[true|false]表示显示结果（数据量较大时不建议），默认为false



**例**

```
./build/bin/main.exe ./TestInput.in true
```

**结果**

```
time consumption of shellsort:1
results of shellsort:
-19 -8 0 2 4 5 6 70 99 100
----------------------------------------------------------------------------------------------
time consumption of quicksort:0
results of quicksort:
-19 -8 0 2 4 5 6 70 99 100
----------------------------------------------------------------------------------------------
time consumption of insertsort:0
results of insertsort:
-19 -8 0 2 4 5 6 70 99 100
----------------------------------------------------------------------------------------------
time consumption of radixsort:1
results of radixsort:
19 30 38 40 42 43 44 108 137 138
----------------------------------------------------------------------------------------------
time consumption of mergesort:0
results of mergesort:
-19 -8 0 2 4 5 6 70 99 100
----------------------------------------------------------------------------------------------
```



# 项目结构

每个算法的实现：`./mylib/`

编译出来的windows可执行程序：`./build/bin/main.exe`