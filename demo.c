#include <stdio.h>
#include "dansketal.h"  
#include "demo_ui.c"   

#define BUFFER_SIZE 256

// Funktion til at printe faste testeksempler
void faste_eksempler() {
    char buffer[BUFFER_SIZE];
    int tal;

    // Test 1: Tallet 125
    tal = 125;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "et hundrede og femogtyve"

    // Test 2: Tallet -1001
    tal = -1001;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "minus et tusinde og en"

    // Test 3: Tallet 999999
    tal = 999999;
    buffer[0] = '\0'; 
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "ni hundrede nioghalvfems tusinde ni hundrede nioghalvfems"

    // Test 4: Tallet 99
    tal = 99;
    buffer[0] = '\0'; 
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "nioghalvfems"

    // Test 5: Tallet 21
    tal = 21;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "enogtyve"

    // Test 6: Tallet 100
    tal = 100;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "et hundrede"

    // Test 7: Tallet 1000000
    tal = 1000000;
    buffer[0] = '\0'; 
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "en million"

    // Test 8: Tallet 13579
    tal = 13579;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%d -> %s\n", tal, buffer);  // Forventet: "tretten tusinde fem hundrede og nioghalvfjerds"
}

// Funktion til at konvertere et brugerdefineret tal og udskrive dets tekst
void bruger_valgte_tal() {
    char buffer[BUFFER_SIZE];
    int brugerTal;

    printf("Indtast et heltal (positiv eller negativ): ");
    scanf("%d", &brugerTal);

    buffer[0] = '\0';  
    dansketal(brugerTal, buffer);
    printf("%d -> %s\n", brugerTal, buffer);  
}

int main() {
    char choice;

    
    while (1) {
        printMenu();  
        scanf(" %c", &choice);  

        if (choice == '1') {
            printf("\nDu har valgt: Faste testeksempler\n");
            faste_eksempler();
        } else if (choice == '2') {
            printf("\nDu har valgt: Vælg dine egne tal\n");
            bruger_valgte_tal();
        } else if (choice == 'Q' || choice == 'q') {
            printf("Afslutter programmet.\n");
            break;
        } else {
            printf("Ugyldigt valg! Benyt 1, 2 eller Q\n");
        }
    }
    return 0;
}
