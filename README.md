# Group-Project-Account
This is a group project for the CECFC class 161. This Repository will have the main program, the classes, and derived classes for this project.
# *NOTE*
Define MAIN or FANCYMAIN in Account.h, but not both. This will determine what main function gets used.

# ERRORS
*Note* - Warning level 5, so not all warnings matter. All errors still do.
```1>------ Rebuild All started: Project: grp, Configuration: Debug Win32 ------
1>Source.cpp
1>Source1.cpp
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(6,20): error C2597: illegal reference to non-static member 'Checking::intrest'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(6,29): error C2597: illegal reference to non-static member 'Checking::feeCost'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(6,11): error C7550: 'Checking::{ctor}': the qualified name in this context names a constructor, not a type
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(6,38): error C2448: 'Checking::{ctor}': function-style initializer appears to be a function definition
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(13,17): error C2541: 'delete': cannot delete objects that are not pointers
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(14,17): error C2541: 'delete': cannot delete objects that are not pointers
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(19,8): error C2065: 'balance': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(22,6): error C2065: 'fee': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(23,12): error C2065: 'bal': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(23,18): error C2065: 'fee': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(29,15): error C2065: 'fee': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(33,23): error C2440: 'return': cannot convert from 'std::string' to 'Checking Checking::* '
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Checking.cpp(33,9): message : No user-defined-conversion operator available that can perform this conversion, or the operator cannot be called
1>Source2.cpp
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Savings.cpp(37,6): warning C4806: '==': unsafe operation: no value of type 'bool' promoted to type 'char' can equal the given constant
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Savings.cpp(37,29): warning C4806: '==': unsafe operation: no value of type 'bool' promoted to type 'char' can equal the given constant
1>Source3.cpp
1>Source4.cpp
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(24,30): error C2146: syntax error: missing ';' before identifier 'savings'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(24,30): error C2065: 'savings': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(24,39): error C2275: 'HELOC': illegal use of this type as an expression
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\HELOC.h(19): message : see declaration of 'HELOC'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(24,45): error C2146: syntax error: missing ';' before identifier 'heloc'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(24,45): error C2065: 'heloc': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(34,29): error C2109: subscript requires array or pointer type
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(62,17): error C2065: 'savings': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(68,17): error C2065: 'heloc': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(71,36): error C2065: 'savings': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-1.00000\Main.cpp(73,34): error C2065: 'heloc': undeclared identifier
1>Source5.cpp
1>Generating Code...
1>Done building project "grp.vcxproj" -- FAILED.
========== Rebuild All: 0 succeeded, 1 failed, 0 skipped ==========```
