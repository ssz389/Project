/*******************************************************************
*Name: Suby Singh
*File: README file 
*Description: A demostration to generate RB instances for CSP
*
*Compile: "g++ assign2ssz389.cpp -o assign2ssz389"
*Sample run: "assign2ssz389"   --- Follow the execution for program input
*
*Please note : For some CSP cases, there can be no solution. This is due to random generation of constraints over the variables and domains. You can also enter lower value for p(tightness) and check the result. I have shown below two examples for the same.
*
*
*********************************************************************/
Sample run:

hercules[6]% g++ assign2ssz389.cpp -o assign2ssz389
venus[41]% assign2ssz389
Enter number of variables                         : 4

Enter the value for tightness                     : 0.33

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 3
Constraint size(c), (n*r*log(n))                  : 4
no of Incompatible pairs(ip), (p*d^2)             : 3

Variables    :    {X0, X1, X2, X3}
Domain of the variable    :
   X0 : { 0,  1,  2}
   X1 : { 0,  1,  2}
   X2 : { 0,  1,  2}
   X3 : { 0,  1,  2}

Constraints :       Incompatible pairs
   (X1, X3)   :   [(1,1), (2,0), (0,0)]
   (X2, X0)   :   [(2,0), (1,1), (0,0)]
   (X3, X0)   :   [(0,2), (2,1), (2,2)]
   (X3, X2)   :   [(0,0), (2,2), (2,1)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 1

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  0
    X1  :  1
    X2  :  1
    X3  :  0

Time measured : 0 seconds.
venus[42]% assign2ssz389
Enter number of variables                         : 4

Enter the value for tightness                     : 0.33

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 3
Constraint size(c), (n*r*log(n))                  : 4
no of Incompatible pairs(ip), (p*d^2)             : 3

Variables    :    {X0, X1, X2, X3}
Domain of the variable    :
   X0 : { 0,  1,  2}
   X1 : { 0,  1,  2}
   X2 : { 0,  1,  2}
   X3 : { 0,  1,  2}

Constraints :       Incompatible pairs
   (X1, X3)   :   [(1,1), (2,0), (0,0)]
   (X2, X0)   :   [(2,0), (1,1), (0,0)]
   (X3, X0)   :   [(0,2), (2,1), (2,2)]
   (X3, X2)   :   [(0,0), (2,2), (2,1)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 2

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  0
    X1  :  1
    X2  :  1
    X3  :  0

Time measured : 0 seconds.
venus[43]% assign2ssz389
Enter number of variables                         : 4

Enter the value for tightness                     : 0.3

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 3
Constraint size(c), (n*r*log(n))                  : 4
no of Incompatible pairs(ip), (p*d^2)             : 3

Variables    :    {X0, X1, X2, X3}
Domain of the variable    :
   X0 : { 0,  1,  2}
   X1 : { 0,  1,  2}
   X2 : { 0,  1,  2}
   X3 : { 0,  1,  2}

Constraints :       Incompatible pairs
   (X1, X3)   :   [(1,1), (2,0), (0,0)]
   (X2, X0)   :   [(2,0), (1,1), (0,0)]
   (X3, X0)   :   [(0,2), (2,1), (2,2)]
   (X3, X2)   :   [(0,0), (2,2), (2,1)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 3

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  0
    X1  :  1
    X2  :  1
    X3  :  0

Time measured : 0 seconds.
venus[44]% assign2ssz389
Enter number of variables                         : 6

Enter the value for tightness                     : 0.33

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 4
Constraint size(c), (n*r*log(n))                  : 8
no of Incompatible pairs(ip), (p*d^2)             : 5

Variables    :    {X0, X1, X2, X3, X4, X5}
Domain of the variable    :
   X0 : { 0,  1,  2,  3}
   X1 : { 0,  1,  2,  3}
   X2 : { 0,  1,  2,  3}
   X3 : { 0,  1,  2,  3}
   X4 : { 0,  1,  2,  3}
   X5 : { 0,  1,  2,  3}

Constraints :       Incompatible pairs
   (X1, X4)   :   [(2,2), (1,3), (1,0), (3,2), (1,1)]
   (X2, X1)   :   [(2,1), (2,3), (2,0), (3,2), (3,0)]
   (X3, X1)   :   [(1,3), (0,1), (2,0), (3,2), (1,2)]
   (X4, X0)   :   [(0,3), (0,1), (2,1), (1,1), (3,0)]
   (X5, X0)   :   [(1,0), (0,0), (0,1), (2,1), (1,1)]
   (X5, X1)   :   [(3,0), (0,1), (2,2), (1,0), (1,1)]
   (X5, X2)   :   [(2,2), (2,3), (3,2), (3,1), (1,2)]
   (X5, X4)   :   [(0,2), (0,0), (3,3), (2,3), (3,0)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 1

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  0
    X1  :  0
    X2  :  0
    X3  :  0
    X4  :  0
    X5  :  2

Time measured : 0 seconds.
venus[45]% assign2ssz389
Enter number of variables                         : 8

Enter the value for tightness                     : 0.25

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 5
Constraint size(c), (n*r*log(n))                  : 12
no of Incompatible pairs(ip), (p*d^2)             : 6

Variables    :    {X0, X1, X2, X3, X4, X5, X6, X7}
Domain of the variable    :
   X0 : { 0,  1,  2,  3,  4}
   X1 : { 0,  1,  2,  3,  4}
   X2 : { 0,  1,  2,  3,  4}
   X3 : { 0,  1,  2,  3,  4}
   X4 : { 0,  1,  2,  3,  4}
   X5 : { 0,  1,  2,  3,  4}
   X6 : { 0,  1,  2,  3,  4}
   X7 : { 0,  1,  2,  3,  4}

Constraints :       Incompatible pairs
   (X1, X3)   :   [(1,4), (4,2), (3,4), (0,0), (3,1), (1,0)]
   (X1, X5)   :   [(3,0), (2,3), (1,3), (3,4), (3,1), (4,4)]
   (X1, X7)   :   [(1,3), (2,0), (1,1), (0,0), (4,2), (1,0)]
   (X2, X3)   :   [(2,0), (1,3), (4,2), (1,1), (4,4), (0,0)]
   (X2, X4)   :   [(1,4), (3,2), (4,0), (2,0), (4,2), (4,4)]
   (X3, X0)   :   [(4,2), (2,1), (2,3), (1,0), (1,3), (4,4)]
   (X3, X6)   :   [(4,3), (2,1), (2,2), (1,2), (1,0), (1,1)]
   (X3, X7)   :   [(1,0), (3,0), (4,4), (2,1), (3,1), (2,0)]
   (X4, X0)   :   [(0,4), (4,4), (4,0), (1,2), (2,1), (1,0)]
   (X6, X2)   :   [(1,3), (3,0), (1,1), (1,0), (4,3), (3,4)]
   (X7, X5)   :   [(3,1), (2,4), (3,4), (0,3), (3,0), (0,4)]
   (X7, X6)   :   [(4,2), (2,3), (2,4), (3,1), (1,2), (4,3)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 3

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  0
    X1  :  1
    X2  :  0
    X3  :  3
    X4  :  0
    X5  :  0
    X6  :  0
    X7  :  2

Time measured : 0 seconds.
venus[46]% assign2ssz389
Enter number of variables                         : 8

Enter the value for tightness                     : 0.3

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 5
Constraint size(c), (n*r*log(n))                  : 12
no of Incompatible pairs(ip), (p*d^2)             : 8

Variables    :    {X0, X1, X2, X3, X4, X5, X6, X7}
Domain of the variable    :
   X0 : { 0,  1,  2,  3,  4}
   X1 : { 0,  1,  2,  3,  4}
   X2 : { 0,  1,  2,  3,  4}
   X3 : { 0,  1,  2,  3,  4}
   X4 : { 0,  1,  2,  3,  4}
   X5 : { 0,  1,  2,  3,  4}
   X6 : { 0,  1,  2,  3,  4}
   X7 : { 0,  1,  2,  3,  4}

Constraints :       Incompatible pairs
   (X1, X3)   :   [(0,0), (3,1), (1,0), (1,3), (2,0), (1,1), (4,2), (0,1)]
   (X1, X5)   :   [(4,3), (2,1), (2,2), (1,2), (1,0), (1,1), (0,4), (4,4)]
   (X1, X7)   :   [(1,4), (3,2), (4,0), (2,0), (4,2), (4,4), (3,0), (2,3)]
   (X2, X3)   :   [(0,4), (1,2), (2,1), (1,0), (4,2), (2,3), (0,1), (1,3)]
   (X2, X4)   :   [(1,3), (3,4), (3,1), (4,4), (2,0), (4,2), (1,1), (0,0)]
   (X3, X0)   :   [(4,4), (2,1), (3,1), (2,0), (4,1), (1,2), (2,3), (0,2)]
   (X3, X6)   :   [(4,4), (3,1), (2,4), (3,4), (0,3), (3,0), (0,4), (1,3)]
   (X3, X7)   :   [(2,0), (4,0), (0,4), (4,1), (4,2), (2,4), (2,2), (3,1)]
   (X4, X0)   :   [(3,0), (1,1), (1,0), (4,3), (3,4), (0,1), (0,3), (4,4)]
   (X6, X2)   :   [(3,3), (1,0), (4,3), (4,2), (2,1), (3,4), (0,3), (0,4)]
   (X7, X5)   :   [(4,1), (3,0), (4,2), (0,3), (3,3), (3,1), (3,4), (1,4)]
   (X7, X6)   :   [(4,2), (2,3), (2,4), (3,1), (1,2), (4,3), (1,4), (3,4)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 1

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************Solution not found***************

Time measured : 0 seconds.
venus[48]% assign2ssz389
Enter number of variables                         : 10

Enter the value for tightness                     : 0.3

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 6
Constraint size(c), (n*r*log(n))                  : 16
no of Incompatible pairs(ip), (p*d^2)             : 11

Variables    :    {X0, X1, X2, X3, X4, X5, X6, X7, X8, X9}
Domain of the variable    :
   X0 : { 0,  1,  2,  3,  4,  5}
   X1 : { 0,  1,  2,  3,  4,  5}
   X2 : { 0,  1,  2,  3,  4,  5}
   X3 : { 0,  1,  2,  3,  4,  5}
   X4 : { 0,  1,  2,  3,  4,  5}
   X5 : { 0,  1,  2,  3,  4,  5}
   X6 : { 0,  1,  2,  3,  4,  5}
   X7 : { 0,  1,  2,  3,  4,  5}
   X8 : { 0,  1,  2,  3,  4,  5}
   X9 : { 0,  1,  2,  3,  4,  5}

Constraints :       Incompatible pairs
   (X0, X6)   :   [(1,1), (5,2), (2,4), (4,4), (0,0), (3,3), (5,0), (2,3), (0,5), (2,5), (4,5)]
   (X0, X9)   :   [(4,5), (5,4), (5,5), (0,1), (2,1), (5,1), (3,1), (2,2), (3,3), (0,3), (2,4)]
   (X1, X2)   :   [(5,3), (3,4), (0,1), (2,4), (5,5), (3,2), (1,0), (4,4), (5,4), (1,1), (5,1)]
   (X1, X8)   :   [(4,0), (5,5), (2,4), (3,2), (0,2), (1,3), (3,4), (2,5), (2,0), (5,3), (4,2)]
   (X2, X0)   :   [(0,2), (0,0), (2,5), (3,4), (5,2), (3,5), (4,3), (1,2), (1,5), (5,4), (3,3)]
   (X2, X3)   :   [(1,0), (2,1), (2,2), (2,0), (4,2), (0,0), (0,1), (3,0), (5,2), (4,4), (3,3)]
   (X2, X7)   :   [(1,5), (5,4), (2,2), (1,2), (1,4), (2,4), (0,4), (5,2), (3,3), (5,1), (3,4)]
   (X2, X8)   :   [(0,4), (4,5), (2,1), (0,2), (4,0), (2,2), (1,3), (1,2), (4,2), (2,5), (2,0)]
   (X3, X5)   :   [(2,1), (0,0), (2,0), (1,4), (4,0), (0,5), (3,4), (2,4), (5,3), (5,2), (3,0)]
   (X3, X6)   :   [(3,5), (2,1), (2,2), (5,0), (5,4), (1,2), (2,3), (4,1), (3,3), (3,2), (2,5)]
   (X6, X2)   :   [(4,2), (1,2), (2,1), (3,5), (4,5), (4,3), (3,1), (5,3), (1,3), (3,4), (0,5)]
   (X7, X5)   :   [(4,3), (1,5), (0,3), (3,0), (2,3), (2,2), (3,2), (1,0), (0,2), (2,0), (3,5)]
   (X7, X9)   :   [(4,4), (5,4), (3,1), (1,0), (4,5), (0,2), (4,0), (0,5), (2,4), (2,0), (2,3)]
   (X9, X1)   :   [(4,5), (5,2), (4,3), (2,5), (3,5), (0,0), (5,4), (3,4), (0,5), (2,1), (2,3)]
   (X9, X2)   :   [(2,2), (0,5), (0,3), (1,0), (1,1), (5,1), (3,2), (2,5), (5,0), (5,2), (0,4)]
   (X9, X3)   :   [(2,1), (1,2), (0,3), (4,4), (4,2), (0,0), (0,1), (4,0), (3,1), (1,0), (2,3)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 2

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  1
    X1  :  0
    X2  :  0
    X3  :  2
    X4  :  0
    X5  :  2
    X6  :  4
    X7  :  1
    X8  :  0
    X9  :  2

Time measured : 0 seconds.
venus[49]% assign2ssz389
Enter number of variables                         : 10

Enter the value for tightness                     : 0.31

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 6
Constraint size(c), (n*r*log(n))                  : 16
no of Incompatible pairs(ip), (p*d^2)             : 11

Variables    :    {X0, X1, X2, X3, X4, X5, X6, X7, X8, X9}
Domain of the variable    :
   X0 : { 0,  1,  2,  3,  4,  5}
   X1 : { 0,  1,  2,  3,  4,  5}
   X2 : { 0,  1,  2,  3,  4,  5}
   X3 : { 0,  1,  2,  3,  4,  5}
   X4 : { 0,  1,  2,  3,  4,  5}
   X5 : { 0,  1,  2,  3,  4,  5}
   X6 : { 0,  1,  2,  3,  4,  5}
   X7 : { 0,  1,  2,  3,  4,  5}
   X8 : { 0,  1,  2,  3,  4,  5}
   X9 : { 0,  1,  2,  3,  4,  5}

Constraints :       Incompatible pairs
   (X0, X6)   :   [(1,1), (5,2), (2,4), (4,4), (0,0), (3,3), (5,0), (2,3), (0,5), (2,5), (4,5)]
   (X0, X9)   :   [(4,5), (5,4), (5,5), (0,1), (2,1), (5,1), (3,1), (2,2), (3,3), (0,3), (2,4)]
   (X1, X2)   :   [(5,3), (3,4), (0,1), (2,4), (5,5), (3,2), (1,0), (4,4), (5,4), (1,1), (5,1)]
   (X1, X8)   :   [(4,0), (5,5), (2,4), (3,2), (0,2), (1,3), (3,4), (2,5), (2,0), (5,3), (4,2)]
   (X2, X0)   :   [(0,2), (0,0), (2,5), (3,4), (5,2), (3,5), (4,3), (1,2), (1,5), (5,4), (3,3)]
   (X2, X3)   :   [(1,0), (2,1), (2,2), (2,0), (4,2), (0,0), (0,1), (3,0), (5,2), (4,4), (3,3)]
   (X2, X7)   :   [(1,5), (5,4), (2,2), (1,2), (1,4), (2,4), (0,4), (5,2), (3,3), (5,1), (3,4)]
   (X2, X8)   :   [(0,4), (4,5), (2,1), (0,2), (4,0), (2,2), (1,3), (1,2), (4,2), (2,5), (2,0)]
   (X3, X5)   :   [(2,1), (0,0), (2,0), (1,4), (4,0), (0,5), (3,4), (2,4), (5,3), (5,2), (3,0)]
   (X3, X6)   :   [(3,5), (2,1), (2,2), (5,0), (5,4), (1,2), (2,3), (4,1), (3,3), (3,2), (2,5)]
   (X6, X2)   :   [(4,2), (1,2), (2,1), (3,5), (4,5), (4,3), (3,1), (5,3), (1,3), (3,4), (0,5)]
   (X7, X5)   :   [(4,3), (1,5), (0,3), (3,0), (2,3), (2,2), (3,2), (1,0), (0,2), (2,0), (3,5)]
   (X7, X9)   :   [(4,4), (5,4), (3,1), (1,0), (4,5), (0,2), (4,0), (0,5), (2,4), (2,0), (2,3)]
   (X9, X1)   :   [(4,5), (5,2), (4,3), (2,5), (3,5), (0,0), (5,4), (3,4), (0,5), (2,1), (2,3)]
   (X9, X2)   :   [(2,2), (0,5), (0,3), (1,0), (1,1), (5,1), (3,2), (2,5), (5,0), (5,2), (0,4)]
   (X9, X3)   :   [(2,1), (1,2), (0,3), (4,4), (4,2), (0,0), (0,1), (4,0), (3,1), (1,0), (2,3)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 1

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************************Solution**************************
    X0  :  1
    X1  :  0
    X2  :  0
    X3  :  2
    X4  :  0
    X5  :  2
    X6  :  0
    X7  :  1
    X8  :  0
    X9  :  2

Time measured : 0 seconds.
venus[50]% assign2ssz389
Enter number of variables                         : 10

Enter the value for tightness                     : 0.33

Enter the value for alpha constant                : 0.8

Enter the value for r constant                    : 0.7

Domain size(d), (n^alpha)                         : 6
Constraint size(c), (n*r*log(n))                  : 16
no of Incompatible pairs(ip), (p*d^2)             : 12

Variables    :    {X0, X1, X2, X3, X4, X5, X6, X7, X8, X9}
Domain of the variable    :
   X0 : { 0,  1,  2,  3,  4,  5}
   X1 : { 0,  1,  2,  3,  4,  5}
   X2 : { 0,  1,  2,  3,  4,  5}
   X3 : { 0,  1,  2,  3,  4,  5}
   X4 : { 0,  1,  2,  3,  4,  5}
   X5 : { 0,  1,  2,  3,  4,  5}
   X6 : { 0,  1,  2,  3,  4,  5}
   X7 : { 0,  1,  2,  3,  4,  5}
   X8 : { 0,  1,  2,  3,  4,  5}
   X9 : { 0,  1,  2,  3,  4,  5}

Constraints :       Incompatible pairs
   (X0, X6)   :   [(4,5), (4,0), (5,5), (2,4), (3,2), (0,2), (1,3), (3,4), (2,5), (2,0), (5,3), (4,2)]
   (X0, X9)   :   [(3,3), (0,3), (2,4), (1,1), (5,2), (4,2), (4,4), (0,0), (5,0), (2,3), (0,5), (2,5)]
   (X1, X2)   :   [(4,0), (0,0), (1,2), (3,1), (2,1), (1,0), (2,3), (2,0), (0,5), (5,4), (1,1), (3,5)]
   (X1, X8)   :   [(4,4), (5,4), (3,1), (1,0), (4,5), (0,2), (4,0), (0,5), (2,4), (2,0), (2,3), (0,0)]
   (X2, X0)   :   [(2,0), (4,2), (0,0), (0,1), (3,0), (1,0), (5,2), (4,4), (3,3), (2,2), (0,5), (0,3)]
   (X2, X3)   :   [(1,0), (1,1), (5,1), (3,2), (2,5), (5,0), (5,2), (0,4), (4,0), (4,5), (2,1), (0,2)]
   (X2, X7)   :   [(5,2), (3,3), (5,1), (3,4), (4,5), (5,4), (5,5), (0,1), (2,1), (1,5), (3,1), (2,2)]
   (X2, X8)   :   [(3,2), (0,1), (4,4), (5,4), (1,1), (5,1), (2,1), (1,2), (0,3), (4,2), (0,0), (1,0)]
   (X3, X5)   :   [(2,0), (1,4), (4,0), (0,5), (3,4), (2,4), (5,3), (5,2), (3,0), (4,2), (1,2), (2,1)]
   (X3, X6)   :   [(3,5), (2,1), (2,2), (5,0), (5,4), (1,2), (2,3), (4,1), (3,3), (3,2), (2,5), (4,3)]
   (X6, X2)   :   [(3,5), (4,5), (4,3), (3,1), (5,3), (1,3), (3,4), (0,5), (5,4), (5,2), (2,5), (0,0)]
   (X7, X5)   :   [(1,5), (0,3), (3,0), (2,3), (2,2), (3,2), (1,0), (0,2), (2,0), (3,5), (2,1), (0,0)]
   (X7, X9)   :   [(2,5), (3,4), (5,2), (3,5), (4,3), (1,2), (1,5), (5,4), (3,3), (1,0), (2,1), (2,2)]
   (X9, X1)   :   [(4,5), (4,3), (0,5), (2,1), (2,3), (1,5), (5,4), (2,2), (1,2), (1,4), (2,4), (0,4)]
   (X9, X2)   :   [(4,0), (2,2), (1,3), (2,1), (4,2), (2,5), (0,2), (5,3), (3,4), (0,1), (2,4), (5,5)]
   (X9, X3)   :   [(5,4), (0,3), (2,4), (1,2), (3,3), (4,0), (2,3), (0,2), (2,1), (2,2), (4,2), (3,2)]

Please select a solving strategy from below list :
1. Standard Backtracking
2. Forward Checking
3. Full Look Ahead
Please select a number from 1 to 3 : 1

Check Arc-consistency before backtrack?? Enter (y/n) : y

The CSP is Arc-consistent.
****Finding Solution****
*************Solution not found***************

Time measured : 0 seconds.
venus[51]% 
