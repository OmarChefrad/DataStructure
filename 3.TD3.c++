fonction inserer(liste, element):
    si liste est vide:
        insérer element comme premier élément de la liste
    sinon:
        pour chaque élément dans la liste:
            si élément > element:
                insérer element avant cet élément
                retourner
        insérer element à la fin de la liste

