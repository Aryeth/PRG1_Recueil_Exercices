# Opérations sur le type char

Que va afficher le programme C++ suivant ?

~~~cpp
char x = 'A'; // 65
char y = '0'; // 48
char z;

z = x + 4;
//z = 69 (E)

cout << "1. " << z << endl;
// prints E
cout << "2. " << ++z << endl;
// prints F

z = x + 0;
//z = 65 (E)
cout << "3. " << z << endl;
// prints E

z = x + '0';
cout << "4. " << z << endl;
// prints A0 X FALSE prints q because '0' = 48 -> 48 + 65 = 113 = 'q'
~~~




    

<details>
<summary>Solution</summary>

1. E   
2. F
3. A
4. q
   



</details>
