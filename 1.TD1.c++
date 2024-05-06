#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure date
typedef struct {
    int jour;
    int mois;
    int an;
} Date;

// Structure etudiant
typedef struct {
    char nom[21];
    char cne[21];
    Date dateNs;
    char filiere[50];
    int semestre;
    float notes[6];
} Etudiant;

// Tableau de 200 étudiants
Etudiant Tab_Etd[200];

// Fonction de saisie des informations d'un étudiant
void saisie(Etudiant *etd) {
    printf("Nom de l'etudiant: ");
    fgets(etd->nom, sizeof(etd->nom), stdin);
    printf("CNE de l'etudiant: ");
    fgets(etd->cne, sizeof(etd->cne), stdin);
    printf("Date de naissance (jour mois an): ");
    scanf("%d %d %d", &etd->dateNs.jour, &etd->dateNs.mois, &etd->dateNs.an);
    getchar(); // pour absorber le retour à la ligne restant dans le buffer
    printf("Filiere de l'etudiant: ");
    fgets(etd->filiere, sizeof(etd->filiere), stdin);
    printf("Semestre de l'etudiant: ");
    scanf("%d", &etd->semestre);
    printf("Notes des modules (separees par un espace): ");
    for (int i = 0; i < 6; i++) {
        scanf("%f", &etd->notes[i]);
    }
}

// Tableaux de 100 étudiants chacun pour les filières sma et smi
Etudiant Tab_sma[100];
Etudiant Tab_smi[100];

// Fonction de répartition des étudiants selon la filière
void par_filiere(Etudiant *Tab_Etd, int taille) {
    int index_sma = 0;
    int index_smi = 0;
    for (int i = 0; i < taille; i++) {
        if (strcmp(Tab_Etd[i].filiere, "sma\n") == 0) {
            Tab_sma[index_sma++] = Tab_Etd[i];
        } else if (strcmp(Tab_Etd[i].filiere, "smi\n") == 0) {
            Tab_smi[index_smi++] = Tab_Etd[i];
        }
    }
}

// Tableau de 100 étudiants pour le semestre S4
Etudiant Tab_S4[100];

// Fonction de répartition des étudiants selon le semestre
void par_semestre(Etudiant *Tab_Etd, int taille) {
    int index = 0;
    for (int i = 0; i < taille; i++) {
        if (Tab_Etd[i].semestre == 4) {
            Tab_S4[index++] = Tab_Etd[i];
        }
    }
}

// Fonction d'affichage des noms et notes des étudiants pour un module donné
void affichage_module(Etudiant *tab, int taille) {
    printf("Noms des etudiants avec leur note pour le module Structures de données:\n");
    for (int i = 0; i < taille; i++) {
        printf("%s : %.2f\n", tab[i].nom, tab[i].notes[1]); // Le deuxième module est à l'index 1
    }
}

// Fonction de validation d'un module pour un tableau donné
int valider_module(Etudiant *tab, int taille) {
    int count = 0;
    for (int i = 0; i < taille; i++) {
        if (tab[i].notes[1] >= 10.0) { // Le deuxième module est à l'index 1
            count++;
        }
    }
    return count;
}

int main() {
    // Exemple de saisie d'un étudiant
    Etudiant etudiant;
    printf("Saisie des informations d'un etudiant:\n");
    saisie(&etudiant);

    // Déclaration et initialisation du tableau Tab_Etd de 200 étudiants
    // (Les données peuvent être saisies par l'utilisateur ou générées automatiquement)
    // Pour simplifier, nous supposons que le tableau est déjà rempli pour les besoins de l'exemple.

    // Appel de la fonction de répartition des étudiants selon la filière
    par_filiere(Tab_Etd, 200);

    // Appel de la fonction de répartition des étudiants selon le semestre
    par_semestre(Tab_Etd, 200);

    // Appel de la fonction d'affichage des noms et notes des étudiants pour le module Structures de données
    affichage_module(Tab_Etd, 200);

    // Appel de la fonction de validation du module pour le tableau Tab_Etd
    int nb_etudiants_valides = valider_module(Tab_Etd, 200);
    printf("Nombre d'etudiants ayant valide le module Structures de donnees: %d\n", nb_etudiants_valides);

    return 0;
}
