#pragma once
#include <iostream>

enum FileState { NotEnable, ReadOnly, WriteOnly, ReadAndWrite };
enum Responce { Success, GenerateError, FileNotExist, SizeError, FileManagerFail, InputAndOutputIsEqual};

enum SeqType {Best, Average, Worst};
enum TypeOfSort {Bubble, Quick, Heap, Fail};