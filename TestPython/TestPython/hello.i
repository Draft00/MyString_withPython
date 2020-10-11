%module hello

%{
#include "hello.h"
%}

using namespace std;


%include "std_string.i"
%include "std_list.i"
%include hello.h