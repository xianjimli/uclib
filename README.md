# uclib
---------------------
small library for c, includes array, map, string, obj, value, thread, mutex, file, event emitter...

C语言是我最常用的编程语言之一，不过对它也算是爱恨交加了，喜欢它的简洁和高效，但是经常需要重复造轮子。搜遍整个github，也没有找到我满意的C语言程序库。

趁这次计划开发FTK 2.0，把我需要的C语言程序库重新整理出来。uclib的主要特色有：

### 常用。
    
目前主要有：

* value : 一个通用数据类型，用来存放整数、浮点数、obj、str和其它对象。 

* array : 动态数组，根据数据项的个数自动扩展数组的长度。

* map : 存放key/value映射的容器，方便通过key查找value。

* obj : 通用的对象。提供通用的属性设置/获取函数，和事件注册/分发功能。

* emitter : 事件发射器。相当于观察者模式中被观察的对象，提供事件注册、注销和分发功能。

* str : 字符串对象。

* thread : 跨平台的线程对象。

* mutex  : 跨平台的互斥锁对象。

* file : 文件工具函数。

* date\_time : 时间相关函数。

### 可移植。
    
可以在Windows(VS 2008)、Linux和MacOS上编译和运行。

### 单元测试。

使用gtest为所有函数开发单元测试，保证程序库的可靠性。

### API文档。

使用jsduck格式为API编写注释。由于jsduck不能直接解析C语言头文件，所以先用工具(bin/extract\_doc)提取注释，然后在用jsduck生成文档。

文档入口：docs/index.html

### valgrind内存检查。

使用valgrind对程序进行内存检查，保证没有内存泄露和越界的问题。

### 方便JS绑定。

可以从jsduck格式的注释中提取API的描述，从而生成JS引擎需要的API，当然绑定到其它动态语言也可以的。后续将提供jerryscript的绑定工具。


