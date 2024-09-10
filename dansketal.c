#include <stdio.h>
#include <string.h>

// Arrays der indeholder ord for talrækkerne
const char* nulTilNi[] = {
    "nul", "en", "to", "tre", "fire", "fem", "seks", "syv", "otte", "ni"
};

const char* tiere[] = {
    "", "ti", "tyve", "tredive", "fyrre", "halvtreds", "tres", "halvfjerds", "firs", "halvfems"
};

const char* tiTilNitten[] = {
    "ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"
};

// Hjælpefunktion til at tilføje tekst til buffer
void append_to_buffer(char* buffer, const char* text) {
    strcat(buffer, text);
}

// Funktion til at konvertere heltal til dansk tekst
void dansketal(int tal, char* buffer) {
    // Håndter negative tal
    if (tal < 0) {
        append_to_buffer(buffer, "minus ");
        tal = -tal;
    }

    // Håndterer 0 
    if (tal == 0) {
        append_to_buffer(buffer, "nul");
        return;
    }

    // Håndterer millioner
    if (tal >= 1000000) {
        int millioner = tal / 1000000;
        if (millioner == 1) {
            append_to_buffer(buffer, "en million ");
        } else {
            dansketal(millioner, buffer);
            append_to_buffer(buffer, " millioner ");
        }
        tal %= 1000000;
    }

    // Håndterer tusinder
    if (tal >= 1000) {
        int tusinder = tal / 1000;
        if (tusinder == 1) {
            append_to_buffer(buffer, "et tusinde ");
        } else {
            dansketal(tusinder, buffer);
            append_to_buffer(buffer, " tusinde ");
        }
        tal %= 1000;
    }

    // Håndterer hundreder
    if (tal >= 100) {
        int hundreder = tal / 100;
        if (hundreder == 1) {
            append_to_buffer(buffer, "et hundrede");
        } else {
            append_to_buffer(buffer, nulTilNi[hundreder]);
            append_to_buffer(buffer, " hundrede");
        }
        tal %= 100;
        if (tal > 0) {
            append_to_buffer(buffer, " og ");
        }
    }

    // Håndterer tal mellem 20 og 99
    if (tal >= 20) {
        int tier = tal / 10;
        int enhed = tal % 10;
        if (enhed > 0) {
            append_to_buffer(buffer, nulTilNi[enhed]);
            append_to_buffer(buffer, "og");
        }
        append_to_buffer(buffer, tiere[tier]);
    }
    // Håndterer tal mellem 10 og 19 
    else if (tal >= 10) {
        append_to_buffer(buffer, tiTilNitten[tal - 10]);
    }
    // Håndterer tal fra 1 til 9
    else if (tal > 0) {
        append_to_buffer(buffer, nulTilNi[tal]);
    }
}

/*int main() {
    char buffer[256];

    int tal = 125;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%s\n", buffer);  // Forventet: "et hundrede og femogtyve"

    tal = -1001;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%s\n", buffer);  // Forventet: "minus et tusinde og en"

    tal = 999999;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%s\n", buffer);  // Forventet: "ni hundrede nioghalvfems tusinde ni hundrede nioghalvfems"

    tal = 99;
    buffer[0] = '\0';  
    dansketal(tal, buffer);
    printf("%s\n", buffer);  // Forventet: "nioghalvfems"

    return 0;
}
*/