/*  _____   _____ ____    ___   ___ ___  ____
 * |  __ \ / ____/ __ \  |__ \ / _ \__ \|___ \
 * | |__) | |   | |  | |    ) | | | | ) | __) |
 * |  ___/| |   | |  | |   / /| | | |/ / |__ <
 * | |    | |___| |__| |  / /_| |_| / /_ ___) |
 * |_|     \_____\____/  |____|\___/____|____/
 */

#include "locomotivebehavior.h"
#include "ctrain_handler.h"

void LocomotiveBehavior::run()
{
    //Initialisation de la locomotive
    loco.allumerPhares();
    loco.demarrer();
    loco.afficherMessage("Ready!");

    /* A vous de jouer ! */

    // Vous pouvez appeler les méthodes de la section partagée comme ceci :
    //sharedSection->access(loco);
    //sharedSection->leave(loco);
    //sharedSection->stopAtStation(loco);

    while(true) {
        // On attend qu'une locomotive arrive sur le contact 1.
        // Pertinent de faire ça dans les deux threads? Pas sûr...

        if(loco.numero() == 7){ // rouge
            attendre_contact(25);
            loco.afficherMessage("J'ai atteint le contact 25");
            attendre_contact(24);
            loco.afficherMessage("J'ai atteint le contact 24");

            // rentre dans la section partager
            sharedSection->access(loco);

            attendre_contact(23);
            loco.afficherMessage("J'ai atteint le contact 23");
            attendre_contact(16);
            loco.afficherMessage("J'ai atteint le contact 16");
            attendre_contact(15);
            loco.afficherMessage("J'ai atteint le contact 15");

            // sort de la section critique
            sharedSection->leave(loco);

            attendre_contact(14);
            loco.afficherMessage("J'ai atteint le contact 14");
            attendre_contact(7);
            loco.afficherMessage("J'ai atteint le contact 7");
            attendre_contact(6);
            loco.afficherMessage("J'ai atteint le contact 6");
            attendre_contact(5);
            loco.afficherMessage("J'ai atteint le contact 5");
            attendre_contact(33);
            loco.afficherMessage("J'ai atteint le contact 33");
            attendre_contact(32);
            loco.afficherMessage("J'ai atteint le contact 32");

            loco.arreter();
            loco.afficherMessage("Fin du tour");

        }
        if(loco.numero() == 42){ // bleu
            attendre_contact(22);
            loco.afficherMessage("J'ai atteint le contact 22");

            // Changer l'aiguillage 16 et 15
            //diriger_aiguillage(16, DEVIE, 0);
            //diriger_aiguillage(15, TOUT_DROIT, 0);

            attendre_contact(24);
            loco.afficherMessage("J'ai atteint le contact 24");

            // rentre dans la section partager
            sharedSection->access(loco);

            attendre_contact(23);
            loco.afficherMessage("J'ai atteint le contact 23");
            attendre_contact(16);
            loco.afficherMessage("J'ai atteint le contact 16");
            attendre_contact(15);
            loco.afficherMessage("J'ai atteint le contact 15");

            // sort de la section critique
            sharedSection->leave(loco);

            // changer l'aiguillage 8 et 9


            attendre_contact(10);
            loco.afficherMessage("J'ai atteint le contact 10");
            attendre_contact(4);
            loco.afficherMessage("J'ai atteint le contact 4");
            attendre_contact(3);
            loco.afficherMessage("J'ai atteint le contact 3");
            attendre_contact(2);
            loco.afficherMessage("J'ai atteint le contact 2");
            attendre_contact(1);
            loco.afficherMessage("J'ai atteint le contact 1");
            attendre_contact(31);
            loco.afficherMessage("J'ai atteint le contact 31");
            attendre_contact(30);
            loco.afficherMessage("J'ai atteint le contact 30");
            attendre_contact(29);
            loco.afficherMessage("J'ai atteint le contact 29");
            attendre_contact(28);
            loco.afficherMessage("J'ai atteint le contact 28");

            loco.arreter();
            loco.afficherMessage("Fin du tour.");

        }
    }
}

void LocomotiveBehavior::printStartMessage()
{
    qDebug() << "[START] Thread de la loco" << loco.numero() << "lancé";
    loco.afficherMessage("Je suis lancée !");
}

void LocomotiveBehavior::printCompletionMessage()
{
    qDebug() << "[STOP] Thread de la loco" << loco.numero() << "a terminé correctement";
    loco.afficherMessage("J'ai terminé");
}
