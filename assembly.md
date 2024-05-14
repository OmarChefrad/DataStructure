# TP n°1 : Assembleur 8086/8088

## Objectif du TP
Se familiariser avec les registres du 8086 et certaines instructions de base.

## Présentation de DEBUG
DEBUG est un programme fourni avec MSDOS. Nous l'utiliserons pour :
1. Consulter/modifier les registres.
2. Afficher/modifier le contenu de la mémoire.
3. Éditer/exécuter des programmes élémentaires.

### Chargement de DEBUG sous Windows 32 bits
- Sous DOS : taper `DEBUG` + Entrée.
- Sous Windows : ouvrir une fenêtre DOS en tapant `cmd`, puis `DEBUG` + Entrée.

### Chargement de DEBUG sous Windows 64 bits
1. Télécharger le fichier "debugger.rar" [ici](https://drive.google.com/file/d/0B5e9xJJnxxM6RXo5Y0xybVRSOHM/view).
2. Extraire le fichier rar.
3. Copier `debug.com` sur le lecteur `C:\`.
4. Installer DosBox.
5. Exécuter les commandes suivantes dans DosBox :
    ```sh
    z:\ mount c c:\ 
    z:\ c: 
    c:\ debug 
    ```

### Consultation des registres du processeur
- Utiliser la commande `R` pour afficher les registres.
- Observer et noter les valeurs des registres CS et IP.
- Calculer l'adresse réelle représentée par le couple segment:offset (CS:IP) en décimal et en hexadécimal.
- Modifier un registre avec `R reg` (ex : `R AX`), entrer une valeur en hexadécimal (ex : `ABFD`), vérifier le contenu avec `R reg`.

### Édition de lignes de programme
- Initialiser `AX` à `0000`.
- Taper la commande `A 100` pour commencer à entrer un programme à l'adresse 100 du segment défini par CS.
- Entrer les instructions suivantes :
    ```assembly
    mov ax, a0a1
    mov bx, b0b1
    mov cx, c0c1
    mov dx, d0d1
    ```

### Désassembler la mémoire
- Utiliser la commande `U 100` pour vérifier que les lignes sont bien en mémoire.

### Exécuter des lignes de programme
- Utiliser la commande `t=100 4` pour exécuter 4 lignes de programme à partir de l'adresse `CS:100`.
- Observer l'évolution des registres `AX`, `BX`, `CX` et `DX`.
- Remettre les registres `AX`, `BX`, `CX` et `DX` à `0000` et lancer le programme avec `G=100 10C`.

### Scrutation de la mémoire
- Utiliser la commande `D 100` pour scruter la mémoire et vérifier les lignes de programme.
- Montrer que les 12 premiers octets correspondent au code des lignes de programme en utilisant l'annexe A.

## Exercices

### 1. Programme de sauvegarde dans la pile
```assembly
mov ax, 35
mov bx, 41
mov cx, 30
mov dx, 6
push ax
push bx
push cx
push dx
add ax, bx
add cx, dx
int 20
```
- Exécuter et vérifier les valeurs sauvegardées dans la pile.
- Conclusion sur l'ordre de stockage dans la pile et des parties hautes et basses des mots de 16 bits.

### 2. Programme d'addition
```assembly
mov al, 17
mov cl, 14
add cl, al
int 20
```
- Transcrire le programme en hexadécimal avec la commande `E`.

### 3. Affichage de BONJOUR
- Mettre `02` dans `AH` et le code ASCII du caractère dans `DL`, puis appeler l'interruption `int 21`.

### 4. Lecture et affichage d'un caractère
- Mettre `08` dans `AH` pour attendre un caractère tapé au clavier, qui sera alors dans `AL`, puis l'afficher avec `int 21`.

## Commandes de DEBUG
- **A (assemble)** : `A <adresse>`
- **C (compare)** : `C <bloc> <adresse>`
- **D (dump)** : `D <adresse>`
- **E (enter)** : `E <adresse> <liste d'octets>`
- **F (fill)** : `F <bloc> <liste d'octets>`
- **G (go)** : `G [=<adresse1>] [<adresse2>...]`
- **H (hexa)** : `H <mot1> <mot2>`
- **I (input)** : `I <port>`
- **L (load)** : `L <adresse> <disque> <secteur> <nombre de secteurs>`
- **M (move)** : `M <bloc> <adresse>`
- **N (name)** : `N <nom de fichier>`
- **O (output)** : `O <port> <octet>`
- **P (proceed)** : `P [=<adresse>] [<mot>]`
- **Q (quit)** : `Q`
- **R (registre)** : `R [<registre>]`
- **S (search)** : `S <bloc> <liste d'octets>`
- **T (trace)** : `T [=<adresse>] [<mot>]`
- **U (unassemble)** : `U <adresse>`
- **W (write)** : `W <adresse> <disque> <secteur> <nombre de secteurs>`
