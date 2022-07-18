# programma-esame-informatica-prova
programma calcolo area/perimetro figure piane 

#####
READ ME

Programma per il calcolo di area e perimetro di tutte le figure piane note compilato in C tramite Xcode

Il programma è eseguibile tramite qualsiasi IDE per linguaggio C. 
Nella cartella è presente sia il progetto Xcode (.xcodeproj) che CodeBlocks (.cbp), dunque sarà sufficiente aprire il progetto con l'estensione corrispondente al programma con cui lo si vuole eseguire. In ogni caso è disponibile nella cartella anche il file main.c e vari .c e .h inclusi in esso.



ATTIVAZIONE E FUNZIONALITÀ DEL PROGRAMMA

Una volta aperto il progetto ed eseguito, il programma chiederà di quante figure (n figure) si vuole eseguire le operazioni per area e perimetro per un massimo di 30 figure. 
Figure disponibili:  rettangolo, triangolo, trapezio, rombo, quadrato, cerchio, poligoni regolari (fino al dodecagono).

Una volta terminato il calcolo delle n figure scelte, il programma stamperà tutti i risultati con gli eventuali errori.



DIAGNOSTICHE DI ERRORE

Il programma è in grado di restituire due tipologie di errore:  uno generico ed altri specifici. 

Nel caso di calcolo di più figure (n > 1) il  programma restituirà un errore generico -1 anche nel caso di un singolo errore in una della n figure 
(In ogni caso il programma alla stampa dei risultati farà noto in quale figura è presente l'errore). 

Se si desidera che il programma restituisca un errore specifico al termine dell'esecuzione ("Program ended with exit code:"), calcolare la singola figura della quale è stato reso noto precedentemente esserci un errore tra il calcolo delle n figure.

I vari codice errore sono definiti in "errore.h".



INTERRUZIONE DEL PROGRAMMA IN CORSO

È possibile interrompere l'esecuzione del programma inserendo "0" durante la selezione della figura da calcolare.

Così facendo il programma interromperà gli inserimenti successivi, stamperà quelli precedentemente già inseriti e ritornerà al menù "Continuare? Sì/No" dove si potrà scegliere se continuare con un nuovo inserimento oppure terminare il programma e restituire l'errore (eventuale) secondo le modalità precedentemente descritte in "DIAGNOSTICHE DI ERRORE".



GIT
Per scaricare l'ultima versione del codice accedere a https://github.com al seguente link: 
https://github.com/andreap0106/programma-esame-informatica
