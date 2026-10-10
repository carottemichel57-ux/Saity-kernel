// Saity kernel - ETAPE 1 (test d'ecriture uniquement)
// Au chargement, ecrit un petit fichier dans ux0:data/ pour verifier que le noyau peut ecrire.
// Ne fait rien d'autre. Pas de zone partagee, pas de menu.
#include <taihen.h>
#include <stdint.h>
#include <string.h>
#include <psp2kern/kernel/sysmem.h>
#include <psp2kern/io/fcntl.h>

int ksceIoOpen(const char *file, int flags, int mode);
int ksceIoWrite(int fd, const void *data, unsigned int size);
int ksceIoClose(int fd);

int module_start(SceSize argc, const void *args) {
    int fd = ksceIoOpen("ux0:data/saity_kernel_test.txt",
                        SCE_O_WRONLY | SCE_O_CREAT | SCE_O_TRUNC, 0777);
    if (fd >= 0) {
        static const char msg[] = "saity kernel ok\n";
        ksceIoWrite(fd, msg, sizeof(msg) - 1);
        ksceIoClose(fd);
    }
    return 0;   /* succes */
}

int module_stop(SceSize argc, const void *args) {
    return 0;   /* succes */
}
