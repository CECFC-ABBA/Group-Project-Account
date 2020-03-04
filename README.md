# Group-Project-Account
This is a group project for the CECFC class 161. This Repository will have the main program, the classes, and derived classes for this project.
# *NOTE*
Define MAIN or FANCYMAIN in Account.h, but not both. This will determine what main function gets used.

# ERRORS
*Note* - Warning level 5, so not all warnings matter. All errors still do.
```1>------ Rebuild All started: Project: grp, Configuration: Debug Win32 ------
1>Source.cpp
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Account.cpp(23,15): error C2039: 'setMonths': is not a member of 'Account'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Account.h(4): message : see declaration of 'Account'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Account.cpp(24,5): error C2065: 'months': undeclared identifier
1>Source1.cpp
1>Source2.cpp
1>Source3.cpp
1>Source4.cpp
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(23,30): error C2146: syntax error: missing ';' before identifier 'savings'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(23,30): error C2065: 'savings': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(23,39): error C2275: 'HELOC': illegal use of this type as an expression
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\HELOC.h(22): message : see declaration of 'HELOC'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(23,45): error C2146: syntax error: missing ';' before identifier 'heloc'
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(23,45): error C2065: 'heloc': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(33,29): error C2109: subscript requires array or pointer type
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(61,17): error C2065: 'savings': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(67,17): error C2065: 'heloc': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(70,36): error C2065: 'savings': undeclared identifier
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Main.cpp(72,34): error C2065: 'heloc': undeclared identifier
1>Generating Code...
1>C:\Users\ajkmc\downloads\Group-Project-Account\Group-Project-Account-A\Savings.cpp(50): error C4700: uninitialized local variable 'e' used
1>Done building project "grp.vcxproj" -- FAILED.
========== Rebuild All: 0 succeeded, 1 failed, 0 skipped ==========```
