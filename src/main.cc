#include "fetch.hh"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <regex>
#include <string>
#include <sys/utsname.h>
using namespace std;

#define _win 1
#define _mac 2
#define _linux 3

void getKernelVersion() {
    char *ret;
    char buf[128] = {0};
    FILE *fp;

    if ((fp = popen("echo $(uname -r) | cut -d'-' -f1-1", "r")) == NULL) {
        printf("[ERROR]: Couldn't pipe!\n");
        exit(1);
    }

    while (fgets(buf, 128, fp) != NULL) {
        std::cout << buf;
    }
}

void getUsr() {
    char *ret;
    char buf[128] = {0};
    FILE *fp;

    if ((fp = \
        popen("echo -e \"\\033[0;32m$(whoami)\\033[0;31m@\\033[0;36m$(hostname)\\033[37;0m\"", "r")) \
        == NULL) {
        printf("[ERROR]: Couldn't pipe!\n");
        exit(1);
    }

    while (fgets(buf, 128, fp) != NULL) {
        std::cout << buf;
    }
}


/* This only works if you have faith in the Linux gods that
 * every linux distrobution has this "/etc/os-release" file,
 * which I hope, but I would never know. */
string getDistroName() {
    std::ifstream stream("/etc/os-release");
    std::string line;
    std::regex nameRegex("^NAME=\"(.*?)\"$");
    std::smatch match;

    std::string name;
    while (std::getline(stream, line)) {
        if (std::regex_search(line, match, nameRegex)) {
            name = match[1].str();
            break;
        }
    }
    return name;
}

int EFetch::fetch() {
    string ascii = \
    "         _nnnn_                      \n"
    "        dGGGGMMb                     \n"
    "       @p~qp~~qMb                    \n"
    "       M|@||@) M|                    \n"
    "       @,----.JM|                    \n"
    "      JS^\\__/   qKL                   \n"
    "     dZP        qKRb                 \n"
    "    dZP          qKKb                \n"
    "   fZP            SMMb               \n"
    "   HZM            MMMM               \n"
    "   FqM            MMMM               \n"
    " __| \".        |\\dS\"qML              \n"
    " |    `.       | `' \\Zq              \n"
    "_)      \\.___.,|     .'              \n"
    "\\____   )MMMMMM|   .'                \n"
    "     `-'       `--'                  \n";
    std::cout << ascii + "\n";
    getUsr();
    std::cout << "\x1b[0;32mOperating system:\x1b[0;37m " + getDistroName() + "\n";
    std::cout << "\x1b[0;32mKernel version:\x1b[0;37m ";
    getKernelVersion();
    return 0;
}

int main(int argc, char **argv) {
    EFetch ef;
    ef.fetch();
    return 0;
}
