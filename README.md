# Liste d'attente prioritaire générique

Cet exemple montre une implémentation générique d'une liste d'attente générique utilisant une liste simplement chaînée.

L'implémentation comporte :

- Une routine d'initialisation d'une nouvelle file d'attente (`init`)
- L'ajout d'un élément dans la file d'attente (`push`)
- L'observation de l'élément le plus prioritaire (`front`)
- La récupération et la suppression de l'élément le plus prioritaire (`pop`)
- Le parcours de la liste avec une fonction de callback (`traverse`)

Le Makefile montre l'exemple de la construction d'une bibliothèque dynamqiue (`libqueue.so`).
