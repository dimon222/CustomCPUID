# CustomCPUID
DLL with function to identify AVX2 support

## What is this?
I was looking for way to identify AVX2 support in CPU at runtime in C# application. Sadly, .NET framework doesn't offer this low level API, but C++ does have such power. So this DLL is hacky way to inject such function in any language that can work with DLL Imported functions.

Example of usage in C# can be found [here](https://github.com/WFCD/WFinfo/commit/ab4bfc28616b098810afab21dfca94a506211c89)
