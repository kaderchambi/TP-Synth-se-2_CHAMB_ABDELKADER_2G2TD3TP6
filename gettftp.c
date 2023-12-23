#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>  

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <serveur> <fichier>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *serveur = argv[1];
    char *fichier = argv[2];

    // Utilisation de getaddrinfo pour obtenir l'adresse du serveur
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(serveur, "tftp", &hints, &result);
    if (status != 0) {
        fprintf(stderr, "Erreur lors de la résolution de l'adresse: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // result maintenant contient les informations sur l'adresse.

    freeaddrinfo(result);

    return 0;
}

