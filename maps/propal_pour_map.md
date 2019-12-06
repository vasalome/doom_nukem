[ -> ouverture case
[X] 1 -> type de case
[X] 1 -> tex plafond
[X] 1 -> tex sol
[/] N -> Texture NORD
[/] E -> Texture EST
[/] S -> Texture SUD
[/] O -> Texture OUEST
[] 0 -> 1 ou 0 / cliping ou non
[] 1 -> 1 ou 0 / ray passe ou non // overdraw ?
[] 1.25 -> hauteur du sol
[] AJOUTER HAUTEUR DES MURS ?
[] 0 -> 1 ou 0 /plafond ou non
[] 2.25 -> hauteur plafond
[/] 1 -> 1 ou 0 / teleport ou non
[/] 10 11 A -> coordonnees si teleport x;y;direction A:meme_direction si != 'A' -> nouvelle_direction
[] 1 -> choix du son
[] 1 -> triggered case / voir interaction
] -> fermeture case

exemple: [1,0,1,1.25,1,2.25,N,E,S,O,1,10 11 A,1,1]