# NewAtCLI
Application CLI Window aidant les nouveaux progrmmeurs à utiliser leur terminal dans leur flow de travail.

## Description
Cette application CLI permet :

-make Rapidement créer un dossier et un fichier

-remember Liste de commandes que l'utilisateur veut pourvoir se rappeler rapidement

-todo Liste de tâche à accomplir(?Faire une liste par programme?)

-help

## Utilisation
### Formule d'appel: 

`NewAtCLI -option <argument1> ...`

*Vous pouvez utiliser des lettres majuscules ou minuscules
### Les options :
#### Make
`$ NewCli -Make <foldername> <filename>`
#### Remember
`$ NewCli -remember`

`$ NewCli -remember Add <texte>`

`$ NewCli -remember Remove <id>`

`$ NewCli -remember Modify <id>`
#### Todo
`$ NewCli -todo`

`$ NewCli -todo add <texte> <date>`

`$ NewCli -todo remove <id>`

`$ NewCli -todo modify <id>`

`$ NewCli -Help`
## Dev
Simplement utiliser les méthodes standard d'input et d'output.

Accèder aux arguments du main avec int argc et char* argv[]

Ajouter l'application dans les variables d'environnement(PATH) pour pouvoir appeler de nimporte quel fichier.

Création d'objet Remember et ToDo.

|  Remember |
|-----------|
|Id         |
|Text       |

| To do     |
|-----------|
| id        |
| Text      |
| Date      |
| Done      |

L'OOP n'est pas la meilleur approche mais permet de pratiquer mon OOP C++.

`make` pour compiler du dossier.

`make clean` pour effacer les .o créé par le compilateur.

`./NewAtCLI.exe` pour appeler.