# README for A.Y. Chernov

How to use (OK, maybe how I use it):
____
### How to start Python with MyString class quick and easy:

1. Go to the folder where the .py and .pyd files are stored (TestPython/TestPython/_hello.pyd, TestPython/TestPython/hello.py). Command: 
>\>python

hello - name of module (I know this is bad, but I was too lazy to rename it).

2. Command:
>\>>>import hello

Now you can use MyString objects. The example below.
____
### How to use constructors:

1. Don't forget the module name.
>\>>>test = hello.MyString()

>\>>>test = hello.MyString("lala")

>\>>>test = hello.MyString(4, 'c')

etc.  
**BUT!** You can't use initializer_list constructor. 
____
### How to use operator= with different data types:

1. MyString = char:
>\>>>test.equal_c('c') 
2. MyString = cchar_array[]:
>\>>>test.equal_char_array("arrayofchar")
3. MyString = std::string:
>\>>>test.equal_std_string("stringstd");
____
### How to print MyString variable:
>\>>>print (variable)

or

>\>>>print (variable.c_str()) 
____
### How to use operator+ with different data types:
1. MyString is always on the left:
>\>>>test1 = "kfkf"

>\>>>test2 = hello.MyString("lala")

>\>>>test3 = test2 + test1. 

![cmd](https://github.com/Draft00/MyString_withPython/blob/main/images/cmd.PNG)
