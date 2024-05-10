fonction inserer(liste, element):
    si liste est vide:
        insérer element comme premier élément de la liste
    sinon:
        pour chaque élément dans la liste:
            si élément > element:
                insérer element avant cet élément
                retourner
        insérer element à la fin de la liste

fonction afficherPile(P):
    si estVide(P):
        afficher "La pile est vide"
    sinon:
        pour chaque élément dans la pile:
            afficher donnee(élément)

fonction desempilerKelt(P, k):
    pour i allant de 1 à k:
        si estVide(P):
            retourner
        desempiler(P)


fonction defilerJusqua(F, elt):
    tant que non estVide(F):
        si premier(F) = elt:
            retourner
        sinon:
            defiler(F)
