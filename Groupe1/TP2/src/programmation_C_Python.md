1. Debeugage

En C avec gdb

gdb est l’outil principal de débogage en C. Il permet de placer des points d'arrêt, d'inspecter les variables, d’exécuter le code ligne par ligne, et d'analyser la pile d'appels.

En Python avec pdb

pdb est le débogueur intégré pour Python. Il offre une interface interactive similaire à gdb.

Python permet un débogage souvent plus simple grâce à son interpréteur qui ne nécessite pas de compilation. L'exécution peut être démarrée directement dans le débogueur.

Résumé : Le débogage en C exige une étape de compilation avec des informations supplémentaires, tandis que Python permet un débogage plus fluide en raison de son interprétation dynamique.

2. Chaîne de Compilation

En C avec gcc

Prétraitement (gcc -E) : Expansion des macros et inclusion des fichiers d’en-tête.
Compilation (gcc -S) : Traduction du code source en langage assembleur.
Assemblage (gcc -c) : Conversion du code assembleur en code machine (objet).
Édition des liens (gcc) : Assemblage des fichiers objets et des bibliothèques en un exécutable.
Exemple :
gcc -o programme programme.c

En Python

Python ne nécessite pas de compilation explicite. Le code source est directement interprété par l’interpréteur Python, ou compilé en bytecode (fichier .pyc) pour une exécution plus rapide lors de l'importation de modules.
Gestion des modules : Python charge les modules dynamiquement lors de leur importation avec des instructions comme import.

Résumé : Le processus en C est plus complexe et nécessite des étapes spécifiques de compilation, alors que Python simplifie cela avec une gestion dynamique des modules.

3. Inspection de Code

En C

Pour inspecter le code compilé en C, des outils sont utilisés pour examiner les symboles, les sections de mémoire et les instructions en assembleur.

En Python avec dis

Python dispose du module dis pour désassembler le bytecode Python et permettre l'inspection du code exécuté par l’interpréteur.
avec import dis


Résumé : En C, l'inspection s'effectue au niveau de l'assembleur et des symboles du fichier binaire. En Python, dis permet une inspection à un niveau plus abstrait, au niveau du bytecode.


Conclusion
La programmation en C est centrée sur le contrôle fin des ressources et des performances, ce qui est idéal pour des applications à faible niveau. En revanche, Python privilégie la simplicité d’utilisation et la productivité, au prix d'une gestion automatique de la mémoire et de performances légèrement moindres dans certaines situations. -->