# Evaluation d'expressions - Opérateurs logiques

Que va afficher le programme C++ suivant ?

~~~cpp
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

   int i, j, k;

   i = j = k = 1;
   i += j += k;
   // j = 2, i = 3, k = 1 CORRECT
   cout << "A : i = " << i << " j = " << j << " k = " << k << endl;
   // prints i = 3 j = 2 k = 1
   
   i = 3; j = 2;
   k = i++ > j || j++ != 3;
   // k = true (1) i = 4 j = 2 CORRECT
   cout << "B : i = " << i << " j = " << j << " k = " << k << endl;
   
   i = 3; j = 2;
   k = i++ < j || j++ != 3;
   // i = 3, j = 3, k = true (1) FAUX -> j = 4 car i++ <j = false -> on passe quand meme par le coté droite du ou
   cout << "C : i = " << i << " j = " << j << " k = " << k << endl;

   i = 3; j = 2;
   k = ++i == 3 && ++j == 3;
   //i = 4 j = 2 , k = false (0) CORRECT
   cout << "D : i = " << i << " j = " << j << " k = " << k << endl;

   i = 3; j = 2;
   k = ++i > 3 && ++j == 3;
   //i = 4, j = 3, k = true (1) CORRECT
   cout << "E : i = " << i << " j = " << j << " k = " << k << endl;
     
   return EXIT_SUCCESS;
}


~~~




    

<details>
<summary>Solution</summary>

- A : i = 3 j = 2 k = 1
- B : i = 4 j = 2 k = 1
- C : i = 4 j = 3 k = 1
- D : i = 4 j = 2 k = 0
- E : i = 4 j = 3 k = 1



</details>