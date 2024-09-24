# Modulo

Soient les déclarations suivantes :

~~~cpp
int i = 5, j = 11, n = 10;
double x = 5, y = 11;
~~~

Quel est le résultat d'évaluation des expressions suivantes ? en cas d'erreur, indiquez la raison.

| # | Expression  | Résultat                            |
|---|-------------|-------------------------------------|
| 1 | `j % i`     | 1                                   |
| 2 | `n % i`     | 0                                   |
| 3 | `y % x`     | erreur mod marche pas sur un double |
| 4 | `y % i`     | meme erreur                         |
| 5 | `-j % i`    | -1                                  |
| 6 | `n % ++i`   | 4                                   |
| 7 | `n++ % ++i` | 4                                   |

*! le modulo ne fonctionne PAS sur un double !*

<details>
<summary>Solution</summary>

| # | Expression  | Résultat |
|---|-------------|---|
| 1 | `j % i`     | 1 |
| 2 | `n % i`     | 0 |
| 3 | `y % x`     | Erreur, le modulo n'est pas défini pour les réels |
| 4 | `y % i`     | Erreur, le modulo n'est pas défini pour les réels |
| 5 | `-j % i`    | -1 |
| 6 | `n % ++i`   | 4 |
| 7 | `n++ % ++i` | 4 |


</details>
