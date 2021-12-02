This program implements the unification algorithm in C++
Compile: "g++ assign1ssz389.cpp -o assign1ssz389"
Sample run: "assign1ssz389 "f(f(X,Y),X),f(f(V,U),g(U,Y))""   --- provide both the terms inside double quotes with a comma in between as shown in sample run.

Examples:


hercules[67]% g++ assign1ssz389.cpp -o assign1ssz389
hercules[68]% assign1ssz389 "a,X"
...checking input syntax
...finding terms
Term1 = a Term2 = X
Type(term1) = 2 Type(term2) = 1
        X = a
        yes
hercules[69]% assign1ssz389 "X,Y"
...checking input syntax
...finding terms
Term1 = X Term2 = Y
Type(term1) = 1 Type(term2) = 1
        Y = X
        yes
hercules[70]% assign1ssz389 "X,f(Y)"
...checking input syntax
...finding terms
Term1 = X Term2 = f(Y)
Type(term1) = 1 Type(term2) = 3
        X = f(Y)
        yes
hercules[71]% assign1ssz389 "X,h(a,Y)"
...checking input syntax
...finding terms
Term1 = X Term2 = h(a,Y)
Type(term1) = 1 Type(term2) = 3
        X = h(a,Y)
        yes
hercules[72]% assign1ssz389 "f(f(X,Y),X),f(f(V,U),g(U,Y))"
...checking input syntax
...finding terms
Term1 = f(f(X,Y),X) Term2 = f(f(V,U),g(U,Y))
Type(term1) = 3 Type(term2) = 3
        V = g(U,U)
        X = g(U,U)
        Y = U
        yes
hercules[73]% assign1ssz389 "a,a"
...checking input syntax
...finding terms
Term1 = a Term2 = a
Type(term1) = 2 Type(term2) = 2
        yes
hercules[74]% assign1ssz389 "a,b"
...checking input syntax
...finding terms
Term1 = a Term2 = b
Type(term1) = 2 Type(term2) = 2
        no
hercules[75]%
