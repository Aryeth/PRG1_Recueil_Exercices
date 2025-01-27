# Opérateurs

Que va afficher le programme C++ suivant ?


~~~cpp
// déclaration variable mais pas déclaration namespace ?
int i, j, k;

// i = 1, k = 0
i = 0; k = i++;

// prints : A : i = 1 k = 0
cout << "A : i = " << i << " k = " << k << endl;

// i = 2, k = 2
i = 1; k = ++i;
// prints : B : i = 2 k = 2
cout << "B : i = " << i << " k = " << k << endl;


i = 2; j = 3;
//k = 2*4 = 8, j = 4 i = 3
k = i++ * ++j;
// prints : C : i = 3 j = 4 k = 8
cout << "C : i = " << i << " j = " << j << " k = " << k << endl;


i = 3; j = 4;
// k = 3*3 = 9, j = 3, i = 9
k = i *= --j;
// prints D : i = 9 j = 3 k = 9
cout << "D : i = " << i << " j = " << j << " k = " << k << endl;

~~~

<details>
<summary>Solution</summary>

- A : i = 1 k = 0
- B : i = 2 k = 2
- C : i = 3 j = 4 k = 8
- D : i = 9 j = 3 k = 9


</details>