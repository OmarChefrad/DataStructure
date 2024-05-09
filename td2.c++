#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int jour, mois, an;
} date;

typedef struct etudiant {
    char nom[20], cne[20], filiere[5];
    date dateNs;
    int semestre;
    float notes[6];
    struct etudiant *suivant;
} etudiant;

typedef struct {
    etudiant *premier;
} List_Etd;

// Fonction pour créer une liste vide
List_Etd* creer_liste_vide() {
    List_Etd *liste = (List_Etd*)malloc(sizeof(List_Etd));
    liste->premier = NULL;
    return liste;
}

// Fonction pour insérer un étudiant au début de la liste
void ajout_debut(List_Etd *liste, etudiant *nouveau_etudiant) {
    nouveau_etudiant->suivant = liste->premier;
    liste->premier = nouveau_etudiant;
}

// Fonction pour insérer un étudiant à la fin de la liste
void ajout_fin(List_Etd *liste, etudiant *nouveau_etudiant) {
    etudiant *courant = liste->premier;
    if (courant == NULL) {
        liste->premier = nouveau_etudiant;
        return;
    }
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    courant->suivant = nouveau_etudiant;
    nouveau_etudiant->suivant = NULL;
}

// Fonction pour insérer un étudiant au milieu de la liste
void ajout_milieu(List_Etd *liste, etudiant *nouveau_etudiant, int position) {
    if (position == 1) {
        ajout_debut(liste, nouveau_etudiant);
        return;
    }
    etudiant *courant = liste->premier;
    int i = 1;
    while (courant != NULL && i < position - 1) {
        courant = courant->suivant;
        i++;
    }
    if (courant == NULL) {
        printf("Position invalide\n");
        return;
    }
    nouveau_etudiant->suivant = courant->suivant;
    courant->suivant = nouveau_etudiant;
}

// Fonction pour afficher tous les éléments de la liste
void afficher(List_Etd *liste) {
    etudiant *courant = liste->premier;
    while (courant != NULL) {
        printf("Nom: %s, CNE: %s, Filiere: %s, Semestre: %d\n", courant->nom, courant->cne, courant->filiere, courant->semestre);
        courant = courant->suivant;
    }
}

// Fonction pour calculer et retourner le nombre des éléments d'une liste
int nb_elm(List_Etd *liste) {
    int count = 0;
    etudiant *courant = liste->premier;
    while (courant != NULL) {
        count++;
        courant = courant->suivant;
    }
    return count;
}

// Fonction pour rechercher si un étudiant existe parmi les éléments de la liste
// Retourne la position de cet élément s'il est trouvé et -1 sinon
int chercher_position(List_Etd *liste, char cne[]) {
    int position = 1;
    etudiant *courant = liste->premier;
    while (courant != NULL) {
        if (strcmp(courant->cne, cne) == 0) {
            return position;
        }
        courant = courant->suivant;
        position++;
    }
    return -1;
}

// Fonction pour copier les éléments de L qui sont inscrits en S4 dans L_S4
void semestre4(List_Etd *L, List_Etd *L_S4) {
    etudiant *courant = L->premier;
    while (courant != NULL) {
        if (courant->semestre == 4) {
            etudiant *nouveau_etudiant = (etudiant*)malloc(sizeof(etudiant));
            memcpy(nouveau_etudiant, courant, sizeof(etudiant));
            nouveau_etudiant->suivant = NULL;
            ajout_fin(L_S4, nouveau_etudiant);
        }
        courant = courant->suivant;
    }
}

int main() {
    // Déclaration de la liste vide L
    List_Etd *L = creer_liste_vide();

    // Code pour remplir la liste L avec des étudiants...

    // Déclaration de la liste vide L_S4
    List_Etd *L_S4 = creer_liste_vide();

    // Code pour appeler la fonction semestre4 et copier les étudiants de L inscrits en S4 dans L_S4...

    return 0;
}
