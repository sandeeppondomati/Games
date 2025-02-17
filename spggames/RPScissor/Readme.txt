Description: Rock-Paper-Scissor Game
             its built on mac, uses spgames(sandeep pondomati games) namespace

1) How to compile?
[Run] make all

2) How to clean?
[Run] make clean

3) How to clean and compile?
[Run] make clean all

4) How to run? 
[Run] ./game 

5) Known tradeoffs (on time constraints)
   5.1) Files are not organised in hierarchy -  this will help create the shared libs, dividing the common files and readability
   5.2) templates are not initialised separately - this will avoid code bloat however template is iniatialised in a only one translation unit in this task
   5.3) Unit tests are not added - integration tests are run to success
   5.4) Decorators need a clean up - to minimise use of manual formating further, parameteries int type templates and fine tuned streaming
   5.5) This task is done with a assumption as the requirement was minimum - single player vs computer, only single game scores are maintained at any point in time nd GUI is limited to command line menu. 
   5.5) Analyse more Patterns for extensibility
