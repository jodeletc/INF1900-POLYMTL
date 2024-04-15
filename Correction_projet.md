# Polytechnique Montréal

Département de génie informatique et génie logiciel

INF1900: Projet initial de système embarqué

# Grille de correction des programmes:

Identification:
+ Travail    : Projet final
+ Section #  : 1
+ Équipe #   : 0626
+ Correcteur : Ghali Chraibi

# LISIBILITÉ
## En-têtes en début de programme   

| Pénalité par erreur                          | -1.5       |
| -------------------------------------------- | ---------- |
| Noms des auteurs                             |            |
| Description du programme                     |            |
| Identifications matérielles (Broches I/O)    |            |
| Table des états ou autres s'il y a lieu      |            |
| __Résultat partiel__                         | __(0.5/1.5)__ |

- Pas de description du programme ni n'identification matérielle dans les différents fichiers utilisés de votre librairie. Je ne retire pas tous les points vu que la description dans votre README est exhaustive. (-1)

## Identificateurs significatifs (Autodocumentation)

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de *chiffres magiques*               | (0/0.5)     |
| Noms de variables décrivent l'intention      | (0.1/0.5)     |
| Noms de fonctions décrivent l'intention      | (0.5/0.5)     |
| __Résultat partiel__                         | __(0.6/1.5)__ |

- Plusieurs chiffres magiques : `Dijkstra.cpp` lignes 16, 18, 167, 170, 171 `Robot.cpp` lignes 146, 148, 151, etc. (-0.5)

- Les noms des enum class doivent être en PascalCase: `selection`. (-0.1)
- Les noms des états doivent être significatifs: `LCBH`, `LCBV` ? (-0.1)
- Les variables et constantes doivent être encapsulées dans des classes ou des namespace afin de ne pas polluer l'espace global. (-0.2)
- Quelques noms de variables non significatifs: `_int_N`, `_on`, `_select`. (-0.1)

- Tous les noms de fonctions sont significatifs, bravo!

## Commentaires pertinents

Bonnes raisons d'un commentaire
 + Explication d'un algorithme 
 + Procédure peu évidente (ou *hack*)
 + Référence d'extraits de code copiés d'Internet
 + Détail du POURQUOI d'un extrait de code

| Pénalité par erreur                          | -0.5       |
| -------------------------------------------- | ---------- |
| __Résultat partiel__                         | __(0/1.0)__ |

- Plusieurs commentaires auraient pu être évités par des noms de variables significatifs ou des noms de fonctions implémentant le bloc commenté: `Navigation.cpp`, `Dijkstra.cpp`, etc. (-0.5)
- Beaucoup de code mort (-0.5)

## Indentation   

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Indentation structurée                       | (/0.5)     |
| Indentation uniforme dans le programme       | (/0.5)     |
| __Résultat partiel__                         | __(1/1.0)__ |


# MODULARITÉ ET COMPRÉHENSION
## Fonctions bien définies

| Pénalité par erreur                          | -0.5       |
| -------------------------------------------- | ---------- |
| Responsabilité unique d'une fonction         |            |
| Maximum de 4 paramètres                      |            |
| Absence de code dupliqué                     |            |
| etc                                          |            |
| __Résultat partiel__                         | __(0.5/1.0)__ |

- Pluiseurs fonctions manquent énormément de modularité. Il faudrait les séparer en plusieurs fonctions plus petites afin de faciliter la compréhension du code. (Ex: `_goForwardFirstLine`, `_goForwardSecondLine`, `_nextMove`, `_chooseRightTurn`, etc.) (-0.5)

## Bonne application des concepts de programmation et systèmes embarqués

| Pénalité par erreur                          | -1.0       |
| -------------------------------------------- | ---------- |
| Utilisation appropriée des registres         |            |
| Machine à états codée clairement             |            |
| Délais et minuteries utilisés judicieusement |            |
| PWM bien établi                              |            |
| Scrutation et interruptions bien utilisées   |            |
| etc                                          |            |
| __Résultat partiel__                         | __(3/4.0)__ |

- Il est nécessaire de toujours prioriser les bitshifts au lieu de valeurs magiques (en binaire ou en hexadécimal). Ex: `OUTER_LEFT = 0b00001` aurait dû être `OUTER_LEFT = 1 << PA0`. (Je ne retire que la moitié des points vu que cela a bien été fait dans la plupart des cas.) (-0.5)
- Il faut manipuler dans un registre que les bits pertinents pour votre mise en situation à l’aide des opérations `|=` et `&=`. On utilse le `=` que lorsqu’il est nécessaire d’écraser tout le registre: `Navigation.cpp` DDRD. (Encore une fois, je ne retire que la moitié des points vu que cela a bien été fait dans la plupart des cas.) (-0.5)

# FONCTIONNALITÉS
## Git

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Fichiers aux bons endroits                   | (/1.5)     |
| Absence de fichiers inutiles                 | (/1.5)     |
| __Résultat partiel__                         | __(3/3.0)__ |


## Compilation    

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de messages d'erreurs de compilation | (/1.5)     |
| Absence de messages d'attention (*warning*)  | (/0.5)     |
| __Résultat partiel__                         | __(1.5/2.0)__ |
   
- Beaucoup de warnings de compilation. (-0.5)

## Évaluation boîte noire  

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Cas normal de fonctionnement                 | (/2.5)     |
| Cas limites observables                      | (/2.5)     |
| __Résultat partiel__                         | __(5/5.0)__ |

# Résultat

__Total des points: 15.1/20__

# Commentaires du correcteur:

Votre projet montre une bonne compréhension de la programmation en systèmes embarqués. Vos machines à états sont bien pensées. Cependant, une meilleure documentation et une réduction des chiffres magiques seraient bénéfiques. Visez aussi une modularité accrue pour faciliter la maintenance. Bon travail global! 

Passez de belles fêtes et rechargez vos batteries pour cet hiver! 🌟

# Basé sur le commit suivant
```
commit 8474b406ddc0170d18bd7c71ad9af71c8a729c62
Author: Noah Blanchard <noah.blanchard@fastercom.ca>
Date:   Tue Dec 5 07:46:15 2023 -0500

    remove unnecessary'
```

# Fichiers indésirables pertinents
Aucun

# Tous les fichiers indésirables
```
tp/.DS_Store
tp/projet/.DS_Store
tp/projet/lib_dir/.DS_Store
tp/projet/lib_dir/libstatique.a
tp/tp9-code-comments/lib_dir/libstatique.a
tp/tp9/lib_dir/.DS_Store
tp/tp9/lib_dir/libstatique.a
```

# Sorties de `make` dans les sous-répertoires

## Sortie de `make` dans `projet/lib`
```
rm -f libstatique.a  LED.o Timer.o Bouton.o Wheel.o Navigation.o can.o IdentifyCorner.o Sound.o lcm_so1602dtr_m_fw.o lcm_so1602dtr_m.o customprocs.o LineMaker.o InfraRedSensor.o Robot.o MakeTrip.o Dijkstra.o *.d
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c LED.cpp
LED.cpp:12:46: warning: integer overflow in expression of type 'int' results in '0' [-Woverflow]
   12 | #define OVERFLOW_FREQ (CPU_FREQ / (PRESCALER * 256))
      |                                              ^
LED.cpp:15:32: note: in expansion of macro 'OVERFLOW_FREQ'
   15 | const uint8_t countsRequired = OVERFLOW_FREQ / 4;
      |                                ^~~~~~~~~~~~~
LED.cpp:12:33: warning: division by zero [-Wdiv-by-zero]
   12 | #define OVERFLOW_FREQ (CPU_FREQ / (PRESCALER * 256))
      |                                 ^
LED.cpp:15:32: note: in expansion of macro 'OVERFLOW_FREQ'
   15 | const uint8_t countsRequired = OVERFLOW_FREQ / 4;
      |                                ^~~~~~~~~~~~~
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Timer.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Bouton.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Wheel.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Navigation.cpp
Navigation.cpp: In member function 'Move Navigation::followTrip(Move*)':
Navigation.cpp:307:16: warning: enumeration value 'GO_BACK' not handled in switch [-Wswitch]
  307 |         switch (_tripState)
      |                ^
Navigation.cpp: In member function 'void Navigation::_nextMove()':
Navigation.cpp:424:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
  424 |         switch (*_currentOrientation)
      |                ^
Navigation.cpp: In member function 'void Navigation::_moveForward()':
Navigation.cpp:533:16: warning: enumeration value 'NO_LINE' not handled in switch [-Wswitch]
  533 |         switch (lineMakerFlag)
      |                ^
Navigation.cpp: In member function 'void Navigation::_moveForwardDelay()':
Navigation.cpp:590:16: warning: enumeration value 'NO_LINE' not handled in switch [-Wswitch]
  590 |         switch (lineMakerFlag)
      |                ^
Navigation.cpp:590:16: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:590:16: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:590:16: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
Navigation.cpp: In member function 'void Navigation::_turnRight()':
Navigation.cpp:688:16: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
  688 |         switch (lineMakerFlag)
      |                ^
Navigation.cpp:688:16: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:688:16: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:688:16: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
Navigation.cpp:688:16: warning: enumeration value 'LEFT_ADJUSTMENT' not handled in switch [-Wswitch]
Navigation.cpp: In member function 'void Navigation::_turnLeft()':
Navigation.cpp:732:16: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
  732 |         switch (lineMakerFlag)
      |                ^
Navigation.cpp:732:16: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:732:16: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:732:16: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
Navigation.cpp:732:16: warning: enumeration value 'RIGHT_ADJUSTMENT' not handled in switch [-Wswitch]
Navigation.cpp: In member function 'void Navigation::_chooseRightTurn()':
Navigation.cpp:783:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  783 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:783:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:783:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:804:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  804 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:804:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:804:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:825:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  825 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:825:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:825:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:846:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  846 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:846:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:846:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:868:16: warning: enumeration value 'EAST' not handled in switch [-Wswitch]
  868 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:868:16: warning: enumeration value 'WEST' not handled in switch [-Wswitch]
Navigation.cpp:868:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:889:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  889 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:889:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:889:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:910:16: warning: enumeration value 'EAST' not handled in switch [-Wswitch]
  910 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:910:16: warning: enumeration value 'WEST' not handled in switch [-Wswitch]
Navigation.cpp:910:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:931:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  931 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:931:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:931:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:952:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  952 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:952:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:952:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:973:16: warning: enumeration value 'EAST' not handled in switch [-Wswitch]
  973 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:973:16: warning: enumeration value 'WEST' not handled in switch [-Wswitch]
Navigation.cpp:973:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:993:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
  993 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:993:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:993:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:1014:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
 1014 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:1014:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:1014:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:1035:16: warning: enumeration value 'NORTH' not handled in switch [-Wswitch]
 1035 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:1035:16: warning: enumeration value 'SOUTH' not handled in switch [-Wswitch]
Navigation.cpp:1035:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
Navigation.cpp:1055:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
 1055 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp:1089:16: warning: enumeration value 'FINISHED' not handled in switch [-Wswitch]
 1089 |         switch (_nextMoveValue.orientation)
      |                ^
Navigation.cpp: In member function 'void Navigation::parking()':
Navigation.cpp:1135:20: warning: enumeration value 'NO_LINE' not handled in switch [-Wswitch]
 1135 |             switch (_lastCrossroad)
      |                    ^
Navigation.cpp:1135:20: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
Navigation.cpp:1135:20: warning: enumeration value 'LEFT_ADJUSTMENT' not handled in switch [-Wswitch]
Navigation.cpp:1135:20: warning: enumeration value 'RIGHT_ADJUSTMENT' not handled in switch [-Wswitch]
Navigation.cpp: In member function 'void Navigation::_turnLeft180()':
Navigation.cpp:1223:16: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
 1223 |         switch (lineMakerFlag)
      |                ^
Navigation.cpp:1223:16: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:1223:16: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:1223:16: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
Navigation.cpp:1223:16: warning: enumeration value 'RIGHT_ADJUSTMENT' not handled in switch [-Wswitch]
Navigation.cpp: In member function 'void Navigation::_turnRight180()':
Navigation.cpp:1272:16: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
 1272 |         switch (lineMakerFlag)
      |                ^
Navigation.cpp:1272:16: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:1272:16: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
Navigation.cpp:1272:16: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
Navigation.cpp:1272:16: warning: enumeration value 'LEFT_ADJUSTMENT' not handled in switch [-Wswitch]
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c can.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c IdentifyCorner.cpp
IdentifyCorner.cpp: In member function 'void IdentifyCorner::identificationProcess(uint8_t*)':
IdentifyCorner.cpp:18:16: warning: enumeration value 'FINISH' not handled in switch [-Wswitch]
   18 |         switch (_state)
      |                ^
IdentifyCorner.cpp: In member function 'void IdentifyCorner::_goForwardFirstLine()':
IdentifyCorner.cpp:87:12: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
   87 |     switch (flag)
      |            ^
IdentifyCorner.cpp: In member function 'void IdentifyCorner::_goBackFirstLine()':
IdentifyCorner.cpp:260:12: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
  260 |     switch (flag)
      |            ^
IdentifyCorner.cpp:260:12: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
IdentifyCorner.cpp:260:12: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
IdentifyCorner.cpp:260:12: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
IdentifyCorner.cpp: In member function 'void IdentifyCorner::_goInitPos()':
IdentifyCorner.cpp:286:12: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
  286 |     switch (flag)
      |            ^
IdentifyCorner.cpp:286:12: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
IdentifyCorner.cpp:286:12: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
IdentifyCorner.cpp:286:12: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
IdentifyCorner.cpp: In member function 'void IdentifyCorner::_goBackSecondLine()':
IdentifyCorner.cpp:340:12: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
  340 |     switch (flag)
      |            ^
IdentifyCorner.cpp:340:12: warning: enumeration value 'OUTER_RIGHT_DETECTION' not handled in switch [-Wswitch]
IdentifyCorner.cpp:340:12: warning: enumeration value 'OUTER_LEFT_DETECTION' not handled in switch [-Wswitch]
IdentifyCorner.cpp:340:12: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
IdentifyCorner.cpp: In member function 'void IdentifyCorner::_goForwardSecondLine()':
IdentifyCorner.cpp:426:12: warning: enumeration value 'NO_ADJUSTMENT' not handled in switch [-Wswitch]
  426 |     switch (flag)
      |            ^
IdentifyCorner.cpp:426:12: warning: enumeration value 'FULL_CROSSROAD' not handled in switch [-Wswitch]
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Sound.cpp
Sound.cpp:3: warning: "F_CPU" redefined
    3 | #define F_CPU 8000000
      | 
<command-line>: note: this is the location of the previous definition
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c lcm_so1602dtr_m_fw.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c lcm_so1602dtr_m.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c customprocs.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c LineMaker.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c InfraRedSensor.cpp
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Robot.cpp
In file included from Robot.cpp:1:
Robot.h: In constructor 'Robot::Robot()':
Robot.h:65:9: warning: 'Robot::_ledModule' will be initialized after [-Wreorder]
   65 |     LED _ledModule;
      |         ^~~~~~~~~~
Robot.h:63:20: warning:   'IdentifyCorner Robot::_identifyCornerModule' [-Wreorder]
   63 |     IdentifyCorner _identifyCornerModule;
      |                    ^~~~~~~~~~~~~~~~~~~~~
Robot.cpp:30:1: warning:   when initialized here [-Wreorder]
   30 | Robot::Robot() : _display(&DDRC, &PORTC), _navModule(_currentPosition, &_currentOrientation), _ledModule(&PORTB, &DDRB, PB6, PB7), _identifyCornerModule(&_ledModule), _maketripModule(&mbButtonPressed, &selButtonPressed, &valButtonPressed)
      | ^~~~~
In file included from Robot.cpp:1:
Robot.h:63:20: warning: 'Robot::_identifyCornerModule' will be initialized after [-Wreorder]
   63 |     IdentifyCorner _identifyCornerModule;
      |                    ^~~~~~~~~~~~~~~~~~~~~
Robot.h:62:14: warning:   'MakeTrip Robot::_maketripModule' [-Wreorder]
   62 |     MakeTrip _maketripModule;
      |              ^~~~~~~~~~~~~~~
Robot.cpp:30:1: warning:   when initialized here [-Wreorder]
   30 | Robot::Robot() : _display(&DDRC, &PORTC), _navModule(_currentPosition, &_currentOrientation), _ledModule(&PORTB, &DDRB, PB6, PB7), _identifyCornerModule(&_ledModule), _maketripModule(&mbButtonPressed, &selButtonPressed, &valButtonPressed)
      | ^~~~~
Robot.cpp: In member function 'void Robot::_navigateTripRoutine()':
Robot.cpp:128:14: warning: unused variable 'buffer' [-Wunused-variable]
  128 |         char buffer[28];
      |              ^~~~~~
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c MakeTrip.cpp
In file included from MakeTrip.cpp:9:
MakeTrip.h: In constructor 'MakeTrip::MakeTrip(volatile bool*, volatile bool*, volatile bool*)':
MakeTrip.h:46:13: warning: 'MakeTrip::_display' will be initialized after [-Wreorder]
   46 |         LCM _display;
      |             ^~~~~~~~
MakeTrip.h:35:24: warning:   'volatile bool* MakeTrip::_mbButtonPressed' [-Wreorder]
   35 |         volatile bool *_mbButtonPressed;
      |                        ^~~~~~~~~~~~~~~~
MakeTrip.cpp:11:1: warning:   when initialized here [-Wreorder]
   11 | MakeTrip::MakeTrip(volatile bool *mb, volatile bool *sel, volatile bool *val) : _display(&DDRC, &PORTC), _mbButtonPressed(mb), _selButtonPressed(sel), _valButtonPressed(val) {}
      | ^~~~~~~~
MakeTrip.cpp: In member function 'void MakeTrip::run(uint8_t*)':
MakeTrip.cpp:27:24: warning: enumeration value 'FINISH' not handled in switch [-Wswitch]
   27 |                 switch (_state)
      |                        ^
avr-gcc -I. -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c Dijkstra.cpp
Dijkstra.cpp: In member function 'void Dijkstra::run(uint8_t*, uint8_t*, Move*)':
Dijkstra.cpp:169:17: warning: unused variable 'result' [-Wunused-variable]
  169 |         uint8_t result = _dijkstraResult[indexR];
      |                 ^~~~~~
avr-ar rcs libstatique.a  LED.o Timer.o Bouton.o Wheel.o Navigation.o can.o IdentifyCorner.o Sound.o lcm_so1602dtr_m_fw.o lcm_so1602dtr_m.o customprocs.o LineMaker.o InfraRedSensor.o Robot.o MakeTrip.o Dijkstra.o
```

## Sortie de `make` dans `projet/app`
```
avr-gcc -I. -I/usr/include/simavr -MMD -I../lib -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall -DF_CPU=8000000UL -fno-exceptions -c main.cpp
avr-gcc -Wl,-Map,main.elf.map -mmcu=atmega324pa -L../lib -o main.elf  main.o \
-lm -lstatique
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
```
