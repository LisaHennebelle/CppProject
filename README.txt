DAns les changements que j'ai fait:

tu peux créer une game automatiquement mais il faut créer les objets Smoke et les y ajouter, on pourra le rajouter dans le constructeur pour voir.

La fonctions isGameOver ne détermine pas la postion des objets quand ils sont déplacés... Il ne peut pas récupérer les flags générés par un ajout dans le sac, les objets qu'il teste doivent être des copies mais je n'arrive pas à détecter la faute.

J'ai rajouté une fonctionnalité: les objets reliés à la fumée changent de couleur quand on appuie sur la touche entree en plus d'afficher un qMessagebox

/!\ vu qu'on a rajouté un QObject, parfois ça bugue à la compilation, éxécute 'qmake' dans le menu 'Compiler' et l'affaire devrait être réglée

/!\ : j'ai rajouté une fonction qui permet d'afficher les objets en fonction de l'image correspondante dans les ressources 
 mais pour qu'elle fonctionne il faut faire comme suit:

	-creer un objet smoke ou objet dans la fonction addItems() ou addSmokeyItems() de game
	-le nommer (dans le constructeur : Objet *example = new Objet("example"); ou apres example->setName("example");
	-placer dans les ressources un fichier .png nommé COMME l'objet
	-Appeler la fonction addPixmapnew() qui lui associe immédiatement le fichier .png du même nom dans les ressources ( example -> addPixmapnew(); )
